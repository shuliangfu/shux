/**
 * pipeline_glue.c — 与 -E 产出的 pipeline_gen.c 同属一个翻译单元的 C 胶水代码。
 *
 * 用法：pipeline_gen.c 末尾有 #include "pipeline_glue.c"（由 runtime.c -E 或 build_patch 追加），
 * 编译 pipeline_gen.c 时由 cc 在同一 TU 内包含本文件，故可直接使用上方已定义的 ast_* / codegen_* 等类型。
 * 不单独编译；无补丁、无 sed，所有逻辑在此源文件内从根源提供。
 */

/* struct shulang_slice_uint8_t 已由 -E 产出的 pipeline_gen.c 上方定义，不在此重复。 */
#include <string.h>

/** 从 (data, len) 构造 slice，供 parser.su 内 parse_into_buf 调 parse_one_function_impl 时使用。 */
struct shulang_slice_uint8_t parser_slice_from_buf(uint8_t *data, int32_t len) {
  struct shulang_slice_uint8_t s;
  s.data = data;
  s.length = (size_t)(len >= 0 ? len : 0);
  return s;
}

/**
 * lexer.su 内的 extern：Codegen 会带 lexer_ 模块前缀，否则会链接到不存在的 lexer_parser_slice_from_buf。
 * 与 parser_slice_from_buf 等价，仅别名。
 */
struct shulang_slice_uint8_t lexer_parser_slice_from_buf(uint8_t *data, int32_t len) {
  return parser_slice_from_buf(data, len);
}

/** 供 pipeline.su run_su_pipeline_impl 使用：与 parser_slice_from_buf 相同，避免 -E 对 parser_* 符号双重前缀。 */
struct shulang_slice_uint8_t pipeline_source_slice(uint8_t *data, int32_t len) {
  return parser_slice_from_buf(data, len);
}

/* C 包装：以 (data, len) 形式调用 pipeline，impl 内用 parse_into_with_init_buf 解析，无需组 slice。 */
extern int32_t pipeline_run_su_pipeline_impl(struct ast_Module *module, struct ast_ASTArena *arena, uint8_t *source_data, size_t source_len, struct codegen_CodegenOutBuf *out_buf, struct ast_PipelineDepCtx *ctx);

int32_t pipeline_run_su_pipeline(struct ast_Module *module, struct ast_ASTArena *arena, const uint8_t *source_data, size_t source_len, struct codegen_CodegenOutBuf *out_buf, struct ast_PipelineDepCtx *ctx) {
  return pipeline_run_su_pipeline_impl(module, arena, (uint8_t *)source_data, source_len, out_buf, ctx);
}

size_t pipeline_sizeof_arena(void) { return sizeof(struct ast_ASTArena); }
size_t pipeline_sizeof_module(void) { return sizeof(struct ast_Module); }
size_t pipeline_arena_offset_num_types(void) { return offsetof(struct ast_ASTArena, num_types); }
size_t pipeline_sizeof_elf_ctx(void) { return sizeof(struct platform_elf_ElfCodegenCtx); }

#include <stdio.h>
void pipeline_debug_module_funcs(void *m) {
  struct ast_Module *mod = (struct ast_Module *)m;
  int i, n = (int)mod->num_funcs;
  if (n > 256) n = 256;
  for (i = 0; i < n; i++) {
    int len = (int)mod->funcs[i].name_len;
    fprintf(stderr, "[DEBUG] module func[%d] name_len=%d name=%.*s\n", i, len, len > 0 && len <= 64 ? len : 0, mod->funcs[i].name);
  }
}

/** 供 runtime.c 诊断：返回 module 的 num_funcs（需与 pipeline 同 TU 以用 ast_Module 布局）。 */
int driver_get_module_num_funcs(void *m) {
  return m ? (int)((struct ast_Module *)m)->num_funcs : 0;
}

/** 供 runtime.c 烟测摘要：解析后 module.main_func_index（无 main 为 -1，与 pipeline.su parse_into_set_main_index 一致）。 */
int driver_get_module_main_func_index(void *m) {
  return m ? (int)((struct ast_Module *)m)->main_func_index : -2;
}

