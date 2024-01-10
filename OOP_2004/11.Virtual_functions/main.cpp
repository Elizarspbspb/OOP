// Глава 11. Виртуальные функции
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////

class Base { // Базовый класс
public:
    //void show() { cout << "Base\n"; }
    virtual void show() { cout << "Base\n"; }   // Виртуальная функция
};
class Derv1 : public Base {     // Производный класс 1
public:
    void show() { cout << "Derv1\n"; }
};
class Derv2 : public Base {     // Производный класс 2
public:
    void show() { cout << "Derv2\n"; }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    Derv1 dv1;      // Объект производного класса 1
    Derv2 dv2;      // Объект производного класса 2
    Base* ptr;      // Указатель на базовый класс
    ptr = &dv1;     // Адрес dv1 занести в указатель
    ptr->show();    // Выполнить show()     // Base // Derv1
    ptr = &dv2;     // Адрес dv2 занести в указатель
    ptr->show();    // Выполнить show()     // Base // Derv2

///////////////////////////////////////////////////////////

    return 0;
}