// smallobj.cpp     демонстрирует простой небольшой объект
#include <iostream>
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
int main()  {
    smallobj s1, s2;    // определение двух объектов класса smallobj
    s1.setdata(1066);   // вызовы метода setdata()
    s2.setdata(1776);
    s1.showdata();      // вызовы метода showdata()
    s2. showdata();
    ///////////////////////////////////////////////
    part part1;     // определение объекта класса part
    part1.setpart(6244, 373, 217.55F);
    part1.showpart();
    return 0;
}