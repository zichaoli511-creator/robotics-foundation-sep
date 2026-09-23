#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::vector<double>> joint_data = {
        {"joint_1", {10.0, 12.0, 14.0, 16.0}},
        {"joint_2", {20.0, 19.0, 21.0, 22.0}},
        {"joint_3", {-5.0, -2.0, 0.0, 3.0}},
        {"joint_4", {30.0, 30.5, 31.0, 29.5}},
        {"joint_5", {45.0, 44.0, 46.0, 45.0}},
        {"joint_6", {0.0, 5.0, -5.0, 10.0}}
    };
    // std::map<std::string, std::vector<double>> joint_data;
    // joint_data["joint_1"] = {10.0, 12.0, 14.0, 16.0};
    // joint_data["joint_2"] = {20.0, 19.0, 21.0, 22.0};
    // joint_data["joint_3"] = {-5.0, -2.0, 0.0, 3.0};
    // joint_data["joint_4"] = {30.0, 30.5, 31.0, 29.5};
    // joint_data["joint_5"] = {45.0, 44.0, 46.0, 45.0};
    // joint_data["joint_6"] = {0.0, 5.0, -5.0, 10.0};

    for (const auto& item : joint_data) {
        const std::string& joint_name = item.first;
        const std::vector<double>& angles = item.second;
        
    // for (const auto& [joint_name, angles] : joint_data) {
        if (angles.empty()) {
            std::cout << joint_name << " 没有数据\n";
            continue;
        }

        auto min_it = std::min_element(
            angles.begin(),
            angles.end()
        );

        auto max_it = std::max_element(
            angles.begin(),
            angles.end()
        );

        double sum = std::accumulate(
            angles.begin(),
            angles.end(),
            0.0
        );

        double average = sum / angles.size();

        std::cout << joint_name << '\n';
        std::cout << "  数据数量: " << angles.size() << '\n';
        std::cout << "  最小值: " << *min_it << '\n';
        std::cout << "  最大值: " << *max_it << '\n';
        std::cout << "  平均值: " << average << '\n';
    }

    return 0;
}