/** 诊断：解析 entry 后打印 main 的 body_ref；日常构建关闭，排查 main 空体时取消下方注释。由 pipeline.su 在 parse 后 / codegen 前调用。 */
void driver_diagnostic_entry_module(struct ast_Module *mod, struct ast_ASTArena *a) {
  (void)a;
  (void)mod;
  /* if (mod && (mod->main_func_index >= 0 && mod->main_func_index < mod->num_funcs)) {
    int32_t br = mod->funcs[mod->main_func_index].body_ref;
    fprintf(stderr, "[diag] entry num_funcs=%d main_idx=%d body_ref=%d\n",
            (int)mod->num_funcs, (int)mod->main_func_index, (int)br);
  } else if (mod) {
    fprintf(stderr, "[diag] entry num_funcs=%d main_idx=%d (invalid)\n",
            (int)mod->num_funcs, (int)mod->main_func_index);
  } */
}

/** 诊断：解析后打印 main 对应 body block 的 num_stmt_order（C 侧调用）；日常构建保留实现不调用，排查时在 runtime.c 恢复调用。 */
void driver_diagnostic_entry_block_after_parse(void *mod, void *arena) {
  struct ast_Module *m = (struct ast_Module *)mod;
  struct ast_ASTArena *a = (struct ast_ASTArena *)arena;
  if (!m || !a || m->main_func_index < 0 || m->main_func_index >= m->num_funcs)
    return;
  int32_t br = m->funcs[m->main_func_index].body_ref;
  if (br <= 0 || br > a->num_blocks)
    return;
  (void)br;
  (void)a;
  /* struct ast_Block b = ast_ast_arena_block_get(a, br);
  fprintf(stderr, "[diag] after_parse body_ref=%d num_blocks=%d block.num_stmt_order=%d\n",
          (int)br, (int)a->num_blocks, (int)b.num_stmt_order); */
}

/* std.io.driver 单次 _buf 声明与 inline 已由 -E 产出在 pipeline_gen.c 顶部（runtime.c -E 路径 preamble），此处仅保留批量读写桩。 */

/* std.io.driver 批量读写桩：pipeline_gen.c 同 TU 已定义 struct std_io_driver_Buffer；io.o 提供 io_read_batch_buf/io_write_batch_buf，供 shu_su 链接时解析。 */
extern ptrdiff_t io_read_batch_buf(int fd, const struct std_io_driver_Buffer *bufs, int n, unsigned timeout_ms);
extern ptrdiff_t io_write_batch_buf(int fd, const struct std_io_driver_Buffer *bufs, int n, unsigned timeout_ms);

int32_t std_io_driver_submit_read_batch_buf(size_t handle, struct std_io_driver_Buffer *bufs, int32_t n, uint32_t timeout_ms) {
  ptrdiff_t r = io_read_batch_buf((int)handle, bufs, n, timeout_ms);
  return (r < 0) ? -1 : (int32_t)r;
}

int32_t std_io_driver_submit_write_batch_buf(size_t handle, struct std_io_driver_Buffer *bufs, int32_t n, uint32_t timeout_ms) {
  ptrdiff_t r = io_write_batch_buf((int)handle, bufs, n, timeout_ms);
  return (r < 0) ? -1 : (int32_t)r;
}

/** 读池中 expr.kind；仅供本文件与 glue 导出函数使用（SU 无法用 Expr 局部安全 typeck）。 */
static enum ast_ExprKind glue_arena_expr_kind_at_ref(struct ast_ASTArena *a, int32_t expr_ref) {
  int32_t ix;
  if (!a || expr_ref <= 0 || expr_ref > a->num_exprs)
    return ast_ExprKind_EXPR_LIT;
  ix = expr_ref - 1;
  if (ix < 0 || ix >= 8192)
    return ast_ExprKind_EXPR_LIT;
  return a->exprs[ix].kind;
}

/**
 * ast.su extern：块末若为 RETURN/PANIC/BREAK/CONTINUE，返回 1（禁止隐式尾）；非法 ref 视为 1。
 * 符号名 deliberately 无前缀，供 SU「extern function」原样映射，避免与其它 ast_ast_* extern 串联重复前缀。
 */
