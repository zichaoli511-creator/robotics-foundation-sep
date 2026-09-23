#include <iostream>

void printSign(const int& number)
{
    if (number > 0)
    {
        std::cout << "positive\n";
    }
    else if (number < 0)
    {
        std::cout << "negative\n";
    }
    else
    {
        std::cout << "zero\n";
    }
}

int main()
{
    int number1 = 8;
    int number2 = -5;
    int number3 = 0;

    printSign(number1);
    printSign(number2);
    printSign(number3);

    return 0;
}