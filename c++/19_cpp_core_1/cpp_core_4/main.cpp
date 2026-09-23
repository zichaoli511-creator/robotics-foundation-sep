#include <iostream>
#include <vector>
#include <cmath>

void printValues(const std::vector<double>& values)
{
    for (double value : values)
    {
        std::cout << value << " ";
    }

    std::cout << '\n';
}

double average(const std::vector<double>& values)
{
    if (values.empty())
    {
        return 0.0;
    }

    double sum = 0.0;

    for (double value : values)
    {
        sum += value;
    }

    return sum / values.size();
}

const double* findMax(const std::vector<double>& values)
{
    if (values.empty())
    {
        return nullptr;
    }

    const double* maxPointer = &values[0];

    for (std::size_t index = 1; index < values.size(); index++)
    {
        if (values[index] > *maxPointer)
        {
            maxPointer = &values[index];
        }
    }

    return maxPointer;
}

void normalize(std::vector<double>& values)
{
    if (values.empty())
    {
        return;
    }

    double maximumAbsolute = 0.0;

    for (double value : values)
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

    for (double& value : values)
    {
        value = value / maximumAbsolute;
    }
}

int main()
{
    std::vector<double> joints{
        0.2, -0.5, 1.1, 0.7, -0.3, 0.9
    };
    std::cout << "原始关节数据：";
    printValues(joints);


    double result = average(joints);
    std::cout << "平均值：" << result << '\n';


    const double* maximum = findMax(joints);
    if (maximum != nullptr)
    {
        std::cout << "最大值：" << *maximum << '\n';
    }
    else
    {
        std::cout << "没有数据\n";
    }


    normalize(joints);
    std::cout << "归一化数据：";
    printValues(joints);
    return 0;
}