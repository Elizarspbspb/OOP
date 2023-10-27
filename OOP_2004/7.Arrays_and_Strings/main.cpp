#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;

const int MAX = 100;
//////////////////////////////////////////////////////////////

void display(double[DISTRICTS][MONTHS]);

//////////////////////////////////////////////////////////////

struct part {
    int modelnumber;
    int partnumber;
    float cost;
};

///////////////////////////////////////////////////////////

class Stack {
private:
    enum { MAX = 10 };  // немного нестандартный синтаксис
    // or
    // static const int MAX = 10;
    int st[MAX];        // стек в виде массива
    int top;            // вершина стека
public:
    Stack() { top = 0; }
    void push(int var)  // поместить в стек
    { st[++top] = var; }
    int pop()           // взять из стека
    { return st[top--]; }
};

///////////////////////////////////////////////////////////

class Distance {
private:
    int feet;
    float inches;
public:
    void getdist() // получение информации
    {
        cout << "\n Введите футы: "; cin >> feet;
        cout << " Введите дюймы: "; cin >> inches;
    }
    void showdist() const // показ информации
    { cout << feet << "\'-" << inches << '\"'; }
};

///////////////////////////////////////////////////////////
// cardaray.cpp     класс игральных карт
enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card {
private:
    int number;
    Suit suit;
public:
    card() {}                   // конструктор
    void set(int n, Suit s)     // установка значения
    { suit = s; number = n; }
    void displayCard();             // показ карты
};
/////////////////////////////////////////////////////////////
void card::displayCard() {
    if(number >= 2 && number <= 10)
        cout << number;
    else {
        switch(number) {
            case jack: cout << 'J'; break;
            case queen: cout << 'Q'; break;
            case king: cout << 'K'; break;
            case ace: cout << 'A'; break;
        }
    }
    switch(suit) {
        case clubs: cout << static_cast<char>(5); break;    // печать в виде символов
        case diamonds: cout << static_cast<char>(4); break;
        case hearts: cout << static_cast<char>(3); break;
        case spades: cout << static_cast<char>(6); break;
    }
}

