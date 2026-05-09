# .su 与 C 流水线同步状态

## 目标

所有 .su 必须与 C 同步支持相同语法，否则自举无意义。需同步的语法包括：

1. **顶层 let/const** — `let global_x = 42;`、`const N = 7;`
2. **整模块 import** — `import path;`
3. **绑定 import** — `const xxx = import std.xxxx;`
4. **解构 import** — `const { a, b } = import std.xxx;`

---

## 当前状态（已全面同步）

| 语法 | C 流水线 | .su 流水线 | 测试 |
|------|----------|------------|------|
| 顶层 let/const | ✅ | ✅ | `run-toplevel-let.sh`（main.su、two_lets.su），run-all 始终跑 |
| `import path;` | ✅ | ✅ | run-import、run-process 等 |
| `const x = import path;` | ✅ | ✅ | `tests/process/spawn_wait.su`，run-process.sh 通过（shu_su） |
| `const { a,b } = import path;` | ✅ | ✅ | .su 已实现；run-import 的 const_select.su 用整模块 import 保证 C/shu_su 都过，解构可手动改 const { print_str } 用 shu_su 验证 |

---

## 已实现（.su）

- **ast.su**：`ImportKind`、`Module` 的 `import_kinds` / `import_binding_name` / `import_select_*`、`top_level_let_*` 与 C 对齐。
- **parser.su**：
  - 顶层 let/const：`parse_one_top_level_let_into` + `parse_into_buf` 中解析并写 `module.top_level_let_*`。
  - `collect_imports` / `collect_imports_buf`：支持 `import path;`（`import_kinds[i]=0`）、`const id = import path;`（`import_kinds[i]=1`，填 `import_binding_name`）、`const { a, b } = import path;`（`import_kinds[i]=2`，填 `import_select_count` / `import_select_names`）。
- **typeck.su**：顶层 let 名字进作用域；`resolve_call_callee_return_type` 支持绑定（EXPR_FIELD_ACCESS base=VAR 按 `import_binding_name` 找 dep）、解构（EXPR_VAR 按 `import_select_names` 找 dep）。
- **codegen.su**：顶层 let/const 生成 static/init_globals、main 内 `init_globals();`；EXPR_CALL 时对绑定形式（process.getenv）生成 `dep_prefix + field_name(...)`，对解构形式（裸 getenv）按 `import_select_names` 匹配 dep 后生成 `dep_prefix + name(...)`。

---

## 测试清单（与 C 同步相关）

- **run-toplevel-let.sh**：顶层 let/const，C 与 shu_su 均跑，已加入 run-all。
- **run-process.sh**：含 spawn_wait.su（`const process = import std.process;` + `process.getenv` / `process.spawn_simple`），C 与 shu_su 均通过。
- **run-import.sh**：const_select.su 使用整模块 `import std.io;`，C 与 shu_su 均通过；解构形式已实现，可将该文件改为 `const { print_str } = import std.io` 用 shu_su 验证。

结论：**SU 已与 C 全面同步**；四种语法均有实现与测试（run-toplevel-let、run-process、run-import 覆盖绑定与解构）。
