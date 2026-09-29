# 环境与工具：第一阶段学习复盘

2026 年 9 月，我在 Windows 11 + WSL 2 + Ubuntu 22.04 中建立了机器人软件学习环境。这一阶段真正学到的是：**系统、编辑器、编译器、依赖库和版本管理各自处在什么位置，以及如何确认它们能一起工作。**

## 完成的环境

| 组件 | 当时验证的版本或状态 | 在项目中的作用 |
| --- | --- | --- |
| WSL 2 / Ubuntu | Ubuntu 22.04 LTS | Linux 开发环境 |
| GCC / G++ | 11.4.0 | 编译 C/C++ 代码 |
| CMake | 3.22.1 | 管理多文件工程的构建 |
| Git | 2.34.1 | 记录变更并同步到 GitHub |
| Python | 3.10.12 | 读取、计算和绘制轨迹数据 |
| Eigen | 3 | 矩阵、向量和坐标变换 |

VS Code 通过 WSL 模式编辑 Ubuntu 中的文件；`scripts/check_environment.sh` 可以再次读取并报告工具状态。

## 我学到的几个区别

- **Windows、WSL 和 Ubuntu**：Windows 是宿主系统，Ubuntu 是实际运行 C++/Python 项目的 Linux 环境。Linux 家目录与 `/mnt/c` 的路径和权限表现不同。
- **源码与构建产物**：源文件和 `CMakeLists.txt` 用于重新构建；`build/` 中的文件由工具生成，不需要放进 Git 历史。
- **Git 与 GitHub**：`git init` 创建本地版本历史；提交完成后仍要同步到远程仓库，网页上才会更新。
- **Python 虚拟环境**：`.venv` 让绘图库安装在当前项目环境中，仓库只保存依赖清单，不上传整个环境目录。

## 已验证的成果

- WSL/Ubuntu、编译器、CMake、Git、Python 和 Eigen 可以正常使用。
- 建立并推送了 `robotics-foundation-sep` 仓库。
- 后续在该环境中完成了 [C++ 多文件工程与 Eigen 练习](../trajectory_project/)，并生成了六关节轨迹图。

这一页是学习回顾；实际遇到的路径、权限、代理与换行问题记在 [踩坑与收获](troubleshooting.md)。
