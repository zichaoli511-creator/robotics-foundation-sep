#pragma once

#include <vector>

class TrajectoryAnalyzer
{
public:
    TrajectoryAnalyzer(
        const std::vector<double>& joint_angles);

    void print() const;
    double average() const;
    double maxValue() const;

private:
    std::vector<double> joint_angles_;
};
