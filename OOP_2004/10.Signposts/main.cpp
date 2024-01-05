// Глава 10. Указатели
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DAYS = 7;

///////////////////////////////////////////////////////////

void centimizeLink(double & v) {
    v *= 2.54;      // v — это то же самое, что и var
}
void centimizePointer(double * ptrd) {
    *ptrd *= 2.54;  // *ptrd — это то же самое, что и var
}

///////////////////////////////////////////////////////////

const int MAX = 5;      // количество элементов в массиве
void centimizeMas(double * ptrd) {
    for(int j = 0; j < MAX; j++)
        *ptrd++ *= 2.54;
}

///////////////////////////////////////////////////////////
// ptrorder.cpp
// сортировка двух аргументов по указателю
void order(int* numb1, int* numb2) { // сортировка двух чисел
    if(*numb1 > *numb2) {
        int temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}
void bsort(int* ptr, int n) {   // сортировка методом пузырька
    int j, k;   // индексы в нашем массиве
    for(j = 0; j < n - 1; j++)          // внешний цикл
        for(k = j + 1; k < n; k++)      // внутренний цикл - нам будет известен первый элемент последовательности, самый маленький.
            order(ptr + j, ptr + k);    // сортируем элементы
}
void dispstr(char* ps) {    // По учебнику создается копия массива ? Но изменяется оригинал *ps = '1'; 
    char one = '1';
    while(*ps) {            // пока не встретим конец строки
        //*ps = '1';        // Ошибка для char* str2. Меняется первый элемент оригинала
        ps = &one;          // Меняется копия
        cout << *ps++;      // Вывод копии или 1
        break;  // так как ps = &one делает все строку равной 1
    }
    cout << endl;
}

///////////////////////////////////////////////////////////
//Копирование строк
// Фун-ия не может изменять строку на которую указывает src
void copystr(char* dest, const char* src) {
    while(*src)             // пока не встретим конец строки
        *dest++ = *src++;   // копируем ее
    *dest = '\0';           // заканчиваем строку
}

///////////////////////////////////////////////////////////

class String {
private:
    char* str;  // указатель на строку
public:
    String(char* s) {               // конструктор с одним параметром
        int length = strlen(s);     // вычисляем длину строки
        str = new char[length + 1]; // выделяем необходимую память
        strcpy(str, s); // копируем строку
    }
    ~String() { // деструктор
        cout << "Удаляем строку\n";
        delete[] str;   // освобождаем память
    }
    void display() { // покажем строку на экране
        cout << str << endl;
    }
};

///////////////////////////////////////////////////////////

class Distance {
    int feet;
    float inches;
public:
    void getdist() {
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() const { cout << feet << "\'-" << inches << '\"'; }
};

///////////////////////////////////////////////////////////

class person {
    char name[40];  // имя человека
public:
    void setName() {
        cout << "Введите имя: "; cin >> name;
    }
    void printName() const {
        cout << "\n Имя: " << name;
    }
};

///////////////////////////////////////////////////////////

struct link {       // один элемент списка
    int data;       // некоторые данные
    link* next;     // указатель на следующую структуру
};
class linklist {    // список
    link* first;
public:
    linklist() { first = NULL; }    // первого элемента пока нет
    void additem(int d);    // добавление элемента
    void display();         // показ данных
};
void linklist::additem(int d) {
    link* newlink = new link;   // выделяем память
    newlink->data = d;          // запоминаем данные
    newlink->next = first;      // запоминаем значение first
    first = newlink;            // first теперь указывает на новый элемент
}
void linklist::display() {
    link* current = first;              // начинаем с первого элемента
    while(current) {                    // пока есть данные
        cout << current->data << endl;  // печатаем данные
        current = current->next;        // двигаемся к следующему элементу
    }
}

///////////////////////////////////////////////////////////

class newPerson {
protected:
    string name;    // имя
public:
    void setName() { cout << "Введите имя: "; cin >> name; }
    void printName() { cout << endl << name; }
    string getName() { return name; }
};
void order(newPerson** pp1, newPerson** pp2) {
    if((*pp1)->getName() > (*pp2)->getName()) // если первая строка больше второй,
    {
        newPerson* tempptr = *pp1; // меняем их местами
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}
void bsort(newPerson** pp, int n) {
    int j, k;   // переменные для циклов
    for(j = 0; j < n - 1; j++)      // внешний цикл
        for(k = j + 1; k < n; k++)  // внутренний цикл
            order(pp + j, pp + k);  // сортируем два элемента
}


///////////////////////////////////////////////////////////
// Калькулятор

const int LEN = 80;         // максимальная длина выражения
const int MAXCALC = 40;
class Stack {
private:
    char st[MAXCALC];       // массив данных
    int top;                // количество сохраненных данных
public:
    Stack() { top = 0; }
    void push(char var) { st[++top] = var; }    // поместить в стек
    char pop() { return st[top--]; }            // взять из стека 
    int gettop() { return top; }                // узнать количество элементов
};
class express {
private:
    Stack s;        // стек данных
    char* pStr;     // строка для ввода
    int len;        // длина строки
public:
    express(char* ptr) {
        pStr = ptr;             // запоминаем указатель на строку
        len = strlen(pStr);     // устанавливаем длину
    }
    void parse();               // разбор выражения
    int solve();                // получение результата
};
void express::parse() { // добавляем данные в стек
    char ch;            // символ из строки
    char lastval;       // последнее значение
    char lastop;        // последний оператор
    for(int j = 0; j < len; j++) {  // для всех символов в строке
        ch = pStr[j];   // получаем символ
        if(ch >= '0' && ch <= '9')  // если это цифра,
            s.push(ch - '0');       // то сохраняем ее значение
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if(s.gettop() == 1)     // если это первый оператор,
                s.push(ch);         // помещаем его в стек
            else {
                lastval = s.pop();  // получаем предыдущее число
                lastop = s.pop();   // получаем предыдущий оператор
                if((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-')) {  // если это * или /, а предыдущий был + или -, то
                    s.push(lastop);         // отменяем последние два взятия из стека
                    s.push(lastval);
                }
                else {      // помещаем в стек результат операции
                    switch(lastop) {
                        case '+': s.push(s.pop() + lastval); break;
                        case '-': s.push(s.pop() - lastval); break;
                        case '*': s.push(s.pop() * lastval); break;
                        case '/': s.push(s.pop() / lastval); break;
                        default: cout << "\nНеизвестный оператор"; exit(1);
                    }
                }
                s.push(ch);     // помещаем в стек текущий оператор
            }
        } else {    // какая-то ерунда...
            cout << "\nНеизвестный символ";
            exit(1);
        }
    }
}
int express::solve() {      // убираем данные из стека
    char lastval;           // предыдущее значение
    while(s.gettop() > 1) {
        lastval = s.pop();          // получаем предыдущее значение
        switch(s.pop()) {           // получаем предыдущий оператор
            case '+': s.push(s.pop() + lastval); break;
            case '-': s.push(s.pop() - lastval); break;
            case '*': s.push(s.pop() * lastval); break;
            case '/': s.push(s.pop() / lastval); break;
            default: cout << "\nНеизвестный оператор"; exit(1);
        }
    }
    return int(s.pop()); // последний оператор в стеке - это результат
}

///////////////////////////////////////////////////////////
// Лошадиные скачки
const int CPF = 5;
const int maxHorses = 7;
class track;
class horse {
private:
    const track* ptrTrack;
    const int horse_number;
    float finish_time;
    float distance_run;
public:
    horse(const int n, const track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0) { }
    ~horse() { }
    void display_horse(const float elapsed_time);
};
class track {
private:
    horse* hArray[maxHorses];
    int total_horses;
    int horse_count;
    const float track_length;
    float elapsed_time;
public:
    track(float lenT, int nH);
    ~track();
    void display_track();
    void run();
    float get_track_len() const;
};
/*void horse::display_horse(float elapsed_time)
{
    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    putch(' '); putch('\xDB'); putch(horse_char); putch('\xDB');
    if(distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        if(rand() % 3)
            distance_run += 0.2F;
        finish_time = elapsed_time;
    } else {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) – mins * 60;
        cout << " Время =" << mins << ":" << secs;
    }
}*/
track::track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0) {
    // init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for(int j = 0; j < total_horses; j++)
        hArray[j] = new horse(horse_count++, this);
    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();
}
track::~track() {
    for(int j = 0; j < total_horses; j++)
        delete hArray[j];   // уничтожить объекты класса horse, образованные конструктором класса track

    // delete[] hArray;     // Эта запись удалит массив указателей, но не объекты
}
void track::display_track() {
    //clear_screen();
    for(int f = 0; f <= track_length; f++)
        for(int r = 1; r <= total_horses * 2 + 1; r++) {
            //set_cursor_pos(f * CPF + 5, r);
            if(f == 0 || f == track_length)
                cout << '\xDE';
            else
                cout << '\xB3';
        }
}
void track::run() {
    /*while(!kbhit()) {
        elapsed_time += 1.75;
        for(int j = 0; j < total_horses; j++)
            hArray[j]->display_horse(elapsed_time);
        wait(500);
    }   
    getch();
    cout << endl; */
}
float track::get_track_len() const
{ return track_length; }

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    int var1 = 11;
    int var2 = 22;
    int var3 = 33;      // напечатаем адреса этих переменных
    cout << &var1 << endl << &var2 << endl << &var3 << endl;

    //////////////////////////////////////////////////////////////

    int* ptr;           // это переменная-указатель на целое
    ptr = &var1;        // присвоим ей значение адреса var1
    cout << ptr << endl;    // покажем адрес
    cout << *ptr << endl;   // показываем содержимое переменной через указатель
    ptr = &var2;        // присвоим ей значение адреса var2
    cout << ptr << endl;    // покажем адрес
    cout << *ptr << endl;   // показываем содержимое переменной через указатель

    ptr = &var1;            // пусть ptr указывает на var1
    *ptr = 37;              // то же самое, что var1 = 37;
    var2 = *ptr;            // то же самое, что var2 = var1;
    cout << var1 << " - " << var2 << endl;   // убедимся, что var1 и var2 равно 37

    //////////////////////////////////////////////////////////////
    // Указатель на void
    int intvar;
    float flovar = 98.6;
    // int* ptrint = &flovar; // Так нельзя; типы int* и float* несовместимы
    void* ptrVoid;  // указатель, который может указывать на любой тип данных
    int* ptrint;    // указатель на int
    float* ptrflo;  // указатель на float
    
    ptrint = &intvar;       // так можно: int* = int*
    // ptrint = &flovar;    // так нельзя: int* = float*
    // ptrflo = &intvar;    // так нельзя: float* = int*
    ptrflo = &flovar;       // так можно: float* = float*
    ptrint = reinterpret_cast<int*>(&flovar);
    ptrflo = reinterpret_cast<float*>(&intvar);

    ptrVoid = &intvar;      // так можно: void* = int*
    ptrVoid = &flovar;      // так можно: void* = float*

    //////////////////////////////////////////////////////////////
    // Доступ к массиву по указателю
    int intarray[5] = { 31, 54, 77, 52, 93 };
    for(int j = 0; j < 5; j++)
        // cout << intarray[j] << endl;
        cout << *(intarray + j) << endl;
    cout << "--------------------------" << endl;
    int* ptrintMas;                         // указатель на int
    ptrintMas = intarray;                   // пусть он указывает на наш массив
    for(int j = 0; j < 5; j++)              // для каждого элемента массива
        // *(intarray++)                    // ERROR аналогично вычислению 0x7ffc4baf6390++. intarray - адрес в памяти
        cout << *(ptrintMas++) << endl;     // напечатаем его значение

    //////////////////////////////////////////////////////////////

    double varCen = 10.0;       // значение переменной varCen равно 10 (дюймов)
    cout << "varCen = " << varCen << " дюймов" << endl;
    centimizeLink(varCen);          // передаем переменную varCen
    cout << "varCen = " << varCen << " сантиметров" << endl;
    centimizePointer(&varCen);      // передаем адрес varCen     
    cout << "varCen = " << varCen << " сантиметров" << endl << " ------------- " << endl;

    //////////////////////////////////////////////////////////////

    double varray[MAX] = { 10.0, 43.1, 95.9, 58.7, 87.3 };
    centimizeMas(varray);           // передача по указателю
    // void centimize(double[]);    // передача по значению
    for(int j = 0; j < MAX; j++)
        cout << "varray [" << j << "] = " << varray[j] << " сантиметров" << endl << " ------------- " << endl;

    //////////////////////////////////////////////////////////////

    int n1 = 99, n2 = 11;
    int n3 = 22, n4 = 88;
    order(&n1, &n2);
    order(&n3, &n4);
    cout << "n1 = " << n1 << endl; // выводим переменные
    cout << "n2 = " << n2 << endl; // на экран
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    const int N = 10;   // размер массива
    int arrSort[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 }; // массив для сортировки
    for(int j = 0; j < N; j++)
        cout << arrSort[j] << " ";
    cout << endl << " =      = =      = " << endl;
    bsort(arrSort, N);
    for(int j = 0; j < N; j++)
        cout << arrSort[j] << " ";
    cout << endl;

    //////////////////////////////////////////////////////////////

    char str1[] = "Определение через массив";
    char* str2 = "Определение через указатель";
    //const char* str2 = "Определение через указатель";
    cout << str1 << endl;   // покажем наши строки
    cout << str2 << endl;
    // str1++;              // так делать нельзя указатель-константа (адрес)
    str2++;                 // а так можно указатель-переменная
    cout << str2 << endl;   // значение str2 немного изменилось
    dispstr(str1);          // str1 - адрес константа, передача по значению
    cout << "str1 после dispstr(str1): "; 
    cout << str1 << endl;   // 111111111111111111111
    dispstr(str2); 
    cout << "str2 после dispstr(str2): ";  
    cout << str2 << endl;   // 111111111111111111111

    //////////////////////////////////////////////////////////////
    // Копирование строк
    char* strCopy1 = "Поспешишь - людей насмешишь!";
    char strCopy2[80];              // пустая строка
    copystr(strCopy2, strCopy1);    // копируем строку strCopy1 в strCopy2
    cout << strCopy2 << endl;       // и показываем результат

    //////////////////////////////////////////////////////////////
    // массив указателей на строки
    char* arrptrs[DAYS] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
    for(int j = 0; j < DAYS; j++)
        cout << arrptrs[j] << endl;

    //////////////////////////////////////////////////////////////
    // познакомимся с оператором new
    char* strNew = "Дурная голова ногам покоя не дает.";
    int len = strlen(strNew);       // вычислим длину нашей строки
    char* ptrNew;                   // определим переменную
    ptrNew = new char[len +1];      // выделим память
    strcpy(ptrNew, strNew);         // скопируем строку strNew в ptr
    cout << "ptrNew = " << ptrNew << endl; // покажем что содержится в ptr
    delete[] ptrNew;                // освободим выделенную память
    //ptr = new SomeClass;    // создаем один объект
    //delete ptr;             // скобок не требуется

    //////////////////////////////////////////////////////////////

    String sNew1 = "Тише едешь - дальше будешь.";
    cout << "sNew1 = ";
    sNew1.display();

    //////////////////////////////////////////////////////////////

    Distance dist;
    dist.getdist();         // получаем информацию
    dist.showdist();        // выводим на экран
    Distance* distptr;      // определяем переменную-указатель на Distance
    distptr = new Distance; // создаем объект Distance
    (*distptr).getdist();   // так можно: разыменование указателя это переменная
    distptr->showdist();    // выводим информацию
    cout << endl;
    delete distptr;

    Distance& distNew = *(new Distance); // создаем объект типа Distance
    distNew.getdist();     // доступ к членам класса осуществляем через оператор "."
    distNew.showdist();

    //////////////////////////////////////////////////////////////

    person* persPtr[100];   // массив указателей
    int n = 0;      // количество элементов в массиве
    char choice;
    do {
        persPtr[n] = new person;    // создаем новый объект
        persPtr[n]->setName();      // вводим имя
        n++;        // увеличиваем количество
        cout << "Продолжаем ввод (д/н)?"; // спрашиваем, закончен ли ввод
        cin >> choice;
    } while(choice == 'д');
    for(int j = 0; j < n; j++) {
        cout << "\nИнформация о номере " << j + 1;
        persPtr[j]->printName();
    }
    cout << endl;
    //delete[] persPtr;

    //////////////////////////////////////////////////////////////

    linklist li;        // создаем переменную-список
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);     // добавляем туда несколько чисел
    li.display();       // показываем список

    //////////////////////////////////////////////////////////////

    newPerson* newPersPtr[100]; // массив указателей на newPerson
    int countElement = 0;       // количество элементов в массиве
    char choiceNew;             // переменная для ввода символа
    do {
        newPersPtr[countElement] = new newPerson;   // создаем новый объект
        newPersPtr[countElement]->setName();        // вводим имя
        countElement++;                             // увеличиваем количество
        cout << "Продолжаем ввод (y/n)?";           // спрашиваем, закончен ли ввод
        cin >> choiceNew;
    } while(choiceNew == 'y');
    cout << "\nНеотсортированный список:";
    int j = 0;
    for(j = 0; j < countElement; j++)           // покажем неотсортированный список
        newPersPtr[j]->printName();
    bsort(newPersPtr, countElement);            // отсортируем указатели
    cout << "\nОтсортированный список:";
    for(j = 0; j < countElement; j++)           // покажем отсортированный список
        newPersPtr[j]->printName();
    cout << endl;

    //////////////////////////////////////////////////////////////

    char ans;           // 'д' или 'н'
    char string[LEN];   // строка для разбора
    cout << "\nВведите арифметическое выражение в виде 2+3*4/3-2"
            "\nЧисла должны быть из одной цифры"
            "\nНе используйте пробелы и скобки";
    do {
        cout << "\nВыражение: ";
        cin >> string;                              // вводим строку
        express* eptr = new express(string);        // создаем объект для разбора
        eptr->parse();      // разбираем
        cout << "\nРезультат: " << eptr->solve() << endl;   // решаем
        delete eptr;        // удаляем объект
        cout << "Еще одно выражение (д/н)? ";
        cin >> ans;
    } while(ans == 'д');

    ///////////////////////////////////////////////////////////

    float length;
    int total;
    cout << "\nВведите длину дистанции (от 1 до 12): ";
    cin >> length;
    cout << "\nВведите количество лошадей (от 1 до 7): ";
    cin >> total;
    track theTrack(length, total);
    theTrack.run();

    return 0;
}