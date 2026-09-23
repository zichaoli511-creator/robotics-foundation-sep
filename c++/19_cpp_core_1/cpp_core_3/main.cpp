#include <iostream>

// 引用传递

void resetToZero(int& number)
{
    number = 0;

    std::cout << "函数内部 number = " << number << '\n';
    std::cout << "函数内部 &number = " << &number << '\n';
}

int main()
{
    int value = 50;

    std::cout << "初始 value = " << value << '\n';
    std::cout << "main 中 &value = " << &value << "\n\n";

    std::cout << "===== 引用传递 =====\n";
    resetToZero(value);
    std::cout << value << '\n';

    return 0;
}
