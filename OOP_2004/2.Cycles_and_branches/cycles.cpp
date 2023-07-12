#include <iostream>
#include <iomanip>  // для setw

using namespace std;

int main()
{
    // relat.cpp
    // применение операций отношения
    int numb;
    cout << "Введите число: ";
    cin >> numb;
    cout << "numb < 10 равно " << (numb < 10) << endl;
    cout << "numb > 10 равно " << (numb > 10) << endl;
    cout << "numb == 10 равно " << (numb == 10) << endl;

    // fordemo.cpp
    // демонстрирует работу простейшего цикла for
    int j;      // определение счетчика цикла
    for (j = 0; j < 15; j++)                // счетчик меняется от 0 до 14
        cout << j * j << " ";       // квадрат значения j выводится на экран
    cout << endl;
    for (int numb = 1; numb <= 10; numb++) { // цикл от 1 до 10
        cout << setw(4) << numb;             // вывод первого столбца
        int cube = numb * numb * numb;       // вычисление куба
        cout << setw(6) << cube << endl;     // вывод второго столбца
    }

    // factor.cpp
    // подсчет факториала числа с помощью цикла for
    unsigned int numb_1;
    unsigned long fact = 1;
    cout << "Введите целое число: ";
    cin >> numb_1;
    for(int j = numb_1; j > 0; j--)
        fact *= j;
    cout << "Факториал числа равен " << fact << endl;

    for(int j = 0, alpha = 100; j < 50; j++, numb_1--) {
        // тело цикла
    }

    // for(; ;)

    // endon0.cpp
    // применение цикла WHILE
    int n = 99; // n не должна быть равна 0 перед началом цикла
    cout << "Введите 0 ";
    while(n != 0)
        cin >> n;
    cout << endl;

    // while4.cpp
    // возведение в четвертую степень целых чисел
    int pow = 1;
    int numb_2 = 1;
    while(pow < 10000) {
        cout << setw(2) << numb_2;
        cout << setw(5) << pow << endl;
        ++numb_2;
        pow = numb_2 * numb_2 * numb_2 * numb_2; // вычисление 4-й степени
    }
    cout << endl;

    // fibo.cpp
    // генерирование чисел Фибоначчи с помощью цикла while
    const unsigned long limit = 4294967295; // граница типа unsigned long
    unsigned long next = 0;     // предпоследний член
    unsigned long last = 1;     // последний член
    while(next < limit / 2)     // результат не должен быть слишком большим
    {
        cout << last << " ";    // вывод последнего члена
        long sum = next + last; // сложение двух последних членов
        next = last;    // обновление предпоследнего
        last = sum;     // обновление и последнего членов
    }
    cout << endl;   

    // divdo.cpp
    // применение цикла do. Сначало действие потом условие
    long dividend, divisor;
    char ch;
    do      // начало цикла do
    {       // действия
        cout << "Введите делимое: "; cin >> dividend;
        cout << "Введите делитель: "; cin >> divisor;
        cout << "Частное равно " << dividend / divisor;
        cout << ", остаток равен " << dividend % divisor;
        cout << "\nЕще раз?(y/n): ";
        cin >> ch;
    } while(ch != 'n'); // условие цикла

    return 0;
}