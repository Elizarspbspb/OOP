#include <iostream>
#include <iomanip>      // setw
#include <cstring>
#include <string>

using namespace std;

const int MAXSTR = 100;  // максимальная длина строки

///////////////////////////////////////////////////////////

// Task 1
char reversit(const char re[]) {
    char input[MAXSTR];
    for (int j = 0, i = strlen(re)-1; i >= -1; --i, ++j) {
        input[j] = re[i];
        cout << input[j] << " ";
    }
    return input;
}
/*void reversit(char s[]) {
    int len = strlen(s);
    for(int j = 0; j < len / 2; j++) {  // поменять все символы из первой половины
        char temp = s[j];               // на символы
        s[j] = s[len - j - 1];          // из второй половины
        s[len - j - 1] = temp;
    }
}*/

int main(int argc, char* argv[]) {
    /*1. Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл 
    for, который меняет местами первый и последний символы, затем следующие и т. д. до предпоследнего. 
    Строка должна передаваться в функцию reversit() как аргумент. Напишите программу для выполнения функции
    reversit(). Программа должна принимать строку от пользователя, вызывать функцию reversit(), а затем 
    выводить полученный результат. Используйте метод ввода, который позволяет использовать внутренние 
    пробелы. Протестируйте программу на примере фразы «Аргентина манит негра». */
    char input[MAXSTR];
    cout << "Введите строку текста" << endl;
    //cin >> input;             // работает до пробела
    cin.ignore();
    cin.get(input, MAXSTR);     // работает до новой строки
    cout << reversit(input) << endl;
    //reversit(input);            // перевернуть строку
    cout << "Перевернутая строка:" << input << endl;

    return 0;
}