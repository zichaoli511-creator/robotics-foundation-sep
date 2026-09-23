#include <iostream>

// 值传递
void increaseByValue(int number)
{
    number += 10;

    std::cout << "函数内部 number = " << number << '\n';
    std::cout << "函数内部 &number = " << &number << '\n';
}

// 引用传递
void increaseByReference(int& number)
{
    number += 10;

    std::cout << "函数内部 number = " << number << '\n';
    std::cout << "函数内部 &number = " << &number << '\n';
}

// const 引用：只读，不允许修改
void printNumber(const int& number)
{
    std::cout << "只读函数 number = " << number << '\n';
    std::cout << "只读函数 &number = " << &number << '\n';

    // number += 10;  // 暂时不要取消注释
}

int main()
{
    int value = 10;

    std::cout << "初始 value = " << value << '\n';
    std::cout << "main 中 &value = " << &value << "\n\n";

    std::cout << "===== 值传递 =====\n";
    increaseByValue(value);
    std::cout << "调用后 value = " << value << "\n\n";

    std::cout << "===== 引用传递 =====\n";
    increaseByReference(value);
    std::cout << "调用后 value = " << value << "\n\n";

    std::cout << "===== const 引用 =====\n";
    printNumber(value);
    std::cout << "调用后 value = " << value << '\n';

    return 0;
}