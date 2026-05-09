#!/usr/bin/env bash
# 阶段 4 Hello World：编译 examples/hello.su 并运行，检查输出含 "Hello World"
# run-all 默认用 C（RUN_ALL_USE_C=1）：用 compiler/shu 走 C 流水线，不构建 bootstrap-driver-seed。
# run-all-su 设 SHU=shu_su：用 .su 流水线（-su）。

set -e
cd "$(dirname "$0")/.."
SHU=${SHU:-./compiler/shu}
if [ -n "${RUN_ALL_USE_C:-}" ]; then
  # run-all 默认 C 流水线
  make -C compiler -q all 2>/dev/null || make -C compiler all
  "$SHU" examples/hello.su -o /tmp/shu_hello
else
  if [[ "$SHU" == *shu-c* ]]; then
    "$SHU" examples/hello.su -o /tmp/shu_hello
  else
    # 使用 .su 流水线时禁止把生成的 C 打到终端（重定向 stdout，保留 stderr）
    "$SHU" -su examples/hello.su -o /tmp/shu_hello 1>/dev/null
  fi
fi
out=$(/tmp/shu_hello)
echo "$out" | grep -q "Hello World" || { echo "expected 'Hello World' in output, got: $out"; exit 1; }
echo "Hello World test OK"
