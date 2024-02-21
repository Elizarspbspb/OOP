// Глава 12. Потоки и файлы
#include <iostream>
#include <string>
#include <cstdlib>      // для atoi(), atof()

#include <fstream>      // для файлового ввода/вывода одновременно

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

class person {
protected:
    char name[80];      // имя человека
    short age;          // возраст
    protected:
public:
    void getdata() {    // получить данные о человеке
        cout << "Введите имя: "; cin >> name;
        cout << "Введите возраст: "; cin >> age;
    }
    void showData() const {   // вывести данные
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {

    // ввод не цифр, а каких-либо символов (например, «девять» вместо «9») 
    /*int input = 0;
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

    //cout << "\nВведите целое число: ";
    //cin.unsetf(ios::skipws);    // не игнорировать разделители
    //cin >> input;
    //if(cin.good()) {}           // ошибок нет          
    // // ОШИБКА!

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
    outfile.close();
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
    infile.close();

///////////////////////////////////////////////////////////

    ofstream outfileString("TEST.TXT");     // создать выходной файл
    outfileString << "Приходит март. Я сызнова служу.\n";     // отправить текст в файл
    outfileString << "В несчастливом кружении событий \n";
    outfileString << "изменчивую прелесть нахожу \n";
    outfileString << "в смешеньи незначительных наитий.\n";
    for(int j = 0; j < str1One.size(); j++)     // каждый символ
        outfileString.put(str1One[j]);          // записывать в файл
    outfileString.close();
    cout << "Файл записан\n";
    // outfileString.seekg(0);      // поставить указатель на начало файла
    const int MAX = 800;                        // размер буфера
    char buffer[MAX];                           // буфер символов
    char ch12;
    ifstream infileString("TEST.TXT");          // создать входной файл
    if(!infileString){
        cerr << "Не удалось открыть файл !" << endl;
        return 1;
    }
    while(!infileString.eof()) {                    // цикл до EOF
    //while(infileString.good())                    // Пока нет ошибок
    //while(infileString)                           // Пока нет ошибок
    //while(!infileString.getline(buffer, MAX)) {        
        infileString.getline(buffer, MAX);          // читает строку текста
        cout << buffer << endl;                     // и выводит ее
        if(infileString.peek() == '\n')
            infileString.ignore();
    }
    while(infileString) {           // читать до EOF или ошибки
        infileString.get(ch12);     // считать символ
        cout << ch12;               // и вывести его
    }
    cout << endl;
    cout << infileString.rdbuf();         // передать его буфер в cout
    cout << endl;
    infileString.close();

///////////////////////////////////////////////////////////

    const int MAXBIN = 100;                         // размер буфера
    int buff[MAXBIN];                               // буфер для целых чисел
    ofstream os("edata.dat", ios::binary);          // записать в него
    os.write(reinterpret_cast<char*>(buff), MAXBIN*sizeof(int));
    os.close();                                     // должен закрыть его
    for(int j = 0; j < MAXBIN; j++)                 // стереть буфер
        buff[j] = 0;            
    ifstream is("edata.dat", ios::binary);          // создать входной поток
    is.read(reinterpret_cast<char*>(buff), MAXBIN*sizeof(int));    // читать из него 
    //reinterpret_cast буфер данных типа int выглядел для функций read() и write() как буфер типа char.
    for(int j = 0; j < MAXBIN; j++)                 // проверка данных
        if(buff[j] != j) {
            cerr << "Некорректные данные!\n";
            break; }
        else 
            cout << "Данные корректны\n";
    is.close();

///////////////////////////////////////////////////////////

    person pers;        // создать объект
    pers.getdata();     // получить данные
    ofstream outfilePerson("PERSON.DAT", ios::binary);                      // создать объект ofstream
    outfilePerson.write(reinterpret_cast<char*>(&pers), sizeof(pers));      // записать в него
    // при записи для данных важен единый формат, а функции любые в классе !
    // Класс, использующийся для чтения объекта в файл, должен быть идентичен классу, использовавшемуся при его записи.
    outfilePerson.close();
    person persTo;      // переменная типа person
    ifstream infilePerson("PERSON.DAT", ios::binary);   // создать поток
    infilePerson.read(reinterpret_cast<char*>(&persTo), sizeof(persTo));    // чтение потока
    persTo.showData();
    infilePerson.close();
*/
///////////////////////////////////////////////////////////

    char chContinue;
    person persMany;
    fstream file;                                                               // создать входной/выходной файл
    file.open("GROUP.DAT",  ios::app | ios::out | ios::in | ios::binary);       // открыть для дозаписи
    // app - Запись, начиная с конца файла (AAPend)
    // out - Открытие для записи (по умолчанию для ofstream)
    // in - Открытие для чтения (по умолчанию для ifstream)
    // binary - Открыть в бинарном (не текстовом) режиме
    do {    // данные от пользователя - в файл
        cout << "\nВведите данные о человеке:" << endl;
        persMany.getdata();     // получить данные
        file.write(reinterpret_cast<char*>(&persMany), sizeof(persMany));       // записать их в файл
        cout << "Продолжить ввод (y/n)? ";
        cin >> chContinue;
    } while(chContinue == 'y');
    file.seekg(0);      // поставить указатель на начало файла
    file.read(reinterpret_cast<char*>(&persMany), sizeof(persMany));        // считать данные о первом человеке
    while(!file.eof()) {            // Выход по EOF
        cout << "\nПерсона:";   
        persMany.showData();    // вывести данные   
        file.read(reinterpret_cast<char*>(&persMany), sizeof(persMany));    // считать данные о следующем
    }
    cout << endl;

///////////////////////////////////////////////////////////

    return 0;
}