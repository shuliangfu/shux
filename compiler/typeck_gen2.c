/* generated (single-file with deps) */
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static inline void shulang_panic_(int has_msg, int msg_val) __attribute__((noreturn, cold));
static inline void shulang_panic_(int has_msg, int msg_val) {
  if (has_msg) (void)fprintf(stderr, "%d\n", msg_val);
  abort();
}
extern int32_t shu_io_register(uint8_t *ptr, size_t len, size_t handle);
extern int32_t shu_io_submit_read(uint8_t *ptr, size_t len, size_t handle, uint32_t timeout_m);
extern int32_t shu_io_submit_write(uint8_t *ptr, size_t len, size_t handle, uint32_t timeout_m);
typedef struct { void *ptr; size_t len; size_t handle; } shu_buffer_abi_t;
static inline int32_t shu_io_register_buf(intptr_t buf) { const shu_buffer_abi_t *b = (const shu_buffer_abi_t *)(uintptr_t)buf; return shu_io_register((uint8_t *)b->ptr, b->len, b->handle); }
static inline int32_t shu_io_submit_read_buf(intptr_t buf, int32_t timeout_m) { const shu_buffer_abi_t *b = (const shu_buffer_abi_t *)(uintptr_t)buf; return shu_io_submit_read((uint8_t *)b->ptr, b->len, b->handle, (uint32_t)timeout_m); }
static inline int32_t shu_io_submit_write_buf(intptr_t buf, int32_t timeout_m) { const shu_buffer_abi_t *b = (const shu_buffer_abi_t *)(uintptr_t)buf; return shu_io_submit_write((uint8_t *)b->ptr, b->len, b->handle, (uint32_t)timeout_m); }
typedef struct { uint8_t *ptr; size_t len; size_t handle; } shu_batch_buf_t;
extern int io_register_buffers_buf_c(const shu_batch_buf_t *bufs, int nr);
static inline int io_register_buffers_buf_i32(intptr_t bufs, int nr) { return io_register_buffers_buf_c((const shu_batch_buf_t *)(uintptr_t)bufs, nr); }
enum ast_TypeKind { ast_TypeKind_TYPE_I32, ast_TypeKind_TYPE_BOOL, ast_TypeKind_TYPE_U8, ast_TypeKind_TYPE_U32, ast_TypeKind_TYPE_U64, ast_TypeKind_TYPE_I64, ast_TypeKind_TYPE_USIZE, ast_TypeKind_TYPE_ISIZE, ast_TypeKind_TYPE_NAMED, ast_TypeKind_TYPE_PTR, ast_TypeKind_TYPE_ARRAY, ast_TypeKind_TYPE_SLICE, ast_TypeKind_TYPE_VECTOR, ast_TypeKind_TYPE_F32, ast_TypeKind_TYPE_F64, ast_TypeKind_TYPE_VOID };
enum ast_ExprKind { ast_ExprKind_EXPR_LIT, ast_ExprKind_EXPR_FLOAT_LIT, ast_ExprKind_EXPR_BOOL_LIT, ast_ExprKind_EXPR_VAR, ast_ExprKind_EXPR_ADD, ast_ExprKind_EXPR_SUB, ast_ExprKind_EXPR_MUL, ast_ExprKind_EXPR_DIV, ast_ExprKind_EXPR_MOD, ast_ExprKind_EXPR_SHL, ast_ExprKind_EXPR_SHR, ast_ExprKind_EXPR_BITAND, ast_ExprKind_EXPR_BITOR, ast_ExprKind_EXPR_BITXOR, ast_ExprKind_EXPR_EQ, ast_ExprKind_EXPR_NE, ast_ExprKind_EXPR_LT, ast_ExprKind_EXPR_LE, ast_ExprKind_EXPR_GT, ast_ExprKind_EXPR_GE, ast_ExprKind_EXPR_LOGAND, ast_ExprKind_EXPR_LOGOR, ast_ExprKind_EXPR_NEG, ast_ExprKind_EXPR_BITNOT, ast_ExprKind_EXPR_LOGNOT, ast_ExprKind_EXPR_IF, ast_ExprKind_EXPR_BLOCK, ast_ExprKind_EXPR_TERNARY, ast_ExprKind_EXPR_ASSIGN, ast_ExprKind_EXPR_ADD_ASSIGN, ast_ExprKind_EXPR_SUB_ASSIGN, ast_ExprKind_EXPR_MUL_ASSIGN, ast_ExprKind_EXPR_DIV_ASSIGN, ast_ExprKind_EXPR_MOD_ASSIGN, ast_ExprKind_EXPR_BITAND_ASSIGN, ast_ExprKind_EXPR_BITOR_ASSIGN, ast_ExprKind_EXPR_BITXOR_ASSIGN, ast_ExprKind_EXPR_SHL_ASSIGN, ast_ExprKind_EXPR_SHR_ASSIGN, ast_ExprKind_EXPR_BREAK, ast_ExprKind_EXPR_CONTINUE, ast_ExprKind_EXPR_RETURN, ast_ExprKind_EXPR_PANIC, ast_ExprKind_EXPR_MATCH, ast_ExprKind_EXPR_FIELD_ACCESS, ast_ExprKind_EXPR_STRUCT_LIT, ast_ExprKind_EXPR_ARRAY_LIT, ast_ExprKind_EXPR_INDEX, ast_ExprKind_EXPR_CALL, ast_ExprKind_EXPR_METHOD_CALL, ast_ExprKind_EXPR_ENUM_VARIANT, ast_ExprKind_EXPR_BINOP, ast_ExprKind_EXPR_AS };
enum ast_ImportKind { ast_ImportKind_IMPORT_WHOLE, ast_ImportKind_IMPORT_BINDING, ast_ImportKind_IMPORT_SELECT };
struct ast_Type { enum ast_TypeKind kind; uint8_t name[64]; int32_t name_len; int32_t elem_type_ref; int32_t array_size; };
struct ast_Expr { enum ast_ExprKind kind; int32_t resolved_type_ref; int32_t line; int32_t col; int32_t int_val; double float_val; uint8_t var_name[64]; int32_t var_name_len; int32_t binop_left_ref; int32_t binop_right_ref; int32_t unary_operand_ref; int32_t if_cond_ref; int32_t if_then_ref; int32_t if_else_ref; int32_t block_ref; int32_t match_matched_ref; int32_t match_arm_result_refs[16]; int32_t match_num_arms; int32_t match_arm_is_wildcard[16]; int32_t match_arm_lit_val[16]; int32_t match_arm_is_enum_variant[16]; int32_t match_arm_variant_index[16]; int32_t field_access_base_ref; uint8_t field_access_field_name[64]; int32_t field_access_field_len; int32_t field_access_is_enum_variant; int32_t field_access_offset; int32_t index_base_ref; int32_t index_index_ref; int32_t index_base_is_slice; int32_t call_callee_ref; int32_t call_arg_refs[16]; int32_t call_num_args; int32_t method_call_base_ref; uint8_t method_call_name[64]; int32_t method_call_name_len; int32_t method_call_arg_refs[16]; int32_t method_call_num_args; int32_t const_folded_val; int32_t const_folded_valid; int32_t index_proven_in_bounds; uint8_t struct_lit_struct_name[64]; int32_t struct_lit_struct_name_len; int32_t struct_lit_num_fields; uint8_t struct_lit_field_names[8][64]; int32_t struct_lit_field_lens[8]; int32_t struct_lit_init_refs[8]; int32_t array_lit_num_elems; int32_t array_lit_elem_refs[16]; int32_t float_bits_lo; int32_t float_bits_hi; int32_t enum_variant_tag; int32_t as_operand_ref; int32_t as_target_type_ref; };
struct ast_ConstDecl { uint8_t name[64]; int32_t name_len; int32_t type_ref; int32_t init_ref; };
struct ast_LetDecl { uint8_t name[64]; int32_t name_len; int32_t type_ref; int32_t init_ref; };
struct ast_WhileLoop { int32_t cond_ref; int32_t body_ref; };
struct ast_ForLoop { int32_t init_ref; int32_t cond_ref; int32_t step_ref; int32_t body_ref; };
struct ast_IfStmt { int32_t cond_ref; int32_t then_body_ref; };
struct ast_StmtOrderItem { uint8_t kind; int32_t idx; };
struct ast_LabeledStmt { uint8_t label[32]; int32_t label_len; int32_t is_goto; uint8_t goto_target[32]; int32_t goto_target_len; int32_t return_expr_ref; };
struct ast_Block { struct ast_ConstDecl const_decls[128]; int32_t num_consts; struct ast_LetDecl let_decls[128]; int32_t num_lets; int32_t num_early_lets; struct ast_WhileLoop loops[8]; int32_t num_loops; struct ast_ForLoop for_loops[8]; int32_t num_for_loops; struct ast_IfStmt if_stmts[16]; int32_t num_if_stmts; int32_t defer_block_refs[8]; int32_t num_defers; struct ast_LabeledStmt labeled_stmts[8]; int32_t num_labeled_stmts; int32_t expr_stmt_refs[32]; int32_t num_expr_stmts; int32_t final_expr_ref; struct ast_StmtOrderItem stmt_order[96]; int32_t num_stmt_order; };
struct ast_Param { uint8_t name[32]; int32_t name_len; int32_t type_ref; };
struct ast_Func { uint8_t name[64]; int32_t name_len; struct ast_Param params[16]; int32_t num_params; int32_t return_type_ref; int32_t body_ref; int32_t body_expr_ref; int32_t is_extern; };
struct ast_StructLayout { uint8_t name[64]; int32_t name_len; int32_t num_fields; uint8_t field_names[8][64]; int32_t field_lens[8]; int32_t field_offsets[8]; int32_t field_type_refs[8]; };
struct ast_Module { struct ast_Func funcs[256]; int32_t func_refs[256]; int32_t num_funcs; int32_t main_func_index; uint8_t import_path_data[2048]; int32_t import_path_lens[32]; int32_t num_imports; int32_t import_kinds[32]; uint8_t import_binding_name[32][64]; int32_t import_binding_name_len[32]; int32_t import_select_count[32]; uint8_t import_select_names[32][8][64]; int32_t import_select_name_lens[32][8]; int32_t num_top_level_lets; uint8_t top_level_let_names[32][64]; int32_t top_level_let_name_lens[32]; int32_t top_level_let_type_refs[32]; int32_t top_level_let_init_refs[32]; int32_t top_level_let_is_const[32]; struct ast_StructLayout struct_layouts[32]; int32_t num_struct_layouts; };
struct ast_ASTArena { struct ast_Type types[512]; int32_t num_types; struct ast_Expr exprs[4096]; int32_t num_exprs; struct ast_Block blocks[512]; int32_t num_blocks; struct ast_Func funcs[256]; int32_t num_funcs; };
struct ast_PipelineDepCtx { struct ast_Module * dep_modules[32]; struct ast_ASTArena * dep_arenas[32]; int32_t ndep; uint8_t entry_dir_buf[512]; int32_t entry_dir_len; int32_t num_lib_roots; uint8_t lib_root_bufs[8][256]; int32_t lib_root_lens[8]; uint8_t path_buf[512]; uint8_t loaded_buf[262144]; ptrdiff_t loaded_len; uint8_t preprocess_buf[262144]; int32_t preprocess_len; int32_t use_asm_backend; int32_t target_arch; int32_t use_macho_o; int32_t use_coff_o; int32_t current_block_ref; int32_t current_func_index; uint8_t * dep_paths[32]; int32_t skip_codegen_dep_0; int32_t entry_already_parsed; int32_t current_func_single_empty_param_index; int32_t current_func_empty_param_count; int32_t current_func_empty_param_indices[16]; int32_t current_emit_empty_var_next_index; int32_t emit_expr_as_callee; struct ast_Module * current_codegen_module; struct ast_ASTArena * current_codegen_arena; };
extern struct ast_Expr ast_ast_arena_expr_get(struct ast_ASTArena * arena, int32_t ref);
extern int32_t ast_ast_arena_type_alloc(struct ast_ASTArena * arena);
extern struct ast_Type ast_ast_arena_type_get(struct ast_ASTArena * arena, int32_t ref);
extern void ast_ast_arena_type_set(struct ast_ASTArena * arena, int32_t ref, struct ast_Type t);
extern int ast_ref_is_null(int32_t ref);
extern void ast_ast_arena_expr_set(struct ast_ASTArena * arena, int32_t ref, struct ast_Expr e);
extern struct ast_Block ast_ast_arena_block_get(struct ast_ASTArena * arena, int32_t ref);
extern int32_t typeck_float64_bits_lo(double d);
extern int32_t typeck_float64_bits_hi(double d);
extern void driver_diagnostic_typeck_func_fail(int32_t func_idx, uint8_t * name, int32_t name_len, int32_t kind);
extern void driver_diagnostic_typeck_ptr_field(int32_t bt_kind, int32_t inner_kind, int32_t inner_nlen, int32_t base_resolved_ref,
    int32_t num_struct_layouts);
