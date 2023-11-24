#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
#include <stdlib.h>     // для функции exit

using namespace std;

// Task 1
class Distance {    // класс английских мер длины
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }   // конструктор без параметров
    Distance(int ft, float in) : feet(ft), inches(in) { }   // конструктор с двумя параметрами
    void setdist() { // получение информации от пользователя
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() { // показ информации
        cout << feet << "\'-" << inches << '\"'; 
    }
    Distance operator+(Distance) const; // сложение двух длин
    Distance operator-(Distance) const; // сложение двух длин
};
Distance Distance::operator+(Distance d2) const {
    int f = feet + d2.feet;         // складываем футы
    float i = inches + d2.inches;   // складываем дюймы
    if(i >= 12.0) {         // если дюймов стало больше 12
        i -= 12.0;          // то уменьшаем дюймы на 12
        f++;                // и увеличиваем футы на 1
    }
    return Distance(f, i);  // создаем и возвращаем временную переменную
}
Distance Distance::operator-(Distance d2) const {
    int f = feet - d2.feet;         // вычитаем футы
    float i;
    if(d2.inches > inches) {         // если дюймов стало больше 12
        i = d2.inches - inches;   // вычитаем дюймы
        i -= 12.0;          // то уменьшаем дюймы на 12
        --f;                // и увеличиваем футы на 1
    } else 
        i = inches - d2.inches;   // вычитаем дюймы
    return Distance(f, i);  // создаем и возвращаем временную переменную
}

///////////////////////////////////////////////////////////

// Task 2
class String { // наш класс для строк
private:
    enum { SZ = 80 };   // максимальный размер строки
    char str[SZ];       // массив для строки
public:
    String() { strcpy(str, ""); }           // конструктор без параметров
    String(char s[]) { strcpy(str, s); }    // конструктор с одним параметром
    void display() const { cout << str << endl; }
    String operator+=(String);          // s3 = s1 += s2;
    //void operator+=(String);        // s1 += s2;
    void getdist() {    // получение строки
        cin.get(str, SZ); 
    }
    bool operator==(String ss) const {      // оператор сравнения
        return (strcmp(str, ss.str) == 0) ? true : false;
    }
};
String String::operator+=(String ss) {      // s3 = s1 += s2;
    if(strlen(str) + strlen(ss.str) >= SZ) {   
        cout << "\nПереполнение!";
        exit(1);
    }
    strcat(str, ss.str);   // добавляем содержимое второй строки
    return String(str);
}
/*void String::operator+=(String ss) {    // s1 += s2;
    if(strlen(str) + strlen(ss.str) >= SZ) {   
        cout << "\nПереполнение!";
        exit(1);
    }
    strcat(str, ss.str);   // добавляем содержимое второй строки
}*/

//Task 3
class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {};
    Time(int hour, int minut, int sec) : hours(hour), minutes(minut), seconds(sec) {};
    void showTime() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    //void sum(const Time&, const Time&);
    Time operator+(Time) const;
    ~Time() = default;
    // Task 5
    Time operator++();
    Time operator++(int);
    Time operator--();
    Time operator--(int);
    // Task 6
    Time operator-(Time) const;
    Time operator*(Time) const;
};
Time Time::operator+(Time one) const {
    unsigned long allSecsOne = one.hours * 3600 + one.minutes * 60 + one.seconds;
    unsigned long allSecsTwo = hours * 3600 + minutes * 60 + seconds;
    allSecsOne += allSecsTwo;
    int hours = allSecsOne/3600;
    int minutes = (allSecsOne - (hours * 3600))/60;
    int seconds = allSecsOne - (hours * 3600) - (minutes * 60);
    return Time(hours, minutes, seconds);
}
// Task 5
Time Time::operator++() {
    ++hours;
    ++minutes;
    ++seconds;
    return Time(hours, minutes, seconds);
}
Time Time::operator++(int) {
    return Time(hours++, minutes++, seconds++);
}
Time Time::operator--() {
    --hours;
    --minutes;
    --seconds;
    return Time(hours, minutes, seconds);
}
Time Time::operator--(int) {
    return Time(hours--, minutes--, seconds--);
}
// Task 6
Time Time::operator-(Time one) const {
    unsigned long allSecsOne = one.hours * 3600 + one.minutes * 60 + one.seconds;
    unsigned long allSecsTwo = hours * 3600 + minutes * 60 + seconds;
    allSecsOne = allSecsTwo - allSecsOne;
    int hours = allSecsOne/3600;
    int minutes = (allSecsOne - (hours * 3600))/60;
    int seconds = allSecsOne - (hours * 3600) - (minutes * 60);
    return Time(hours, minutes, seconds);
}
Time Time::operator*(Time one) const {
    int sec = seconds * one.seconds;
    int min = minutes * one.minutes;
    int hou = hours * one.hours;
    while (sec > 59) {
        sec -= 60;
        min++; 
    }
    while (min > 59) { 
        min -= 60; 
        hou++; 
    }
    return Time(hou, min, sec); // вернуть временное значение
}

