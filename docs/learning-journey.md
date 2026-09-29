# 学习复盘：从项目算法到真实机械臂

这份记录综合了本项目中从环境搭建、Linux、Git、C++/STL、CMake/Eigen 到 Python 轨迹分析的学习对话。它记录**已经理解和实践的内容**，并将 ROS 2、MoveIt 2、仿真和真机明确列为后续路线。

## 1. 环境与工程习惯

- 在 Windows 11 的 WSL 2 中建立 Ubuntu 22.04 开发环境，安装 GCC/G++、CMake、Git、Python 与 Eigen。
- 练习 `pwd`、`ls`、`cd`、`mkdir`、`cp`、`mv`，随后使用 `find`、`grep`、权限、进程、管道与重定向处理真实文件。
- 认识 Linux 路径与 Windows 路径的区别；曾在 `/mnt/c` 练习 `chmod` 时发现权限显示受挂载方式影响，转到 Linux 家目录继续验证。
- 使用 Git 的工作区、暂存区和提交历史记录变化；理解 `status → diff → add → commit → push`，也体验了撤销暂存与远程同步。

对应资料：[环境学习记录](2026-09-15-environment-setup.md) · [踩坑与收获](troubleshooting.md) · [环境检查脚本](../scripts/check_environment.sh)

## 2. C++ 核心与 STL

- 从引用、指针、`const`、传值与传引用开始，逐步理解变量生命周期及对象访问方式。
- 用 `std::vector` 保存角度序列，通过索引、范围循环和迭代器遍历数据。
- 用标准算法求最小值、最大值与平均值；用 `std::map` 建立关节名称到角度序列的对应关系。
- 用阈值和 Lambda 练习异常点检测，理解捕获列表；继续认识智能指针及 `unique_ptr`。

对应代码：[C++ 练习索引](../c++/README.md)

## 3. 从单文件到 CMake 工程

`TrajectoryAnalyzer` 最初是一组零散练习，后来拆成头文件、实现文件和主程序。先用 `g++` 手动编译，理解头文件搜索路径、编译与链接；再用 CMake 建立 `trajectory_lib` 静态库和 `trajectory_app` 可执行目标，并在新的构建目录中验证可重复构建。

这一步让我把“代码能跑”和“工程可重新构建”联系起来。[查看实际工程](../trajectory_project/)

## 4. Eigen 与坐标系

- 从矩阵乘向量入手，验证二维点绕原点旋转 90°。
- 使用“先旋转、后平移”的关系，把局部坐标转换到世界坐标；再扩展到三维。
- 使用 `Eigen::Isometry3d` 表示位姿，练习逆变换和“底座 → 末端 → 工具”两段变换的组合。
- 通过手算核对工具原点与工具尖端的位置，理解变换方向和乘法顺序。

对应代码：[Eigen 示例](../trajectory_project/app/eigen_demo.cpp)

## 5. Python 轨迹数据链

- C++ 生成五个时刻、六个关节角的 CSV。此前的一组六关节角表示**一个时刻**；轨迹则需要多行采样。
- Python 用 `csv.DictReader` 读取列名，用 `float` 转换数字，再整理成形状为 `(5, 6)` 的 NumPy 数组。
- Matplotlib 绘制六关节角度曲线；NumPy 的相邻差值计算四段平均角速度，得到 `(4, 6)` 的速度数组。
- 用练习阈值标记一个超限区间，并把四段速度写回 CSV。

对应结果：[六关节角度图](../trajectory_project/plots/all_joints.png) · [速度与阈值图](../trajectory_project/plots/velocity_limit_check.png)

## 下一段路

| 阶段 | 计划重点 | 当前状态 |
| --- | --- | --- |
| ROS 2 | C++ 节点与消息通信，逐步加入 Topic、Service、Action、Parameter、Launch、TF2 和 rosbag2 | 尚未开始实现 |
| MoveIt 2 | 在理解运动学和机器人模型后接入规划与执行接口 | 计划中 |
| 仿真 | 在可复现实验中验证规划、控制、状态反馈与数据记录 | 计划中 |
| 真机 | 完成基础和仿真验证后，再连接真实机械臂 | 计划中 |

路线会随实践调整；仓库用代码、图和阶段复盘标记实际进度，不把规划写成已完成成果。
