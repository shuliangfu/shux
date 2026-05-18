/**
 * su_stubs.h — build-obj 用运行时符号前向声明
 *
 * 生成的 .su → C 代码引用 std 运行时符号（io_read, io_write 等）。
 * 编译 .o 文件时需此头文件避免 -Wimplicit，链接时由 std .o 提供实际实现。
 */
#ifndef SU_STUBS_H
#define SU_STUBS_H
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- panic ---- */
static inline void shulang_panic_(int has_msg, int msg_val) {
    if (has_msg) (void)fprintf(stderr, "panic: %d\n", msg_val);
    abort();
}

/* ---- io ---- */
extern ptrdiff_t io_read(int32_t fd, uint8_t *buf, size_t count, uint32_t timeout_ms);
extern ptrdiff_t io_write(int32_t fd, uint8_t *buf, size_t count, uint32_t timeout_ms);
extern int32_t io_register_buffer(uint8_t *ptr, size_t len);
extern void io_unregister_buffers(void);
extern uint8_t *io_read_ptr(size_t handle, uint32_t timeout_ms);
extern int32_t io_read_ptr_len(void);

/* ---- shu io core wrappers ---- */
int32_t std_io_core_shu_io_register(uint8_t *ptr, size_t len, size_t handle);
int32_t std_io_core_shu_io_submit_read(uint8_t *ptr, size_t len, size_t handle, uint32_t timeout_ms);
int32_t std_io_core_shu_io_submit_write(uint8_t *ptr, size_t len, size_t handle, uint32_t timeout_ms);
void std_io_core_shu_io_unregister_buffers(void);

/* ---- fs ---- */
extern ptrdiff_t fs_posix_read_c(int32_t fd, uint8_t *buf, size_t count);
extern ptrdiff_t fs_posix_write_c(int32_t fd, const uint8_t *buf, size_t count);
extern int32_t fs_posix_close_c(int32_t fd);

#ifdef __cplusplus
}
#endif
#endif
