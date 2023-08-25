#include <iostream>

using namespace std;

void starline_2() {       // заголовок функции
    for(int j = 0; j < 45; j++) // тело функции
        cout << '*';
    cout << endl;
}
void starline();            // объявление функции (прототип)
void repchar(char, int);    // прототип функции
//void repchar(char symbol, int number);    // аналогично

///////////////////////////
// передача структурных переменных в функцию
struct Distance     // длина в английской системе
{
    int feet;
    float inches;
};
void engldisp(Distance); // объявление

////////////////////////////////
// демонстрирует механизм возврата значения функцией
float lbstokg(float);   // прототип функции

int main()
{
    // table.cpp
    // demonstrates simple function
    char chin = '=';
    starline();             // вызов функции
    cout << "Тип данных Диапазон" << endl;
    repchar(chin, 25);       // вызов функции
    cout << "char   -128...127" << endl 
    << "short   -32 768...32 767" << endl 
    << "int     Системно-зависимый" << endl
    << "long    -2 147 483 648...2 147 483 647" << endl;
    starline_2();             // вызов функции

    // engldisp.cpp
    // передача структурных переменных в функцию
    Distance d1, d2;    // определение двух длин
    d1.feet = 10;
    d1.inches = 8;
    d2.feet = 12;
    d2.inches = 6;
    cout << " d1 = ";
    engldisp(d1);   // вывод значения d1
    cout << "\n d2 = ";
    engldisp(d2);   // вывод значения d2
    cout << endl;

    starline();

    // convert.cpp
    // демонстрирует механизм возврата значения функцией
    float lbs, kgs;
    lbs = 10.2;
    kgs = lbstokg(lbs);
    cout << "Вес в килограммах равен " << kgs << endl;

    return 0;
}

//-------------- определение функции starline()
void starline() {       // заголовок функции
    for(int j = 0; j < 45; j++) // тело функции
        cout << '*';
    cout << endl;
}
// определение функции repchar()
void repchar(char chars, int number) {
    for(int j = 0; j < number; j++)  // тело функции
        cout << chars;
    cout << endl;
}

//////////////////////////////////
// функция engldisp(), отображающая значения полей структурной переменной типа Distance
void engldisp(Distance dd) // параметр dd типа Distance (КОПИЯ)
{
    cout << dd.feet << "\'-" << dd.inches << "\"";
}

// функция lbstokg() переводит фунты в килограммы
float lbstokg(float pounds) {
    float kilograms = 0.453592 * pounds;
    return kilograms;
}