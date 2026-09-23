#include <iostream>

int main()
{
    const double* pointer = nullptr;

    {
        double localValue = 3.14;

        pointer = &localValue;

        std::cout << "作用域内部的值：" << *pointer << '\n';
        std::cout << "作用域内部的地址：" << pointer << '\n';
    }

    // localValue 在这里已经被销毁
    // pointer 仍保存旧地址，但该地址已经不能安全使用

    pointer = nullptr;

    std::cout << "局部变量已销毁，指针已设置为 nullptr\n";

    return 0;
}