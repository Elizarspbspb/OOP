#include <iostream>
#include <iomanip> // для использования setw

using namespace std;

#define PI_1 3.14159

int main() {
    cout << "У каждой эпохи свой язык\n";

    int var1;               // описание переменной var1
    int var2;               // описание переменной var2
    var1 = 20;              // присвоение значения переменной var1
    var2 = var1 + 10;       // присвоение значения переменной var2
    cout << "var1 + 10 = "; // вывод строки
    cout << var2 << endl;   // вывод значения переменной var2
    
    cout << "------------------------------" << endl;
    
    char charvar1 = 'A';        // символьная переменная со значением 'A'
    char charvar2 = '\t';       // символьная переменная со значением символа табуляции
    cout << charvar1;           // вывод переменной на экран
    cout << charvar2;           // вывод переменной на экран
    charvar1 = 'B';             // присваивание константного значения символьной переменной
    cout << charvar1 << '\n';   // вывод переменной на экран and переход на следующую строку

    cout << "------------------------------" << endl;

    int ftemp;  // температура по Фаренгейту
    cout << "Введите температуру по Фаренгейту: ";
    cin >> ftemp;
    int ctemp = (ftemp - 32) * 5 / 9;
    cout << "Температура no Цельсию равна " << ctemp << '\n';

    cout << "------------------------------" << endl;

    float rad;                              // переменная вещественного типа
    const float PI = 3.14159F;              // вещественная константа не изменится в процессе программы
    cout << "Введите радиус окружности: ";  // запрос
    cin >> rad;                             // получение радиуса
    float area = PI * rad * rad;            // вычисление площади круга
    cout << "Площадь круга равна " << area << endl; // вывод результата на экран

    cout << "------------------------------" << endl;

    long pop1 = 4789426, pop2 = 274124, pop3 = 9761;
    cout << "Город " << "Нас." << endl
    << "Москва " << pop1 << endl
    << "Киров " << pop2 << endl
    << "Угрюмовка " << pop3 << endl;
    cout << "------------------------------" << endl;
    cout << setw(9) << "Город" << setw(12) << " Население" << endl
         << setw(9) << "Москва" << setw(12) << pop1 << endl
         << setw(9) << "Киров" << setw(12) << pop2 << endl
         << setw(9) << "Угрюмовка" << setw(12) << pop3 << endl;

    cout << "------------------------------" << endl;

    int signedVar = 1234567890;             // знаковая переменная
    unsigned int unsignVar = 1234567890;    // беззнаковая переменная
    signedVar = (signedVar * 2) / 3;        // выход за границы диапазона
    unsignVar = (unsignVar * 2) / 3;        // вычисления внутри диапазона
    cout << "Знаковая переменная равна " << signedVar << endl;      // ошибка
    cout << "Беззнаковая переменная равна " << unsignVar << endl;   // правильно

    cout << "------------------------------" << endl;

    int intVar = 1500000000;                                // 1 500 000 000
    intVar = (intVar * 10) / 10;                            // слишком большой результат
    cout << "1 Значение intVar равно " << intVar << endl;   // неверный результат
    intVar = 1500000000;                                    
    intVar = (static_cast<double>(intVar) * 100) / 100;     // приведение к временному типу double
    cout << "2 Значение intVar равно " << intVar << endl;   // верный результат
    intVar = 1500000000;
    intVar = (static_cast<double>(intVar) * 10);            // приведение к временному типу double
    cout << "3 Значение intVar равно " << intVar << endl;   // неверный результат, так как static_cast создает временную переменную !
    intVar = 1500000000;
    cout << "4 Значение intVar равно " << (static_cast<double>(intVar) * 20) << endl; // верный результат 3e+10 

    cout << "------------------------------" << endl;

    cout << 6 % 8 << endl   // 6
        << 7 % 8 << endl    // 7
        << 8 % 8 << endl    // 0
        << 9 % 8 << endl    // 1
        << 10 % 8 << endl;  // 2

    int ans = 27;
    ans += 10;  // то же самое, что ans = ans + 10;
    cout << ans << ", ";
    ans -= 7;   // то же самое, что ans = ans - 7;
    cout << ans << ", ";
    ans *= 2;   // то же самое, что ans = ans * 2;
    cout << ans << ", ";
    ans /= 3;   // то же самое, что ans = ans / 3;
    cout << ans << ", ";
    ans %= 3;   // то же самое, что ans = ans % 3;
    cout << ans << endl;

    cout << "------------------------------" << endl;

    int count = 10;
    cout << "count = " << count << endl;    // вывод числа 10
    cout << "count = " << ++count << endl;  // вывод числа 11 (префиксная форма)
    cout << "count = " << count << endl;    // вывод числа 11
    cout << "count = " << count++ << endl;  // вывод числа 11 (постфиксная форма)
    cout << "count = " << count << endl;    // вывод числа 12

    cout << "------------------------------" << endl;

    return 0;
}