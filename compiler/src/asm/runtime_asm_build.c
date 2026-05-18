/**
 * runtime_asm_build.c — Goal 2 用 asm 后端构建 shu 时的最小 C 桩
 *
 * 仅提供 main()，转调 main.su 经 -E 生成 C 后的入口符号 main_entry（模块 main 前缀 + function entry）。
 * 与 main.c 一致：main.c 调 main_entry（driver_gen.c）；asm 全链若 main.o 仍为空桩，Goal2 回退链入 driver_su.o
 * 时同样使用 main_entry，而非裸符号 entry。
 *
 * 链接时需：本 .o + main.su 对应实现（asm main.o 或 driver_su.o 等）+ runtime_driver.o + -lc。
 */
extern int main_entry(int argc, char **argv);

int main(int argc, char **argv) {
    return main_entry(argc, argv);
}
