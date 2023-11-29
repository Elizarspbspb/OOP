#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
#include <stdlib.h>     // для функции exit
#include <strstream>    // Task 8
#include <math.h>        // Task 10

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
    void lowterms();
    // Task 7
    fraction operator+(fraction);
    fraction operator-(fraction);
    fraction operator*(fraction);
    fraction operator/(fraction);
};
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

// Task 8
const int MAXSTR = 100;     // максимальная длина строки
class bMoney {
    long double money;
    char streams[MAXSTR] = "$";
    string strFrom;
public:
    bMoney();
    bMoney(char s[]);
    //bMoney(long double); // конструктор преобразования long double в bMoney 
    explicit bMoney(long double); // explicit - запрет скрытого преобразования типов данных long double в bMoney 
    void putmoney();
    void getmoney();
    long double mstold(string);
    char ldtoms(long double);
    bMoney operator+(bMoney);           // bMoney = bMoney + bMoney
    bMoney operator-(bMoney);           // bMoney = bMoney - bMoney
    bMoney operator*(long double);      // bМоnеу = bMoney * long double
    long double operator/(bMoney);      // long double = bMoney / bMoney
    bMoney operator/(long double);      // bMoney = bMoney / long double
    // Task 12
    long double getParam() const {
        return money;
    }
};
bMoney::bMoney() : money(0) {}
bMoney::bMoney(char s[]) : money(0) {}
bMoney::bMoney(long double mon) : money(mon) {} // неявный конструктор преобразования long double в bMoney
/*bMoney::bMoney(long double mon) {             // явный конструктор преобразования long double в bMoney
    money = static_cast<int>(mon);
}*/
void bMoney::putmoney() {
    cout << "Введите строку с числом " << endl;
    cin >> strFrom;
    mstold(strFrom);
}
long double bMoney::mstold(string strTo) {
    long double mon = 0.0;
    for (int size = 0, sizeTwo = 0; size < strFrom.length(); size++) {
        if (strFrom[size] >= 48 && strFrom[size] <= 57) {
            strTo[sizeTwo++] = strFrom[size];
        } else if (strFrom[size] == '.') {
            strTo[sizeTwo++] = strFrom[size];
        }
    }
    mon = stold(strTo); // mon = _atold(strTo);
    // Task 12
    money = mon;
    return mon;
}
void bMoney::getmoney() {
    cout << ldtoms(money) << streams << endl;
}
char bMoney::ldtoms(long double doubleFrom) {
    if (doubleFrom > 9999999999999990.00)
        return *"Very big number !";
    ostrstream ustring;
    ustring << doubleFrom;
    string len = ustring.str();
    for (int i = 0; i < len.length(); i++)
        streams[i+1] = ustring.str()[i];
    return *streams;    
}
bMoney bMoney::operator+(bMoney two) {
    bMoney three;
    three.money = money + two.money;
    return three;
}
bMoney bMoney::operator-(bMoney two) {
    bMoney three;
    three.money = money - two.money;
    return three;
}
bMoney bMoney::operator*(long double time) {
    bMoney three;
    three.money = money * time;
    return three;
}
long double bMoney::operator/(bMoney two) {
    long double count;
    count = money / two.money;
    return count;
}
bMoney bMoney::operator/(long double two) {
    bMoney three;
    three.money = money / two;
    return three;
}


// Task 9
const int LIMIT = 100;  // размер массива
class safearray {
private:
    int up;
    int lower;
    int dif;
    int arr[LIMIT];
public:
    safearray() = default;
    safearray(int u, int l) : up(u), lower(l) { }
    int& operator[](int n) {
        n = n - dif;
        if (n < 0 || n >= LIMIT) { 
            cout << "\nОшибочный индекс!"; 
            exit(1); 
        }
        return arr[n];
    }
};

// Task 10
class Polar {
private:
    int radius;
    int angle;
public:
    Polar() = default;
    Polar(int ra, int an) : radius(ra), angle(an) {};
    Polar operator+(Polar);
    void show() const {
        cout << radius << " - " << angle << endl;
    }
};
Polar Polar::operator+(Polar two) {
    float x1 = radius * cos(angle); 
    float y1 = radius * sin(angle);
    float x2 = two.radius * cos(two.angle); 
    float y2 = two.radius * sin(two.angle);
    float x3 = x1 + x2; 
    float y3 = y1 + y2;

    Polar newPolar;
    newPolar.radius = sqrt(x3*x3 + y3*y3);
    newPolar.angle = atan(y3 / x3);
    return newPolar;
}

