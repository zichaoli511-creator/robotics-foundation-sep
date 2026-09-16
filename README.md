# Robotics Foundation September

这是我的机器人软件基础学习仓库。第一阶段从 Linux、Git 和开发环境开始，逐步为 C++、CMake、Eigen、Python、ROS 2、机械臂运动学与运动规划打基础。

## 9 月学习目标

- 熟悉常用 Linux 命令
- 使用 Git 记录和同步代码修改
- 使用 CMake 创建并编译 C++ 项目
- 使用 Eigen 完成基础矩阵运算
- 使用 Python、NumPy 和 Matplotlib 处理、绘制轨迹数据
- 完成一个可以独立构建和运行的 GitHub 项目

## 2026-09-15：环境搭建与验收

状态：**通过**

已完成：

- 在 Windows 11 上安装 WSL 2
- 安装并初始化 Ubuntu 22.04 LTS
- 创建 Linux 用户 `robot`
- 更新 Ubuntu 软件包索引
- 安装 GCC、G++、CMake、Git、Python、pip、venv 和 Eigen 3
- 创建本地 Git 仓库并使用 `main` 分支
- 使用 VS Code 连接 WSL 环境
- 创建 README、提交代码并连接 GitHub 远程仓库
- 成功将首个提交推送至 GitHub

验收时记录的主要版本：

| 工具 | 版本 |
| --- | --- |
| Ubuntu | 22.04 LTS |
| WSL | WSL 2 |
| GCC / G++ | 11.4.0 |
| CMake | 3.22.1 |
| Git | 2.34.1 |
| Python | 3.10.12 |
| Eigen | 3 |

## 一键复查环境

在 Ubuntu/WSL 终端中进入仓库，然后运行：

```bash
cd ~/robotics-foundation-sep
bash scripts/check_environment.sh
```

脚本只读取环境信息，不会安装、删除或修改软件。全部必需项目通过时，最后会显示：

```text
验收结果：通过
```

## 学习资料

- [9 月 15 日：从零搭建开发环境](docs/2026-09-15-environment-setup.md)
- [常见问题与排查方法](docs/troubleshooting.md)

## 仓库位置

- Ubuntu 路径：`/home/robot/robotics-foundation-sep`
- Windows 文件资源管理器：`\\wsl.localhost\Ubuntu-22.04\home\robot\robotics-foundation-sep`
- GitHub：<https://github.com/zichaoli511-creator/robotics-foundation-sep>

> WSL 中的项目不直接位于普通的 C、D、E 盘文件夹中。推荐通过 Ubuntu 终端或 VS Code 的 WSL 模式修改，不要直接操作 WSL 的虚拟磁盘文件。
