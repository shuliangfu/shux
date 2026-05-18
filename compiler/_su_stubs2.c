#include <stdint.h>
#include <stddef.h>
int asm_asm_codegen_ast(void *a, void *b, void *c, void *d) { return -1; }
int asm_asm_codegen_elf_o(void *a, void *b, void *c, void *d, void *e) { return -1; }
int io_read_batch_buf(void) { return -1; }
int io_write_batch_buf(void) { return -1; }
int typeck_lsp_main(void) { return -1; }
extern int32_t typeck_preprocess_su_buf(const uint8_t *src, ptrdiff_t src_len, uint8_t *out_buf, int32_t out_cap);
int32_t preprocess_preprocess_su_buf(const uint8_t *src, ptrdiff_t src_len, uint8_t *out_buf, int32_t out_cap) {
    return typeck_preprocess_su_buf(src, src_len, out_buf, out_cap);
}
