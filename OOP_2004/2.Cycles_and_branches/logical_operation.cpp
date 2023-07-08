// advenand.cpp
// применение операции логического И
#include <iostream>
using namespace std;
//#include <process>      // для exit()
//#include <conio.h>      // для getche()
int main()  {
    char dir = 'a';
    int x = 10, y = 10;
    //while(dir != '\r')  {
    while(dir != '\n')  {
        cout << "\nВаши координаты: " << x << ", " << y;
        cout << "\nВыберите направление (n, s, e, w): ";
        //dir = getche();       // ввод направления
        cin >> dir;
        if(x < 5 || x > 15)     // Логическое ИЛИ
            cout << "\nОсторожно - драконы!";
        switch(dir)
        {
            case 'n': y--; break;
            case 's': y++; break;
            case 'e': x++; break;
            case 'w': x--; break;
        }
        if(x == 7 && y == 11)   // Логическое И
        {
            cout << "\nВы нашли сокровище!\n";
            exit(0);    // выход из программы
        }
    }
    return 0;
}