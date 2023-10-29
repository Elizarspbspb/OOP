#include <iostream>
#include <iomanip>      // setw
#include <cstring>

using namespace std;

///////////////////////////////////////////////////////////
class part
{
private:
    char partname[30];  // название
    int partnumber;     // номер
    double cost;        // цена
public:
    void setpart(const char pname[], int pn, double c) {
        strcpy(partname, pname);
        partnumber = pn;
        cost = c;
    }
    void showpart() {
        cout << "\nНазвание = " << partname;
        cout << ", номер = " << partnumber;
        cout << ", цена = $" << cost;
    }
};

///////////////////////////////////////////////////////////

class String {
private:
    enum { SZ = 80 };   // максимальный размер строки
    char str[SZ];       // сама строка
public: 
    String() { str[0] = '\0'; }                 // конструктор без параметров
    String(const char s[]) { strcpy(str, s); }  // конструктор с одним параметром
    void display() const { cout << str; }       // показ строки
    void concat(String s2) {                    // сложение строк
        if(strlen(str) + strlen(s2.str) < SZ)
            strcat(str, s2.str);                // библиотечная функция сложение строк
        else
            cout << "\nПереполнение!";
    }
};

///////////////////////////////////////////////////////////

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

    //////////////////////////////////////////////////////////////

    cout << "\nВведите несколько строк (завершение цикла символ $):\n";
    cin.ignore();
    cin.get(strSTR, MAXSTR, '$');
    cout << "Вы ввели:\n" << strSTR << endl;

    //////////////////////////////////////////////////////////////
    
    char strSTR2[MAXSTR]; // сама строка
    int j = 0;
    for(j = 0; j < strlen(strSTR); j++)
        strSTR2[j] = strSTR[j];  // символов из str1 в str2
    strSTR2[j] = '\0';
    cout << "-Копия строк:" << endl;
    cout << strSTR2 << endl;
    //strcpy(strSTR2, strSTR);    // Библиотечная функция копирования строки из <cstring>

    //////////////////////////////////////////////////////////////

    const int DAYS = 7;         // количество строк в массиве
    const int MAXLEN = 23;      // максимальная длина каждой из них
    // массив строк
    char star[DAYS][MAXLEN] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    // вывод всех строк на экран
    for(int j = 0; j < DAYS; j++)
        cout << star[j] << endl;

    //////////////////////////////////////////////////////////////

    part part1, part2, part3;
    part1.setpart("муфта", 4473, 217.55);
    part2.setpart("вороток", 9924, 419.25);
    cout << "\nПервая деталь: "; part1.showpart();
    cout << "\nВторая деталь: "; part2.showpart();
    cout << endl;
    part3 = part2;

    //////////////////////////////////////////////////////////////

    String s1("С Новым годом! ");       // конструктор с одним параметром
    String s2 = "С новым счастьем!";    // аналогично, но в другой форме
    String s3;                          // конструктор без параметров
    cout << "\ns1 ="; s1.display();
    cout << "\ns2 ="; s2.display();
    cout << "\ns3 ="; s3.display();     // показываем все строки
    s3 = s1;    // поместив массив в класс объекту может быть присвоено значение другого объекта
    cout << "\ns3 ="; s3.display();     // присвоение
    s3.concat(s2);  
    cout << "\ns3 ="; s3.display();
    cout << endl;

    //////////////////////////////////////////////////////////////

    return 0;
}