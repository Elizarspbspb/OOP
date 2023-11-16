#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
#include <stdlib.h>     // для функции exit
//#include <process.h>    // для функции exit

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

    bool operator<(Distance) const;     // сравнение двух длин

    void operator+=(Distance);          // сложение с присвоением

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
///////////////////////////////////////////////////////////
// сравнение двух длин
bool Distance::operator<(Distance d2) const {
    float bf1 = feet + inches / 12;
    float bf2 = d2.feet + d2.inches / 12;
    return (bf1 < bf2) ? true : false;
}
///////////////////////////////////////////////////////////
void Distance::operator+=(Distance d2) {
    feet += d2.feet;        // складываем футы
    inches += d2.inches;    // складываем дюймы
    if(inches >= 12.0)  {   // если дюймов больше 12
        inches -= 12.0;     // то уменьшаем дюймы на 12
        feet++;             // увеличиваем футы на 1
    }
}

///////////////////////////////////////////////////////////

class String { // наш класс для строк
private:
    enum { SZ = 80 };   // максимальный размер строки
    char str[SZ];       // массив для строки
public:
    String() { strcpy(str, ""); }           // конструктор без параметров
    String(char s[]) { strcpy(str, s); }    // конструктор с одним параметром
    void display() const { cout << str; }
    String operator+(String ss) const { // оператор сложения
        String temp;    // временная переменная
        if(strlen(str) + strlen(ss.str) < SZ) {   
            strcpy(temp.str, str);      // копируем содержимое первой строки
            strcat(temp.str, ss.str);   // добавляем содержимое второй строки
        } else {
            cout << "\nПереполнение!";
            exit(1);
        }
        return temp;    // возвращаем результат
    }

    void getdist() {    // получение строки
        cin.get(str, SZ); 
    }
    bool operator==(String ss) const {      // оператор сравнения
        return (strcmp(str, ss.str) == 0) ? true : false;
    }
};

/////////////////////////////////////////////////////////////
// !!! Перегруженная операция индексации должна возвращать свои значения по ссылке. !!!
const int LIMIT = 100; // размер массива
class safearray {
private:
    int arr[LIMIT];
public:
    void putel(int n, int elvalue) {    // установка значения элемента массива
        if(n < 0 || n >= LIMIT) { 
            cout << "\nОшибочный индекс!"; 
            exit(1); 
        }
        arr[n] = elvalue;
    }
    int getel(int n) const {            // получение значения элемента массива
        if(n < 0 || n >= LIMIT) { 
            cout << "\nОшибочный индекс!"; 
            exit(1); 
        }
        return arr[n];
    }

    // обратите внимание, что функция возвращает ссылку!
    int& access(int n) {
        if(n < 0 || n >= LIMIT) { 
            cout << "\nОшибочный индекс!"; 
            exit(1); 
        } 
        return arr[n];
    }

    // обратите внимание, что функция возвращает ссылку!
    int& operator[](int n) {
        if(n < 0 || n >= LIMIT) { 
            cout << "\nОшибочный индекс!"; 
            exit(1); 
        }
        return arr[n];
    }

};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
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

    // используем наш оператор
    if(dist3 < dist4)
        cout << "\ndist3 меньше чем dist4" << endl;
    else
        cout << "\ndist3 больше или равно чем dist4" << endl;

    dist4 += dist3; // dist4 = dist4 + dist3
    cout << "\nПосле добавления:";
    cout << "\ndist4 = "; dist4.showdist();

    //////////////////////////////////////////////////////////////

    String s1 = "\nС Рождеством! ";     // используем конструктор с параметром
    String s2 = "С Новым годом!";       // используем конструктор с параметром
    String s3;                          // используем конструктор без параметров
    s1.display();       // показываем строки
    s2.display();
    s3.display();
    s3 = s1 + s2;       // присваиваем строке s3 результат сложения строк s1 и s2
    s3.display();
    cout << endl;

    String s4 = "да";
    String s5 = "нет";
    String s6;
    cout << "\nВведите 'да' или 'нет': ";
    s6.getdist();           // получаем строку от пользователя
    if(s6 == s4)            // сравниваем со строкой 'да'
        cout << "Вы ввели 'да'\n";
    else if(s6 == s5)       // сравниваем со строкой 'нет'
        cout << "Вы ввели 'нет'\n";
    else
        cout << "Следуйте инструкциям!\n";

    //////////////////////////////////////////////////////////////

    safearray sa1;
    int j = 0;
    for(j = 0; j < LIMIT; j++)
        sa1.putel(j, j * 10);   // задаем значения элементов
    for(j = 0; j < LIMIT; j++) {
        int temp = sa1.getel(j);
        cout << "Элемент " << j << " равен " << temp << endl;   // показываем элементы
    }

    safearray sa2;
    for(j = 0; j < LIMIT; j++)      // задаем значения элементов
        sa2.access(j) = j * 10;     // используем функцию слева от знака =
    for(j = 0; j < LIMIT; j++) {    // показываем элементы
        int temp = sa2.access(j);   // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }

    safearray sa3;
    for(int j = 0; j < LIMIT; j++)  // задаем значения элементов
        sa3[j] = j * 10;            // используем функцию слева от знака =
    for(j = 0; j < LIMIT; j++) {    // показываем элементы
        int temp = sa3[j];          // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }

    //////////////////////////////////////////////////////////////

    return 0;
}