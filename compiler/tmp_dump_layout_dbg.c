/*
 * Minimal debug harness: rebuild not required for main tree; compile:
 * cc -o /tmp/dump_dbg tmp_dump_layout_dbg.c -I "$(pwd)" \
 *    ast_seed.o lexer.o preprocessor stub...  (skipped)
 *
 * Instead we dlopen shu symbols — too brittle. Use GDB style on existing:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    puts("unused");
    return 0;
}
