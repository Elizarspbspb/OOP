#include <iostream>
#include <iomanip>
#include <string.h> // для функций str*

using namespace std;

// englconv.cpp
// перевод длины из класса Distance в метры и обратно
class Distance { // класс английских мер длины
private:
    const float MTF;    // коэффициент перевода метров в футы
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }   // конструктор без параметров
    //explicit Distance(float meters) : MTF(3.280833F) {
    Distance(float meters) : MTF(3.280833F) {               // конструктор с одним параметром, переводящий метры в футы и дюймы
        float fltfeet = MTF * meters;           // переводим в футы
        feet = int(fltfeet);                    // берем число полных футов
        inches = 12 * (fltfeet - feet);         // остаток — это дюймы
    }
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { } // конструктор с двумя параметрами
    void getdist() {  // получение информации от пользователя
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() const                       // показ информации
    { cout << feet << "\'-" << inches << '\"'; }
    operator float() const {                    // оператор перевода для получения метров из футов
        float fracfeet = inches / 12;           // переводим дюймы в футы
        fracfeet += static_cast<float>(feet);   // добавляем целые футы
        return fracfeet / MTF;                  // переводим в метры
    }
};

///////////////////////////////////////////////////////////

class String {
private:
    enum { SZ = 80 };   // размер массива
    char str[SZ];       // массив для хранения строки
public:
    String() { str[0] = '\x0'; }
    String(char s[]) { strcpy(str, s); }    // сохраняем строку в массиве
    void display() const    { cout << str; }
    operator char*() { return str; }        // перевод строки к обычному типу
};

///////////////////////////////////////////////////////////
//class time24;
// times1.cpp
// программа перевода времени в 24-часовом написании
// в 12-часовое
class time12 {
private:
    bool pm;    // true = pm, false = am
    int hrs;    // 1 - 12
    int mins;   // 0 - 59
public:
    time12() : pm(true), hrs(0), mins(0) { }
    //time12(time24); // ИЛИ ТАК !!!, Но определение time24 должно идти раньше !
    time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) { }
    void display() const {      // формат: 23:59.
        cout << hrs << ':';
        if(mins < 10)
            cout << '0'; // дополнительный нуль для "01"
        cout << mins << ' ';
        string am_pm = pm ? "p.m." : "a.m.";
        cout << am_pm;
    }
};
//--------------------------------------------------------------
/*time12::time12(time24 t24) {    // конструктор с 1 аргументом преобразовать time24 в time12
    int hrs24 = t24.getHrs();               // получить часы
    pm = t24.getHrs() < 12 ? false : true;  // определение am/pm
    mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins()+1; // округление секунд
    if(mins == 60) { // переносим минуты?
        mins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)          // переносим часы?
            pm = (pm == true) ? false : true;   // переключатель am/pm
    }
    hrs = (hrs24 < 13) ? hrs24 : hrs24 - 12;    // преобразуем часы
    if(hrs == 0) // 00 это 12 a.m.
    { hrs = 12; pm = false; }
}*/
///////////////////////////////////////////////////////////
class time24 {
private:
    int hours;      // 0 - 23
    int minutes;    // 0 - 59
    int seconds;    // 0 - 59
public:
    time24() : hours(0), minutes(0), seconds(0) {}
    time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) { }
    void display() const {      // формат: 23:15:01
        if(hours < 10)
            cout << '0';
        cout << hours << ':';
        if(minutes < 10) 
            cout << '0';
        cout << minutes << ':';
        if(seconds < 10) 
            cout << '0';
        cout << seconds;
    }
    int getHrs() const { return hours; }
    int getMins() const { return minutes; }
    int getSecs() const { return seconds; }
    operator time12() const;      // ИЛИ ТАК !!!    // оператор преобразования из 24 в 12
};
time24::operator time12() const {               // оператор преобразования
    int hrs24 = hours;
    bool pm = hours < 12 ? false : true;        // определение am/pm
    int roundMins = seconds < 30 ? minutes : minutes + 1;   // округление секунд
    if(roundMins == 60) {     // переносим минуты?
        roundMins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)          // переносим часы?
            pm = (pm == true) ? false : true;   // переключатель am/pm
    }
    int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
    if(hrs12 == 0) {        // 00 это 12 a.m.
        hrs12 = 12;
        pm = false;
    }
    return time12(pm, hrs12, roundMins);
}

///////////////////////////////////////////////////////////

class scrollbar {
private:
    int size;               // релевантный для константы
    mutable string owner;   // не релевантный для константы
public:
    scrollbar(int sz, string own) : size(sz), owner(own) { }
    void setSize(int sz) { size = sz; }                 // изменения размера
    void setOwner(string own) const { owner = own; }    // изменения владелеца
    int getSize() const // возвраты размера
    { return size; }
    string getOwner() const // возвраты владелеца
    { return owner; }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    float mtrs;
    // explicit ERROR Distance dist1 = 2.35F;  
    // Distance dist1(2.35F);
    Distance dist1 = 2.35F;             // используется конструктор, переводящий метры в футы и дюймы
    cout << "\ndist1 = "; dist1.showdist();
    mtrs = static_cast<float>(dist1);   // используем оператор перевода в метры
    cout << "\ndist1 = " << mtrs << " meters\n";
    Distance dist2(5, 10.25);           // используем конструктор с двумя параметрами
    mtrs = dist2;                       // неявно используем перевод типа
    cout << "\ndist2 = " << mtrs << " meters\n";
    // dist2 = mtrs;    // а вот это ошибка - так делать нельзя

    ///////////////////////////////////////////////////////////

    String s1;      // используем конструктор без параметров
    char xstr[] = "Ура, товарищи! ";    // создаем обычную строку
    s1 = xstr;      // неявно используем конструктор с одним параметром
    s1.display();   // показываем строку
    String s2 = "Мы победим!";  // снова используем конструктор с параметром
    cout << static_cast<char*>(s2) << endl;     // display - больше не нужен !!!

    ///////////////////////////////////////////////////////////

    int h, m, s;
    while(true) {       // получение времени в 24-ом формате от пользователя
        cout << "Введите время в 24-часовом формате: \n";
        cout << " Часы (от 0 до 23): "; cin >> h;
        if(h > 23)      // выход, если часов > 23
            return (1);
        cout << " Минуты: "; cin >> m;
        cout << " Секунды: "; cin >> s;
        time24 t24(h, m, s);    // сделать время в 24-часовом формате
        cout << "Исходное время: ";
        t24.display();          // вывести на экран время в 24-часовом формате
        time12 t12 = t24;       // преобразовать time24 - time12
        cout << "\nВ 12-часовом формате: ";
        t12.display();          // вывести на экран время в 12-часовом формате
        cout << "\n\n";
    }

    ///////////////////////////////////////////////////////////

    const scrollbar sbar(60, "Приложение 1");
    // sbar.setSize(100);   // не может быть изменен в объекте-константе
    sbar.setOwner("Приложение 2");  // может быть изменен даже если объект—константа
    cout << sbar.getSize() << ", " << sbar.getOwner() << endl;

    return 0;
}