extern void driver_diagnostic_typeck_block_enter(int32_t func_idx, int32_t block_ref, int32_t n_const, int32_t n_let, int32_t n_loop, int32_t n_for, int32_t n_expr, int32_t final_ref);
extern void driver_diagnostic_typeck_ret_fail(int32_t stage, int32_t op_expr_ref, int32_t expect_ty_ref, int32_t got_ty_ref);
int32_t typeck_type_kind_ordinal(enum ast_TypeKind k);
int typeck_name_equal(uint8_t * a, int32_t a_len, uint8_t * b, int32_t b_len);
int32_t typeck_get_field_offset_from_layout(struct ast_Module * module, uint8_t * type_name, int32_t type_name_len, uint8_t * field_name, int32_t field_name_len);
int32_t typeck_get_field_type_ref_from_layout(struct ast_Module * module, uint8_t * type_name, int32_t type_name_len, uint8_t * field_name, int32_t field_name_len);
int32_t typeck_ensure_struct_layout_from_struct_lit(struct ast_Module * module, struct ast_Expr e);
int typeck_expr_var_name_equal_func(struct ast_ASTArena * arena, int32_t callee_expr_ref, struct ast_Module * mod, int32_t func_index);
int32_t typeck_find_or_alloc_named_type_ref(struct ast_ASTArena * arena, uint8_t * name, int32_t name_len);
int32_t typeck_ensure_i32_type_ref(struct ast_ASTArena * arena);
int32_t typeck_ensure_bool_type_ref(struct ast_ASTArena * arena);
int32_t typeck_ensure_f64_type_ref(struct ast_ASTArena * arena);
int32_t typeck_ensure_usize_type_ref(struct ast_ASTArena * arena);
int32_t typeck_get_dep_return_type_in_caller_arena(int32_t from_dep_index, int32_t dep_return_type_ref, struct ast_ASTArena * caller_arena, struct ast_PipelineDepCtx * ctx);
int32_t typeck_ensure_i64_type_ref(struct ast_ASTArena * caller_arena);
int32_t typeck_find_or_alloc_array_type_ref(struct ast_ASTArena * a, int32_t elem_ref, int32_t array_size);
int32_t typeck_ensure_array_type_ref_named_elem(struct ast_ASTArena * a, uint8_t * elem_nm, int32_t elem_nm_len, int32_t array_size);
int32_t typeck_dep_return_type_to_caller_arena(struct ast_ASTArena * dep_arena, int32_t dep_return_type_ref, struct ast_ASTArena * caller_arena);
int32_t typeck_find_func_return_type_in_module(struct ast_Module * mod, struct ast_ASTArena * mod_arena, struct ast_ASTArena * caller_arena, struct ast_ASTArena * callee_arena, int32_t callee_expr_ref, int32_t from_dep_index, struct ast_PipelineDepCtx * ctx);
int32_t typeck_find_func_return_type_in_module_by_name(struct ast_Module * mod, struct ast_ASTArena * caller_arena, uint8_t * name, int32_t name_len, int32_t from_dep_index, struct ast_PipelineDepCtx * ctx);
int32_t typeck_resolve_call_callee_return_type(struct ast_Module * module, struct ast_ASTArena * arena, int32_t callee_expr_ref, struct ast_PipelineDepCtx * ctx);
int32_t typeck_expr_type_ref_impl(struct ast_ASTArena * arena, int32_t expr_ref);
int32_t typeck_expr_type_ref(struct ast_ASTArena * arena, int32_t expr_ref);
int typeck_type_ref_is_bool_impl(struct ast_ASTArena * arena, int32_t type_ref);
int typeck_type_ref_is_bool(struct ast_ASTArena * arena, int32_t type_ref);
int typeck_type_refs_equal_impl(struct ast_ASTArena * arena, int32_t a, int32_t b);
int typeck_type_refs_equal(struct ast_ASTArena * arena, int32_t a, int32_t b);
int32_t typeck_check_expr_impl(struct ast_Module * module, struct ast_ASTArena * arena, int32_t expr_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx);
int32_t typeck_check_expr(struct ast_Module * module, struct ast_ASTArena * arena, int32_t expr_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx);
int typeck_func_body_has_implicit_return_tail(struct ast_ASTArena * arena, int32_t body_ref);
int32_t typeck_check_block_impl(struct ast_Module * module, struct ast_ASTArena * arena, int32_t block_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx);
int32_t typeck_check_block(struct ast_Module * module, struct ast_ASTArena * arena, int32_t block_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx);
int32_t typeck_typeck_su_ast_impl(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx);
int32_t typeck_typeck_su_ast_library(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx);
int32_t typeck_typeck_su_ast(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx);
int32_t typeck_type_kind_ordinal(enum ast_TypeKind k) {
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_I32) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_BOOL) {   return 1;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_U8) {   return 2;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_U32) {   return 3;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_U64) {   return 4;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_I64) {   return 5;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_USIZE) {   return 6;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_ISIZE) {   return 7;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_NAMED) {   return 8;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_PTR) {   return 9;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_ARRAY) {   return 10;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_SLICE) {   return 11;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_VECTOR) {   return 12;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_F32) {   return 13;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_F64) {   return 14;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (k == ast_TypeKind_TYPE_VOID) {   return 15;
 } else (__tmp = 0) ; __tmp; }));
  return (-1);
}
int typeck_name_equal(uint8_t * a, int32_t a_len, uint8_t * b, int32_t b_len) {
  (void)(({ int __tmp = 0; if (a_len != b_len || a_len <= 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t i = 0;
  while (i < a_len) {
    (void)(({ int __tmp = 0; if ((a)[i] != (b)[i]) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  return 1;
}
int32_t typeck_get_field_offset_from_layout(struct ast_Module * module, uint8_t * type_name, int32_t type_name_len, uint8_t * field_name, int32_t field_name_len) {
  int32_t k = 0;
  while (k < (module)->num_struct_layouts && k < 32) {
    struct ast_StructLayout sl = (k < 0 || (k) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[k]);
    (void)(({ int32_t __tmp = 0; if (typeck_name_equal((sl).name, (sl).name_len, type_name, type_name_len)) {   int32_t j = 0;
  while (j < (sl).num_fields && j < 8) {
    (void)(({ int32_t __tmp = 0; if (typeck_name_equal((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_names)[0]) : ((sl).field_names)[j]), (j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_lens)[0]) : ((sl).field_lens)[j]), field_name, field_name_len)) {   return (j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_offsets)[0]) : ((sl).field_offsets)[j]);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  return (-1);
}
int32_t typeck_get_field_type_ref_from_layout(struct ast_Module * module, uint8_t * type_name, int32_t type_name_len, uint8_t * field_name, int32_t field_name_len) {
  int32_t k = 0;
  while (k < (module)->num_struct_layouts && k < 32) {
    struct ast_StructLayout sl = (k < 0 || (k) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[k]);
    (void)(({ int32_t __tmp = 0; if (typeck_name_equal((sl).name, (sl).name_len, type_name, type_name_len)) {   int32_t j = 0;
  while (j < (sl).num_fields && j < 8) {
    (void)(({ int32_t __tmp = 0; if (typeck_name_equal((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_names)[0]) : ((sl).field_names)[j]), (j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_lens)[0]) : ((sl).field_lens)[j]), field_name, field_name_len)) {   return (j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((sl).field_type_refs)[0]) : ((sl).field_type_refs)[j]);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  return 0;
}
int32_t typeck_ensure_struct_layout_from_struct_lit(struct ast_Module * module, struct ast_Expr e) {
  (void)(({ int32_t __tmp = 0; if ((e).struct_lit_num_fields <= 0 || (e).struct_lit_num_fields > 8) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t name_len = (e).struct_lit_struct_name_len;
  (void)(({ int32_t __tmp = 0; if (name_len <= 0 || name_len > 63) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t k = 0;
  while (k < (module)->num_struct_layouts && k < 32) {
    struct ast_StructLayout sl = (k < 0 || (k) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[k]);
    (void)(({ int32_t __tmp = 0; if (typeck_name_equal((sl).name, (sl).name_len, (e).struct_lit_struct_name, name_len)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  (void)(({ int32_t __tmp = 0; if ((module)->num_struct_layouts >= 32) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  int32_t idx = (module)->num_struct_layouts;
  (void)(((module)->num_struct_layouts = (module)->num_struct_layouts + 1));
  int32_t i = 0;
  while (i < 64) {
    (void)(((i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), 0) : ((((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).name)[i] = (i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), ((e).struct_lit_struct_name)[0]) : ((e).struct_lit_struct_name)[i]), 0))));
    (void)((i = i + 1));
  }
  (void)(((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), 0) : (((module)->struct_layouts)[idx].name_len = name_len, 0))));
  (void)(((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), 0) : (((module)->struct_layouts)[idx].num_fields = (e).struct_lit_num_fields, 0))));
  int32_t off = 0;
  int32_t j = 0;
  while (j < (e).struct_lit_num_fields && j < 8) {
    int32_t fi = 0;
    while (fi < 64) {
      (void)(((fi < 0 || (fi) >= 64 ? (shulang_panic_(1, 0), 0) : (((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), (((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).field_names)[0]) : (((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).field_names)[j]))[fi] = (fi < 0 || (fi) >= 64 ? (shulang_panic_(1, 0), ((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((e).struct_lit_field_names)[0]) : ((e).struct_lit_field_names)[j]))[0]) : ((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((e).struct_lit_field_names)[0]) : ((e).struct_lit_field_names)[j]))[fi]), 0))));
      (void)((fi = fi + 1));
    }
    (void)(((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), 0) : ((((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).field_lens)[j] = (j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), ((e).struct_lit_field_lens)[0]) : ((e).struct_lit_field_lens)[j]), 0))));
    (void)(((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), 0) : ((((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).field_offsets)[j] = off, 0))));
    (void)(((j < 0 || (j) >= 8 ? (shulang_panic_(1, 0), 0) : ((((idx < 0 || (idx) >= 32 ? (shulang_panic_(1, 0), ((module)->struct_layouts)[0]) : ((module)->struct_layouts)[idx])).field_type_refs)[j] = 0, 0))));
    (void)((off = off + 8));
    (void)((j = j + 1));
  }
  return 0;
}
int typeck_expr_var_name_equal_func(struct ast_ASTArena * arena, int32_t callee_expr_ref, struct ast_Module * mod, int32_t func_index) {
  (void)(({ int __tmp = 0; if (callee_expr_ref <= 0 || callee_expr_ref > (arena)->num_exprs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Expr callee = ast_ast_arena_expr_get(arena, callee_expr_ref);
  (void)(({ int __tmp = 0; if ((callee).kind != ast_ExprKind_EXPR_VAR) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t b_len = (callee).var_name_len;
  (void)(({ int __tmp = 0; if (func_index < 0 || func_index >= (mod)->num_funcs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Func ff = (func_index < 0 || (func_index) >= 256 ? (shulang_panic_(1, 0), ((mod)->funcs)[0]) : ((mod)->funcs)[func_index]);
  int32_t a_len = (ff).name_len;
  (void)(({ int __tmp = 0; if (a_len != b_len || a_len <= 0 || a_len > 63) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t i = 0;
  while (i < a_len) {
    (void)(({ int __tmp = 0; if ((i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), ((ff).name)[0]) : ((ff).name)[i]) != (i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), ((callee).var_name)[0]) : ((callee).var_name)[i])) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  return 1;
}
int32_t typeck_find_or_alloc_named_type_ref(struct ast_ASTArena * arena, uint8_t * name, int32_t name_len) {
  (void)(({ int32_t __tmp = 0; if (name_len <= 0 || name_len > 63) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t k = 1;
  while (k <= (arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_NAMED && typeck_name_equal((tk).name, (tk).name_len, name, name_len)) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_NAMED));
  (void)(((ti).name_len = name_len));
  int32_t i = 0;
  while (i < 64) {
    (void)(({ uint8_t __tmp = 0; if (i < name_len) {   (void)(((i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), 0) : (((ti).name)[i] = (name)[i], 0))));
 } else {   (void)(((i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), 0) : (((ti).name)[i] = 0, 0))));
 } ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_ensure_i32_type_ref(struct ast_ASTArena * arena) {
  int32_t k = 1;
  while (k <= (arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_I32) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_I32));
  (void)(((ti).name_len = 0));
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_ensure_bool_type_ref(struct ast_ASTArena * arena) {
  int32_t k = 1;
  while (k <= (arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_BOOL) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_BOOL));
  (void)(((ti).name_len = 0));
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_ensure_f64_type_ref(struct ast_ASTArena * arena) {
  int32_t k = 1;
  while (k <= (arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_F64) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_F64));
  (void)(((ti).name_len = 0));
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_ensure_usize_type_ref(struct ast_ASTArena * arena) {
  int32_t k = 1;
  while (k <= (arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_USIZE) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_USIZE));
  (void)(((ti).name_len = 0));
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_get_dep_return_type_in_caller_arena(int32_t from_dep_index, int32_t dep_return_type_ref, struct ast_ASTArena * caller_arena, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if (from_dep_index < 0 || from_dep_index >= 32) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_ASTArena * dep_arena = (from_dep_index < 0 || (from_dep_index) >= 32 ? (shulang_panic_(1, 0), ((ctx)->dep_arenas)[0]) : ((ctx)->dep_arenas)[from_dep_index]);
  return typeck_dep_return_type_to_caller_arena(dep_arena, dep_return_type_ref, caller_arena);
}
int32_t typeck_ensure_i64_type_ref(struct ast_ASTArena * caller_arena) {
  int32_t k = 1;
  while (k <= (caller_arena)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(caller_arena, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_I64) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t new_ref = ast_ast_arena_type_alloc(caller_arena);
  (void)(({ int32_t __tmp = 0; if (new_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ti = ast_ast_arena_type_get(caller_arena, new_ref);
  (void)(((ti).kind = ast_TypeKind_TYPE_I64));
  (void)(((ti).name_len = 0));
  (void)(((ti).elem_type_ref = 0));
  (void)(((ti).array_size = 0));
  (void)(ast_ast_arena_type_set(caller_arena, new_ref, ti));
  return new_ref;
}
int32_t typeck_find_or_alloc_array_type_ref(struct ast_ASTArena * a, int32_t elem_ref, int32_t array_size) {
  (void)(({ int32_t __tmp = 0; if (elem_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t k = 1;
  while (k <= (a)->num_types) {
    struct ast_Type tk = ast_ast_arena_type_get(a, k);
    (void)(({ int32_t __tmp = 0; if ((tk).kind == ast_TypeKind_TYPE_ARRAY && (tk).elem_type_ref == elem_ref && (tk).array_size == array_size) {   return k;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
  int32_t arr_ref = ast_ast_arena_type_alloc(a);
  (void)(({ int32_t __tmp = 0; if (arr_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ta = ast_ast_arena_type_get(a, arr_ref);
  (void)(((ta).kind = ast_TypeKind_TYPE_ARRAY));
  (void)(((ta).elem_type_ref = elem_ref));
  (void)(((ta).array_size = array_size));
  (void)(((ta).name_len = 0));
  (void)(ast_ast_arena_type_set(a, arr_ref, ta));
  return arr_ref;
}
int32_t typeck_ensure_array_type_ref_named_elem(struct ast_ASTArena * a, uint8_t * elem_nm, int32_t elem_nm_len, int32_t array_size) {
  int32_t elem_ref = typeck_find_or_alloc_named_type_ref(a, elem_nm, elem_nm_len);
  (void)(({ int32_t __tmp = 0; if (elem_ref == 0) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_find_or_alloc_array_type_ref(a, elem_ref, array_size);
}
int32_t typeck_dep_return_type_to_caller_arena(struct ast_ASTArena * dep_arena, int32_t dep_return_type_ref, struct ast_ASTArena * caller_arena) {
  struct ast_Type tt = ast_ast_arena_type_get(dep_arena, dep_return_type_ref);
  (void)(({ int32_t __tmp = 0; if ((tt).kind == ast_TypeKind_TYPE_I32) {   return typeck_ensure_i32_type_ref(caller_arena);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((tt).kind == ast_TypeKind_TYPE_I64) {   return typeck_ensure_i64_type_ref(caller_arena);
 } else (__tmp = 0) ; __tmp; }));
  return 0;
}
int32_t typeck_find_func_return_type_in_module(struct ast_Module * mod, struct ast_ASTArena * mod_arena, struct ast_ASTArena * caller_arena, struct ast_ASTArena * callee_arena, int32_t callee_expr_ref, int32_t from_dep_index, struct ast_PipelineDepCtx * ctx) {
  int32_t j = 0;
  while (j < (mod)->num_funcs) {
    (void)(({ int32_t __tmp = 0; if (j >= 256) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_Func f = (j < 0 || (j) >= 256 ? (shulang_panic_(1, 0), ((mod)->funcs)[0]) : ((mod)->funcs)[j]);
    (void)(({ int32_t __tmp = 0; if (typeck_expr_var_name_equal_func(callee_arena, callee_expr_ref, mod, j)) {   (void)(({ int32_t __tmp = 0; if (from_dep_index < 0) {   return (f).return_type_ref;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_get_dep_return_type_in_caller_arena(from_dep_index, (f).return_type_ref, caller_arena, ctx);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  return 0;
}
int32_t typeck_find_func_return_type_in_module_by_name(struct ast_Module * mod, struct ast_ASTArena * caller_arena, uint8_t * name, int32_t name_len, int32_t from_dep_index, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if (name_len <= 0 || name_len > 63) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  int32_t j = 0;
  while (j < (mod)->num_funcs && j < 256) {
    struct ast_Func f = (j < 0 || (j) >= 256 ? (shulang_panic_(1, 0), ((mod)->funcs)[0]) : ((mod)->funcs)[j]);
    (void)(({ int32_t __tmp = 0; if ((f).name_len == name_len && typeck_name_equal((f).name, (f).name_len, name, name_len)) {   (void)(({ int32_t __tmp = 0; if (from_dep_index < 0) {   return (f).return_type_ref;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_get_dep_return_type_in_caller_arena(from_dep_index, (f).return_type_ref, caller_arena, ctx);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  return 0;
}
int32_t typeck_resolve_call_callee_return_type(struct ast_Module * module, struct ast_ASTArena * arena, int32_t callee_expr_ref, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if (callee_expr_ref <= 0 || callee_expr_ref > (arena)->num_exprs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Expr callee = ast_ast_arena_expr_get(arena, callee_expr_ref);
  (void)(({ int32_t __tmp = 0; if ((callee).kind == ast_ExprKind_EXPR_FIELD_ACCESS && (callee).field_access_base_ref > 0 && (callee).field_access_base_ref <= (arena)->num_exprs) {   struct ast_Expr base = ast_ast_arena_expr_get(arena, (callee).field_access_base_ref);
  __tmp = ({ int32_t __tmp = 0; if ((base).kind == ast_ExprKind_EXPR_VAR && (base).var_name_len > 0 && (base).var_name_len <= 63) {   int32_t ii = 0;
  while (ii < (module)->num_imports && ii < (ctx)->ndep && ii < 32) {
    (void)(({ int32_t __tmp = 0; if ((ii < 0 || (ii) >= 32 ? (shulang_panic_(1, 0), ((module)->import_kinds)[0]) : ((module)->import_kinds)[ii]) == 1 && (ii < 0 || (ii) >= 32 ? (shulang_panic_(1, 0), ((module)->import_binding_name_len)[0]) : ((module)->import_binding_name_len)[ii]) == (base).var_name_len && typeck_name_equal((&(((ii < 0 || (ii) >= 32 ? (shulang_panic_(1, 0), ((module)->import_binding_name)[0]) : ((module)->import_binding_name)[ii]))[0])), (ii < 0 || (ii) >= 32 ? (shulang_panic_(1, 0), ((module)->import_binding_name_len)[0]) : ((module)->import_binding_name_len)[ii]), (base).var_name, (base).var_name_len)) {   struct ast_Module * dm = (ii < 0 || (ii) >= 32 ? (shulang_panic_(1, 0), ((ctx)->dep_modules)[0]) : ((ctx)->dep_modules)[ii]);
  (void)(({ int32_t __tmp = 0; if (dm != ((struct ast_Module *)(0))) {   int32_t ret = typeck_find_func_return_type_in_module_by_name(dm, arena, (callee).field_access_field_name, (callee).field_access_field_len, ii, ctx);
  __tmp = ({ int32_t __tmp = 0; if (ret != 0) {   return ret;
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  break;
 } else (__tmp = 0) ; __tmp; }));
    (void)((ii = ii + 1));
  }
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  int32_t minus_one = -1;
  int32_t ret = typeck_find_func_return_type_in_module(module, arena, arena, arena, callee_expr_ref, minus_one, ctx);
  (void)(({ int32_t __tmp = 0; if (ret != 0) {   return ret;
 } else (__tmp = 0) ; __tmp; }));
  int32_t i = 0;
  while (i < (ctx)->ndep) {
    (void)(({ int32_t __tmp = 0; if (i >= 32) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_Module * dm = (i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((ctx)->dep_modules)[0]) : ((ctx)->dep_modules)[i]);
    (void)((ret = typeck_find_func_return_type_in_module(dm, arena, arena, arena, callee_expr_ref, i, ctx)));
    (void)(({ int32_t __tmp = 0; if (ret != 0) {   return ret;
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (i < (module)->num_imports && (i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_kinds)[0]) : ((module)->import_kinds)[i]) == 2 && (callee).kind == ast_ExprKind_EXPR_VAR && (callee).var_name_len > 0) {   int32_t k = 0;
  while (k < (i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_count)[0]) : ((module)->import_select_count)[i]) && k < 8) {
    (void)(({ int32_t __tmp = 0; if ((k < 0 || (k) >= 8 ? (shulang_panic_(1, 0), ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_name_lens)[0]) : ((module)->import_select_name_lens)[i]))[0]) : ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_name_lens)[0]) : ((module)->import_select_name_lens)[i]))[k]) == (callee).var_name_len && typeck_name_equal((&(((k < 0 || (k) >= 8 ? (shulang_panic_(1, 0), ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_names)[0]) : ((module)->import_select_names)[i]))[0]) : ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_names)[0]) : ((module)->import_select_names)[i]))[k]))[0])), (k < 0 || (k) >= 8 ? (shulang_panic_(1, 0), ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_name_lens)[0]) : ((module)->import_select_name_lens)[i]))[0]) : ((i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((module)->import_select_name_lens)[0]) : ((module)->import_select_name_lens)[i]))[k]), (callee).var_name, (callee).var_name_len)) {   (void)(({ int32_t __tmp = 0; if (dm != ((struct ast_Module *)(0))) {   (void)((ret = typeck_find_func_return_type_in_module_by_name(dm, arena, (callee).var_name, (callee).var_name_len, i, ctx)));
  __tmp = ({ int32_t __tmp = 0; if (ret != 0) {   return ret;
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  break;
 } else (__tmp = 0) ; __tmp; }));
    (void)((k = k + 1));
  }
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  return 0;
}
int32_t typeck_expr_type_ref_impl(struct ast_ASTArena * arena, int32_t expr_ref) {
  struct ast_Expr e = ast_ast_arena_expr_get(arena, expr_ref);
  return (e).resolved_type_ref;
}
int32_t typeck_expr_type_ref(struct ast_ASTArena * arena, int32_t expr_ref) {
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null(expr_ref)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (expr_ref <= 0 || expr_ref > (arena)->num_exprs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_expr_type_ref_impl(arena, expr_ref);
}
int typeck_type_ref_is_bool_impl(struct ast_ASTArena * arena, int32_t type_ref) {
  struct ast_Type t = ast_ast_arena_type_get(arena, type_ref);
  return (t).kind == ast_TypeKind_TYPE_BOOL;
}
int typeck_type_ref_is_bool(struct ast_ASTArena * arena, int32_t type_ref) {
  (void)(({ int __tmp = 0; if (ast_ref_is_null(type_ref)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if (type_ref <= 0 || type_ref > (arena)->num_types) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_type_ref_is_bool_impl(arena, type_ref);
}
int typeck_type_refs_equal_impl(struct ast_ASTArena * arena, int32_t a, int32_t b) {
  struct ast_Type ta = ast_ast_arena_type_get(arena, a);
  struct ast_Type tb = ast_ast_arena_type_get(arena, b);
  (void)(({ int __tmp = 0; if ((ta).kind != (tb).kind) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((ta).kind == ast_TypeKind_TYPE_NAMED && (ta).name_len == (tb).name_len) {   int32_t i = 0;
  while (i < (ta).name_len) {
    (void)(({ int __tmp = 0; if ((i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), ((ta).name)[0]) : ((ta).name)[i]) != (i < 0 || (i) >= 64 ? (shulang_panic_(1, 0), ((tb).name)[0]) : ((tb).name)[i])) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  return 1;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((ta).kind == ast_TypeKind_TYPE_PTR || (ta).kind == ast_TypeKind_TYPE_SLICE) {   return typeck_type_refs_equal(arena, (ta).elem_type_ref, (tb).elem_type_ref);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((ta).kind == ast_TypeKind_TYPE_ARRAY) {   return (ta).array_size == (tb).array_size && typeck_type_refs_equal(arena, (ta).elem_type_ref, (tb).elem_type_ref);
 } else (__tmp = 0) ; __tmp; }));
  return 1;
}
int typeck_type_refs_equal(struct ast_ASTArena * arena, int32_t a, int32_t b) {
  (void)(({ int __tmp = 0; if (ast_ref_is_null(a) || ast_ref_is_null(b)) {   return a == b;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if (a == b) {   return 1;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_type_refs_equal_impl(arena, a, b);
}
int32_t typeck_check_expr_impl(struct ast_Module * module, struct ast_ASTArena * arena, int32_t expr_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx) {
  struct ast_Expr e = ast_ast_arena_expr_get(arena, expr_ref);
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_FLOAT_LIT) {   (void)(((e).float_bits_lo = typeck_float64_bits_lo((e).float_val)));
  (void)(((e).float_bits_hi = typeck_float64_bits_hi((e).float_val)));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
  int32_t ft = typeck_ensure_f64_type_ref(arena);
  (void)(({ int32_t __tmp = 0; if (ft != 0) {   (void)(((e).resolved_type_ref = ft));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_LIT) {   int32_t it = typeck_ensure_i32_type_ref(arena);
  (void)(({ int32_t __tmp = 0; if (it != 0) {   (void)(((e).resolved_type_ref = it));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_BOOL_LIT) {   int32_t bt = typeck_ensure_bool_type_ref(arena);
  (void)(({ int32_t __tmp = 0; if (bt != 0) {   (void)(((e).resolved_type_ref = bt));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_IF || (e).kind == ast_ExprKind_EXPR_TERNARY) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).if_cond_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).if_cond_ref))) {   __tmp = ({ int32_t __tmp = 0; if ((!typeck_type_ref_is_bool(arena, typeck_expr_type_ref(arena, (e).if_cond_ref)))) {   return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).if_then_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).if_else_ref)) && typeck_check_expr(module, arena, (e).if_else_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  int32_t ty_t = typeck_expr_type_ref(arena, (e).if_then_ref);
  int32_t ty_e = typeck_expr_type_ref(arena, (e).if_else_ref);
  int t_named = 0;
  int e_named = 0;
  (void)(({ int __tmp = 0; if ((!ast_ref_is_null(ty_t)) && ty_t > 0 && ty_t <= (arena)->num_types) {   struct ast_Type tt = ast_ast_arena_type_get(arena, ty_t);
  (void)((t_named = (tt).kind == ast_TypeKind_TYPE_NAMED));
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((!ast_ref_is_null(ty_e)) && ty_e > 0 && ty_e <= (arena)->num_types) {   struct ast_Type te = ast_ast_arena_type_get(arena, ty_e);
  (void)((e_named = (te).kind == ast_TypeKind_TYPE_NAMED));
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(ty_t)) && (!ast_ref_is_null(ty_e)) && t_named && e_named && (!typeck_type_refs_equal(arena, ty_t, ty_e))) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(ty_t)) && (!ast_ref_is_null(ty_e))) {   (void)(((e).resolved_type_ref = (e_named && (!t_named) ? ty_e : ty_t)));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(ty_t))) {   (void)(((e).resolved_type_ref = ty_t));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(ty_e))) {   (void)(((e).resolved_type_ref = ty_e));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; })) ; __tmp; })) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_BLOCK) {   (void)(({ int32_t __tmp = 0; if (typeck_check_block(module, arena, (e).block_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).block_ref > 0 && (e).block_ref <= (arena)->num_blocks) {   struct ast_Block b = ast_ast_arena_block_get(arena, (e).block_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null((b).final_expr_ref))) {   (void)(((e).resolved_type_ref = typeck_expr_type_ref(arena, (b).final_expr_ref)));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = ({ int32_t __tmp = 0; if ((b).num_expr_stmts == 1 && ((b).expr_stmt_refs)[0] > 0 && ((b).expr_stmt_refs)[0] <= (arena)->num_exprs) {   struct ast_Expr st = ast_ast_arena_expr_get(arena, ((b).expr_stmt_refs)[0]);
  __tmp = ({ int32_t __tmp = 0; if ((st).kind == ast_ExprKind_EXPR_ASSIGN || (st).kind == ast_ExprKind_EXPR_ADD_ASSIGN || (st).kind == ast_ExprKind_EXPR_SUB_ASSIGN || (st).kind == ast_ExprKind_EXPR_MUL_ASSIGN || (st).kind == ast_ExprKind_EXPR_DIV_ASSIGN || (st).kind == ast_ExprKind_EXPR_MOD_ASSIGN || (st).kind == ast_ExprKind_EXPR_BITAND_ASSIGN || (st).kind == ast_ExprKind_EXPR_BITOR_ASSIGN || (st).kind == ast_ExprKind_EXPR_BITXOR_ASSIGN || (st).kind == ast_ExprKind_EXPR_SHL_ASSIGN || (st).kind == ast_ExprKind_EXPR_SHR_ASSIGN && (!ast_ref_is_null((st).binop_right_ref))) {   (void)(((e).resolved_type_ref = typeck_expr_type_ref(arena, (st).binop_right_ref)));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; })) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_ASSIGN || (e).kind == ast_ExprKind_EXPR_ADD_ASSIGN || (e).kind == ast_ExprKind_EXPR_SUB_ASSIGN || (e).kind == ast_ExprKind_EXPR_MUL_ASSIGN || (e).kind == ast_ExprKind_EXPR_DIV_ASSIGN || (e).kind == ast_ExprKind_EXPR_MOD_ASSIGN || (e).kind == ast_ExprKind_EXPR_BITAND_ASSIGN || (e).kind == ast_ExprKind_EXPR_BITOR_ASSIGN || (e).kind == ast_ExprKind_EXPR_BITXOR_ASSIGN || (e).kind == ast_ExprKind_EXPR_SHL_ASSIGN || (e).kind == ast_ExprKind_EXPR_SHR_ASSIGN) {   int32_t left_ref = (e).binop_left_ref;
  int32_t right_ref = (e).binop_right_ref;
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, left_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, right_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(left_ref)) && (!ast_ref_is_null(right_ref))) {   int32_t lt = typeck_expr_type_ref(arena, left_ref);
  int32_t rt_after = typeck_expr_type_ref(arena, right_ref);
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(lt)) && lt > 0 && lt <= (arena)->num_types) {   struct ast_Expr rhs_coerce = ast_ast_arena_expr_get(arena, right_ref);
  __tmp = ({ int32_t __tmp = 0; if ((rhs_coerce).kind == ast_ExprKind_EXPR_LIT && (!typeck_type_refs_equal(arena, lt, rt_after))) {   struct ast_Type ltp = ast_ast_arena_type_get(arena, lt);
  __tmp = ({ int32_t __tmp = 0; if ((ltp).kind == ast_TypeKind_TYPE_U8 && (rhs_coerce).int_val >= 0 && (rhs_coerce).int_val <= 255) {   (void)(((rhs_coerce).resolved_type_ref = lt));
  (void)(ast_ast_arena_expr_set(arena, right_ref, rhs_coerce));
 } else (__tmp = ({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_ASSIGN && (ltp).kind == ast_TypeKind_TYPE_PTR && (rhs_coerce).int_val == 0) {   (void)(((rhs_coerce).resolved_type_ref = lt));
  (void)(ast_ast_arena_expr_set(arena, right_ref, rhs_coerce));
 } else (__tmp = 0) ; __tmp; })) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  int32_t rt = typeck_expr_type_ref(arena, right_ref);
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(lt)) && (!ast_ref_is_null(rt)) && (!typeck_type_refs_equal(arena, lt, rt))) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if (ast_ref_is_null(lt) && (!ast_ref_is_null(rt)) || (!ast_ref_is_null(lt)) && ast_ref_is_null(rt)) {   return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_RETURN) {   int32_t op_ref = (e).unary_operand_ref;
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, op_ref, return_type_ref, ctx) != 0) {   (void)(driver_diagnostic_typeck_ret_fail(1, op_ref, return_type_ref, 0));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null(return_type_ref)) && (!ast_ref_is_null(op_ref))) {   int32_t got = typeck_expr_type_ref(arena, op_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(got)) && (!typeck_type_refs_equal(arena, got, return_type_ref))) {   (void)(driver_diagnostic_typeck_ret_fail(2, op_ref, return_type_ref, got));
  return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_PANIC) {   return typeck_check_expr(module, arena, (e).unary_operand_ref, return_type_ref, ctx);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_MATCH) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).match_matched_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  int32_t i = 0;
  while (i < (e).match_num_arms) {
    (void)(({ int32_t __tmp = 0; if (i >= 16) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (i < 0 || (i) >= 16 ? (shulang_panic_(1, 0), ((e).match_arm_result_refs)[0]) : ((e).match_arm_result_refs)[i]), return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_FIELD_ACCESS) {   (void)(({ int32_t __tmp = 0; if (ast_ref_is_null((e).field_access_base_ref) || (e).field_access_base_ref <= 0 || (e).field_access_base_ref > (arena)->num_exprs) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).field_access_base_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Expr base = ast_ast_arena_expr_get(arena, (e).field_access_base_ref);
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((base).resolved_type_ref)) && (base).resolved_type_ref > 0 && (base).resolved_type_ref <= (arena)->num_types) {   struct ast_Type bt = ast_ast_arena_type_get(arena, (base).resolved_type_ref);
  (void)(({ int32_t __tmp = 0; if ((bt).kind == ast_TypeKind_TYPE_PTR && (!ast_ref_is_null((bt).elem_type_ref))) {   struct ast_Type inner = ast_ast_arena_type_get(arena, (bt).elem_type_ref);
  (void)(driver_diagnostic_typeck_ptr_field(typeck_type_kind_ordinal((bt).kind), typeck_type_kind_ordinal((inner).kind), (inner).name_len, (base).resolved_type_ref,
      (module)->num_struct_layouts));
  uint8_t nm_astarena[8] = { 65, 83, 84, 65, 114, 101, 110, 97 };
  __tmp = ({ int32_t __tmp = 0; if ((inner).kind == ast_TypeKind_TYPE_NAMED && (inner).name_len == 8 && typeck_name_equal((inner).name, (inner).name_len, (&((nm_astarena)[0])), 8)) {   int32_t fl = (e).field_access_field_len;
  uint8_t * fn = (&(((e).field_access_field_name)[0]));
  uint8_t nm_types[5] = { 116, 121, 112, 101, 115 };
  uint8_t nm_num_types[9] = { 110, 117, 109, 95, 116, 121, 112, 101, 115 };
  uint8_t nm_exprs[5] = { 101, 120, 112, 114, 115 };
  uint8_t nm_num_exprs[9] = { 110, 117, 109, 95, 101, 120, 112, 114, 115 };
  uint8_t nm_blocks[6] = { 98, 108, 111, 99, 107, 115 };
  uint8_t nm_num_blocks[10] = { 110, 117, 109, 95, 98, 108, 111, 99, 107, 115 };
  uint8_t nm_funcs[5] = { 102, 117, 110, 99, 115 };
  uint8_t nm_num_funcs[9] = { 110, 117, 109, 95, 102, 117, 110, 99, 115 };
  uint8_t nm_ty[4] = { 84, 121, 112, 101 };
  uint8_t nm_ex[4] = { 69, 120, 112, 114 };
  uint8_t nm_bl[5] = { 66, 108, 111, 99, 107 };
  uint8_t nm_fu[4] = { 70, 117, 110, 99 };
  int32_t i32r_at = typeck_ensure_i32_type_ref(arena);
  int matched_at = 0;
  (void)(({ int32_t __tmp = 0; if (fl == 5 && typeck_name_equal(fn, fl, (&((nm_types)[0])), 5)) {   (void)(((e).field_access_offset = 0));
  int32_t arr_types = typeck_ensure_array_type_ref_named_elem(arena, (&((nm_ty)[0])), 4, 512);
  __tmp = ({ int32_t __tmp = 0; if (arr_types != 0) {   (void)(((e).resolved_type_ref = arr_types));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 9 && typeck_name_equal(fn, fl, (&((nm_num_types)[0])), 9)) {   (void)(((e).field_access_offset = 40960));
  __tmp = ({ int32_t __tmp = 0; if (i32r_at != 0) {   (void)(((e).resolved_type_ref = i32r_at));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 5 && typeck_name_equal(fn, fl, (&((nm_exprs)[0])), 5)) {   (void)(((e).field_access_offset = 40968));
  int32_t arr_exprs = typeck_ensure_array_type_ref_named_elem(arena, (&((nm_ex)[0])), 4, 4096);
  __tmp = ({ int32_t __tmp = 0; if (arr_exprs != 0) {   (void)(((e).resolved_type_ref = arr_exprs));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 9 && typeck_name_equal(fn, fl, (&((nm_num_exprs)[0])), 9)) {   (void)(((e).field_access_offset = 6234120));
  __tmp = ({ int32_t __tmp = 0; if (i32r_at != 0) {   (void)(((e).resolved_type_ref = i32r_at));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 6 && typeck_name_equal(fn, fl, (&((nm_blocks)[0])), 6)) {   (void)(((e).field_access_offset = 6234124));
  int32_t arr_blocks = typeck_ensure_array_type_ref_named_elem(arena, (&((nm_bl)[0])), 5, 512);
  __tmp = ({ int32_t __tmp = 0; if (arr_blocks != 0) {   (void)(((e).resolved_type_ref = arr_blocks));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 10 && typeck_name_equal(fn, fl, (&((nm_num_blocks)[0])), 10)) {   (void)(((e).field_access_offset = 17184780));
  __tmp = ({ int32_t __tmp = 0; if (i32r_at != 0) {   (void)(((e).resolved_type_ref = i32r_at));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 5 && typeck_name_equal(fn, fl, (&((nm_funcs)[0])), 5)) {   (void)(((e).field_access_offset = 17184784));
  int32_t arr_funcs = typeck_ensure_array_type_ref_named_elem(arena, (&((nm_fu)[0])), 4, 256);
  __tmp = ({ int32_t __tmp = 0; if (arr_funcs != 0) {   (void)(((e).resolved_type_ref = arr_funcs));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!matched_at) && fl == 9 && typeck_name_equal(fn, fl, (&((nm_num_funcs)[0])), 9)) {   (void)(((e).field_access_offset = 17371152));
  __tmp = ({ int32_t __tmp = 0; if (i32r_at != 0) {   (void)(((e).resolved_type_ref = i32r_at));
  (void)((matched_at = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if (matched_at) {   (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if ((bt).kind == ast_TypeKind_TYPE_NAMED && (bt).name_len > 0) {   int32_t off = typeck_get_field_offset_from_layout(module, (bt).name, (bt).name_len, (e).field_access_field_name, (e).field_access_field_len);
  (void)(({ int32_t __tmp = 0; if (off >= 0) {   (void)(((e).field_access_offset = off));
 } else (__tmp = 0) ; __tmp; }));
  int32_t ftr = typeck_get_field_type_ref_from_layout(module, (bt).name, (bt).name_len, (e).field_access_field_name, (e).field_access_field_len);
  (void)(({ int32_t __tmp = 0; if (ftr != 0) {   (void)(((e).resolved_type_ref = ftr));
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (off >= 0 || ftr != 0) {   (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  uint8_t nm_tok_kind_ty[9] = { 84, 111, 107, 101, 110, 75, 105, 110, 100 };
  uint8_t nm_eof_variant[9] = { 84, 79, 75, 69, 78, 95, 69, 79, 70 };
  __tmp = ({ int32_t __tmp = 0; if (off < 0 && ftr == 0 && (bt).name_len == 9 && typeck_name_equal((bt).name, (bt).name_len, nm_tok_kind_ty, 9) && (e).field_access_field_len == 9 && typeck_name_equal((e).field_access_field_name, (e).field_access_field_len, nm_eof_variant, 9)) {   (void)(((e).field_access_is_enum_variant = 1));
  (void)(((e).enum_variant_tag = 0));
  int32_t i32r = typeck_ensure_i32_type_ref(arena);
  __tmp = ({ int32_t __tmp = 0; if (i32r != 0) {   (void)(((e).resolved_type_ref = i32r));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = ({ int32_t __tmp = 0; if ((bt).kind == ast_TypeKind_TYPE_SLICE && (!ast_ref_is_null((bt).elem_type_ref))) {   int32_t nm_len = (e).field_access_field_len;
  uint8_t len_nm[6] = { 108, 101, 110, 103, 116, 104 };
  uint8_t dat_nm[4] = { 100, 97, 116, 97 };
  __tmp = ({ int32_t __tmp = 0; if (nm_len == 6 && typeck_name_equal((e).field_access_field_name, nm_len, len_nm, 6)) {   int32_t ut = typeck_ensure_usize_type_ref(arena);
  __tmp = ({ int32_t __tmp = 0; if (ut != 0) {   (void)(((e).resolved_type_ref = ut));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = ({ int32_t __tmp = 0; if (nm_len == 4 && typeck_name_equal((e).field_access_field_name, nm_len, dat_nm, 4)) {   struct ast_Type et = ast_ast_arena_type_get(arena, (bt).elem_type_ref);
  __tmp = ({ int32_t __tmp = 0; if ((et).kind == ast_TypeKind_TYPE_U8) {   int32_t ptr_ref = ast_ast_arena_type_alloc(arena);
  __tmp = ({ int32_t __tmp = 0; if (ptr_ref != 0) {   struct ast_Type pt = ast_ast_arena_type_get(arena, ptr_ref);
  (void)(((pt).kind = ast_TypeKind_TYPE_PTR));
  (void)(((pt).elem_type_ref = (bt).elem_type_ref));
  (void)(((pt).name_len = 0));
  (void)(((pt).array_size = 0));
  (void)(ast_ast_arena_type_set(arena, ptr_ref, pt));
  (void)(((e).resolved_type_ref = ptr_ref));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; })) ; __tmp; });
 } else (__tmp = 0) ; __tmp; })) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_INDEX) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).index_base_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).index_index_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null((e).index_base_ref) || (e).index_base_ref <= 0 || (e).index_base_ref > (arena)->num_exprs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Expr eb = ast_ast_arena_expr_get(arena, (e).index_base_ref);
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((eb).resolved_type_ref)) && (eb).resolved_type_ref > 0 && (eb).resolved_type_ref <= (arena)->num_types) {   struct ast_Type bt = ast_ast_arena_type_get(arena, (eb).resolved_type_ref);
  __tmp = ({ int32_t __tmp = 0; if ((bt).kind == ast_TypeKind_TYPE_ARRAY || (bt).kind == ast_TypeKind_TYPE_SLICE || (bt).kind == ast_TypeKind_TYPE_PTR && (!ast_ref_is_null((bt).elem_type_ref))) {   (void)(((e).resolved_type_ref = (bt).elem_type_ref));
  (void)(({ int32_t __tmp = 0; if ((bt).kind == ast_TypeKind_TYPE_SLICE) {   (void)(((e).index_base_is_slice = 1));
 } else {   (void)(((e).index_base_is_slice = 0));
 } ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).index_index_ref)) && (e).index_index_ref > 0 && (e).index_index_ref <= (arena)->num_exprs) {   struct ast_Expr idxe = ast_ast_arena_expr_get(arena, (e).index_index_ref);
  __tmp = ({ int32_t __tmp = 0; if ((idxe).kind == ast_ExprKind_EXPR_LIT && (idxe).int_val == 0 && (bt).kind == ast_TypeKind_TYPE_ARRAY && (bt).array_size >= 1) {   (void)(((e).index_proven_in_bounds = 1));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_CALL) {   int32_t j = 0;
  while (j < (e).call_num_args) {
    (void)(({ int32_t __tmp = 0; if (j >= 16) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (j < 0 || (j) >= 16 ? (shulang_panic_(1, 0), ((e).call_arg_refs)[0]) : ((e).call_arg_refs)[j]), return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).call_callee_ref))) {   struct ast_Expr callee = ast_ast_arena_expr_get(arena, (e).call_callee_ref);
  __tmp = ({ int32_t __tmp = 0; if ((callee).kind == ast_ExprKind_EXPR_VAR && (callee).var_name_len > 0 && (callee).var_name_len <= 63) {   int32_t ret_ty = typeck_resolve_call_callee_return_type(module, arena, (e).call_callee_ref, ctx);
  __tmp = ({ int32_t __tmp = 0; if (ret_ty != 0) {   (void)(((e).resolved_type_ref = ret_ty));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_METHOD_CALL) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).method_call_base_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  int32_t j = 0;
  while (j < (e).method_call_num_args) {
    (void)(({ int32_t __tmp = 0; if (j >= 16) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (j < 0 || (j) >= 16 ? (shulang_panic_(1, 0), ((e).method_call_arg_refs)[0]) : ((e).method_call_arg_refs)[j]), return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((j = j + 1));
  }
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_ADD || (e).kind == ast_ExprKind_EXPR_SUB || (e).kind == ast_ExprKind_EXPR_MUL || (e).kind == ast_ExprKind_EXPR_DIV || (e).kind == ast_ExprKind_EXPR_MOD || (e).kind == ast_ExprKind_EXPR_SHL || (e).kind == ast_ExprKind_EXPR_SHR || (e).kind == ast_ExprKind_EXPR_BITAND || (e).kind == ast_ExprKind_EXPR_BITOR || (e).kind == ast_ExprKind_EXPR_BITXOR || (e).kind == ast_ExprKind_EXPR_EQ || (e).kind == ast_ExprKind_EXPR_NE || (e).kind == ast_ExprKind_EXPR_LT || (e).kind == ast_ExprKind_EXPR_LE || (e).kind == ast_ExprKind_EXPR_GT || (e).kind == ast_ExprKind_EXPR_GE || (e).kind == ast_ExprKind_EXPR_LOGAND || (e).kind == ast_ExprKind_EXPR_LOGOR) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).binop_left_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (e).binop_right_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_EQ || (e).kind == ast_ExprKind_EXPR_NE || (e).kind == ast_ExprKind_EXPR_LT || (e).kind == ast_ExprKind_EXPR_LE || (e).kind == ast_ExprKind_EXPR_GT || (e).kind == ast_ExprKind_EXPR_GE || (e).kind == ast_ExprKind_EXPR_LOGAND || (e).kind == ast_ExprKind_EXPR_LOGOR) {   int32_t bt = typeck_ensure_bool_type_ref(arena);
  __tmp = ({ int32_t __tmp = 0; if (bt != 0) {   (void)(((e).resolved_type_ref = bt));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else {   int32_t lt_ar = typeck_expr_type_ref(arena, (e).binop_left_ref);
  int32_t rt_ar = typeck_expr_type_ref(arena, (e).binop_right_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(lt_ar)) && lt_ar > 0 && lt_ar <= (arena)->num_types && (!ast_ref_is_null(rt_ar)) && rt_ar > 0 && rt_ar <= (arena)->num_types) {   struct ast_Type lar = ast_ast_arena_type_get(arena, lt_ar);
  struct ast_Type rar = ast_ast_arena_type_get(arena, rt_ar);
  int32_t out_ar = 0;
  (void)(({ int32_t __tmp = 0; if ((lar).kind == ast_TypeKind_TYPE_I64 || (rar).kind == ast_TypeKind_TYPE_I64) {   (void)((out_ar = typeck_ensure_i64_type_ref(arena)));
 } else (__tmp = ({ int32_t __tmp = 0; if ((lar).kind == ast_TypeKind_TYPE_F64 || (rar).kind == ast_TypeKind_TYPE_F64) {   (void)((out_ar = typeck_ensure_f64_type_ref(arena)));
 } else (__tmp = ({ int32_t __tmp = 0; if (typeck_type_refs_equal(arena, lt_ar, rt_ar)) {   (void)((out_ar = lt_ar));
 } else (__tmp = 0) ; __tmp; })) ; __tmp; })) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if (out_ar != 0) {   (void)(((e).resolved_type_ref = out_ar));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_NEG || (e).kind == ast_ExprKind_EXPR_BITNOT || (e).kind == ast_ExprKind_EXPR_LOGNOT) {   return typeck_check_expr(module, arena, (e).unary_operand_ref, return_type_ref, ctx);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_VAR && (ctx)->current_block_ref != 0 && (ctx)->current_block_ref <= (arena)->num_blocks) {   struct ast_Block b = ast_ast_arena_block_get(arena, (ctx)->current_block_ref);
  int32_t i = 0;
  while (i < (b).num_consts && i < 64) {
    struct ast_ConstDecl cd = (i < 0 || (i) >= 128 ? (shulang_panic_(1, 0), ((b).const_decls)[0]) : ((b).const_decls)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((cd).type_ref)) && typeck_name_equal((cd).name, (cd).name_len, (e).var_name, (e).var_name_len)) {   (void)(((e).resolved_type_ref = (cd).type_ref));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)((i = 0));
  while (i < (b).num_lets && i < 64) {
    struct ast_LetDecl ld = (i < 0 || (i) >= 128 ? (shulang_panic_(1, 0), ((b).let_decls)[0]) : ((b).let_decls)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((ld).type_ref)) && typeck_name_equal((ld).name, (ld).name_len, (e).var_name, (e).var_name_len)) {   (void)(((e).resolved_type_ref = (ld).type_ref));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_VAR && (ctx)->current_func_index >= 0 && (ctx)->current_func_index < (module)->num_funcs) {   struct ast_Func f = ((ctx)->current_func_index < 0 || ((ctx)->current_func_index) >= 256 ? (shulang_panic_(1, 0), ((module)->funcs)[0]) : ((module)->funcs)[(ctx)->current_func_index]);
  int32_t pi = 0;
  while (pi < (f).num_params && pi < 16) {
    struct ast_Param p = (pi < 0 || (pi) >= 16 ? (shulang_panic_(1, 0), ((f).params)[0]) : ((f).params)[pi]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((p).type_ref)) && typeck_name_equal((p).name, (p).name_len, (e).var_name, (e).var_name_len)) {   (void)(((e).resolved_type_ref = (p).type_ref));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
    (void)((pi = pi + 1));
  }
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_VAR) {   uint8_t nm_tok_kind_sym[9] = { 84, 111, 107, 101, 110, 75, 105, 110, 100 };
  __tmp = ({ int32_t __tmp = 0; if ((e).var_name_len == 9 && typeck_name_equal((e).var_name, (e).var_name_len, nm_tok_kind_sym, 9)) {   int32_t tk_tr = typeck_find_or_alloc_named_type_ref(arena, nm_tok_kind_sym, 9);
  __tmp = ({ int32_t __tmp = 0; if (tk_tr != 0) {   (void)(((e).resolved_type_ref = tk_tr));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
  return 0;
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_VAR) {   struct ast_Expr ev = ast_ast_arena_expr_get(arena, expr_ref);
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null((ev).resolved_type_ref)) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_AS) {   (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).as_operand_ref)) && typeck_check_expr(module, arena, (e).as_operand_ref, return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((e).as_target_type_ref))) {   (void)(((e).resolved_type_ref = (e).as_target_type_ref));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((e).kind == ast_ExprKind_EXPR_STRUCT_LIT) {   int32_t fi = 0;
  while (fi < (e).struct_lit_num_fields && fi < 8) {
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((fi < 0 || (fi) >= 8 ? (shulang_panic_(1, 0), ((e).struct_lit_init_refs)[0]) : ((e).struct_lit_init_refs)[fi]))) && typeck_check_expr(module, arena, (fi < 0 || (fi) >= 8 ? (shulang_panic_(1, 0), ((e).struct_lit_init_refs)[0]) : ((e).struct_lit_init_refs)[fi]), return_type_ref, ctx) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((fi = fi + 1));
  }
  (void)(({ int32_t __tmp = 0; if (typeck_ensure_struct_layout_from_struct_lit(module, e) != 0) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  int32_t tr = typeck_find_or_alloc_named_type_ref(arena, (e).struct_lit_struct_name, (e).struct_lit_struct_name_len);
  (void)(({ int32_t __tmp = 0; if (tr != 0) {   (void)(((e).resolved_type_ref = tr));
  (void)(ast_ast_arena_expr_set(arena, expr_ref, e));
 } else (__tmp = 0) ; __tmp; }));
  return 0;
 } else (__tmp = 0) ; __tmp; }));
  return 0;
}
int32_t typeck_check_expr(struct ast_Module * module, struct ast_ASTArena * arena, int32_t expr_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null(expr_ref)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (expr_ref <= 0 || expr_ref > (arena)->num_exprs) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_check_expr_impl(module, arena, expr_ref, return_type_ref, ctx);
}
int typeck_func_body_has_implicit_return_tail(struct ast_ASTArena * arena, int32_t body_ref) {
  (void)(({ int __tmp = 0; if (ast_ref_is_null(body_ref) || body_ref <= 0 || body_ref > (arena)->num_blocks) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Block bb = ast_ast_arena_block_get(arena, body_ref);
  (void)(({ int __tmp = 0; if (ast_ref_is_null((bb).final_expr_ref)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Expr fe = ast_ast_arena_expr_get(arena, (bb).final_expr_ref);
  (void)(({ int __tmp = 0; if ((fe).kind == ast_ExprKind_EXPR_RETURN) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((fe).kind == ast_ExprKind_EXPR_PANIC) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((fe).kind == ast_ExprKind_EXPR_BREAK) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int __tmp = 0; if ((fe).kind == ast_ExprKind_EXPR_CONTINUE) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return 1;
}
int32_t typeck_check_block_impl(struct ast_Module * module, struct ast_ASTArena * arena, int32_t block_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx) {
  int32_t saved_block_ref = (ctx)->current_block_ref;
  (void)(((ctx)->current_block_ref = block_ref));
  struct ast_Block b = ast_ast_arena_block_get(arena, block_ref);
  (void)(driver_diagnostic_typeck_block_enter((ctx)->current_func_index, block_ref, (b).num_consts, (b).num_lets, (b).num_loops, (b).num_for_loops, (b).num_expr_stmts, (b).final_expr_ref));
  int32_t i = 0;
  while (i < (b).num_consts) {
    (void)(({ int32_t __tmp = 0; if (i >= 64) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_ConstDecl cd = (i < 0 || (i) >= 128 ? (shulang_panic_(1, 0), ((b).const_decls)[0]) : ((b).const_decls)[i]);
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (cd).init_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((cd).init_ref)) && (!ast_ref_is_null((cd).type_ref))) {   int32_t init_ty = typeck_expr_type_ref(arena, (cd).init_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(init_ty)) && (!typeck_type_refs_equal(arena, (cd).type_ref, init_ty))) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)((i = 0));
  while (i < (b).num_lets) {
    (void)(({ int32_t __tmp = 0; if (i >= 64) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_LetDecl ld = (i < 0 || (i) >= 128 ? (shulang_panic_(1, 0), ((b).let_decls)[0]) : ((b).let_decls)[i]);
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (ld).init_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((ld).init_ref)) && (!ast_ref_is_null((ld).type_ref))) {   int32_t init_ty = typeck_expr_type_ref(arena, (ld).init_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(init_ty)) && (!typeck_type_refs_equal(arena, (ld).type_ref, init_ty))) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)((i = 0));
  while (i < (b).num_loops) {
    (void)(({ int32_t __tmp = 0; if (i >= 8) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_WhileLoop w = (i < 0 || (i) >= 8 ? (shulang_panic_(1, 0), ((b).loops)[0]) : ((b).loops)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((w).cond_ref)) && (!typeck_type_ref_is_bool(arena, typeck_expr_type_ref(arena, (w).cond_ref)))) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (w).cond_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_block(module, arena, (w).body_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)((i = 0));
  while (i < (b).num_for_loops) {
    (void)(({ int32_t __tmp = 0; if (i >= 8) {   break;
 } else (__tmp = 0) ; __tmp; }));
    struct ast_ForLoop fl = (i < 0 || (i) >= 8 ? (shulang_panic_(1, 0), ((b).for_loops)[0]) : ((b).for_loops)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((fl).cond_ref)) && (!typeck_type_ref_is_bool(arena, typeck_expr_type_ref(arena, (fl).cond_ref)))) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (fl).init_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (fl).cond_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (fl).step_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_block(module, arena, (fl).body_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)((i = 0));
  while (i < (b).num_expr_stmts) {
    (void)(({ int32_t __tmp = 0; if (i >= 32) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (i < 0 || (i) >= 32 ? (shulang_panic_(1, 0), ((b).expr_stmt_refs)[0]) : ((b).expr_stmt_refs)[i]), return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
    (void)((i = i + 1));
  }
  (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((b).final_expr_ref))) {   (void)(({ int32_t __tmp = 0; if (typeck_check_expr(module, arena, (b).final_expr_ref, return_type_ref, ctx) != 0) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(return_type_ref))) {   int32_t got = typeck_expr_type_ref(arena, (b).final_expr_ref);
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null(got)) && (!typeck_type_refs_equal(arena, got, return_type_ref))) {   (void)(((ctx)->current_block_ref = saved_block_ref));
  return (-1);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
  (void)(((ctx)->current_block_ref = saved_block_ref));
  return 0;
}
int32_t typeck_check_block(struct ast_Module * module, struct ast_ASTArena * arena, int32_t block_ref, int32_t return_type_ref, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null(block_ref)) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (block_ref <= 0 || block_ref > (arena)->num_blocks) {   return 0;
 } else (__tmp = 0) ; __tmp; }));
  return typeck_check_block_impl(module, arena, block_ref, return_type_ref, ctx);
}
int32_t typeck_typeck_su_ast_impl(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx) {
  struct ast_Func main_f = ((module)->main_func_index < 0 || ((module)->main_func_index) >= 256 ? (shulang_panic_(1, 0), ((module)->funcs)[0]) : ((module)->funcs)[(module)->main_func_index]);
  (void)(({ int32_t __tmp = 0; if ((main_f).is_extern == 1 && ast_ref_is_null((main_f).body_ref)) {   return (-1);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null((main_f).body_ref) && ast_ref_is_null((main_f).body_expr_ref)) {   return (-2);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if (ast_ref_is_null((main_f).return_type_ref)) {   return (-3);
 } else (__tmp = 0) ; __tmp; }));
  struct ast_Type ret_ty = ast_ast_arena_type_get(arena, (main_f).return_type_ref);
  (void)(({ int32_t __tmp = 0; if ((ret_ty).kind != ast_TypeKind_TYPE_I32 && (ret_ty).kind != ast_TypeKind_TYPE_I64) {   return (-4);
 } else (__tmp = 0) ; __tmp; }));
  int32_t i = 0;
  while (i < (module)->num_funcs) {
    (void)(({ int32_t __tmp = 0; if (i >= 256) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(((ctx)->current_func_index = i));
    struct ast_Func f = (i < 0 || (i) >= 256 ? (shulang_panic_(1, 0), ((module)->funcs)[0]) : ((module)->funcs)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((f).body_ref)) && (f).is_extern == 0) {   (void)(({ int32_t __tmp = 0; if (typeck_check_block(module, arena, (f).body_ref, (f).return_type_ref, ctx) != 0) {   (void)(driver_diagnostic_typeck_func_fail(i, (&(((f).name)[0])), (f).name_len, 0 - 5));
  (void)(((ctx)->current_func_index = (-1)));
  return (-5);
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null((f).return_type_ref))) {   struct ast_Type rt = ast_ast_arena_type_get(arena, (f).return_type_ref);
  __tmp = ({ int32_t __tmp = 0; if ((rt).kind != ast_TypeKind_TYPE_VOID && typeck_func_body_has_implicit_return_tail(arena, (f).body_ref)) {   (void)(driver_diagnostic_typeck_func_fail(i, (&(((f).name)[0])), (f).name_len, 0 - 6));
  (void)(((ctx)->current_func_index = (-1)));
  return (-6);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
    (void)(((ctx)->current_func_index = (-1)));
    (void)((i = i + 1));
  }
  return 0;
}
int32_t typeck_typeck_su_ast_library(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx) {
  int32_t i = 0;
  while (i < (module)->num_funcs) {
    (void)(({ int32_t __tmp = 0; if (i >= 256) {   break;
 } else (__tmp = 0) ; __tmp; }));
    (void)(((ctx)->current_func_index = i));
    struct ast_Func f = (i < 0 || (i) >= 256 ? (shulang_panic_(1, 0), ((module)->funcs)[0]) : ((module)->funcs)[i]);
    (void)(({ int32_t __tmp = 0; if ((!ast_ref_is_null((f).body_ref)) && (f).is_extern == 0) {   (void)(({ int32_t __tmp = 0; if (typeck_check_block(module, arena, (f).body_ref, (f).return_type_ref, ctx) != 0) {   (void)(driver_diagnostic_typeck_func_fail(i, (&(((f).name)[0])), (f).name_len, 0 - 5));
  (void)(((ctx)->current_func_index = (-1)));
  return (-5);
 } else (__tmp = 0) ; __tmp; }));
  __tmp = ({ int32_t __tmp = 0; if ((!ast_ref_is_null((f).return_type_ref))) {   struct ast_Type rt2 = ast_ast_arena_type_get(arena, (f).return_type_ref);
  __tmp = ({ int32_t __tmp = 0; if ((rt2).kind != ast_TypeKind_TYPE_VOID && typeck_func_body_has_implicit_return_tail(arena, (f).body_ref)) {   (void)(driver_diagnostic_typeck_func_fail(i, (&(((f).name)[0])), (f).name_len, 0 - 6));
  (void)(((ctx)->current_func_index = (-1)));
  return (-6);
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; });
 } else (__tmp = 0) ; __tmp; }));
    (void)(((ctx)->current_func_index = (-1)));
    (void)((i = i + 1));
  }
  return 0;
}
int32_t typeck_typeck_su_ast(struct ast_Module * module, struct ast_ASTArena * arena, struct ast_PipelineDepCtx * ctx) {
  (void)(({ int32_t __tmp = 0; if ((module)->main_func_index < 0) {   return (-10);
 } else (__tmp = 0) ; __tmp; }));
  (void)(({ int32_t __tmp = 0; if ((module)->main_func_index >= (module)->num_funcs) {   return (-11);
 } else (__tmp = 0) ; __tmp; }));
  return typeck_typeck_su_ast_impl(module, arena, ctx);
}