// Task 4
class Int {
    int value;
public:
    Int() : value(0) {};                // конструктор значение = нулю
    Int(int number) : value(number) {}; // метод установки целого значения
    void showValue() const {            // метод вывода значения
        cout << "Значение поля = " << value << endl; 
    }
    Int operator+(Int);
    Int operator-(Int);
    Int operator*(Int);
    Int operator/(Int);
    Int checkit(long double);
};
Int Int::operator+(Int two) {
    long double valueNew = value + two.value;
    return checkit(valueNew);
} 
Int Int::operator-(Int two) {
    long double valueNew = value - two.value;
    return checkit(valueNew);
} 
Int Int::operator*(Int two) {
    long double valueNew = value * two.value;
    return checkit(valueNew);
} 
Int Int::operator/(Int two) {
    long double valueNew = value / two.value;
    return checkit(valueNew);
} 
Int Int::checkit(long double answer) {      // проверка результатов
    if (answer > 2147483648.0L || answer <-2147483648.0L) { 
        cout << "\nОшибка переполнения\n ";
        exit(1); 
    }
    return Int(int(answer));
}

// Task 7
class fraction {
    int dividend;
    int divisor;
    char symb;
public:
    fraction() { dividend = 0; divisor = 0; symb = '/'; }
    fraction(int divid, int divis) : dividend(divid), divisor(divis) {};
    void enterFr() {
        cin >> dividend >> symb >> divisor;
    }
    void showFr() const {
        cout << dividend << "/" << divisor << endl;
    }
    fraction operator+(fraction);
    fraction operator-(fraction);
    fraction operator*(fraction);
    fraction operator/(fraction);
    void lowterms();
};
fraction fraction::operator+(fraction second) {
    int dividend2 = dividend * second.divisor + divisor * second.dividend;
    int divisor2 = divisor * second.divisor;
    return fraction(dividend2, divisor2);         
}
fraction fraction::operator-(fraction second) {        
    int dividend2 = dividend * second.divisor - divisor * second.dividend;
    int divisor2 = divisor * second.divisor; 
    return fraction(dividend2, divisor2);               
}
fraction fraction::operator*(fraction second) {
    int dividend2 = dividend * second.dividend;
    int divisor2 = divisor * second.divisor; 
    return fraction(dividend2, divisor2);               
}
fraction fraction::operator/(fraction second) {
    int dividend2 = dividend * second.divisor;
    int divisor2 = divisor * second.dividend;
    return fraction(dividend2, divisor2);               
}
void fraction::lowterms() {         // сокращение дроби
    long tnum, tden, temp, gcd;
    tnum = labs(dividend);          // используем неотрицательные значения (нужен cmath)
    tden = labs(divisor);
    if(tden == 0)               // проверка знаменателя на 0
        { cout << "Недопустимый знаменатель!"; exit(1); }
    else if(tnum == 0)      // проверка числителя на 0
        { dividend = 0; divisor = 1; return; }
    while(tnum != 0) {      // нахождение наибольшего общего делителя
        if(tnum < tden)     // если числитель больше знаменателя,
            { temp = tnum; tnum = tden; tden = temp; }      // меняем их местами
        tnum = tnum - tden;     // вычитание
    }
    gcd = tden;
    dividend = dividend / gcd; // делим числитель и знаменатель на полученный наибольший общий делитель
    divisor = divisor / gcd;
}

