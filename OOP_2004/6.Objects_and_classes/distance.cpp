// englcon.cpp
// constructors, adds objects using member function
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////
class Distance {    // длина в английской системе
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }                   // конструктор без аргументов
    // Перегрузка конструктора
    Distance(int ft, float in) : feet(ft), inches(in) { }   // конструктор с двумя аргументами
    void getdist() {    // ввод длины пользователем
        cout << "\nВведите число футов: "; cin >> feet;
        cout << "Введите число дюймов: "; cin >> inches;
    }
    void showdist() const {   // вывод длины на экран
        cout << feet << "\'-" << inches << '\"'; 
    }
    void add_dist(Distance, Distance);          // прототип копии
    //void add_dist(Distance&, Distance&);      // прототип адреса оригинала
    Distance add_dist(Distance) const;          // const функция
    //Distance add_dist(const Distance) const;    // const функция и const ссылка для защиты
};
//--------------------------------------------------------
void Distance::add_dist(Distance dd1, Distance dd2) {     // копия
//void Distance::add_dist(Distance& dd1, Distance& dd2) { // ссылка
    inches = dd1.inches + dd2.inches;   // сложение дюймов с возможным заемом
    feet = 0;
    if(inches >= 12.0) {    // если число дюймов больше 12.0,
        inches -= 12.0;     // то уменьшаем число дюймов на 12.0
        feet++;             // и увеличиваем число футов на 1
    }
    feet += dd1.feet + dd2.feet;    // сложение футов
    dd1.inches = 0;     // Копия не изменит оригинал но выделяет память 
    dd2.inches = 0;     // А если ссылка то изменит оригинал и не выделяет память
    dd1.feet = 0;       
    dd2.feet = 0;
}
// сложение данного объекта с d2, возврат суммы
Distance Distance::add_dist(Distance d2) const {
    Distance temp;  // временная переменная
    temp.inches = inches + d2.inches; // сложение дюймов
    if(temp.inches >= 12.0) {   // если сумма больше 12.0, то уменьшаем ее на
        temp.inches -= 12.0;    // 12.0 и увеличиваем
        temp.feet = 1;
    }
    temp.feet += feet + d2.feet;
    return temp;
}
//////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    Distance dist1, dist3, dist4;          // две длины
    Distance dist2(11, 6.25);       // определение и инициализация
    dist1.getdist();                // ввод dist1
    dist3.add_dist(dist1, dist2);   // dist3 = dist1 + dist2
    // dist3 = dist1 + dist2
    dist4 = dist1.add_dist(dist2);
    // вывод всех длин
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << "\ndist4 = "; dist4.showdist();
    cout << endl;
    /////////////////////////////////////////////////////////////
    const Distance football(300, 0);
    // football.getdist();
    // ошибка: метод getdist() неконстантный
    cout << " Длина поля равна ";
    football.showdist();    // корректно
    cout << endl;

    return 0;
}