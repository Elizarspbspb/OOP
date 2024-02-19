// Глава 12. Потоки и файлы
#include <iostream>
#include <string>
#include <cstdlib>      // для atoi(), atof()

#include <fstream>      // для файлового ввода/вывода

using namespace std;

///////////////////////////////////////////////////////////

int isFeet(string);     // объявление
class Distance {        // Класс английских расстояний
private:
    int feet;
    float inches;
public:
    Distance() { feet = 0; inches = 0.0; }
    Distance(int ft, float in) { feet = ft; inches = in; }
    void showdist() const { cout << feet << "\'-" << inches << '\"'; }
    void getdist();         // запросить длину у пользователя
};
//---------------------------------------------------------
void Distance::getdist() {
    string instr;                       // для входной строки
    while(true) {                       // цикл, пока футы не будут правильными
        cout << "\n\nВведите футы: ";
        cin.unsetf(ios::skipws);        // не пропускать разделители
        cin >> instr;                   // получить футы как строку
        if(isFeet(instr)) {             // правильное значение? да
            cin.ignore(10, '\n');           // съесть символы, включая разделитель строк
            feet = atoi(instr.c_str());     // перевести значение в целочисленное
            break;                          // выход из цикла 'while'
        }                                   // нет, не целое
        cin.ignore(10, '\n');               // съесть символы, включая разделитель строк
        cout << "Футы должны быть целыми < 1000\n";
    }
    while(true) {                       // цикл проверки дюймов
        cout << "Введите дюймы: ";
        cin.unsetf(ios::skipws);                // не пропускать разделители
        cin >> inches;                          // получить дюймы (тип float)
        if(inches >= 12.0 || inches < 0.0) {
            cout << "Дюймы должны быть между 0.0 и 11.99\n";
            cin.clear(ios::failbit);            // "искусственно" установить флаг ошибки
        }
        if(cin.good()) {                        // все ли хорошо с cin (обычно вводят не цифры)
            cin.ignore(10, '\n');               // съесть разделитель
            break;                              // Ввод корректный, выйти из 'while'
        }
        cin.clear();                            // ошибка; очистить статус ошибки
        cin.ignore(10, '\n');                   // съесть символы с разделителем
        cout << "Неверно введены дюймы\n";      // заново
    }                                           // конец while для дюймов
}
//---------------------------------------------------------
int isFeet(string str) {                // true если введена строка с правильным значением футов
    int slen = str.size();              // получить длину
    if(slen == 0 || slen > 5)           // не было или слишком много данных
        return 0;                       // не целое
    for(int j = 0; j < slen; j++)       // проверить каждый символ
        if((str[j] < '0' || str[j] > '9') && str[j] != '-')     // если не цифра или минус
            return 0;                   // строка неправильных футов
    double n = atof(str.c_str());       // перевод в double
    if(n <-999.0 || n > 999.0)          // вне допустимых значений?
        return 0;                       // если да, неправильные футы
    return 1;                           // правильные футы
}

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {

    // ввод не цифр, а каких-либо символов (например, «девять» вместо «9») 
    int input = 0;
    while(true) {           // Цикл до тех пор. пока ввод не будет корректным
        cout << "\nВведите целое число: ";
        cin >> input;
        if(cin.good()) {                    // если нет ошибок (goodbit flag)
            cin.ignore(10, '\n');           // удалить разделитель строк
            break;                          // выйти из цикла
        }
        cin.clear();                        // Очистить биты ошибок
        cout << "Неправильный ввод данных";
        cin.ignore(10, '\n');               // Удалить разделитель строк
    }
    cout << "целое число: " << input;           // целое без ошибок

///////////////////////////////////////////////////////////

    /*cout << "\nВведите целое число: ";
    cin.unsetf(ios::skipws);    // не игнорировать разделители
    cin >> input;
    if(cin.good()) {}           // ошибок нет          
    // ОШИБКА! */

///////////////////////////////////////////////////////////

    Distance d; // создать объект Distance
    char ans;
    do {
        d.getdist();                    // получить его значение
        cout << "\nРасстояние = ";
        d.showdist();                   // вывести его
        cout << "\nЕще раз (y/n)? ";
        cin >> ans;
        cin.ignore(10, '\n');           // съесть символы и разделитель
    } while(ans != 'n');                // цикл до 'n'

///////////////////////////////////////////////////////////

    char chOne = 'x';
    int jOne = 77;
    double dOne = 6.02;
    string str1One = "Kafka";               // строки без
    string str2One = "Proust";              // пробелов
    ofstream outfile("fdata.txt");          // создать объект ofstream, инициализация файлом
    outfile << chOne                        // вставить (записать) данные
            << jOne << ' '                  // пробелы между числами
            << dOne
            << str1One << ' '               // пробелы между строками
            << str2One;
    cout << "Файл записан\n";

///////////////////////////////////////////////////////////

    char chTwo;
    int jTwo;
    double dTwo;
    string str1Two;
    string str2Two;
    ifstream infile("fdata.txt");                                   // создать объект ifstream
    infile >> chTwo >> jTwo >> dTwo >> str1Two >> str2Two;          // извлечь (прочесть) из него данные
    cout << chTwo << "-endl-" << jTwo << endl << dTwo << endl << str1Two << endl << str2Two << endl;

///////////////////////////////////////////////////////////

    ofstream outfileString("TEST.TXT");     // создать выходной файл
    outfileString << "Приходит март. Я сызнова служу.\n";     // отправить текст в файл
    outfileString << "В несчастливом кружении событий \n";
    outfileString << "изменчивую прелесть нахожу \n";
    outfileString << "в смешеньи незначительных наитий.\n";
    for(int j = 0; j < str1One.size(); j++)     // каждый символ
        outfileString.put(str1One[j]);          // записывать в файл
    cout << "Файл записан\n";

    const int MAX = 80;                 // размер буфера
    char buffer[MAX];                   // буфер символов
    char ch12;
    ifstream infileString("TEST.TXT");        // создать входной файл
    while(!infileString.eof()) {              // цикл до EOF
    //while(infile.good())                    // Пока нет ошибок
    //while(infile)                           // Пока нет ошибок
        infileString.getline(buffer, MAX);    // читает строку текста
        cout << buffer << " - ";         // и выводит ее
    }
    while(infileString) {         // читать до EOF или ошибки
        infileString.get(ch12);     // считать символ
        cout << ch12;         // и вывести его
    }
    cout << endl;

///////////////////////////////////////////////////////////

    return 0;
}