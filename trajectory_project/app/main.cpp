#include "TrajectoryAnalyzer.h"

#include <iostream>
#include <vector>

int main()
{
    std::vector<double> joint_angles{
        0.2,
        -0.5,
        1.1,
        0.7,
        -0.3,
        0.9
    };

    TrajectoryAnalyzer analyzer(joint_angles);

    std::cout << "原始六关节数据：";
    analyzer.print();

    std::cout << "平均值："
              << analyzer.average()
              << '\n';

    std::cout << "最大值："
          << analyzer.maxValue()
          << '\n';

    return 0;
}
