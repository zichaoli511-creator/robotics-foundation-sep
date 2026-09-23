#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> angles = {
        10.0,
        12.0,
        14.0,
        50.0
    };

    double sum = std::accumulate(
        angles.begin(),
        angles.end(),
        0.0
    );

    double average = sum / angles.size();
    double threshold = 20.0;

    auto is_abnormal =
    // Lambda 表达式
        [average, threshold](double angle) {
            return std::abs(angle - average) > threshold;
        };

    std::cout << "平均值: " << average << '\n';

    for (double angle : angles) {
        if (is_abnormal(angle)) {
            std::cout << "异常角度: " << angle << '\n';
        }
    }

    int abnormal_count = std::count_if(
        angles.begin(),
        angles.end(),
        is_abnormal
    );

    std::cout << "异常点数量: "
              << abnormal_count
              << '\n';

    return 0;
}