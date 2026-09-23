#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> joint_angles = {
        10.0,
        25.5,
        30.0,
        40.0
    };

    if (joint_angles.empty()) {
        std::cout << "没有数据\n";
        return 0;
    }

    auto min_it = std::min_element(
        joint_angles.begin(),
        joint_angles.end()
    );

    auto max_it = std::max_element(
        joint_angles.begin(),
        joint_angles.end()
    );

    double sum = std::accumulate(
        joint_angles.begin(),
        joint_angles.end(),
        0.0
    );

    double average = sum / joint_angles.size();

    std::cout << "最小值: " << *min_it << '\n';
    std::cout << "最大值: " << *max_it << '\n';
    std::cout << "总和: " << sum << '\n';
    std::cout << "平均值: " << average << '\n';

    return 0;
}