#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>     // для функций strcpy, strcat
//#include <process.h>    // Task 6 // для функции exit

using namespace std;

// Task 1
class publication {
private:
    string nameBook;
    float costBook;
public:
    void getdata() {
        cout << "\nВведите название книги: "; cin >> nameBook;
        cout << "Введите стоимость книги: "; cin >> costBook;
    }
    void putdata() const {
        cout << "\n Книга: " << nameBook;
        cout << "\n Цена: " << costBook << endl;
    }
};
// Task 3 start
class sales {
private:
    enum { MONTHS = 3 };
    float quarter[MONTHS];
public:
    void getdata() {
        for (int i = 0; i < MONTHS; i++) {
            cout << "\nВведите общую стоимость книг в " << i+1 << " месяце: "; 
            cin >> quarter[i];
        }
    }
    void putdata() const {
        for (int i = 0; i < MONTHS; i++) {
            cout << "\nОбщая стоимость книг в " << i+1 << " месяце =  " << quarter[i]; 
        }
    }
};
// Task 3 end
//class book : private publication {    // Task 2
class book : private publication, public sales {
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "\nВведите количество страниц: "; cin >> pages;
        sales::getdata();
    }
    void putdata() const {
        publication::putdata();
        cout << "\n Страниц: " << pages;
        sales::putdata();
    }
};
//class type : private publication {    // Task 2
class type : private publication, public sales {
    float minutTime;
public:
    void getdata() {
        publication::getdata();
        cout << "\nВведите время записи в минутах: "; cin >> minutTime;
        sales::getdata();
    }
    void putdata() const {
        publication::putdata();
        cout << "\n Время: " << minutTime << " минут";
        sales::putdata();
    }
};

// Task 2
class String {
protected:
    enum { SZ = 80 };   // размер массива
    char str[SZ];       // массив для хранения строки
public:
    String() { str[0] = '\x0'; }
    String(char s[]) { strcpy(str, s); }
    void display() const { cout << str; }
    operator char*() { return str; }
};
class Pstring : public String {
public:
    //Pstring(char s[]) { 
    Pstring(const char* s) { 
        if (strlen(s) > SZ-1) {
            //strncpy(str, s, SZ-1);
            int j = 0;
            while (j < SZ-1) {
                str[j++] = s[j];
            }
            str[j] = '\0';
        } else
            //str = s;    // ERROR ‘char*’ to ‘char [80]’
            String(s); 
    }
    //Pstring(char s[]) : String(s) {}
};

// Task 4
class disk : public publication {
    enum typeDisk {CD, DVD} typeD;
public:
    void getdata() {
        char type;
        publication::getdata();
        cout << "Выберите тип диска (c - CD, d - DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            typeD = CD;
        } else if (type == 'd' || type == 'D') {
            typeD = DVD;
        } else {
            cout << "Некорректный выбор. Устанавливается тип CD по умолчанию." << endl;
            typeD = CD;
        }
    }
    void putdata() const {
        publication::putdata();
        cout << endl << "Тип диска: " << (typeD == CD ? "CD" : "DVD") << endl;
    }
};

