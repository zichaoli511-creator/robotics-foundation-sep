#include "TrajectoryAnalyzer.h"

#include <algorithm>
#include <iostream>
#include <numeric>

TrajectoryAnalyzer::TrajectoryAnalyzer(
    const std::vector<double>& joint_angles)
    : joint_angles_(joint_angles)
{
}

void TrajectoryAnalyzer::print() const
{
    for (double angle : joint_angles_)
    {
        std::cout << angle << " ";
    }

    std::cout << '\n';
}

double TrajectoryAnalyzer::average() const
{
    if (joint_angles_.empty())
    {
        return 0.0;
    }

    double sum = std::accumulate(
        joint_angles_.begin(),
        joint_angles_.end(),
        0.0);

    return sum /
           static_cast<double>(joint_angles_.size());
}

double TrajectoryAnalyzer::maxValue() const
{
    if (joint_angles_.empty())
    {
        return 0.0;
    }

    auto max_it = std::max_element(
        joint_angles_.begin(),
        joint_angles_.end());

    return *max_it;
}
