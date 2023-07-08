// adifelse.cpp
// приключенческая игра с применением ветвления if...else
#include <iostream>
using namespace std;
//#include <conio.h>  // для getche()
int main() {
    char dir = 'a';
    int x = 10, y = 10;
    cout << "Нажмите Enter для выхода...\n";
    //1 - while(dir != '\r'){     // пока не будет нажата клавиша Enter
    while(dir != '\n'){     // пока не будет нажата клавиша Enter
        cout << "\nВаши координаты: " << x << ", " << y;
        cout << "\nВыберите направление (n, s, e, w): ";
        cin >> dir;
        //1 - dir = getche();     // ввод символа
        if(dir == 'n')      // движение на север
            y--;
        else if(dir == 's') // движение на юг
            y++;
        else if(dir == 'e') // движение на восток
            x++;
        else if(dir == 'w') // движение на запад
            x--;
    }
    return 0;
}