// Task 5
const int LEN = 80;                 // максимальная длина имени
class employee  {                   // некий сотрудник
private:
    char name[LEN];                 // имя сотрудника
    unsigned long number;           // номер сотрудника
public:
    void getdata() {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: "; cin >> number;
    }
    void putdata() const {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};
class employee2 : public employee {
    double compensation;
    enum period {HOUR, WEEK, MONTH} periodMoney;
public:
    void getdata() {
        cout << "\n Введите сумму оплаты труда: "; cin >> compensation;
        char type;
        cout << "Выберите период оплаты труда (h - часовая, w - недельная, m - месячная): ";
        cin >> type;
        if (type == 'h' || type == 'H') {
            periodMoney = HOUR;
        } else if (type == 'w' || type == 'W') {
            periodMoney = WEEK;
        } else if (type == 'm' || type == 'M') {
            periodMoney = MONTH;
        } else {
            cout << "Некорректный выбор. Устанавливается тип оплаты труда по умолчанию." << endl;
            periodMoney = MONTH;
        }
    }
    void putdata() const {
        cout << "\n Оплата труда: " << compensation << endl;
        if (periodMoney == HOUR) {
            cout << "Оплата труда почасовая" << endl;
        } else if (periodMoney == WEEK) {
            cout << "Оплата труда еженедельная" << endl;
        } else {
            cout << "Оплата труда ежемесячная" << endl;
        }
    }
};
class manager : public employee {   // менеджер
private:
    char title[LEN];        // должность, например вице-президент
    double dues;            // сумма взносов в гольф-клуб
public:
    void getdata() {
        employee::getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
    }
};
class scientist : public employee { // ученый
private:
    int pubs;   // количество публикаций
public:
    void getdata() {
        employee::getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
    }
    void putdata() const {
        employee::putdata();
        cout << "\n Количество публикаций: " << pubs;
    }
};
class laborer : public employee { // рабочий
};
class manager2 : public employee2, public manager {
public:
    void getdata() {
        manager::getdata();
        employee2::getdata();
    }
    void putdata() const {
        manager::putdata();
        employee2::putdata();
    }
};
class scientist2 : public employee2, public scientist {
public:
    void getdata() {
        scientist::getdata();
        employee2::getdata();
    }
    void putdata() const {
        scientist::putdata();
        employee2::putdata();
    }
};
class laborer2 : public employee2, public laborer {
public:
    void getdata() {
        employee2::getdata();
    }
    void putdata() const {
        employee2::putdata();
    }
};


// Task 6
// arrover3.cpp демонстрация создания безопасного массива, проверяющего свои индексы при использовании используется перегрузка операции []
const int LIMIT = 100;  // размер массива
class safearray {
private:
    int arr[LIMIT];
public:
    int& operator[](int n) {  // обратите внимание, что функция возвращает ссылку!
        if(n < 0 || n >= LIMIT) { cout << "\nОшибочный индекс!"; exit(1); }
        return arr[n];
    }
};
class safehilo : private safearray {
    int up;
    int lower;
    int dif;
public:
    safehilo() = default;
    safehilo(int u, int l) : up(u), lower(l) { dif = up - lower;}
    int& operator[](int n) {
        return safearray::operator[](n - lower);
    }
};

// Task 7
class Counter {
protected:
    int count;     // счетчик
public:
    Counter() : count() {}
    Counter(int c) : count(c) { }
    unsigned int get_count() const // получение значения
    { return count; }
    Counter operator++() { return Counter(++count); }
};
class CountDn : public Counter {
public:
    CountDn() : Counter() { }
    CountDn(int c) : Counter(c) { }
    CountDn operator--() { return CountDn(--count); }
};
class CountPrefPost : public CountDn {
public:
    CountPrefPost() : CountDn() { }
    CountPrefPost(int c) : CountDn(c) { }
    // 1 // CountPrefPost& operator++() { ++count; return *this; }
    // 2 // CountPrefPost operator--() { return CountPrefPost(--count); }
    // 2 // CountPrefPost operator++() { return CountPrefPost(++count); }
    CountPrefPost operator--() { CountDn::operator--(); return *this; }
    CountPrefPost operator++() { CountDn::operator++(); return CountPrefPost(count); }
    CountPrefPost operator--(int) { return CountPrefPost(--count); }
    CountPrefPost operator++(int) { return CountPrefPost(++count); }
};

// Task 8
class Pstring2 : public Pstring {
public:
    Pstring2(char s[]) : Pstring(s) {}
    //char& left(char s[], int count);
    char left(char s[], int count);
    void mid(char s[], int symbol, int count);
    void right(char s[], int count);
};
char Pstring2::left(char s[], int count) {
    int j = 0;
    while (j < count) {
        str[j] = s[j++];
    }
    return *str;
}
void Pstring2::mid(char s[], int symbol, int count) {
    int j = symbol;
    while (j < count+symbol) {
        str[j] = s[j++];
    }
}
void Pstring2::right(char s[], int count) {
    int j = count;
    while (j > 0) {
        str[j] = s[j--];
    }
}


// Task 9
class date {
    int day;
    int mounth;
    int year;
public:
    date() : day(0), mounth(0), year(0) {};
    void getdate(int days, int mounths, int years) {
        day = days;
        mounth = mounths;
        year = years;
    }
    void showdate() const {
        cout << "День = " << day << endl;
        cout << "Месяц = " << mounth << endl;
        cout << "Год = " << year << endl;
    }
};
class publication2 : public publication, public date {
protected:
    date da;
public:
    void getdata() {
        publication::getdata();
        int day, mounth, year;
        char slash = '/';
        cout << "Введите дату в формате 31/12/2002" << endl;
        cin >> day >> slash >> mounth >> slash >> year;
        da.getdate(day, mounth, year);
    }
    void putdata() const {
        publication::putdata();
        da.showdate();
    }
};
class book2 : public publication2, public sales {
    int pages;
public:
    void getdata() {
        publication2::getdata();
        cout << "\nВведите количество страниц: "; cin >> pages;
        sales::getdata();
    }
    void putdata() const {
        publication2::putdata();
        cout << "\n Страниц: " << pages;
        sales::putdata();
    }
};
class type2 : private publication2, public sales {
    float minutTime;
public:
    void getdata() {
        publication2::getdata();
        cout << "\nВведите время записи в минутах: "; cin >> minutTime;
        sales::getdata();
    }
    void putdata() const {
        publication2::putdata();
        cout << "\n Время: " << minutTime << " минут";
        sales::putdata();
    }
};

// Task 10
class executive : public manager {
    int bonusYear;
    int shareNumbers;
public:
    void getdata() {
        manager::getdata();
        cout << "\nВведите размер годового бонуса: "; cin >> bonusYear;
        cout << "\nВведите количество акций: "; cin >> shareNumbers;
    }
    void putdata() const {
        manager::putdata();
        cout << "\nРазмер годового бонуса: " << bonusYear;
        cout << "\nКоличество акций: " << shareNumbers;
    }
};

// Task 11
class Stack {
protected:
    enum { MAX = 10 };   // размер стека
    int st[MAX];        // данные, хранящиеся в стеке
    int top;            // индекс последнего элемента в стеке
public:
    Stack() { top = -1; }
    void push(int var) { st[++top] = var; }
    int pop() { return st[top--]; }
};
class Stack2 : public Stack {
public:
    void push(int var) {
        if(top >= MAX - 1) {    // если стек полон, то ошибка
            cout << "\nОшибка: стек полон"; 
            exit(1); 
        }
        Stack::push(var);       // вызов функции push класса Stack
    }
    int pop() {         // извлечение числа из стека
        if(top < 0) {   // если стек пуст, то ошибка
            cout << "\nОшибка: стек пуст\n"; 
            exit(1); 
        }
        return Stack::pop();    // вызов функции pop класса Stack(можно без return)
    }
};
class pairStack : public Stack2 {
public:
    int x, y;
public:
    pairStack() : x(0), y(0) {}
    pairStack(int x1, int y1) {
        x = x1; 
        y = y1;
        push(x, y);
    }
    void push(int xin, int yin) {
        x = xin;
        y = yin;
        Stack2::push(x);
        Stack2::push(y);
    }
    pairStack pop() {
        y = Stack2::pop();
        x = Stack2::pop();
        return pairStack(x, y);
    }
};


// Task 12
#include "task12.h"
class sterfrac : public sterling, public fraction {
private:
    int eighths;
    sterling str;
    fraction fra;
public:
    sterfrac() : sterling(), fraction() {}
    sterfrac(sterling one2, fraction two2) {
        str = one2;
        fra = two2;
        fra.lowterms();
    }
    sterfrac(long pounds2, int shillings2, int pence2, int dividend2, int divisor2) {
        str = sterling(pounds2, shillings2, pence2);
        fra = fraction(dividend2, divisor2);
        fra.lowterms();
    }
    void setSterling() {
        cout << "Введите денежки в формате - 1.1.1-1/4 или 9.19.11-7/8" << endl;
        str.getSterling();
        cout << "Введите дробные части пенни в одну строку" << endl;
        fra.enterFr();
    }
    void getSterling() const {
        str.putSterling();
        cout << "-";
        fra.showFr();
    }
    sterfrac operator+(sterfrac);
    sterfrac operator-(sterfrac);
    sterfrac operator*(sterfrac);
    sterfrac operator/(sterfrac);
};
sterfrac sterfrac::operator+(sterfrac two) {
    sterling newStr = str.operator+(two.str);
    fraction newFra = fra.operator+(two.fra);
    sterfrac three(newStr, newFra);
    return three;
}
sterfrac sterfrac::operator-(sterfrac two) {
    sterling newStr = str.operator-(two.str);
    fraction newFra = fra.operator-(two.fra);
    sterfrac three(newStr, newFra);
    return three;
}
sterfrac sterfrac::operator*(sterfrac two) {
    sterling newStr = str.operator*(two.str);
    fraction newFra = fra.operator*(two.fra);
    sterfrac three(newStr, newFra);
    return three;
}
sterfrac sterfrac::operator/(sterfrac two) {
    sterling newStr = str.operator/(two.str);
    fraction newFra = fra.operator/(two.fra);
    sterfrac three(newStr, newFra);
    return three;
}

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    /*1. Представьте себе издательскую компанию, которая торгует книгами и аудио-записями этих книг. 
    Создайте класс publication, в котором хранятся название (строка) и цена (типа float) книги. От этого 
    класса наследуются еще два класса: book, который содержит информацию о количестве страниц в книге 
    (типа int), и type, который содержит время записи книги в минутах (тип float). В каждом из этих трех 
    классов должен быть метод getdata(), через который можно получать данные от пользователя с клавиатуры,
    и putdata(), предназначенный для вывода этих данных. 
    Напишите функцию main() программы для проверки классов book и type. Создайте их объекты в программе и 
    запросите пользователя ввести и вывести данные с использованием методов getdata() и putdata(). */
    book readBook;
    type listenBook;
    readBook.getdata();
    listenBook.getdata();
    readBook.putdata();
    listenBook.putdata();

