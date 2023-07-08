// showprim.cpp
// изображает распределение простых чисел
#include <iostream>
using namespace std;
// #include <conio.h>
// для getche()
int main()  {
    const unsigned char WHITE = 219;    // белый цвет для простых чисел
    const unsigned char GRAY = 176;     // серый цвет для остальных чисел
    unsigned char ch;   // действия для каждой позиции на экране
    for(int count = 0; count < 80 * 25 - 1; count++) {
        ch = WHITE; // предполагаем, что число простое
        for(int j = 2; j < count; j++) // делим на каждое целое, большее 2
            if(count % j == 0)  // если остаток равен 0,
            {
                ch = GRAY;  // то число не простое
                break;      // выход из внутреннего цикла
            }
            cout << ch; // вывод символа на экран
        }
    //getch();    // задержка полученного изображения
    cout << endl;
    // -------------------------------------------------
    long dividend, divisor;
    char again;
    do {
        cout << "Введите делимое: "; cin >> dividend;
        cout << "Введите делитель: "; cin >> divisor;
        if(divisor == 0) {   // при попытке деления на ноль
            cout << "Некорректный делитель!\n"; // вывод сообщения
            continue;   // возврат в начало цикла
        }
        cout << "Частное равно " << dividend / divisor;
        cout << ", остаток равен " << dividend % divisor;
        cout << "\nЕще раз?(y/n): ";
        cin >> again;
    } while(again != 'n');

    goto SystemCrash;   
    // операторы
    SystemCrash:        // сюда передается управление оператором goto

    return 0;
}