#include <iostream>
#include <string>

using namespace std;

// множественное наследование
const int LEN = 80;     // максимальная длина имени
class student {         // сведения об образовании
private:
    char school[LEN];   // название учебного заведения
    char degree[LEN];   // уровень образования
public:
    void getedu() {
        cout << " Введите название учебного заведения: ";
        cin >> school;
        cout << " Введите степень высшего образования\n";
        cout << " (неполное высшее, бакалавр, магистр, кандидат наук): ";
        cin >> degree;
    }
    void putedu() const {
        cout << "\n Учебное заведение: " << school;
        cout << "\n Степень: " << degree;
    }
};
class employee { // некий сотрудник
private:
    char name[LEN];         // имя сотрудника
    unsigned long number;   // номер сотрудника
public:
    void getdata() {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: ";
        cin >> number;
    }
    void putdata() const {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};
class manager : private employee, private student { // менеджер
private:
    char title[LEN];    // должность сотрудника
    double dues;        // сумма взносов в гольф-клуб
public:
    void getdata() {
        employee::getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
        student::getedu();
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};
class scientist : private employee, private student { // ученый
private:
    int pubs;       // количество публикаций
public:
    void getdata() {
        employee::getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
        student::getedu();
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Количество публикаций: " << pubs;
        student::putedu();
    }
};
class laborer : public employee // рабочий
{ };
/*
    Классы manager и scientist являются частными производными классов employee и student. 
    В этом случае нет надобности использовать общее наследование, так как объекты классов manager и 
    scientist не пользуются методами базовых классов employee и student. Однако класс laborer должен быть 
    общим производным класса employee, поскольку он пользуется его методами.
*/

///////////////////////////////////////////////////////////

class Type {    // Тип древесины
private:
    string dimensions;
    string grade;
public:
    Type() : dimensions("N/A"), grade("N/A") { }
    Type(string di, string gr) : dimensions(di), grade(gr) { }
    void gettype() {            // запрос информации у пользователя
        cout << "Введите номинальные размеры(2x4 и т.д.): ";
        cin >> dimensions;
        cout << "Введите сорт(необработанная, брус и т.д.): ";
        cin >> grade;
    }
    void showtype() const {     // показ информации
        cout << "\n Размеры: " << dimensions;
        cout << "\n Сорт: " << grade;
    }
};
// -----------------------------------------------
class Distance {    // английские меры длины
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }
    void getdist() { // запрос информации у пользователя
        cout << "Введите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() const // показ информации
    { cout << feet << "\'-" << inches << '\"'; }
};
// -----------------------------------------------
class Lumber : public Type, public Distance {
private:
    int quantity;   // количество штук
    double price;   // цена за штуку
public:
    Lumber() : Type(), Distance(), quantity(0), price(0.0) { }
    Lumber(string di, string gr,    // параметры для Type
            int ft, float in,       // параметры для Distance
            int qu, float prc) :    // наши собственные параметры
            Type(di, gr),           // вызов конструктора Type
            Distance(ft, in),       // вызов конструктора Distance
            quantity(qu), price(prc)// вызов наших конструкторов
    { }
    void getlumber() {
        Type::gettype();
        Distance::getdist();
        cout << "Введите количество: "; cin >> quantity;
        cout << "Введите цену: "; cin >> price;
    }
    void showlumber() const {
        Type::showtype();
        cout << "\nДлина: ";
        Distance::showdist();
        cout << "\nСтоимость " << quantity << " штук: $" << (price * quantity) << " рублей";
    }
};

///////////////////////////////////////////////////////////

// демонстрация неопределенности при множественном наследовании
class A {
public:
    void show() { cout << "Класс A\n"; }
};
class B {
public:
    void show() { cout << "Класс B\n"; }
};
class C : public A, public B { };

///////////////////////////////////////////////////////////

class A2 {
public:
    virtual void func();
};
class B2 : public A2 { };
class C2 : public A2 { };
class D2 : public B2, public C2 { };

///////////////////////////////////////////////////////////

class A3 { };
class В3 {
	A3 objA3;
};
// содержат копии классов employee и student как атрибуты.
class managerInput {
private:
    string title;
    double dues;
    employee emp;   // Включение
    student stu;    // Включение
public:
    void getdata() {
        emp.getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
        stu.getedu();
    }
    void putdata() const {
        emp.putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
        stu.putedu();
    }
};
// -----------------------------------------------
class scientistInput {
private:
    int pubs;
    employee emp;   // Включение
    student stu;    // Включение
public:
    void getdata() {
        emp.getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
        stu.getedu();
    }
    void putdata() const {
        emp.putdata();
        cout << "\n Количество публикаций: " << pubs;
        stu.putedu();
    }
};
// -----------------------------------------------
class laborerInput {
private:
    employee emp;   // Включение
public:
    void getdata() { emp.getdata(); }
    void putdata() const { emp.putdata(); }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    manager m1;
    scientist s1, s2;
    laborer l1;
    // введем информацию о нескольких сотрудниках
    cout << endl;
    cout << "\nВвод информации о первом менеджере";
    m1.getdata();
    cout << "\nВвод информации о первом ученом";
    s1.getdata();
    cout << "\nВвод информации о втором ученом";
    s2.getdata();
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    // выведем полученную информацию на экран
    cout << "\nИнформация о первом менеджере";
    m1.putdata();
    cout << "\nИнформация о первом ученом";
    s1.putdata();
    cout << "\nИнформация о втором ученом";
    s2.putdata();
    cout << "\nИнформация о первом рабочем";
    l1.putdata();
    cout << endl;

    ///////////////////////////////////////////////////////////

    Lumber siding;              // используем конструктор без параметров
    cout << "\n Информация об обшивке:\n";
    siding.getlumber();         // получаем данные от пользователя
    Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F);   // используем конструктор с шестью параметрами
    cout << "\nОбшивка";
    siding.showlumber();
    cout << "\nБрус";
    cout << endl;

    ///////////////////////////////////////////////////////////

    // демонстрация неопределенности при множественном наследовании
    C objC; // объект класса C
    // objC.show();     // так делать нельзя - программа не скомпилируется
    objC.A::show();     // так можно
    objC.B::show();     // так можно

    ///////////////////////////////////////////////////////////

    //D2 objD2;
    //objD2.func(); // неоднозначность: программа не скомпилируется

    ///////////////////////////////////////////////////////////

    managerInput mIn1;
    scientistInput sIn1, sIn2;
    laborerInput lIn1;
    // введем информацию о нескольких сотрудниках
    cout << endl;
    cout << "\nВвод информации о первом менеджере";
    mIn1.getdata();
    cout << "\nВвод информации о первом ученом";
    sIn1.getdata();
    cout << "\nВвод информации о втором ученом";
    sIn2.getdata();
    cout << "\nВвод информации о первом рабочем";
    lIn1.getdata();
    // выведем полученную информацию на экран
    cout << "\nИнформация о первом менеджере";
    mIn1.putdata();
    cout << "\nИнформация о первом ученом";
    sIn1.putdata();
    cout << "\nИнформация о втором ученом";
    sIn2.putdata();
    cout << "\nИнформация о первом рабочем";
    lIn1.putdata();
    cout << endl;

    ///////////////////////////////////////////////////////////

    return 0;
}