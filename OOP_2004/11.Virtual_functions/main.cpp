// Глава 11. Виртуальные функции
#include <iostream>
#include <cstring>      // для strcpy() и т. д.

using namespace std;

///////////////////////////////////////////////////////////

class Base {        // Базовый класс
public:
    //void show() { cout << "Base\n"; }
    //virtual void show() { cout << "Base\n"; }   // Виртуальная функция
    virtual void show() = 0;    // чисто виртуальная функция и класс стал абстрактным
    //~Base()                     // невиртуальный деструктор. Вызов только в базовом классе
    //{ cout << "Не виртуальный Base удален\n"; }
    virtual ~Base()             // виртуальный деструктор. Вызов в базовом классе и наследниках
    { cout << "Виртуальный Base удален\n"; }
};
class Derv1 : public Base {     // Производный класс 1
public:
    void show() { cout << "Derv1\n"; }
    ~Derv1() { cout << "Derv1 удален\n"; }
};
class Derv2 : public Base {     // Производный класс 2
public:
    void show() { cout << "Derv2\n"; }
    ~Derv2() { cout << "Derv2 удален\n"; }
};

///////////////////////////////////////////////////////////

class person {      // абстрактный
protected:
    char name[40];
public:
    void getName() { cout << " Введите имя: "; cin >> name; }
    void putName() { cout << " Имя: " << name << endl; }
    virtual void getdata() = 0;         // чистые виртуальные
    virtual bool isOutstanding() = 0;   // функции
};
class student : public person {
private:
    float gpa;              // средний балл
public:
    void getdata() {        // запросить данные об ученике у пользователя
        person::getName();
        cout << " Средний балл ученика: "; cin >> gpa;
    }
    bool isOutstanding() { return (gpa > 3.5) ? true : false; }
};
class professor : public person {
private:
    int numPubs;        // число публикаций
public:
    void getdata() {    // запросить данные о педагоге у пользователя
        person::getName();
        cout << " Число публикаций: "; cin >> numPubs;
    }
    bool isOutstanding() { return (numPubs > 100) ? true : false; }
};

////////////////////////////////////////////////

/*#include "msoftcon.h"   // для графических функций
class shape {
protected:
    int xCo, yCo;           // координаты центра
    color fillcolor;        // цвет
    fstyle fillstyle;       // заполнение
public:
    shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL) { }
    shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs) { }
    virtual void draw() = 0 {   // чистая виртуальная функция
        set_color(fillcolor);
        set_fill_style(fillstyle);
    }
};
class ball : public shape {
private:
    int radius; // центр с координатами(xCo, yCo)
public:
    ball() : shape() { }
    ball(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r) { }
    void draw() {   // нарисовать шарик
        shape::draw();
        draw_circle(xCo, yCo, radius);
    }
};
class rect : public shape {
private:
    int width, height;  // (xCo, yCo) - верхний левый угол
public:
    rect() : shape(), height(0), width(0) {}    // конструктор без аргументов
    rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w) { }
    void draw() {   // нарисовать прямоугольник
        shape::draw();
        draw_rectangle(xCo, yCo, xCo + width, yCo + height);
        set_color(cWHITE);  // нарисовать диагональ
        draw_line(xCo, yCo, xCo + width, yCo + height);
    }
};
class tria : public shape {
private:
    int height;     // (xCo, yCo) - вершина пирамиды
public:
    tria() : shape(), height(0) { }
    tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h) { }
    void draw() {   // нарисовать треугольник
        shape::draw();
        draw_pyramid(xCo, yCo, height);
    }
}; */

///////////////////////////////////////////////////////////

// normbase.cpp
class Parent {
protected:
    int basedata;
};
//class Child1 : public Parent { };       // ОШИБКА: неоднозначность
//class Child2 : public Parent { };       // ОШИБКА: неоднозначность
class Child1 : virtual public Parent { };      
class Child2 : virtual public Parent { };      
class Grandchild : public Child1, public Child2 {
public:
    int getdata() { return basedata; }  // ОШИБКА: неоднозначность
};

