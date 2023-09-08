#include <iostream>

using namespace std;

void starline_2() {       // заголовок функции
    for(int j = 0; j < 45; j++) // тело функции
        cout << '*';
    cout << endl;
}
void starline();            // объявление функции (прототип)

// Переменное число аргументов функции
void repchar();             // прототипы
void repchar(char);
void repchar(char, int);    // прототип функции
//void repchar(char symbol, int number);    // аналогично
// missarg.cpp
// применение аргументов по умолчанию
void repchar(char = '*', int = 45); // прототип с аргументами по умолчанию

///////////////////////////
// передача структурных переменных в функцию
struct Distance     // длина в английской системе
{
    int feet;
    float inches;
};
void engldisp(Distance); // объявление
    // Различные типы аргументов
void engldisp(float);

////////////////////////////////
// демонстрирует механизм возврата значения функцией
float lbstokg(float);   // прототип функции

// retstrc.cpp
// демонстрирует возвращение функцией структурной переменной
Distance addengl(Distance, Distance);   // прототипы

//////////////////////////////////////////////////////////

// referst.cpp
// передача структурной переменной по ссылке
void scale(Distance&, float);       // прототипы функций

// factor2.cpp
// подсчет факториала числа с помощью рекурсии
unsigned long factfunc(unsigned long);  // прототип

// функция lbstokgInline()
// переводит фунты в килограммы
inline float lbstokgInline(float pounds) {
    return 0.453592 * pounds;
}

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

    starline();

    // reforder.cpp     
    // упорядочивает по возрастанию пары чисел
    void order(int&, int&); // прототип
    int n1 = 99, n2 = 11;   // неупорядоченная пара
    int n3 = 22, n4 = 88;   // упорядоченная пара
    order(n1, n2);      // упорядочивание обеих пар
    order(n3, n4);
    cout << "n1 =" << n1 << endl; // вывод результатов
    cout << "n2 =" << n2 << endl;
    cout << "n3 =" << n3 << endl;
    cout << "n4 =" << n4 << endl;

    starline();

    // referst.cpp  передача структурной переменной по ссылке
    Distance d6 = { 12, 6.5 };      // инициализация d6 и d7
    Distance d7 = { 10, 5.5 };
    cout << "d6 = "; engldisp(d6);      // вывод исходных значений d6 и d7
    cout << "\nd7 = "; engldisp(d7);
    scale(d6, 0.5);                     // масштабирование d6 и d7
    scale(d7, 0.25);
    cout << "\nd6 = "; engldisp(d6);    // вывод новых значений d6 и d7
    cout << "\nd7 = "; engldisp(d7);
    cout << endl;

    starline();

    // factor2.cpp  подсчет факториала числа с помощью рекурсии
    int n;  // число, вводимое пользователем
    unsigned long fact;     // факториал этого числа
    n = 5;
    fact = factfunc(n);
    cout << "Факториал числа " << n << "равен " << fact << endl;

    starline();

    float lbsIn;
    lbsIn = 18.8;
    cout << " " << lbstokgInline(lbsIn) << endl;

    return 0;
}

//-------------- определение функции starline()
void starline() {       // заголовок функции
    for(int j = 0; j < 45; j++) // тело функции
        cout << '*';
    cout << endl;
}

//---функция repchar()-----------------------------
// выводит на экран 45 символов '*'
void repchar() {
    for(int j = 0; j < 45; j++) // цикл, выполняющийся 45 раз
        cout << '*';            // вывод символа '*'
    cout << endl;
}

//--- функция repchar(char ch)-----------------------------
// выводит 45 заданных символов
void repchar(char ch) {
    for(int j = 0; j < 45; j++) // цикл, выполняющийся 45 раз
        cout << ch;             // вывод заданного символа
    cout << endl;
}

// определение функции repchar(char chars, int number)
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
// engldisp()   вывод переменной типа float в футах и дюймах
void engldisp(float dd) {   // параметр dd типа float
    int feet = static_cast<int>(dd / 12);
    float inches = dd - feet * 12;
    cout << feet << "\'-" << inches << "\"";
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

//--------------------------------------------------------
// reforder.cpp     упорядочивает по возрастанию пары чисел
void order(int& numb1, int& numb2)  // упорядочивает два числа
{
    if(numb1 > numb2) { // если первое число больше второго.
        int temp = numb1;   // то меняем их местами
        numb1 = numb2;
    numb2 = temp;
    }
}

//-- функция scale()---масштабирование значения типа Distance ---------------
void scale(Distance& dd, float factor) {
    float inches = (dd.feet*12 + dd.inches)*factor; // перевод футов в дюймы и
    dd.feet = static_cast<int>(inches / 12);
    dd.inches = inches - dd.feet * 12;          // и умножение на коэффициент
}

//---------------- функция factfunc()-------- рекурсивно подсчитывает факториал числа
unsigned long factfunc(unsigned long n) {
    if(n > 1)
        return n * factfunc(n - 1);     // вызов самой себя
    else
        return 1;
}