    /*2. Вспомните пример STRCONV из главы 8. Класс String в этом примере имеет дефект: у него нет защиты 
    на тот случай, если его объекты будут инициализированы слишком длинной строкой (константа SZ имеет 
    значение 80). Например, определение String s = "Эта строка имеет очень большую длину и мы можем быть 
    уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям."; будет 
    причиной переполнения массива str строкой s с непредсказуемыми последствиями вплоть до краха системы. 
    Создадим класс Pstring, производный от класса String, в котором предотвратим возможность переполнения 
    буфера при определении слишком длинной строковой константы. Новый конструктор производного класса будет 
    копировать в str только SZ-1 символов, если строка окажется слишком длинной, и будет копировать строку 
    полностью, если она будет иметь длину меньшую, чем SZ. Напишите функцию main() программы для проверки 
    ее работы со строками разной длины. */
    Pstring s1 = "Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям.";
    s1.display();
    cout << " - - - " << endl;
    Pstring s2 = "Короткая строка.";
    s2.display();

    /*3. Начните с классов book, type и publication из упражнения 1. Добавьте базовый класс sales, в 
    котором содержится массив, состоящий из трех значений типа float, куда можно записать общую стоимость 
    проданных книг за последние три месяца. Включите в класс методы getdata() для получения значений 
    стоимости от пользователя и putdata() для вывода этих цифр. Измените классы book и type так, чтобы они 
    стали производными обоих классов: publications и sales. Объекты классов book и type должны вводить и 
    выводить данные о продажах вместе с другими своими данными. Напишите функцию main() для создания 
    объектов классов book и type, чтобы протестировать возможности ввода/вывода данных. */
    book readBook3;
    type listenBook3;
    readBook3.getdata();
    listenBook3.getdata();
    readBook3.putdata();
    listenBook3.putdata();

