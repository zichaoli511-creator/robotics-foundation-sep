# C++ 基础与 STL 练习索引

这里保留了按阶段写出的练习代码。每个文件对应一次概念练习，因此一些示例会重复前一阶段的代码；这样能看到功能如何逐步增加。

| 目录 | 学过的重点 |
| --- | --- |
| [`19_cpp_core_1/`](19_cpp_core_1/) | 引用与指针、`const`、函数传参、变量生命周期 |
| [`20_cpp_core_1/`](20_cpp_core_1/) | 用前一天的概念处理关节数据 |
| [`21_22_cpp-stl-practice/`](21_22_cpp-stl-practice/) | `vector` 遍历和迭代器、`min_element` / `max_element` / `accumulate`、`map`、异常点判断与 Lambda |

学习中还讨论了 `unique_ptr`、对象的 `.` 与指针的 `->`。这部分帮助我理解后续在 ROS 2 C++ 接口里会遇到的对象和指针写法。

这些文件是概念练习，不承担完整项目的构建入口；可运行的多文件项目在 [`trajectory_project/`](../trajectory_project/)。