// Task 11
class sterling {
    long pounds;
    int shillings, pence;
    double newMoney;
public:
    sterling() = default;
    sterling(double newMon) : newMoney(newMon) {}
    sterling(long po, int sh, int pe) : pounds(po), shillings(sh), pence(pe) {}
    long getNewMoney(long, int, int);
    sterling getAldMoney(double);
    void getSterling();
    void putSterling() const;
    sterling operator+(sterling);
    sterling operator-(sterling);
    sterling operator*(double);
    sterling operator/(sterling);
    sterling operator/(double);
    operator double() const {  
        return pounds + (static_cast<double>(12 * shillings + pence) / 240);    // 240 - 12 * 20.  
    }
    // Task 12
    operator bMoney();      // 1
    sterling(bMoney);       // 2
};
long sterling::getNewMoney(long pounds, int shillings, int pence) {
    return pounds + (static_cast<double>(12 * shillings + pence) / 240);    // 240 - 12 * 20.  
}
/*sterling sterling::operator+(sterling s2) {
            return sterling(double(sterling(pounds, shillings, pense)) + double(s2));
}*/
sterling sterling::getAldMoney(double newMoney) {
    long poundsNew = static_cast<int>(newMoney);
    double decfrac = newMoney - poundsNew;  // десятичная дробная часть
    decfrac *= 240;
    int shil, pens;
    shil = static_cast<int>(decfrac) / 12;
    pens = static_cast<int>(decfrac) % 12;
    // Task 12
    pounds = poundsNew;
    shillings = shil;
    pence = pens;
    return sterling(pounds, shil, pens);
}
sterling sterling::operator+(sterling one) {
    sterling sumMoney;
    sumMoney.pence = pence + one.pence;
    if (sumMoney.pence > 11) {
        while (sumMoney.pence >= 12) {
            sumMoney.pence -= 12;
            one.shillings++;
        }
    }
    sumMoney.shillings = shillings + one.shillings;
    if (sumMoney.shillings > 19) {
        while (sumMoney.shillings >= 20) {
            sumMoney.shillings -= 20;
            one.pounds++;
        }
    }
    sumMoney.pounds = pounds + one.pounds;
    return sumMoney;
}
sterling sterling::operator-(sterling one) {
    sterling difMoney;
    difMoney.pence = pence;
    difMoney.shillings = shillings;
    difMoney.pounds = pounds;
    if (one.pence > difMoney.pence) {
        while (difMoney.pence <= one.pence) {
            difMoney.pence += 12;
            --difMoney.shillings;
        }
    }
    difMoney.pence -= one.pence;
    if (one.shillings > difMoney.shillings) {
        while (difMoney.shillings <= one.shillings) {
            difMoney.shillings += 20;
            --difMoney.pounds;
        }
    }
    difMoney.shillings -= one.shillings;
    difMoney.pounds -= one.pounds;
    return difMoney;
}
sterling sterling::operator*(double one) {
    double um = getNewMoney(pounds, shillings, pence);
    um *= one;
    return getAldMoney(um);
}
sterling sterling::operator/(sterling one) {
    double del1 = getNewMoney(pounds, shillings, pence);
    double del2 = getNewMoney(one.pounds, one.shillings, one.pence);
    del1 /= del2;
    return getAldMoney(del1);
}
sterling sterling::operator/(double one) {
    double um = getNewMoney(pounds, shillings, pence);
    um /= one;
    return getAldMoney(um);
}
void sterling::getSterling() {
    cout << "Введите количество фунтов: ";
    cin >> pounds;
    cout << "Введите количество шиллингов: ";
    cin >> shillings;
    cout << "Введите количество пенсов: ";
    cin >> pence;
}
void sterling::putSterling() const {
    cout << " £" << pounds << " " << shillings << " " << pence << endl;
}
// Task 12
sterling::operator bMoney() {               // оператор преобразования 1
    double newModel = getNewMoney(pounds, shillings, pence);
    newModel *= 50.0;
    return bMoney(newModel);
}
sterling::sterling(bMoney one) {               // конструктор преобразования 2
    newMoney = one.getParam();
    newMoney /= 50.0;
    cout << newMoney << endl;
    getAldMoney(newMoney);
}

