#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
#include <stdlib.h>     // для функции exit

using namespace std;

///////////////////////////////////////////////////////////
class Counter {
private:
    unsigned int count; // значение счетчика
public:
    Counter() : count (0) {}        // конструктор
    unsigned int get_count()        // получить значение
    { return count; }
    //void operator++() { ++count; }  // Префиксное увеличить значение
    Counter operator++() {          // увеличить значение
        ++count;
        Counter temp;
        temp.count = count;
        return temp;
    }
};

/////////////////////////////////////////////////////////////

class CounterTwo {
private:
    unsigned int count;
public:
    CounterTwo() : count(0) {}
    CounterTwo(int c) : count(c) {}
    unsigned int get_count() { return count; }
    CounterTwo operator++() {
        ++count;
    return CounterTwo(count);
    }
    CounterTwo operator++(int) {       // Постфиксные операции
        return CounterTwo(count++);
    }
};

///////////////////////////////////////////////////////////

// englplus.cpp
// перегрузка операции + для сложения переменных типа Distances
class Distance {    // класс английских мер длины
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }   // конструктор без параметров
    Distance(int ft, float in) : feet(ft), inches(in) { }   // конструктор с двумя параметрами
    void getdist() { // получение информации от пользователя
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() { // показ информации
        cout << feet << "\'-" << inches << '\"'; 
    }
    Distance operator+(Distance) const; // сложение двух длин
};
///////////////////////////////////////////////////////////
// сложение двух длин
Distance Distance::operator+(Distance d2) const {
    int f = feet + d2.feet;         // складываем футы
    float i = inches + d2.inches;   // складываем дюймы
    if(i >= 12.0) {         // если дюймов стало больше 12
        i -= 12.0;          // то уменьшаем дюймы на 12
        f++;                // и увеличиваем футы на 1
    }
    return Distance(f, i);  // создаем и возвращаем временную переменную
}

/////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    
    Counter c1, c2; // определяем переменные
    cout << "\nc1 = " << c1.get_count();    // выводим на экран
    cout << "\nc2 = " << c2.get_count();
    ++c1;   // увеличиваем c1 void
    ++c2;   // увеличиваем c2 void
    ++c2;   // увеличиваем c2 void
    cout << "\nc1 = " << c1.get_count();    // снова показываем значения
    cout << "\nc2 = " << c2.get_count() << endl;
    c1 = ++c2;      // увеличиваем c2 Counter
    // c1 = 3, c2 = 3
    cout << "\nc1 = " << c1.get_count();            // 3
    cout << "\nc2 = " << c2.get_count() << endl;    // 3

    //////////////////////////////////////////////////////////////

    CounterTwo ctwo1, ctwo2;  // определяем переменные
    cout << "ctwo1 = " << ctwo1.get_count() << endl;
    cout << "ctwo2 = " << ctwo2.get_count() << endl;    // выводим на экран
    ++ctwo1;
    ctwo2 = ++ctwo1;
    cout << "ctwo1 = " << ctwo1.get_count() << endl;    // снова показываем значения
    cout << "ctwo2 = " << ctwo2.get_count() << endl;
    ctwo2 = ctwo1++;
    cout << "ctwo1 = " << ctwo1.get_count();
    cout << "ctwo2 = " << ctwo2.get_count() << endl;
    
    //////////////////////////////////////////////////////////////

    Distance dist1, dist3, dist4;   // определяем переменные
    dist1.getdist();                // получаем информацию
    Distance dist2(11, 6.25);       // определяем переменную с конкретным значением
    dist3 = dist1 + dist2;          // складываем две переменные
    dist4 = dist1 + dist2 + dist3;  // складываем несколько переменных
    cout << "dist1 = "; dist1.showdist(); cout << endl;
    cout << "dist2 = "; dist2.showdist(); cout << endl;
    cout << "dist3 = "; dist3.showdist(); cout << endl;
    cout << "dist4 = "; dist4.showdist(); cout << endl;

    //////////////////////////////////////////////////////////////

    return 0;
}