/////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    int age[4];
    for (int j = 0; j < 4; j++) {
        cout << "Введите возраст: ";
        cin >> age[j];
    }
    for (int j = 0; j < 4; j++)
        cout << "Вы ввели: " << age[j] << endl;
    
    //////////////////////////////////////////////////////////////

    const int SIZE = 6;
    double sales[SIZE];
    cout << "Введите объем продаж на каждый из шести дней\n";
    for (int j = 0; j < SIZE; j++)
        cin >> sales[j];
    double total = 0;
    for (int j = 0; j < SIZE; j++)
        total += sales[j];
    double average = total / SIZE;
    cout << "Средний объем: " << average << endl;

    //////////////////////////////////////////////////////////////

    int month, day, total_days;
    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cout << "\n Введите месяц (от 1 до 12): ";
    cin >> month;
    cout << "\n Введите день (от 1 до 31): ";
    cin >> day;
    total_days = day;
    for (int j = 0; j < month - 1; j++)
        total_days += days_per_month[j];
    cout << "Общее число дней с начала года: " << total_days << endl;

    //////////////////////////////////////////////////////////////

    int d, m;
    double market[DISTRICTS][MONTHS];
    cout << endl;
    for (d = 0; d < DISTRICTS; d++)
        for (m = 0; m < MONTHS; m++) {
            cout << "Введите объем продаж для отдела " << d + 1;
            cout << ", за месяц " << m + 1 << ": ";
            cin >> market[d][m];
        }
    cout << endl << endl;
    cout << "Месяц\n";
    cout << "   1   2   3";
    for (d = 0; d < DISTRICTS; d++) {
        cout << "\nОтдел " << d + 1;
        for (m = 0; m < MONTHS; m++)
            cout << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << setprecision(2)
                << setw(10)
                << market[d][m];
    }
    cout << endl;

    //////////////////////////////////////////////////////////////

    int date, mon;
    double salesDouble[DISTRICTS][MONTHS] =
    {
        { 1432.07,  234.50,     654.01 },
        { 322.00,   13838.32,   17589.88 },
        { 9328.34,  934.00,     4492.30 },
        { 12838.29, 2332.63,    32.93 }
    };
    cout << endl << endl;
    cout << "Месяц\n";
    cout << "   1   2   3";
    for (date = 0; date < DISTRICTS; date++)  {
        cout << "\nОтдел " << date + 1;
        for (mon = 0; mon < MONTHS; mon++) {
            cout << setw(10) << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint) << setprecision(2)
                << salesDouble[date][mon];
        }
    }
    display(salesDouble);
    cout << endl;

    //////////////////////////////////////////////////////////////

    int number;
    part apart[SIZE];
    for (number = 0; number < SIZE; number++) {
        cout << endl;
        cout << "Введите номер модели: ";
        cin >> apart[number].modelnumber;
        cout << "Введите номер части: ";
        cin >> apart[number].partnumber;
        cout << "Введите стоимость: ";
        cin >> apart[number].cost;
    }
    cout << endl;
    for (number = 0; number < SIZE; number++) {
        cout << "Модель " << apart[number].modelnumber;
        cout << "Часть " << apart[number].partnumber;
        cout << "Стоимость " << apart[number].cost << endl;
    }   

    //////////////////////////////////////////////////////////////

    Stack s1;
    s1.push(11);
    s1.push(22);
    cout << "1: " << s1.pop() << endl;
    cout << "2: " << s1.pop() << endl;
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    cout << "3: " << s1.pop() << endl;
    cout << "4: " << s1.pop() << endl;
    cout << "5: " << s1.pop() << endl;
    cout << "6: " << s1.pop() << endl;

    //////////////////////////////////////////////////////////////

    Distance dist[MAX]; // массив переменных
    int n = 0;          // счетчик данных
    char ans;           // ответ пользователя (y/n)
    cout << endl;
    do {
        cout << "Введите длину номер " << n + 1;
        dist[n++].getdist();    // получаем и сохраняем длину
        cout << "Продолжить ввод (y/n)?: ";
        cin >> ans;
        if(n >= MAX) {
            cout << "\nМассив полон!!!";
            break;
        }
    } while(ans != 'n');    // продолжать, пока не будет введено 'n'
    // показываем все введенное
    for (int j = 0; j < n; j++) {
        cout << "\nДлина номер " << j + 1 << " : ";
        dist[j].showdist();
    }
    cout << endl;

    //////////////////////////////////////////////////////////////
    // cardaray.cpp
    // класс игральных карт
    card deck[52];
    cout << endl;
    for (int j = 0; j < 52; j++) { // создаем упорядоченную колоду карт
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    // показываем исходную колоду
    cout << "Исходная колода:\n";
    for (int j = 0; j < 52; j++) {
        deck[j].displayCard();
        cout << " ";
        if(!((j + 1) % 13))     // начинаем новую строку после каждой 13-й карты
            cout << endl;
    }
    srand(time(NULL));          // инициализируем генератор случайных чисел
    for (int j = 0; j < 52; j++) {
        int k = rand() % 52;    // выбираем случайную карту
        card temp = deck[j];    // и меняем ее с текущей
        deck[j] = deck[k];
        deck[k] = temp;
    }
    // показываем перемешанную колоду
    cout << "\nПеремешанная колода:\n";
    for(int j = 0; j < 52; j++) {
        deck[j].displayCard();
        cout << " ";
        if(!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            cout << endl;
    }
    
    return 0;
}

// display()    функция для вывода на экран массива
void display(double funsales[DISTRICTS][MONTHS]) {
    int d, m;
    cout << endl << endl;
    cout << "Месяц\n";
    cout << "1   2   3";
    for (d = 0; d < DISTRICTS; d++) {
        cout << "\nОтдел " << d + 1;
        for (m = 0; m < MONTHS; m++) {
            cout << setiosflags(ios::fixed) << setw(10)
                << setiosflags(ios::showpoint) << setprecision(2)
                << funsales[d][m];
        }
    }
}