    /*4. Предположим, что издатель из упражнений 1 и 3 решил добавить к своей продукции версии книг на комп.
    дисках для тех, кто любит читать книги на своих компьютерах. Добавьте класс disk, который, как book и 
    type, является производным класса publication. Класс disk должен включать в себя те же функции, что и в 
    других классах. Полем только этого класса будет тип диска: CD или DVD. Для хранения этих данных вы 
    можете ввести тип enum. Пользователь должен выбрать подходящий тип, набрав на клавиаtype с или d. */
    disk oneD;
    oneD.getdata();
    oneD.putdata();

    /*5. Создайте производный класс employee2 от базового класса employee из программы EMPLOY этой главы. 
    Добавьте в новый класс поле compensation типа double и поле period типа enum для обозначения периода 
    оплаты работы служащего: почасовая, понедельная или помесячная. Для простоты вы можете изменить классы 
    laborer, manager и scientist так, чтобы они стали производными нового класса employee2. Однако заметим,
    что во многих случаях создание отдельного класса compensation и трех его производных классов manager2, 
    scientist2 и laborer2 более соответствовало бы духу ООП. Затем можно применить множественное 
    наследование и сделать так, чтобы эти три новых класса стали производными класса compensation и 
    первоначальных классов manager, scientist и laborer. Таким путем можно избежать модификации исходных классов.*/
    manager2 man;
    man.getdata();
    man.putdata();
    scientist2 sci;
    sci.getdata();
    sci.putdata();
    laborer2 lab;
    lab.getdata();
    lab.putdata();

