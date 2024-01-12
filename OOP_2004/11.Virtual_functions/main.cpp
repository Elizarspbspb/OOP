// Глава 11. Виртуальные функции
#include <iostream>

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
    return 0;
}