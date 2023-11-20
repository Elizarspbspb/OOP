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


    return 0;
}