    /*6. Вспомним программу ARROVER3 из главы 8. Сохраним класс safearray таким же и, используя наследование, 
    добавим к нему возможность для пользователя определять верхнюю и нижнюю границы массива в конструкторе.
    Это похоже на упражнение 9 из главы 8, за исключением того, что применено наследование для создания 
    нового класса (можно назвать его safehilo) взамен модификации исходного класса. */
    int up, lower;
    cout << "Введите нижнюю границу массива: ";
    cin >> lower;
    cout << "Введите верхнюю границу массива: "; 
    cin >> up;
    safehilo sa1(up, lower);
    int j = 0;
    for(j = lower; j < up; j++)
        sa1[j] = j * 10;        // используем функцию слева от знака =
    for(j = lower; j < up; j++) {
        int temp = sa1[j];      // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }

    /*7. Вспомним программу COUNTEN2 из этой главы. В ней можно увеличивать и уменьшать счетчик, используя 
    префиксные операции. Используя наследование, добавьте возможность использования постфиксных операций 
    для случаев увеличения и уменьшения. (Описание постфиксных операций вы сможете найти в главе 8.) */
    CountPrefPost c1;     // переменные класса CountPrefPost
    CountPrefPost c2(100);
    cout << "\nc1 = " << c1.get_count();        // выводим значения на экран
    cout << "\nc2 = " << c2.get_count();
    ++c1; c1++; ++c1;       // увеличиваем c1
    cout << "\nc1 = " << c1.get_count();        // показываем результат
    --c2; c2--;
    cout << "\nc2 = " << c2.get_count();
    CountPrefPost c3 = c2--;      // создаем переменную c3 на основе c2
    cout << "\nc3 = " << c3.get_count();        // показываем значение

    /*8. В некоторых компьютерных языках, таких, как Visual Basic, есть операции, с помощью которых можно 
    выделить часть строки и присвоить ее другой строке. (В стандартном классе string предложены различные 
    подходы.) Используя наследование, добавьте такую возможность в класс Pstring из упражнения 2. В новом 
    производном классе Pstring2 разместите три новых функции: left(), mid() и right().
        s2.left(s1, n)      // в строку s2 помещаются n самых левых символов строки s1
        s2.mid(s1, s, n)    // в строку s2 помещаются n символов из строки начиная с символа номер s
        s2.right(s1, n)     // в строку s2 помещаются n самых правых символов строки s1
    Вы можете использовать цикл for для копирования символ за символом подходящих частей строки s1 во 
    временный объект класса Pstring2, который затем их возвратит. Для получения лучшего результата 
    используйте в этих функциях возврат по ссылке, чтобы они могли быть использованы с левой стороны знака 
    «равно» для изменения части существующей строки. */
    Pstring2 s18 = "Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям.";
    s18.display();
    cout << " - - - " << endl;
    Pstring2 s28 = "Короткая строка.Эта строка имеет очень большую длину и мы можем быть уверены, что она ///////////////////////////////////";
    s28.left(s18, 5);
    s28.display();

    /*9. Вспомним классы publication, book и type из упражнения 1. Предположим, что мы хотим добавить в 
    классы book и type дату выхода книги. Создайте новый производный класс publication2, который является 
    производным класса publication и включает в себя поле, хранящее эту дату. Затем измените классы book и 
    type так, чтобы они стали производными класса publication2 вместо publication. Сделайте необходимые 
    изменения функций классов так, чтобы пользователь мог вводить и выводить дату выхода книги. Для даты 
    можно использовать класс data из упражнения 5 главы 6, который хранит дату в виде трех целых: 
    для месяца, для дня и для года. */
    book2 readBook2;
    type2 listenBook2;
    readBook2.getdata();
    listenBook2.getdata();
    readBook2.putdata();
    listenBook2.putdata();

    /*10. В программе EMPMULT этой главы существует только один тип должности менеджера. В любой серьезной 
    компании кроме менеджеров существуют еще и управляющие. Создадим производный от класса manager класс 
    executive. (Мы предполагаем, что управляющий — это главный менеджер.) Добавочными данными этого класса 
    будут размер годовой премии и количество его акций в компании. Добавьте подходящие методы для этих 
    данных, позволяющие их вводить и выводить. */
    executive mainMan;
    mainMan.getdata();
    mainMan.putdata();

    /*11. В различных ситуациях иногда требуется работать с двумя числами, объединенными в блок. Например, 
    каждая из координат экрана имеет горизонтальную составляющую (x) и вертикальную (y). Представьте такой 
    блок чисел в качестве структуры pair, которая содержит две переменные типа int. Теперь предположим, что
    мы хотим иметь возможность хранить переменные типа pair в стеке. То есть мы хотим иметь возможность 
    положить переменную типа pair в стек путем вызова метода push() с переменной типа pair в качестве 
    аргумента и вынуть ее из стека путем вызова метода pop(), возвращающего переменную типа pair. Начнем с 
    класса Stack2 программы STAKEN из этой главы. Создадим производный от него класс pairStack. В нем будут
    содержаться два метода: перегружаемый метод push() и перегружаемый метод pop(). Метод pairStack::push()
    должен будет сделать два вызова метода Stack2::push(), чтобы сохранить оба числа из пары, а метод 
    pairStack::pop() должен будет сделать два вызова метода Stack2::pop(). */
    pairStack one9;
    one9.push(1, 2);
    one9.push(2, 2);
    one9.push(3, 4);
    one9.push(3, 4);
    one9.pop();
    cout << endl << one9.x << " - " << one9.y;
    pairStack two9;
    two9 = one9.pop();
    cout << endl << one9.x << " - " << one9.y;
    one9.pop();
    cout << endl << one9.x << " - " << one9.y;
    two9.pop();
    cout << endl << two9.x << " - " << two9.y;

    /*12. Рассмотрим старую Британскую платежную систему фунты-стерлинги-пенсы (см. упражнение 10 главы 4 
    «Структуры»). Пенни в дальнейшем делятся на фартинги и полупенни. Фартинг — это 1/4 пенни. Существовали 
    монеты фартинг, полфартинга и пенни. Любые сочетания монет выражались через восьмые части пенни:
        1/8 пенни — это полфартинга;
        1/4 пенни — это фартинг;
        3/8 пенни — это фартинг с половиной;
        1/2 пенни — это по\пенни;
        5/8 пенни — это полфартинга плюс по\пенни;
        3/4 пенни — это по\пенни плюс фартинг;
        7/8 пенни — это по\пенни плюс фартинг с половиной.
    Давайте предположим, что мы хотим добавить в класс sterling возможность пользоваться этими дробными 
    частями пенни. Формат ввода/вывода может быть похожим на £1.1.1-1/4 или £9.19.11-7/8, где дефисы 
    отделяют дробные части от пенни. Создайте новый класс sterfrac, производный от класса sterling. В нем 
    должна быть возможность выполнения четырех основных арифметических операций со стерлингами, включая 
    восьмые части пенни. Поле eighths типа int определяет количество восьмых. Вам нужно будет перегрузить
    методы класса sterling, чтобы они могли работать с восьмыми частями. Пользователь должен иметь 
    возможность ввести и вывести дробные части пенни. Не обязательно использовать класс fraction полностью
    (см. упражнение 11 главы 6), по вы можете это сделать для большей точности. */
    sterfrac one12(4, 4, 4, 4, 4);
    sterfrac two12;
    two12.setSterling();
    one12.getSterling();
    cout << endl;
    two12.getSterling();
    cout << endl;
    sterfrac three12;
    three12 = one12 + two12;
    three12.getSterling();
    cout << endl;
    three12 = one12 / two12;
    three12.getSterling();

    return 0;
}