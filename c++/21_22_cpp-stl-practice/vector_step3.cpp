#include <iostream>
#include <vector>

int main() {
    std::vector<double> joint_angles = {
        10.0,
        25.5,
        30.0,
        40.0
    };
    // std::vector<double>::iterator it = joint_angles.begin();
    for (auto it = joint_angles.begin();
         it != joint_angles.end();
         ++it) 
         {
        std::cout << "当前角度: " << *it << '\n';
    }

    return 0;
}