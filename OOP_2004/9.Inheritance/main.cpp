// Глава 9. Наследование
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
#include <stdlib.h>     // для функции exit

using namespace std;

//////////////////////////////////////////////////////////

class Counter { // базовый класс
protected:
    unsigned int count;     // счетчик
public:
    Counter() : count(0) {}         // конструктор без аргументов
    Counter(int c) : count(c) {}    // конструктор с одним параметром
    unsigned int get_count() const  // возвращает значение счетчика
    { return count; }
    Counter operator++()            // увеличивает значение
    { return Counter(++count); }    // счетчика (префикс)
};
class CountDn : public Counter {    // производный класс
public:
    CountDn() : Counter() {}        // вызов конструктора Counter() базового класса.
    CountDn(int c) : Counter(c) {}  // параметр с передается в конструктор класса Counter
    Counter operator--()    // уменьшает значение счетчика
    { return Counter(--count); }
};
// CountDn наследует все возможности класса Counter: конструктор без арг. и методы.

///////////////////////////////////////////////////////////

class Stack {
protected:
    enum { MAX = 3 };   // размер стека
    int st[MAX];        // данные, хранящиеся в стеке
    int top;            // индекс последнего элемента в стеке
public:
    Stack() { top = -1; }
    void push(int var) { st[++top] = var; }
    int pop() { return st[top--]; }
};
class Stack2 : public Stack {
public:
    void push(int var) {
        if(top >= MAX - 1) {    // если стек полон, то ошибка
            cout << "\nОшибка: стек полон"; 
            exit(1); 
        }
        Stack::push(var);       // вызов функции push класса Stack
    }
    int pop() {         // извлечение числа из стека
        if(top < 0) {   // если стек пуст, то ошибка
            cout << "\nОшибка: стек пуст\n"; 
            exit(1); 
        }
        return Stack::pop();    // вызов функции pop класса Stack(можно без return)
    }
};

///////////////////////////////////////////////////////////

enum posneg { pos, neg };
class Distance {    // класс для английских мер длины
// private
protected:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }
    void getdist() {
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() const { cout << feet << "\'-" << inches << '\"'; }
};
class DistSign : public Distance { // добавление знака к длине
private:
    posneg sign;    // значение может быть pos или neg
public:
    DistSign() : Distance() { sign = pos; }
    // либо два, либо три аргумента. Третий необязательный
    DistSign(int ft, float in, posneg sg = pos) : Distance(ft, in) { sign = sg; }
    void getdist() {
        Distance::getdist();    // вызов функции getdist из базового класса
        char ch;                // запрос знака
        cout << "Введите знак (+ или -): "; 
        cin >> ch;
        sign = (ch == '+') ? pos : neg;
    }
    void showdist() const {     // вывод расстояния
        cout << ((sign == pos) ? "(+)" : "(-)");    // вывод всей информации, включая знак
        Distance::showdist();
    }
};

///////////////////////////////////////////////////////////

