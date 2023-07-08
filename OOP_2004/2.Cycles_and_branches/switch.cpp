// platters.cpp
// применение ветвления switch
#include <iostream>
using namespace std;
int main()
{
    int speed;  // скорость вращения грампластинки
    cout << "\nВведите число 33, 45 или 78: ";
    cin >> speed;
    switch(speed)   // действия, зависящие от выбора скорости
    {
        case 33:    // если пользователь ввел 33
            cout << "Долгоиграющий формат\n";
            break;
        case 45:    // если пользователь ввел 45
            cout << "Формат сингла\n";
            break;
        case 78:    // если пользователь ввел 78
            cout << "Устаревший формат\n";
            break;
        default:
            cout << "ERROR" << endl;
    }
    return 0;
}