///////////////////////////////////////////////////////////

class beta;     // нужно для объявления frifunc
class alpha {
private:
    int data;
public:
    alpha() : data(3) {}
    friend int frifunc(alpha, beta); // дружественная функция
};
class beta {
private:
    int data;
public:
    beta() : data(7) { }
    friend int frifunc(alpha, beta); // дружественная функция
};
int frifunc(alpha a, beta b) {
    return (a.data + b.data);
}

///////////////////////////////////////////////////////////
// ограничение перегрузки оператора «+»
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(float fltfeet) {                   // переводит float в Distance
        feet = static_cast<int>(fltfeet);
        inches = 12*(fltfeet - feet);           // слева — дюймы
    }
    Distance(int ft, float in) { feet = ft; inches = in; }
    void showdist() { cout << feet << "\'-" << inches << '\"'; }
    //Distance operator+(Distance);
    friend Distance operator+(Distance, Distance);      // дружественный
    //float square();                                     // обычный метод
    friend float square(Distance);                      // дружественная ф-ция
};
/*Distance Distance::operator+(Distance d2) {     // прибавить расстояние к d2
    int f = feet + d2.feet;                     // добавить футы
    float i = inches + d2.inches;               // добавить дюймы
    if(i >= 12.0) { i -= 12.0; f++; }
    return Distance(f, i);
}*/
Distance operator+(Distance d1, Distance d2) {  // d1 + d2
    int f = d1.feet + d2.feet;                  // + футы
    float i = d1.inches + d2.inches;            // + дюймы
    if(i >= 12.0) { i -= 12.0; f++; }
    return Distance(f, i);
}
/*float Distance::square() {
    float fltfeet = feet + inches / 12;     // перевод во float
    float feetsqrd = fltfeet * fltfeet;     // возведение в квадрат
    return feetsqrd;
}*/
float square(Distance d) {
    float fltfeet = d.feet + d.inches / 12;     // конвертировать в float
    float feetsqrd = fltfeet * fltfeet;         // вычислить квадрат
    return feetsqrd;                            // вернуть квадратные футы
}

///////////////////////////////////////////////////////////
// Дружественные классы
class alpha2 {
private:
    int data1;
public:
    alpha2() : data1(99) { }     // конструктор
    friend class beta2;          // beta - дружественный класс
}; 
class beta2 {    // все методы имеют доступ к скрытым данным alpha
public:
    void func1(alpha2 a) { cout << "\ndata1 =" << a.data1; }
    void func2(alpha2 a) { cout << "\ndata1 =" << a.data1; }
    //friend alpha2;          
};

///////////////////////////////////////////////////////////

class gamma {
private:
    static int total;   // всего объектов класса (только объявление)
    int id;             // ID текущего объекта
public:
    gamma() {
        total++;            // добавить объект
        id = total;         // id равен текущему значению total
    }
    ~gamma() {
        total--;
        cout << "Удаление ID " << id << endl;
    }
    static void showtotal() {       // статическая функция
        cout << "Всего: " << total << endl;
    }
    void showid() {                 // Нестатическая функция
        cout << "ID: " << id << endl;
    }
};
int gamma::total = 0;

///////////////////////////////////////////////////////////

class newAlpha {
private:
    int data;
public:
    newAlpha() { }
    newAlpha(int d) { data = d; }
    void display() { cout << data; }
    newAlpha operator=(newAlpha& a) {   // перегружаемый =
        data = a.data;                  // не выполняется автоматически
        cout << "\nЗапущен оператор присваивания";
        return newAlpha(data);          // возвращает копию newAlpha
    }
};

///////////////////////////////////////////////////////////

class copyAlpha {
private:
    int data;
public:
    copyAlpha() { }
    copyAlpha(int d) { data = d; }
    copyAlpha(copyAlpha& a) {           // конструктор копирования
        data = a.data;
        cout << "\nЗапущен конструктор копирования";
    }
    void display() { cout << data; }
    void operator=(copyAlpha& a) {      // переопределение присваивания
        data = a.data;
        cout << "\nЗапущен оператор присваивания";
    }
};

