#include <iostream>
#include <iomanip>

using namespace std;

// englconv.cpp
// перевод длины из класса Distance в метры и обратно
class Distance { // класс английских мер длины
private:
    const float MTF;    // коэффициент перевода метров в футы
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }   // конструктор без параметров
    Distance(float meters) : MTF(3.280833F) {               // конструктор с одним параметром,переводящий метры в футы и дюймы
        float fltfeet = MTF * meters;       // переводим в футы
        feet = int(fltfeet);                // берем число полных футов
        inches = 12 * (fltfeet - feet);     // остаток — это дюймы
    }
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { } // конструктор с двумя параметрами
    void getdist() {  // получение информации от пользователя
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() const                       // показ информации
    { cout << feet << "\'-" << inches << '\"'; }
    operator float() const {                    // оператор перевода для получения метров из футов
        float fracfeet = inches / 12;           // переводим дюймы в футы
        fracfeet += static_cast<float>(feet);   // добавляем целые футы
        return fracfeet / MTF;                  // переводим в метры
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    float mtrs;
    Distance dist1 = 2.35F;             // используется конструктор, переводящий метры в футы и дюймы
    cout << "\ndist1 = "; dist1.showdist();
    mtrs = static_cast<float>(dist1);   // используем оператор перевода в метры
    cout << "\ndist1 = " << mtrs << " meters\n";
    Distance dist2(5, 10.25);           // используем конструктор с двумя параметрами
    mtrs = dist2;                       // неявно используем перевод типа
    cout << "\ndist2 = " << mtrs << " meters\n";
    // dist2 = mtrs;    // а вот это ошибка - так делать нельзя

    ///////////////////////////////////////////////////////////

    return 0;
}