int implicit_tail_expr_disallowed_by_glue(struct ast_ASTArena *a, int32_t expr_ref) {
  enum ast_ExprKind kd;
  if (!a || expr_ref <= 0 || expr_ref > a->num_exprs)
    return 1;
  kd = glue_arena_expr_kind_at_ref(a, expr_ref);
  if (kd == ast_ExprKind_EXPR_RETURN || kd == ast_ExprKind_EXPR_PANIC ||
      kd == ast_ExprKind_EXPR_BREAK || kd == ast_ExprKind_EXPR_CONTINUE)
    return 1;
  return 0;
}

/**
 * backend.su 经 import codegen，extern 编成 codegen_codegen_* / codegen_driver_*。
 * pipeline_gen.c 已声明 codegen_su_import_path_to_c_prefix、driver_call_num_args_override，
 * 实现在 codegen.o + runtime.c（runtime_driver.o）；此处只做一层转发。
 */
void codegen_codegen_su_import_path_to_c_prefix(uint8_t *path, uint8_t *buf, int32_t len) {
  codegen_su_import_path_to_c_prefix(path, buf, len);
}

int32_t codegen_driver_call_num_args_override(uint8_t *prefix, int32_t prefix_len, uint8_t *name, int32_t name_len, int32_t num_args) {
  return driver_call_num_args_override(prefix, prefix_len, name, name_len, num_args);
}

/**
 * 从 arena.types[ref-1] 拷贝整块 name[64] 到调用方缓冲区（memcpy），避免 ast_ast_arena_type_get
 * 在大 struct ast_Type 场景下按值返回时后端只传部分字段导致名段撕裂（如 AArch64 上布局查找失败）。
 * 返回 name_len；ref 无效或越界返回 0。
 */
int32_t pipeline_type_named_name_into(struct ast_ASTArena *arena, int32_t ref, uint8_t *out64) {
  int32_t idx;
  struct ast_Type *t;
  if (!arena || !out64 || ref <= 0 || ref > arena->num_types)
    return 0;
  idx = ref - 1;
  if (idx < 0 || idx >= 512)
    return 0;
  t = &arena->types[idx];
  memcpy(out64, t->name, sizeof(t->name));
  return t->name_len;
}

/**
 * 读取 arena.types[ref-1].kind 作为与 TypeKind ordinal 对齐的枚举序数。
 * ref 无效时返回 -1。
 */
int32_t pipeline_type_kind_ord_at(struct ast_ASTArena *arena, int32_t ref) {
  int32_t idx;
  if (!arena || ref <= 0 || ref > arena->num_types)
    return -1;
  idx = ref - 1;
  if (idx < 0 || idx >= 512)
    return -1;
  return (int32_t)arena->types[idx].kind;
}

/**
 * 读取 arena.types[ref-1].elem_type_ref（指针指向元素类型、向量元素类型等）。
 * ref 无效时返回 0。
 */
int32_t pipeline_type_elem_ref_at(struct ast_ASTArena *arena, int32_t ref) {
  int32_t idx;
  if (!arena || ref <= 0 || ref > arena->num_types)
    return 0;
  idx = ref - 1;
  if (idx < 0 || idx >= 512)
    return 0;
  return arena->types[idx].elem_type_ref;
}

/**
 * 读取 arena.types[ref-1].array_size（数组长度、向量 lane 数等）。
 * ref 无效时返回 0。
 */
int32_t pipeline_type_array_size_at(struct ast_ASTArena *arena, int32_t ref) {
  int32_t idx;
  if (!arena || ref <= 0 || ref > arena->num_types)
    return 0;
  idx = ref - 1;
  if (idx < 0 || idx >= 512)
    return 0;
  return arena->types[idx].array_size;
}

/** struct_layout 槽有效下标：返回名称字节长度（与 StructLayout.name_len 一致）。 */
int32_t pipeline_module_struct_layout_name_len(struct ast_Module *m, int32_t idx) {
  int32_t len;
  if (!m || idx < 0 || idx >= 32)
    return 0;
  len = (int32_t)m->struct_layouts[idx].name_len;
  if (len <= 0 || len > 63)
    return 0;
  return len;
}

