#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    // 每一行：同一时刻的六个关节角，单位为弧度
    std::vector<std::vector<double>> samples{
        {0.0,  0.0,   0.0,  0.0,  0.0,   0.0},
        {0.1, -0.1,   0.2,  0.0,  0.05, -0.05},
        {0.2, -0.2,   0.35, 0.1,  0.1,  -0.1},
        {0.3, -0.25,  0.5,  0.15, 0.2,  -0.15},
        {0.4, -0.3,   0.65, 0.2,  0.25, -0.2}
    };

    std::ofstream csv("joint_trajectory.csv");
    if (!csv)
    {
        std::cerr << "无法创建 CSV 文件\n";
        return 1;
    }

    csv << "time_s,joint_1_rad,joint_2_rad,joint_3_rad,"
           "joint_4_rad,joint_5_rad,joint_6_rad\n";

    for (std::size_t time = 0; time < samples.size(); ++time)
    {
        csv << time;

        for (double angle : samples[time])
        {
            csv << ',' << angle;
        }

        csv << '\n';
    }

    csv.close();
    std::cout << "已生成 joint_trajectory.csv\n";
    return 0;
}
