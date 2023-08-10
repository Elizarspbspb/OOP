#include <iostream>
//#include <conio.h>    // для getche() Borland
#include <stdio.h>      // c lib
using namespace std;
// объявление перечисляемого типа
enum days_of_week { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

// wdcount.cpp
enum itsaWord { NO, YES };  // NO = 0, YES = 1

int main()
{
    days_of_week day1, day2;    // определения переменных, хранящих дни недели
    day1 = Mon;     // инициализация переменных
    day2 = Thu;
    //day1 = halloween; // ERROR
    //day1 = 5;   // ERROR
    int diff = day2 - day1;     // арифметическая операция = 3
    cout << "Разница в днях: " << diff << endl;
    if(day1 < day2)     // сравнение
        cout << "day1 наступит раньше, чем day2\n";

    // wdcount.cpp
    // подсчет числа слов в предложении с использованием перечислений
    itsaWord isWord = NO;   // isWord равно YES, когда вводится слово, и NO, когда вводятся пробелы
    char ch = 'a';  // считывание символа с клавиатуры
    int wordcount = 0;  // число слов
    cout << "Введите предложение: \n";
    do {
        //ch = getche();      // ввод символа while(number != '\n')  {
        ch = getchar();
        if(ch == ' ' || ch == '\r') {   // если введен пробел,
            if(isWord == YES) {         // а до этого вводилось слово, значит, слово закончилось
                wordcount++;            // учет слова
                isWord = NO;            // сброс флага
            }
        } else      // иначе ввод слова продолжается
            if(isWord == NO)    // если начался ввод слова,
                isWord = YES;   // то устанавливаем флаг
    } while(ch != '\n');
    if(isWord == YES){
        wordcount++; 
    }
    cout << "\n---Число слов */: " << wordcount << "---\n";

    return 0;
}