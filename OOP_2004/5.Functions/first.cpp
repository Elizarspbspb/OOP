#include <iostream>

using namespace std;

void starline_2() {       // заголовок функции
    for(int j = 0; j < 45; j++) // тело функции
        cout << '*';
    cout << endl;
}
void starline();            // объявление функции (прототип) (описатель)

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

char globalCh = 'a';  // глобальная переменная ch

static char globalStaticCh = 'g';  // глобальная переменная ch

// Статические локальные перменные
float getavg(float);    // прототип функции

// retref.cpp   возвращение значения по ссылке
int globalX;          // глобальная переменная
int& setglobalX();    // прототип ссылочной функции

// constarg.cpp
// демонстрирует константные аргументы функций
void aFunc(int& a, const int& b);   // прототип функции

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

    starline();     // вызов функции

    // convert.cpp
    // демонстрирует механизм возврата значения функцией
    float lbs, kgs;
    lbs = 10.2;
    kgs = lbstokg(lbs);
    cout << "Вес в килограммах равен " << kgs << endl;

    starline();     // вызов функции

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

    starline();     // вызов функции

    // ref.cpp
    // применение ссылочного механизма передачи аргументов
    void intfrac(float, float&, float&);    // прототип
    float number, intpart, fracpart;
    number = 10.56;
    intfrac(number, intpart, fracpart);     // нахождение целой и дробной части
    cout << "Целая часть равна " << intpart // вывод результатов
    << ", дробная часть равна " << fracpart << endl;

    starline();     // вызов функции

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

    starline();     // вызов функции

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

    starline();     // вызов функции

    // factor2.cpp  подсчет факториала числа с помощью рекурсии
    int n;  // число, вводимое пользователем
    unsigned long fact;     // факториал этого числа
    n = 5;
    fact = factfunc(n);
    cout << "Факториал числа " << n << "равен " << fact << endl;

    starline();     // вызов функции

    float lbsIn;
    lbsIn = 18.8;
    cout << " " << lbstokgInline(lbsIn) << endl;

    cout << "globalCh = " << globalCh << endl;                      // a
    globalCh = 'b';
    cout << "globalCh after = " << globalCh << endl;                // b

    cout << "globalStaticCh = " << globalStaticCh << endl;          // g
    globalStaticCh = 'b';
    cout << "globalStaticCh after = " << globalStaticCh << endl;    // b

    // Статические локальные перменные
    float data = 10, avg;
    while(data != 40) {
        avg = getavg(data);
        cout << "Число: " << data << endl;  // 10, 20, 30
        cout << "Среднее значение: " << avg << endl;    // 10, 15, 30
        data += 10;
    }

    setglobalX() = 92;    // присваивание значения x при помощи вызова функции слева
    cout << "globalX = " << globalX << endl; // вывод нового значения x

    int alpha = 7;
    int beta = 11;
    aFunc(alpha, beta); // вызов функции

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
void repchar() {        // определение функции
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
float lbstokg(float pounds) {   // определение функции
    float kilograms = 0.453592 * pounds;
    return kilograms;
}

// демонстрирует возвращение функцией структурной переменной
Distance addengl(Distance dd1, Distance dd2) // определение функции
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
void scale(Distance& dd, float factor) {    // определение функции
    float inches = (dd.feet*12 + dd.inches)*factor; // перевод футов в дюймы и
    dd.feet = static_cast<int>(inches / 12);
    dd.inches = inches - dd.feet * 12;          // и умножение на коэффициент
}

//---------------- функция factfunc()-------- рекурсивно подсчитывает факториал числа
unsigned long factfunc(unsigned long n) {   // определение функции
    if(n > 1)
        return n * factfunc(n - 1);     // вызов самой себя
    else
        return 1;
}

// Статические локальные перменные
// функция getavg() находит среднее арифметическое всех введенных значений
float getavg(float newdata) {   // определение функции
    static float total = 0;     // инициализация статических переменных при первом вызове
    static int count = 0;       // при static обнуление не произойдет
    //float total = 0;            // 0 всегда
    //int count = 0;
    count++;                    // увеличение счетчика
    total += newdata;           // добавление нового значения к сумме
    return total / count;       // возврат нового среднего значения
}

//--------------------------------------------------------
int& setglobalX() {     // определение функции
    return globalX;     // возвращает значение, которое будет изменено
}

//int& setglobalX() {   
//    return 3;     // ERROR
// ----------------------
//    int x = 3;
//    return x;   // ошибка, так как локальная переменная не сущетсвует за пределами функции
//}

//--------------------------------------------------------
void aFunc(int& a, const int& b) {  // определение функции
    a = 107;    // корректно
    //b = 111;    // ошибка при попытке изменить константный аргумент
}