///////////////////////////////////////////////////////////

class hiddenAlpha {
private:
    hiddenAlpha& operator=(hiddenAlpha&);   // Скрытое присваивание
    hiddenAlpha(hiddenAlpha&);              // Скрытое копирование
public:
    hiddenAlpha() { }
};

///////////////////////////////////////////////////////////

/* strCount класс содержит указатель на реальную строку и считает, 
сколько объектов класса String на нее указывают. */
class strCount {    // Класс-счетчик уникальных строк
private:                            // методы скрыты
    int count;                      // собственно счетчик
    char* str;                      // указатель на строку
    friend class String;            // сделаем себя доступными
    strCount(char* s) {
        int length = strlen(s);     // длина строкового аргумента
        str = new char[length + 1]; // занять память под строку
        strcpy(str, s);             // копировать в нее аргументы
        count = 1;                  // считать с единицы
    }
    ~strCount() { delete[] str; }   // удалить строку
};
class String {          // класс String
private:
    strCount* psc;      // указатель на strCount
public:
    String() { psc = new strCount("NULL"); }
    String(char* s) { psc = new strCount(s); }
    String(String& S) {             // конструктор копирования
        psc = S.psc;
        (psc->count)++;
    }
    ~String() {
        if(psc->count == 1)         // если последний пользователь,
            delete psc;             // удалить strCount
        else                        // иначе
            (psc->count)--;         // уменьшить счетчик
    }
    void display() {
        cout << psc->str;                   // вывести строку
        cout << " (addr =" << psc << ")";   // вывести адрес
    }
    void operator=(String& S) {             // присвоение String
        if(psc->count == 1)                 // если последний пользователь,
            delete psc;                     // удалить strCount
        else                                // иначе
            (psc->count)--;                 // уменьшить счетчик
        psc = S.psc;                        // использовать strCount аргумента
        (psc->count)++;                     // увеличить счетчик
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    Derv1 dv1;          // Объект производного класса 1
    Derv2 dv2;          // Объект производного класса 2
    //Base one;           // работает если есть виртуальная функция
                        // не работает если есть чисто виртуальная функция
    Base* ptr;          // Указатель на базовый класс
    ptr = &dv1;         // Адрес dv1 занести в указатель
    ptr->show();        // Выполнить show()     // Base // Derv1
    ptr = &dv2;         // Адрес dv2 занести в указатель
    ptr->show();        // Выполнить show()     // Base // Derv2

///////////////////////////////////////////////////////////

    Base* arr[2];       // массив указателей на Base
    arr[0] = &dv1;      // Занести адрес dv1 в массив
    arr[1] = &dv2;      // Занести адрес dv2 в массив
    arr[0]->show();     // Выполнить функцию show() над обоими объектами
    arr[1]->show();

///////////////////////////////////////////////////////////

    person* persPtr[100];       // массив указателей на person
    int n = 0;                  // число людей, внесенных в список char choice;
    char choice;
    do {
        cout << " Учащийся (s) или педагог (p): ";
        cin >> choice;
        if(choice == 's')                       // Занести нового ученика
            persPtr[n] = new student;           // в массив
        else                                    // Занести нового
            persPtr[n] = new professor;         // педагога в массив
        persPtr[n++]->getdata();                // Запрос данных о персоне
        cout << " Ввести еще персону (y/n)? ";  // создать еще персону
        cin >> choice;
    } while(choice == 'y');                     // цикл, пока ответ 'y'
    for(int j = 0; j < n; j++) {
        persPtr[j]->putName();                      // Вывести все имена,
        if(persPtr[j]->isOutstanding())             // сообщать о
            cout << " Это выдающийся человек!\n";   // выдающихся
    }

///////////////////////////////////////////////////////////

    /*int j;
    init_graphics();                                        // инициализация графики
    shape* pShapes[3];                                      // массив указателей на фигуры
    pShapes[0] = new ball(40, 12, 5, cBLUE, X_FILL);        // определить три фигуры
    pShapes[1] = new rect(12, 7, 10, 15, cRED, SOLID_FILL);
    pShapes[2] = new tria(60, 7, 11, cGREEN, MEDIUM_FILL);
    for(j = 0; j < 3; j++)
        pShapes[j]->draw();                                 // нарисовать все фигуры
    for(j = 0; j < 3; j++)
        delete pShapes[j];
    set_cursor_pos(1, 25);      */

///////////////////////////////////////////////////////////

    Base* pBase = new Derv1;
    delete pBase;

///////////////////////////////////////////////////////////

    alpha aa;
    beta bb;
    cout << frifunc(aa, bb) << endl; // вызов функции

///////////////////////////////////////////////////////////
// ограничение перегрузки оператора «+»
    Distance d1 = 2.5;      // конструктор переводит feet типа float в Distance
    Distance d2 = 1.25;
    Distance d3;
    cout << "\nd1 = "; d1.showdist();
    cout << "\nd2 = "; d2.showdist();
    d3 = d1 + 10.0;                     // distance + float: OK
    cout << "\nd3 = "; d3.showdist();   // d3 = 10.0 + d1;
    // float + Distance: ОШИБКА без virtual
    // cout << "\nd3 = "; d3.showdist();
    d3 = 10.0 + d1;                     // float + Distance: OK если virtual
    cout << "\nd3 = "; d3.showdist();
    cout << endl;

///////////////////////////////////////////////////////////

    Distance dist(3, 6.0);
    float sqft;
    //sqft = dist.square();                               // вычислить квадрат расстояния
    sqft = square(dist);
    cout << "\nРасстояние = "; dist.showdist();         // показать расст. и квадрат расст.
    cout << "\nКвадрат расст. = " << sqft << " кв. футов\n";

///////////////////////////////////////////////////////////

    alpha2 a;
    beta2 b;
    b.func1(a);
    b.func2(a);
    cout << endl;

///////////////////////////////////////////////////////////

    gamma g1;
    gamma::showtotal();
    gamma g2, g3;
    gamma::showtotal();
    g1.showid();
    g2.showid();
    g3.showid();
    cout << "----------конец программы----------\n";

///////////////////////////////////////////////////////////

    newAlpha a1(37);
    newAlpha a2;
    a2 = a1;                            // запуск перегружаемого =
    cout << "\na2 ="; a2.display();     
    newAlpha a3 = a2;                   // инициализация копирования, а не присваивание!
    cout << "\na3 ="; a3.display();     
    //newAlpha a3(a2);                  // альтернативный вариант инициализации копирования
    cout << endl;

///////////////////////////////////////////////////////////

    copyAlpha a11(37);
    copyAlpha a22;
    a22 = a11;                                // запуск перегружаемого =
    cout << "\na22 ="; a22.display();
    copyAlpha a33(a11);                       // запуск конструктора копирования
    // copyAlpha a33 = a11;                   // эквивалентное определение a3
    cout << "\na33 ="; a33.display();
    cout << endl;

///////////////////////////////////////////////////////////

    hiddenAlpha a1H, a2H;   
    //a1H = a2H;                // присваивание
    //hiddenAlpha a3H(a1H);     // копирование

///////////////////////////////////////////////////////////

    String s3 = "Муха по полю пошла, муха денежку нашла";
    cout << "\ns3 ="; s3.display();         // вывести s3
    String s1;                              // определить объект String
    s1 = s3;                                // присвоить его другому объекту (ПЕРЕГРУЗКА ПРИСВАИВАНИЯ)
    cout << "\ns1 ="; s1.display();         // вывести его
    String s2(s3);                          // инициализация (ПЕРЕГРУЗКА ОПЕРАЦИИ КОПИРОВАНИЯ)
    cout << "\ns2 ="; s2.display();         // вывести инициализированное
    cout << endl;

///////////////////////////////////////////////////////////

    return 0;
}