// smallobj.cpp     демонстрирует простой небольшой объект
#include <iostream>

//#include "msoftcon.h"   // для функций консольной графики

using namespace std;
////////////////////////////////////////////////////
class smallobj {    // определение класса
    private:
        int somedata;           // поле класса
    public:
        void setdata(int d) {   // метод класса, изменяющий значение поля
            somedata = d; 
        }
        void showdata() {       // метод класса, отображающий значение поля
            cout << "Значение поля равно " << somedata << endl; 
        }
};
//////////////////////////////////////////////////////////
// objpart.cpp      детали изделия в качестве объектов
class part {    // определение класса
    private:
        int modelnumber;    // номер изделия   
        int partnumber;     // номер детали
        float cost;         // стоимость детали
    public:
        void setpart(int mn, int pn, float c) {     // установка данных
            modelnumber = mn;
            partnumber = pn;
            cost = c;
        }
        void showpart() {   // вывод данных
            cout << "Модель " << modelnumber;   
            cout << ", деталь " << partnumber;
            cout << ", стоимость $" << cost << endl;
        }
};
//////////////////////////////////////////////////////////
/*class circle {              // графический Объект "круг"
    protected:
        int xCo, yCo;       // координаты центра
        int radius;
        color fillcolor;    // цвет
        fstyle fillstyle;   // стиль заполнения
    public:
        //void set(int x, int y, int r, color fc, fstyle fs) {    // установка атрибутов круга
        //    xCo = x;
        //    yCo = y;
        //    radius = r;
        //    //fillcolor = fc;
        //    //fillstyle = fs;
        //}
        // ИЛИ
        // конструктор
        circle(int x, int y, int r, color fc, fstyle fs):xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs)
        { }
        void draw() {   // рисование круга
            set_color(fillcolor);       // установка цвета и
            set_fill_style(fillstyle);  // стиля заполнения
            draw_circle(xCo, yCo, radius);// рисование круга
        }
};*/
//////////////////////////////////////////////////////////
class Distance { // длина в английской системе
    private:
        int feet;
        float inches;
    public:
        void setdist(int ft, float in) {    // установка значений полей
            feet = ft; inches = in; 
        }
        void getdist() {    // ввод полей с клавиатуры
            cout << "\nВведите число футов: "; cin >> feet;
            cout << "Введите число дюймов: "; cin >> inches;
        }
        void showdist() const {   // вывод полей на экран
            cout << feet << "\'-" << inches << '\"'; 
        }
};
//////////////////////////////////////////////////////////////
// счетчик в качестве объекта
class Counter {
    private:
        unsigned int count;     // значение счетчика
    public:   
        Counter() : count(0)    // конструктор
        { cout << "Конструктор\n"; }
        void inc_count() {      // инкрементирование счетчика
            count++; 
        }
        int get_count() { // получение значения счетчика
            return count; 
        }
};
////////////////////////////////////////////////////
class foo {
private:
    static int count;   // общее поле для всех объектов (в смысле "объявления")
public:
    foo()               // инкрементирование при создании объекта
    { count++; }
    int getcount()      // возвращает значение count
    { return count; }
};
int foo::count = 0;     // *определение* count
////////////////////////////////////////////////////
// constfu.cpp
// применение константных методов
class aClass {
private:
    int alpha;
public:
    void nonFunc()          // неконстантный метод корректно
    { alpha = 99; } 
    //void conFunc()const     // константный метод
    //{ alpha = 99; }         // ошибка: нельзя изменить значение поля
};

//////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    smallobj s1, s2;    // определение двух объектов класса smallobj
    s1.setdata(1066);   // вызовы метода setdata()
    s2.setdata(1776);
    s1.showdata();      // вызовы метода showdata()
    s2.showdata();
    ///////////////////////////////////////////////
    part part1;     // определение объекта класса part
    part1.setpart(6244, 373, 217.55F);
    part1.showpart();
    ///////////////////////////////////////////////
    /*init_graphics();    // инициализация графики
    circle c1, c2, c3;          // создание кругов
    //c1.set(15, 7, 5, cBLUE, X_FILL);    // установка атрибутов кругов
    //c2.set(41, 12, 7, cRED, O_FILL);
    //c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);

    circle c1(15, 7, 5, cBLUE, X_FILL);
    circle c2(41, 12, 7, cRED, O_FILL);
    circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);

    c1.draw();  // рисование кругов
    c2.draw();
    c3.draw();
    set_cursor_pos(1, 25);  // нижний левый угол */
    ///////////////////////////////////////////////
    Distance dist1, dist2;      // две длины
    dist1.setdist(11, 6.25);    // установка значений для d1
    dist2.getdist();
    cout << "\ndist1 - "; dist1.showdist(); // вывод длин на экран
    cout << "\ndist2 - "; dist2.showdist();
    cout << endl;
    ///////////////////////////////////////////////
    Counter c1, c2; // определение с инициализацией
    cout << "\nc1 =" << c1.get_count(); // вывод
    cout << "\nc2 =" << c2.get_count();
    c1.inc_count();     // инкрементирование c1
    c2.inc_count();     // инкрементирование c2
    c2.inc_count();     // инкрементирование c2
    cout << "\nc1 =" << c1.get_count(); // вывод
    cout << "\nc2 =" << c2.get_count();
    cout << endl;
    ///////////////////////////////////////////////
    foo f1, f2, f3; // создание трех объектов
    // каждый объект видит одно и то же значение
    cout << "Число объектов: " << f1.getcount() << endl;
    cout << "Число объектов: " << f2.getcount() << endl;
    cout << "Число объектов: " << f3.getcount() << endl;
    ///////////////////////////////////////////////
    return 0;
}