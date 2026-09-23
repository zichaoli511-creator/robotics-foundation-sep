#include <iostream>

int main()
{
    int value = 10;
    int& reference = value;
    int* pointer = &value;

    reference = 20;
    *pointer = 30;

    std::cout << "value: " << value << '\n';
    std::cout << "reference: " << reference << '\n';
    std::cout << "*pointer: " << *pointer << '\n';

    std::cout << "&value: " << &value << '\n';
    std::cout << "&reference: " << &reference << '\n';
    std::cout << "pointer: " << pointer << '\n';

    return 0;
}