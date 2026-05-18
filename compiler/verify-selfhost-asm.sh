#!/bin/sh
# verify-selfhost-asm.sh — asm 构建质量与 shu_asm 烟囱测试（零 cc 路线验收辅助）
# 用法：cd compiler && ./verify-selfhost-asm.sh
# 要求：./shu 已存在（make bootstrap-driver-seed）；不替代 make bootstrap-verify（语义自举仍以 shu-su 为准）。

set -e
cd "$(dirname "$0")"

echo "============================================"
echo " Shulang asm 自举质量验证"
echo "============================================"

if [ ! -x ./shu ]; then
  echo "verify-selfhost-asm: ./shu missing, run: make bootstrap-driver-seed"
  exit 1
fi

echo ""
echo "── Step 1: build_asm + __text 质量 ──"
SHU=./shu SHU_ASM_QUALITY_STRICT=1 ./scripts/build_shu_asm.sh || {
  echo "verify-selfhost-asm: build_shu_asm failed (strict __text)"
  exit 1
}

if [ ! -x ./shu_asm ]; then
  echo "verify-selfhost-asm: shu_asm not produced"
  exit 1
fi

echo ""
echo "── Step 2: shu_asm 编译 smoke（return-value）──"
RV=../tests/return-value/main.su
if [ -f "$RV" ]; then
  set +e
  ./shu_asm -backend asm -o /tmp/shu_asm_rv.o "$RV"
  RC=$?
  set -e
  if [ "$RC" -ne 0 ]; then
    echo "verify-selfhost-asm: shu_asm compile $RV failed (rc=$RC)"
    exit 1
  fi
  echo "verify-selfhost-asm: shu_asm smoke OK"
else
  echo "verify-selfhost-asm: skip smoke ($RV missing)"
fi

echo ""
echo "verify-selfhost-asm: PASS (asm quality + shu_asm smoke)"
echo "Note: full zero-cc (no cc -c pipeline_gen) needs SHU_ASM_LINK_TOPOLOGY=full_asm and all __text non-empty."
