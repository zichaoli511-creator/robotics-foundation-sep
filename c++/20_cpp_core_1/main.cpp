#include <iostream>
#include <vector>
#include <cmath>

class TrajectoryAnalyzer
{
public:
    TrajectoryAnalyzer(const std::vector<double>& joints);
    ~TrajectoryAnalyzer();

    void print() const;
    double average() const;
    double maxValue() const;
    void normalize();

private:
    std::vector<double> joints_;
};

TrajectoryAnalyzer::TrajectoryAnalyzer(
    const std::vector<double>& joints)
    : joints_(joints)
{
    std::cout << "TrajectoryAnalyzer 对象已创建\n";
    std::cout << "关节数量：" << joints_.size() << '\n';

    std::cout << "外部数据地址：" << joints.data() << '\n';
    std::cout << "内部数据地址：" << joints_.data() << '\n';
}

TrajectoryAnalyzer::~TrajectoryAnalyzer()
{
    std::cout << "TrajectoryAnalyzer 对象已销毁\n";
}

void TrajectoryAnalyzer::print() const
{
    for (double value : joints_)
    {
        std::cout << value << " ";
    }

    std::cout << '\n';
}

double TrajectoryAnalyzer::average() const
{
    if (joints_.empty())
    {
        return 0.0;
    }

    double sum = 0.0;

    for (double value : joints_)
    {
        sum += value;
    }

    return sum / joints_.size();
}

double TrajectoryAnalyzer::maxValue() const
{
    if (joints_.empty())
    {
        return 0.0;
    }

    double maximum = joints_[0];

    for (double value : joints_)
    {
        if (value > maximum)
        {
            maximum = value;
        }
    }

    return maximum;
}

void TrajectoryAnalyzer::normalize()
{
    if (joints_.empty())
    {
        return;
    }

    double maximumAbsolute = 0.0;

    for (double value : joints_)
    {
        if (std::abs(value) > maximumAbsolute)
        {
            maximumAbsolute = std::abs(value);
        }
    }

    if (maximumAbsolute == 0.0)
    {
        return;
    }

    for (double& value : joints_)
    {
        value = value / maximumAbsolute;
    }
}

int main()
{
    std::cout << "程序开始\n";

    {
        std::vector<double> joints{
            0.2, -0.5, 1.1, 0.7, -0.3, 0.9
        };

        TrajectoryAnalyzer analyzer(joints);

        std::cout << "原始数据：";
        analyzer.print();

        std::cout << "平均值："
                  << analyzer.average()
                  << '\n';

        std::cout << "最大值："
                  << analyzer.maxValue()
                  << '\n';

        analyzer.normalize();

        std::cout << "归一化后：";
        analyzer.print();
    }

    std::cout << "程序结束\n";

    return 0;
}