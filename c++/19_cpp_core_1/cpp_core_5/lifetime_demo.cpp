#include <iostream>
#include <vector>

int main()
{
    std::vector<double> values{1.0, 2.0};

    const double* elementPointer = &values[0];
    const double* oldStorage = values.data();

    std::size_t oldCapacity = values.capacity();

    std::cout << "扩容前地址：" << oldStorage << '\n';
    std::cout << "扩容前容量：" << oldCapacity << '\n';
    std::cout << "指针指向的值：" << *elementPointer << '\n';

    // 持续添加元素，直到 vector 扩容
    while (values.capacity() == oldCapacity)
    {
        values.push_back(0.0);
    }

    std::cout << "扩容后地址：" << values.data() << '\n';
    std::cout << "扩容后容量：" << values.capacity() << '\n';

    if (oldStorage != values.data())
    {
        std::cout << "存储地址发生变化，旧指针已经失效\n";
    }

    // 不要再使用 *elementPointer
    elementPointer = nullptr;

    return 0;
}