int main(int argc, char* argv[]) 
{
    /*1. Добавьте в класс Distance из программы ENGLPLUS этой главы перегруженную операцию -, которая 
    вычисляет разность двух интервалов. Она должна позволять выполнение выражений типа 
    dist3 = dist1-dist2;. Предполагаем, что эта операция никогда не будет использоваться для вычитания
    большего интервала из меньшего (так как отрицательного интервала быть не может). */
    /*Distance dist3;
    Distance dist1(15, 6.25);
    Distance dist2(11, 7.25);
    dist3 = dist1 - dist2;          
    cout << "\ndist1 ="; dist1.showdist();
    cout << "\ndist2 ="; dist2.showdist();
    cout << "\ndist3 ="; dist3.showdist(); */

    /*2. Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в 
    программе STRPLUS этой главы. Эта операция должна позволять записывать выражения типа: s1 += s2;
    где s2 прибавляется (объединяется) к строке s1, результат при этом остается в s1. Операция должна 
    также позволять использовать результат для других вычислений, например в выражениях типа s3 = s1 += s2; */
    /*String s1 = "\nС Рождеством! ";
    String s2 = "С Новым годом!";
    String s3;
    s1.display();
    s2.display();
    s3.display();
    s3 = s1 += s2;
    //s1 += s2;     
    s1.display();
    s3.display(); */

    /*3. Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо метода add_time() можно было
    использовать операцию + для складывания двух значений времени. Напишите программу для проверки класса.*/
    /*Time one(10, 30, 45);
    Time two(6, 20, 5);
    Time three;
    three = one + two;
    one.showTime();
    two.showTime();
    three.showTime(); */

    /*4. Создайте класс Int, основанный на упражнении 1 из главы 6. Перегрузите четыре целочисленных 
    арифметических операции (+, -, * и /) так, чтобы их можно было использовать для операций с объектами
    класса Int. Если результат какой-либо из операций выходит за границы типа int (в 32-битной системе),
    имеющие значение от 2 147 483 648 до -2 147 483 648, то операция должна послать сообщение об ошибке
    и завершить программу. Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим 
    переполнением, которое недопустимо. Подсказка: для облегчения проверки переполнения выполняйте 
    вычисления с использованием типа long double. Напишите программу для проверки этого класса. */
    /*Int one(1200);
    Int two(60);
    Int three;
    three = one + two;
    one.showValue();
    two.showValue();
    three.showValue();
    three = one - two;
    three.showValue();
    three = one * two;
    three.showValue();
    three = one / two;
    three.showValue(); */

    /*5. Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) 
    и уменьшения (--), которые работают в обеих, префиксной и постфиксной, формах записи и возвращают 
    значение. Дополните функцию main(), чтобы протестировать эти операции. */
    /*Time inc(10, 10, 10);
    inc.showTime();     // 10 10 10
    inc++;
    inc.showTime();     // 11 11 11
    --inc;
    inc.showTime();     // 10 10 10
    ++inc;
    inc.showTime();     // 11 11 11
    inc--;
    inc.showTime();     // 10 10 10     */

    /*6. Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя 
    перегруженную операцию -, и умножать эти значения, используя тип float и перегруженную операцию *. */
    /*Time SixOne(10, 10, 10);
    Time SixTwo(2, 5, 4);
    Time SixThree;
    SixThree = SixOne - SixTwo;
    SixOne.showTime(); 
    cout << endl;
    SixTwo.showTime(); 
    cout << endl;
    SixThree.showTime(); 
    SixThree = SixOne * SixTwo;
    SixThree.showTime(); 
    cout << endl; */

    /*7. Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 главы 6
    так, чтобы он использовал перегруженные операции сложения, вычитания, умножения и деления. (Вспомните 
    правила арифметики с дробями в упражнении 12 главы 3 «Циклы и ветвления».) Также перегрузите операции 
    сравнения == и != и используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения
    двух частей дроби. Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее 
    аргумента, уменьшенное до несократимой дроби. Это будет полезным в арифметических функциях, которые 
    могут быть выполнены сразу после получения ответа. */
    /*fraction first7(2, 6);
    fraction second7(1, 3);
    fraction third(0, 0);
    third = first7 + second7; 
    third.lowterms();
    first7.showFr();
    second7.showFr();
    third.showFr(); */

    /*8. Модифицируйте класс bMoney из упражнения 12 главы 7 «Массивы и строки», включив арифметические 
    операции, выполненные с помощью перегруженных операций:
        bMoney = bMoney + bMoney
        bMoney = bMoney - bMoney
        bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие)
        long double = bMoney / bMoney (общая цена, деленная на цену за изделие)
        bMoney = bMoney / long double (общая цена, деленная на количество изделий).
    Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их аргументы разные. Помним, что легче вы-
полнять арифметические операции с объектами класса bMoney, выполняя
те же операции с его long double данными.
Убедитесь, что программа main() запросит ввод пользователем двух де-
нежных строк и числа с плавающей точкой. Затем она выполнит все пять
операций и выведет результаты. Это должно происходить в цикле, так,
чтобы пользователь мог ввести еще числа, если это понадобится.
Некоторые операции с деньгами не имеют смысла: bMoney*bMoney не пред-
ставляет ничего реального, так как нет такой вещи, как денежный квад-
рат; вы не можете прибавить bMoney к long double (что же будет, если рубли
сложить с изделиями?). Чтобы сделать это невозможным, скомпилируйте
такие неправильные операции, не включая операции преобразования для
bMoney в long double или long double в bMoney. Если вы это сделаете и запи-
шете затем выражение типа:
bmon2 = bmon1 + widgets; // это не имеет смысла
то компилятор будет автоматически преобразовывать widgets в bMoney и
выполнять сложение. Без них компилятор будет отмечать такие преобра-
зования как ошибки, что позволит легче найти концептуальные ошибки.
Также сделайте конструкторы преобразований явными.
Вот некоторые другие вероятные операции с деньгами, которые мы еще
не умеем выполнять с помощью перегруженных операций, так как они
требуют объекта справа от знака операции, а не слева:
long double * bMoney // Пока не можем это сделать: bMoney возможен только справа
long double / bMoney // Пока не можем это сделать: bMoney возможен только справа
Мы рассмотрим выход из этой ситуации при изучении дружественных
функций в главе 11.
*/

    return 0;
}