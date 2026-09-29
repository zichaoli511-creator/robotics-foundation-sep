# 六关节轨迹分析小工程

这个工程把 9 月的 C++、CMake、Eigen 和 Python 练习接成一条数据链：

```text
C++ 多文件程序与 Eigen 坐标变换
             ↓
C++ 生成六关节轨迹 CSV
             ↓
Python 读取 CSV → NumPy 计算 → Matplotlib 绘图
             ↓
四段平均角速度、阈值标记与速度 CSV
```

## 实际完成的内容

| 部分 | 学习与实现 |
| --- | --- |
| `trajectory_lib` + `trajectory_app` | 把类的声明、实现和调用分开；计算一组六关节角的平均值与最大值 |
| `eigen_demo` | 矩阵乘法、二维/三维旋转和平移、位姿组合、逆变换；验证工具尖端在不同坐标系中的位置 |
| `export_trajectory` | 写出包含时间列和六个关节角列的示例轨迹 CSV |
| `read_trajectory.py` | 按列名读取 CSV，并把角度文本转换为数字 |
| `plot_trajectory.py` | 使用 NumPy 数组计算四段平均角速度，绘图、检查练习阈值并导出速度 CSV |

一个容易混淆的点是：**六个关节角只描述一个时刻**。本项目的 `joint_trajectory.csv` 有五行采样数据，每行是一个时刻的六个角度；NumPy 角度数组的形状为 `(5, 6)`。相邻时刻之间有四段，因此速度数组是 `(4, 6)`。

## 结果预览

![六关节角度](plots/all_joints.png)

![六关节平均角速度及练习阈值](plots/velocity_limit_check.png)

示例数据中，第一关节的四段平均角速度约为 `0.10 rad/s`；第三关节在 `0～1 s` 的平均角速度为 `0.20 rad/s`，超过代码中设置的 `0.16 rad/s` **练习阈值**。这只是演示如何检查数据，不对应真实设备限制。

## 文件位置

- [CMakeLists.txt](CMakeLists.txt)：静态库和三个可执行目标。
- [app/](app/)：主程序、Eigen 示例、CSV 导出程序。
- [include/](include/) 与 [src/](src/)：`TrajectoryAnalyzer` 的声明与实现。
- [scripts/](scripts/)：CSV 读取与轨迹分析。
- [joint_trajectory.csv](joint_trajectory.csv) 与 [joint_velocity.csv](joint_velocity.csv)：示例输入与计算结果。
- [plots/](plots/)：五张可视化结果图。

## 复现入口

从本目录运行：

```bash
cmake -S . -B build && cmake --build build
./build/export_trajectory
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
mkdir -p plots
python scripts/plot_trajectory.py
```

运行环境：Ubuntu 22.04、C++17、CMake、Eigen 3、Python 3；Python 依赖见 [requirements.txt](requirements.txt)。

目前数据是五个时刻的手工示例，还没有接入 ROS 2、仿真器或真实机械臂。