// наследование применяется для других целей, как часть первоначальной разработки программы.
const int LEN = 80;                 // максимальная длина имени
class employee  {                   // некий сотрудник
private:
    char name[LEN];                 // имя сотрудника
    unsigned long number;           // номер сотрудника
public:
    void getdata() {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: "; cin >> number;
    }
    void putdata() const {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};
class manager : public employee {   // менеджер
private:
    char title[LEN];        // должность, например вице-президент
    double dues;            // сумма взносов в гольф-клуб
public:
    void getdata() {
        employee::getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
    }
};
class scientist : public employee { // ученый
private:
    int pubs;   // количество публикаций
public:
    void getdata() {
        employee::getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Количество публикаций: " << pubs;
    }
};
class laborer : public employee { // рабочий
};
class foreman : public laborer  { // бригадир
private:
    float quotas;   // норма выработки
public:
    void getdata() {
        laborer::getdata();
        cout << " Введите норму выработки: "; cin >> quotas;
    }
    void putdata() const {
        laborer::putdata();
        cout << "\n Норматив: " << quotas;
    }
};

///////////////////////////////////////////////////////////

// геометрические фигуры
/*#include <msoftcon.h>
class shape {           // базовый класс
protected:
    int xCo, yCo;       // координаты фигуры
    color fillcolor;    // цвет
    fstyle fillstyle;   // стиль изображения
public:
    shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL) { }
    shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs) { }
    void draw() const { // функция установки цвета и стиля
        set_color(fillcolor);
        set_fill_style(fillstyle);
    }
};
// -----------------------------------------------
class circle : public shape {
private:
    int radius;             // радиус, а xCo и yCo будут координатами центра
public:
    circle() : shape() { }
    circle(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r) { }
    void draw() const {     // функция рисования окружности
        shape::draw();
        draw_circle(xCo, yCo, radius);
    }
};
// -----------------------------------------------
class rect : public shape {
private:
    int width, height;      // ширина и высота, а xCo и yCo будут координатами верхнего правого угла
public:
    rect() : shape(), height(0), width(0) { }
    rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w) { }
    void draw() const {     // функция рисования прямоугольника
        shape::draw();
        draw_rectangle(xCo, yCo, xCo + width, yCo + height);    // нарисуем диагональ
        set_color(xWHITE);
        draw_line(xCo, yCo, xCo + width, yCo + height);
    }
};
// -----------------------------------------------
class tria : public shape {
private:
    int height; // высота пирамиды, а xCo и yCo будут координатами вершины
public:
    tria() : shape(), height(0) { }
    tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h) { }
    void draw() const {
        shape::draw();
        draw_pyramid(xCo, yCo, height);
    }
}; */

///////////////////////////////////////////////////////////

// испытание классов наследованных как public и private
class A { // базовый класс
private:
    int privdataA;
protected:
    int protdataA;
public:
    int pubdataA;
};
// -----------------------------------------------
class B : public A {    // public наследование
public:
    void funct() {
        int a;
        //a = privdataA;  // ошибка, нет доступа
        a = protdataA;  // так можно
        a = pubdataA;   // так можно
    }
};
// -----------------------------------------------
class C : private A {   // private наследование
public:
    void funct() {
        int a;
        //a = privdataA;  // ошибка, нет доступа
        a = protdataA;  // так можно
        a = pubdataA;   // так можно
    }
};
// -----------------------------------------------
class D : protected A {   // private наследование
public:
    void funct() {
        int a;
        //a = privdataA;  // ошибка, нет доступа
        a = protdataA;  // так можно
        a = pubdataA;   // так можно
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    /*CountDn c2(10);         // ERROR без CountDn(int c) : Counter(c) {}
    CountDn c1;             // объект c1
    cout << "\n c1 =" << c1.get_count();    // вывод на печать
    ++c1; ++c1; ++c1;       // увеличиваем c1 три раза
    cout << "\n c1 =" << c1.get_count();    // вывод на печать
    --c1; --c1;             // уменьшаем c1 два раза
    cout << "\n c1 =" << c1.get_count();    // вывод на печать
    cout << endl;

    //////////////////////////////////////////////////////////////

    Stack2 s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);                // поместим в стек несколько чисел
    cout << endl << s1.pop();   // заберем числа из стека
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    //cout << endl << s1.pop();   // Ошибка: стек пуст
    cout << endl;

    //////////////////////////////////////////////////////////////

    DistSign alpha;                     // используем конструктор по умолчанию
    alpha.getdist();                    // получаем данные от пользователя
    DistSign beta(11, 6.25);            // конструктор с двумя аргументами
    DistSign gamma(100, 5.5, neg);      // конструктор с тремя аргументами
    cout << "\nA = "; alpha.showdist();
    cout << "\nB = "; beta.showdist();
    cout << "\nC = "; gamma.showdist();
    cout << endl;

    //////////////////////////////////////////////////////////////

    manager m1, m2; // конструктор, установленный по умолчанию для класса manager
    scientist s1;
    laborer l1;
    cout << endl;
    // введем информацию о нескольких сотрудниках
    cout << "\nВвод информации о первом менеджере";
    m1.getdata();
    cout << "\nВвод информации о втором менеджере";
    m2.getdata();
    cout << "\nВвод информации о первом ученом";
    s1.getdata();
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    // выведем полученную информацию на экран
    cout << "\nИнформация о первом менеджере";
    m1.putdata();
    cout << "\nИнформация о втором менеджере";
    m2.putdata();
    cout << "\nИнформация о первом ученом";
    s1.putdata();
    cout << "\nИнформация о первом рабочем";
    l1.putdata();
    cout << endl;

    //////////////////////////////////////////////////////////////

    init_graphics();    // инициализируем систему отображения графики
    circle cir(40, 12, 5, cBLUE, X_FILL);       // создаем круг
    rect rec(12, 7, 10, 15, cRED, SOLID_FILL);  // создаем прямоугольник
    tria tri(60, 7, 11, cGREEN, MEDIUM_FILL);   // создаем пирамиду
    cir.draw();         // рисуем все наши фигуры
    rec.draw();
    tri.draw(); 
    set_cursor_pos(1, 25); // переводим курсор в самый низ экрана */

    //////////////////////////////////////////////////////////////

    int a;
    B objB;
    // a = objB.privdataA;     // ошибка, нет доступа
    // a = objB.protdataA;     // ошибка, нет доступа
    a = objB.pubdataA;          // так можно
    C objC;
    // a = objC.privdataA;     // ошибка, нет доступа
    // a = objC.protdataA;     // ошибка, нет доступа
    // a = objC.pubdataA;      // ошибка, нет доступа
    D objD;
    // a = objD.privdataA;     // ошибка, нет доступа
    // a = objD.protdataA;     // ошибка, нет доступа
    // a = objD.pubdataA;      // ошибка, нет доступа

    //////////////////////////////////////////////////////////////

    laborer l1;
    foreman f1;
    cout << endl;
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    cout << "\nВвод информации о первом бригадире";
    f1.getdata();
    // выведем полученную информацию на экран
    cout << endl;
    cout << "\nИнформация о первом рабочем";
    l1.putdata();
    cout << "\nИнформация о первом бригадире";
    f1.putdata();
    cout << endl;

    //////////////////////////////////////////////////////////////

    return 0;
}