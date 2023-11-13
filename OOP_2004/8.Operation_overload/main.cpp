#include <iostream>
#include <iomanip>
#include <ctime>

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

    return 0;
}