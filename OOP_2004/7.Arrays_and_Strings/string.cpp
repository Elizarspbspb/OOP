#include <iostream>
#include <iomanip>      // setw

using namespace std;

int main(int argc, char* argv[]) {
    const int MAX = 80;             // максимальный размер строки
    char str[MAX];                  // сама строка
    cout << "Введите строку: ";     // ввод строки
    cin >> str;
    cout << "Вы ввели: " << str << endl;// показ результата
    
    //////////////////////////////////////////////////////////////

    const int MAXSETW = 6;              // максимальный размер строки
    char strSet[MAXSETW];               // сама строка
    cout << "\nВведите строку: ";
    cin >> setw(MAXSETW) >> strSet;     // ввод не более чем MAX символов
    cout << "Вы ввели: " << strSet << endl;

    //////////////////////////////////////////////////////////////

    char strConstStr[] = "Я памятник себе воздвиг нерукотворный.";
    cout << strConstStr << endl;
    //char strConstSym[] = {'Я', ' ', ' п', 'а', ' м', 'я', 'т', 'н', 'и', 'к'};
    //cout << strConstSym << endl; 

    //////////////////////////////////////////////////////////////

    const int MAXSTR = 80;  // максимальная длина строки
    char strSTR[MAXSTR];    // сама строка
    cout << "\nВведите строку с пробелами: " << endl;
    cin.ignore();
    cin.get(strSTR, MAXSTR);
    cout << "Вы ввели: " << strSTR << endl;

    return 0;
}