/** 拷贝 Name 字段到 out64（固定 64 字节缓冲区）。idx 无效时不写入。 */
void pipeline_module_struct_layout_name_into(struct ast_Module *m, int32_t idx, uint8_t *out64) {
  if (!m || idx < 0 || idx >= 32 || !out64)
    return;
  memcpy(out64, m->struct_layouts[idx].name, sizeof(m->struct_layouts[idx].name));
}

/** 字段个数（与 StructLayout.num_fields 一致）。 */
int32_t pipeline_module_struct_layout_num_fields(struct ast_Module *m, int32_t idx) {
  int32_t nf;
  if (!m || idx < 0 || idx >= 32)
    return 0;
  nf = (int32_t)m->struct_layouts[idx].num_fields;
  if (nf < 0 || nf > 24)
    return 0;
  return nf;
}

/** 第 j 个字段的类型池 ref；无效返回 0。 */
int32_t pipeline_module_struct_layout_field_type_ref(struct ast_Module *m, int32_t li, int32_t j) {
  if (!m || li < 0 || li >= 32 || j < 0 || j >= 24)
    return 0;
  return m->struct_layouts[li].field_type_refs[j];
}

/** 字段名长度；无效返回 0。 */
int32_t pipeline_module_struct_layout_field_name_len(struct ast_Module *m, int32_t li, int32_t j) {
  int32_t fl;
  if (!m || li < 0 || li >= 32 || j < 0 || j >= 24)
    return 0;
  fl = (int32_t)m->struct_layouts[li].field_lens[j];
  if (fl <= 0 || fl > 63)
    return 0;
  return fl;
}

/** 拷贝字段名到 out64。 */
void pipeline_module_struct_layout_field_name_into(struct ast_Module *m, int32_t li, int32_t j, uint8_t *out64) {
  if (!m || li < 0 || li >= 32 || j < 0 || j >= 24 || !out64)
    return;
  memcpy(out64, m->struct_layouts[li].field_names[j], sizeof(m->struct_layouts[li].field_names[j]));
}

/**
 * 将 struct_layout 整槽清零；parse_struct_record_layout_into 在向 Module 填入布局前必须先调用，
 * 避免残留垃圾；亦为后续 set_name/set_field 提供干净基底。
 */
void pipeline_module_struct_layout_reset_slot(struct ast_Module *m, int32_t idx) {
  if (!m || idx < 0 || idx >= 32)
    return;
  memset(&m->struct_layouts[idx], 0, sizeof(m->struct_layouts[idx]));
}

/** memcpy + name_len：避免 SU 对大嵌套 struct_layout.name 逐字节赋值在 AArch64 等后端不落盘。 */
void pipeline_module_struct_layout_set_name(struct ast_Module *m, int32_t idx, uint8_t *bytes, int32_t len) {
  struct ast_StructLayout *sl;
  if (!m || idx < 0 || idx >= 32 || !bytes)
    return;
  if (len <= 0 || len > 63)
    return;
  sl = &m->struct_layouts[idx];
  sl->name_len = len;
  memset(sl->name, 0, sizeof(sl->name));
  memcpy(sl->name, bytes, (size_t)len);
}

/** memcpy 字段名并写 lens/type_refs/offsets；与 set_name 同类 ABI 补丁。 */
void pipeline_module_struct_layout_set_field(struct ast_Module *m, int32_t li, int32_t j, uint8_t *fname_bytes,
                                              int32_t fname_len, int32_t ftype_ref, int32_t foff) {
  struct ast_StructLayout *sl;
  if (!m || li < 0 || li >= 32 || j < 0 || j >= 24)
    return;
  if (fname_len <= 0 || fname_len > 63)
    return;
  sl = &m->struct_layouts[li];
  sl->field_lens[j] = fname_len;
  sl->field_type_refs[j] = ftype_ref;
  sl->field_offsets[j] = foff;
  memset(sl->field_names[j], 0, sizeof(sl->field_names[j]));
  if (fname_bytes)
    memcpy(sl->field_names[j], fname_bytes, (size_t)fname_len);
}