int main(int argc, char* argv[]) 
{
    /*1. Добавьте в класс Distance из программы ENGLPLUS этой главы перегруженную операцию -, которая 
    вычисляет разность двух интервалов. Она должна позволять выполнение выражений типа 
    dist3 = dist1-dist2;. Предполагаем, что эта операция никогда не будет использоваться для вычитания
    большего интервала из меньшего (так как отрицательного интервала быть не может). */
    Distance dist3;
    Distance dist1(15, 6.25);
    Distance dist2(11, 7.25);
    dist3 = dist1 - dist2;          
    cout << "\ndist1 ="; dist1.showdist();
    cout << "\ndist2 ="; dist2.showdist();
    cout << "\ndist3 ="; dist3.showdist();

    /*2. Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в 
    программе STRPLUS этой главы. Эта операция должна позволять записывать выражения типа: s1 += s2;
    где s2 прибавляется (объединяется) к строке s1, результат при этом остается в s1. Операция должна 
    также позволять использовать результат для других вычислений, например в выражениях типа s3 = s1 += s2; */
    String s1 = "\nС Рождеством! ";
    String s2 = "С Новым годом!";
    String s3;
    s1.display();
    s2.display();
    s3.display();
    s3 = s1 += s2;
    //s1 += s2;     
    s1.display();
    s3.display();

    /*3. Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо метода add_time() можно было
    использовать операцию + для складывания двух значений времени. Напишите программу для проверки класса.*/
    Time one(10, 30, 45);
    Time two(6, 20, 5);
    Time three;
    three = one + two;
    one.showTime();
    two.showTime();
    three.showTime();

    /*4. Создайте класс Int, основанный на упражнении 1 из главы 6. Перегрузите четыре целочисленных 
    арифметических операции (+, -, * и /) так, чтобы их можно было использовать для операций с объектами
    класса Int. Если результат какой-либо из операций выходит за границы типа int (в 32-битной системе),
    имеющие значение от 2 147 483 648 до -2 147 483 648, то операция должна послать сообщение об ошибке
    и завершить программу. Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим 
    переполнением, которое недопустимо. Подсказка: для облегчения проверки переполнения выполняйте 
    вычисления с использованием типа long double. Напишите программу для проверки этого класса. */
    Int one4(1200);
    Int two4(60);
    Int three4;
    three4 = one4 + two4;
    one4.showValue();
    two4.showValue();
    three4.showValue();
    three4 = one4 - two4;
    three4.showValue();
    three4 = one4 * two4;
    three4.showValue();
    three4 = one4 / two4;
    three4.showValue();

    /*5. Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) 
    и уменьшения (--), которые работают в обеих, префиксной и постфиксной, формах записи и возвращают 
    значение. Дополните функцию main(), чтобы протестировать эти операции. */
    Time inc(10, 10, 10);
    inc.showTime();     // 10 10 10
    inc++;
    inc.showTime();     // 11 11 11
    --inc;
    inc.showTime();     // 10 10 10
    ++inc;
    inc.showTime();     // 11 11 11
    inc--;
    inc.showTime();     // 10 10 10     

    /*6. Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя 
    перегруженную операцию -, и умножать эти значения, используя тип float и перегруженную операцию *. */
    Time SixOne(10, 10, 10);
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
    cout << endl;

    /*7. Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 главы 6
    так, чтобы он использовал перегруженные операции сложения, вычитания, умножения и деления. (Вспомните 
    правила арифметики с дробями в упражнении 12 главы 3 «Циклы и ветвления».) Также перегрузите операции 
    сравнения == и != и используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения
    двух частей дроби. Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее 
    аргумента, уменьшенное до несократимой дроби. Это будет полезным в арифметических функциях, которые 
    могут быть выполнены сразу после получения ответа. */
    fraction first7(2, 6);
    fraction second7(1, 3);
    fraction third(0, 0);
    third = first7 + second7; 
    third.lowterms();
    first7.showFr();
    second7.showFr();
    third.showFr();

    /*8. Модифицируйте класс bMoney из упражнения 12 главы 7 «Массивы и строки», включив арифметические 
    операции, выполненные с помощью перегруженных операций:
        bMoney = bMoney + bMoney
        bMoney = bMoney - bMoney
        bМоnеу = bMoney * long double (цена за единицу времени, затраченного на изделие)
        long double = bMoney / bMoney (общая цена, деленная на цену за изделие)
        bMoney = bMoney / long double (общая цена, деленная на количество изделий).
    Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их 
    аргументы разные. Помним, что легче выполнять арифметические операции с объектами класса bMoney, 
    выполняя те же операции с его long double данными. Убедитесь, что программа main() запросит ввод 
    пользователем двух денежных строк и числа с плавающей точкой. Затем она выполнит все пять операций 
    и выведет результаты. Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, 
    если это понадобится. Некоторые операции с деньгами не имеют смысла: bMoney*bMoney не представляет 
    ничего реального, так как нет такой вещи, как денежный квадрат; вы не можете прибавить bMoney к long 
    double (что же будет, если рубли сложить с изделиями?). Чтобы сделать это невозможным, скомпилируйте
    такие неправильные операции, не включая операции преобразования для bMoney в long double или long 
    double в bMoney. Если вы это сделаете и запишете затем выражение типа:
        bmon2 = bmon1 + widgets; // это не имеет смысла
    то компилятор будет автоматически преобразовывать widgets в bMoney и выполнять сложение. Без них 
    компилятор будет отмечать такие преобразования как ошибки, что позволит легче найти концептуальные 
    ошибки. Также сделайте конструкторы преобразований явными. Вот некоторые другие вероятные операции с 
    деньгами, которые мы еще не умеем выполнять с помощью перегруженных операций, так как они требуют 
    объекта справа от знака операции, а не слева: 
    long double * bMoney // Пока не можем это сделать: bMoney возможен только справа
    long double / bMoney // Пока не можем это сделать: bMoney возможен только справа
    Мы рассмотрим выход из этой ситуации при изучении дружественных функций в главе 11. */
    bMoney one8, two8, three8;
    char contin = 'y';
    do {
        one8.putmoney();
        two8.putmoney();
        one8.getmoney();
        two8.getmoney();
            three8 = one8 + two8;
        cout << "Сумма = ";
        three8.getmoney();
            three8 = one8 - two8;
        cout << "Разница = ";
        three8.getmoney();
            three8 = one8 * 13.5;
        cout << "Цена за единицу времени, затраченного на изделие = ";
        three8.getmoney();
            cout << "Общая цена, деленная на цену за изделие = " << one8 / two8 << endl;
            three8 = one8 / 13.5;
        cout << "Общая цена, деленная на количество изделий = ";
        three8.getmoney();
        //three = one + 10; // Error если нет конструктора с параметром long double
        three8.getmoney();
        cout << "Добавить еще сотрудника (y or n) ? : ";
        cin >> contin;
    } while(contin != 'n');

    /*9. Дополните класс safearay из программы ARROVER3 этой главы так, чтобы пользователь мог определять
    и верхнюю, и нижнюю границы массива (например, индексы, начинающиеся с 100 и заканчивающиеся 200). 
    Имеем перегруженную операцию доступа к членам массива, проверяющую индексы каждый раз, когда к массиву
    нужен доступ, для проверки того, что мы не вышли за пределы массива. Вам понадобится конструктор с 
    двумя аргументами, который определяет верхнюю и нижнюю границы. Так как мы еще не изучили, как выделять
    память динамически, то данные класса все еще будут размещаться в массиве, состоящем из 100 элементов, 
    но вообще вы можете преобразовывать индексы массива safearay в индексы реального массива целых чисел 
    произвольным образом. Например, если пользователь определил диапазон от 100 до 175, то вы можете 
    преобразовать его в диапазон от arr[0] до arr[75]. */
    int up, lower;
    cout << "Введите нижнюю границу массива: ";
    cin >> lower;
    cout << "Введите верхнюю границу массива: "; 
    cin >> up;
    safearray sa1(up, lower);
    for(int j = 0; j < LIMIT; j++)
        sa1[j] = j * 10;
    for(int j = 0; j < LIMIT; j++) {
        int temp = sa1[j];
        cout << "Элемент " << j << " равен " << temp << endl;
    }

    /*10. Только для любителей математики: создайте класс Polar, который предназначен для хранения 
    полярных координат (радиуса и угла). Перегрузите операцию + для выполнения сложения для объектов 
    класса Polar. Сложение двух объектов выполняется путем сложения координат X объектов, а затем 
    координат Y. Результат будет координатами новой точки. Таким образом, вам нужно будет преобразовать 
    полярные координаты к прямоугольным, сложить их, а затем обратно преобразовать прямоугольные 
    координаты результата к полярным. */
    Polar al(5, 30);
    Polar al2(10, 15);
    Polar al3;
    al3 = al + al2;
    al3.show();

    /*11. Помните структуру sterling? Мы встречались с ней в упражнении 10 главы 2 «Основы программирования
    на C++», в упражнении 11 главы 5 и в других местах. Преобразуйте ее в класс, имеющий переменные для 
    фунтов (типа long), шиллингов (типа int) и пенсов (типа int). Создайте в классе следующие функции:
        ♦ конструктор без аргументов;
        ♦ конструктор с одним аргументом типа double (для преобразования от десятичных фунтов);    
        ♦ конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
        ♦ метод getSterling() для получения от пользователя значений количества фунтов, шиллингов и 
        пенсов в формате £9.19.11;
        ♦ метод putSterling() для вывода значений количества фунтов, шиллингов и пенсов в формате £9.19.11;
        ♦ метод для сложения (sterling + sterling), используя перегруженную операцию +;
        ♦ метод вычитания (sterling - sterling), используя перегруженную операцию -;
        ♦ метод умножения (sterling * double), используя перегруженную операцию *;
        ♦ метод деления (sterling / sterling), используя перегруженную операцию /;
        ♦ метод деления (sterling / double), используя перегруженную операцию /;
        ♦ операцию double (для преобразования к типу double)
    Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, 
    затем шиллинги и т. д. Однако легче использовать операцию преобразования для преобразования объекта 
    класса sterling к типу double, выполнить вычисления с типами double, а затем преобразовать обратно к 
    типу sterling. Таким образом, операция + выглядит похожей на эту:
        sterling sterling::operator+(sterling s2) {
            return sterling(double(sterling(pounds, shillings, pense)) + double(s2));
        }
    Так мы создадим две временных переменных типа double, одна происходит от объекта, который вызывает 
    функцию, а другая от аргумента s2. Эти переменные затем складываются, результат преобразовывается к 
    типу sterling и возвращается. Заметим, что мы использовали другой подход для класса sterling, нежели
    для класса bMoney. В классе sterling мы используем операции преобразования, таким образом отказавшись
    от возможности поиска неправильных операций, но получив простоту при записи перегружаемых 
    математических операций. */
    double money = 10;
    sterling one11(15, 18, 10);
    sterling two11(6, 2, 8);
    sterling three11;
    one11.putSterling();
    two11.putSterling();
        three11 = one11 + two11;
    three11.putSterling();
        three11 = one11 - two11;
    three11.putSterling();
        three11 = one11 * money;
    three11.putSterling();
        three11 = one11 / two11;
    three11.putSterling();
        three11 = one11 / money;
    three11.putSterling();
    money = three11;
    cout << "money = " << money << endl;

    /*12. Напишите программу, объединяющую в себе классы bMoney из упражнения 8 и sterling из упражнения 11. 
    Напишите операцию преобразования для преобразования между классами bMoney и sterling, предполагая, что 
    один фунт (£1.0.0) равен пятидесяти долларам ($50.00). Это приблизительный курс обмена для XIX века, 
    когда Британская империя еще использовала меру фунты-шиллинги-пенсы. Напишите программу main(), которая 
    позволит пользователю вводить суммы в каждой из валют и преобразовывать их в другую валюту с выводом 
    результата. Минимизируйте количество изменений в существующих классах bMoney и sterling. */
    char continueEnter = '0';
    uint change = 0;
    while (continueEnter != 'n') {
        cout << "Для перевода фунтов в доллары введите 1 " << endl;
        cout << "Для перевода долларов в фунты введите 2 " ;
        cin >> change;
        if (change == 1) {
            sterling from;
            from.getSterling();
            from.putSterling(); 
            cout << " -> " << endl;
            bMoney to = from;
            to.getmoney();
        } else if (change == 2) {
            bMoney from;
            from.putmoney();
            from.getmoney();
            cout << " -> " << endl;
            sterling to = from;
            to.putSterling(); 
        } else
            continue;
        cout << "Продолжить ввод денежных единиц (y or n) : ";
        cin >> continueEnter; 
    }

    return 0;
}