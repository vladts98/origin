#include <iostream>
#include <Windows.h>

class Counter {
public:
    Counter() {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::string answer;
        std::cin >> answer;
        if (answer == "нет") {
        } else if (answer == "да") {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> count;
        }
    }
    bool make(std::string& pull) {
        if (pull == "+") {
            count++;
            return true;
        } else if (pull == "-") {
            count--;
            return true;
        }
        else if (pull == "=") {
            std::cout << count << std::endl;
        }
        else if (pull == "x" || pull == "х") {
            std::cout << "До свидания! ";
            return false;
        }
        else {
            std::cout << "bad";
            return false;
        }
    }

private:
    int count = 1;
    
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    Counter c;
    std::string pull;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> pull;
    } while (c.make(pull));
}