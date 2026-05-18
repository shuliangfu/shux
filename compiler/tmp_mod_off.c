/* 临时 offsetof 计算器：镜像 pipeline_gen.c 中 Ast Module 尾部布局字段，供 lldb / 手写偏移对照。 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

struct ast_Param {
  uint8_t name[32];
  int32_t name_len;
  int32_t type_ref;
};

struct ast_Func {
  uint8_t name[64];
  int32_t name_len;
  struct ast_Param params[16];
  int32_t num_params;
  int32_t return_type_ref;
  int32_t body_ref;
  int32_t body_expr_ref;
  int32_t is_extern;
};

struct ast_StructLayout {
  uint8_t name[64];
  int32_t name_len;
  int32_t num_fields;
  uint8_t field_names[24][64];
  int32_t field_lens[24];
  int32_t field_offsets[24];
  int32_t field_type_refs[24];
};

struct ast_Module {
  struct ast_Func funcs[256];
  int32_t func_refs[256];
  int32_t num_funcs;
  int32_t main_func_index;
  uint8_t import_path_data[2048];
  int32_t import_path_lens[32];
  int32_t num_imports;
  int32_t import_kinds[32];
  uint8_t import_binding_name[32][64];
  int32_t import_binding_name_len[32];
  int32_t import_select_count[32];
  uint8_t import_select_names[32][8][64];
  int32_t import_select_name_lens[32][8];
  int32_t num_top_level_lets;
  uint8_t top_level_let_names[32][64];
  int32_t top_level_let_name_lens[32];
  int32_t top_level_let_type_refs[32];
  int32_t top_level_let_init_refs[32];
  int32_t top_level_let_is_const[32];
  struct ast_StructLayout struct_layouts[32];
  int32_t num_struct_layouts;
};

int main(void) {
  printf("sizeof(ast_Func)=%zu sizeof(ast_StructLayout)=%zu\n",
         sizeof(struct ast_Func),
         sizeof(struct ast_StructLayout));
  printf("offsetof(struct_layouts)=%zu\n", offsetof(struct ast_Module, struct_layouts));
  printf("offsetof(num_struct_layouts)=%zu\n", offsetof(struct ast_Module, num_struct_layouts));
  printf("offsetof field_names=%zu field_lens=%zu offsets=%zu type_refs=%zu\n",
         offsetof(struct ast_StructLayout, field_names),
         offsetof(struct ast_StructLayout, field_lens),
         offsetof(struct ast_StructLayout, field_offsets),
         offsetof(struct ast_StructLayout, field_type_refs));
  printf("offsetof(first layout.field_lens[0])=%zu\n",
         offsetof(struct ast_Module, struct_layouts) +
             offsetof(struct ast_StructLayout, field_lens));
  return 0;
}
