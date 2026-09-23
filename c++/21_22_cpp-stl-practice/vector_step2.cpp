#include <cstddef>
#include <iostream>
#include <vector>

int main() 
{
    std::vector<double> joint_angles = {10.0, 20.0, 30.0};
    std::cout << "样本数量: " << joint_angles.size() << '\n';
    std::cout << "第一个角度: " << joint_angles[0] << '\n'<< '\n';

    std::cout << "原来的第二个角度: "
              << joint_angles[1] << '\n';
    joint_angles[1] = 25.5;
    std::cout << "修改后的第二个角度: "
              << joint_angles[1] << '\n'<< '\n';

    joint_angles.push_back(40.0);
    std::cout << "添加后的样本数量: "
              << joint_angles.size() << '\n';
    std::cout << "新加入的角度: "
              << joint_angles[3] << '\n'<< '\n';

    for (std::size_t i = 0; i < joint_angles.size(); ++i) {
        std::cout << "索引 " << i
                  << "，角度 " << joint_angles[i]
                  << '\n';
    }

    return 0;
}