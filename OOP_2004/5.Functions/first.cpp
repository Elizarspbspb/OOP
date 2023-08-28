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

// retstrc.cpp
// демонстрирует возвращение функцией структурной переменной
Distance addengl(Distance, Distance);   // прототипы
//////////////////////////////////////////////////////////

// ref.cpp
// применение ссылочного механизма передачи аргументов

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

    starline();

    // retstrc.cpp
    // демонстрирует возвращение функцией структурной переменной
    Distance d3, d4, d5;    // три структурные переменные
    d3.feet = 10;
    d3.inches = 9;
    d4.feet = 6;
    d4.inches = 12;
    d5 = addengl(d3, d4);   // d3 равно сумме d1 и d2
    engldisp(d3); 
    cout << " + ";
    engldisp(d4); 
    cout << " = ";
    engldisp(d5); 
    cout << endl;

    starline();

    // ref.cpp
    // применение ссылочного механизма передачи аргументов
    void intfrac(float, float&, float&);    // прототип
    float number, intpart, fracpart;
    number = 10.56;
    intfrac(number, intpart, fracpart);     // нахождение целой и дробной части
    cout << "Целая часть равна " << intpart // вывод результатов
    << ", дробная часть равна " << fracpart << endl;


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

// демонстрирует возвращение функцией структурной переменной
Distance addengl(Distance dd1, Distance dd2)
{
    Distance dd3;   // переменная для хранения будущей суммы
    dd3.inches = dd1.inches + dd2.inches;   // сложение дюймов
    dd3.feet = 0;   // с заемом;
    if(dd3.inches >= 12.0) {    // если число дюймов больше 12.0, то уменьшаем число дюймов
        dd3.inches -= 12.0;     // на 12.0 и увеличиваем
        dd3.feet++;
    }
    dd3.feet += dd1.feet + dd2.feet; // сложение футов
    return dd3;     // возврат значения
}
//--------------------------------------------------------

// функция intfrac() вычисляет целую и дробную часть вещественного числа
void intfrac(float n, float& intp, float& fracp) {
    long temp = static_cast<long>(n);   // преобразование к типу long,
    intp = static_cast<float>(temp);    // и обратно во float
    fracp = n - intp;                   // вычитаем целую часть
}