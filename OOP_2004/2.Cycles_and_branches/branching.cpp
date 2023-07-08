#include <iostream>
#include <iomanip>  // для setw
//#include <conio.h>  // для getche() MS-DOS

using namespace std;

int main() {
    int x;
    cout << "Введите число: ";
    cin >> x;
    if(x > 100)
        cout << "Это число больше, чем 100\n ";
    else
        cout << "Это число не больше, чем 100\n";
    if(x > 100) {
        cout << "Число " << x;
        cout << " больше, чем 100\n";
    }
    for(unsigned long j = 2; j <= x / 2; j++)    // деление на целые числа,
        if(x % j == 0) {  // начиная с 2; если остаток нулевой, то число не простое     
            cout << "Число не простое: делится на " << j << endl;
            exit(0);    // выход из программы
        }
        cout << "Число является простым\n";

    cout << "------------------------" << endl;

    int chcount = 0;        // число непробельных символов
    int wdcount = 1;        // число пробелов
    char ch = 'a';          // ch должна иметь определенное значение
    cin.clear();            // обнулениe всех битов состояния
    cin >> noskipws;        // пробельные символы не будут пропускаться
    cout << "Введите строку: ";
    //2 - while(ch != '\n') {     // цикл, пока не будет нажата клавиша Enter
    //3 - while(cin >> ch && ch != '\n') {
    //4 - while(cin >> ch && cin.get() != '\n') {
    //1 - while((ch = getche()) != '\r')    // считывание символа
    while(ch != '\n') {
        //2 - ch = cin.get();
        cin >> ch;
        if(ch == ' ')       // если символ является пробелом,
            wdcount++;      // то инкрементируем число слов
        else {               // в противном случае
            chcount++;      // инкрементируем число символов
            //cout << "@@ " << ch << "; " << cin.get() << endl;
        }
    }
    cout << "\nCлов: " << wdcount << endl;
    cout << "Букв: " << (chcount - 1) << endl;

    cout << "------------------------" << endl;

    return 0;
}