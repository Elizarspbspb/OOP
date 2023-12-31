// Глава 10. Указатели
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
//#include <string> // start 6
#include <iomanip>  // для использования setw

using namespace std;

// Task 2
class String {  // пользовательский строковый тип
private:
    char *str;  // указатель на строку
public:
    String(char *s) {
        int length = strlen(s);     // длина строки из аргумента
        str = new char[length + 1]; // занять память
        strcpy(str, s);             // скопировать туда строку
    }
    ~String() { delete str; }
    void display() { cout << str; }
    void upit();                    // каждый символ в верхний регистр
};
void String::upit() {
    char *upSymb = str;              // указатель на эту строку
    while(*upSymb) {                 // до пустого символа,
        *upSymb = toupper(*upSymb);  // каждый символ в ВЕРХНИЙ РЕГИСТР
        cout << toupper(*upSymb);
        upSymb++;                    // перейти к следующему символу
    }
}

///////////////////////////////////////////////////////////

// Task 3
void order(char** numb1, char** numb2) {
    if(strcmp(*numb1, *numb2) > 0) { 
        char *temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}
void bsort(char** ptr, int n) {   // сортировка методом пузырька
    int j, k;   // индексы в нашем массиве
    for(j = 0; j < n - 1; j++)          // внешний цикл
        for(k = j + 1; k < n; k++)      // внутренний цикл - нам будет известен первый элемент последовательности, самый маленький.
            order(ptr + j, ptr + k);    // сортируем элементы
}

///////////////////////////////////////////////////////////

// Task 4
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
    ~linklist();
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
linklist::~linklist() {
    cout << "Деструктор linklist" << endl;
    link* current = first;              // установить указатель на первый элемент
    while(current != NULL) {            // выход по достижении последнего элемента
        link* temp = current;           // сохранить указатель на данный элемент
        cout << current->data << endl;  // 64 49 36 25
        current = current->next;        // получить ссылку на следующую ссылку
        delete temp;                    // удалить эту ссылку
        cout << current->data << endl;  // 49 36 25
    }
}

///////////////////////////////////////////////////////////

//Task 5
void addarrays(float *one, float *two, float *three, int count) {
    for (int i = 0; i < count; i++) {
        *three++ = *one + *two++;
        cout << "one = " << one << endl;        // one = 0x7ffc4baf639c
        cout << "*one = " << *one << endl;      // *one = 12.5
        cout << "++one = " << ++one << endl;    // ++one = 0x7ffc4baf63a0
    }
}

///////////////////////////////////////////////////////////

//Task 6
int compstr(const char * first, const char * second) {
    //int size = (length(first) > length(second)) ? first : second;
    while(*first != '\0' && *second != '\0') {
        if (*first < *second) {
            //cout << *first << " - " << *second << endl;
            return -1; 
        } else if (*first > *second) {
            //cout << *first << " - " << *second << endl;
            return 1;
        }
        first++; 
        second++;
    }
    return 0;
}

///////////////////////////////////////////////////////////

// Task 7
class person {
    char name[40];  // имя человека
    float salary;
public:
    void setData() {
        cout << "Введите имя: "; cin >> name;
        cout << "Введите зарплату: "; cin >> salary;
    }
    void printData() const {
        cout << "\n Имя: " << name;
        cout << "\n Зарплата: " << salary;
    }
    string getName() { return name; }
    float getSalary() { return salary; }
    //void salsort(person** , int );
};
void order(person** pp1, person** pp2) {
    if((*pp1)->getSalary() > (*pp2)->getSalary()) // если первая строка больше второй,
    {
        person* tempptr = *pp1; // меняем их местами
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}
//void person::salsort(person** pp, int n) {
void salsort(person** pp, int n) {
    int j, k;   // переменные для циклов
    for(j = 0; j < n - 1; j++)      // внешний цикл
        for(k = j + 1; k < n; k++)  // внутренний цикл
            order(pp + j, pp + k);  // сортируем два элемента
}

///////////////////////////////////////////////////////////

// Task 8
struct link8 {       // один элемент списка
    int data;       // некоторые данные
    link8* next;     // указатель на следующую структуру
};
class linklistNew {    // список
    link8* first;
    link8* last;
public:
    linklistNew() { first = NULL; }     // первого элемента пока нет
    void additemFirst(int d);           // добавление элемента
    void additemSecond(int d);          // добавление элемента
    void displayFirst();                // показ данных
    void displaySecond();               // показ данных
};
void linklistNew::additemFirst(int d) {
    link8* newlink = new link8;         // выделяем память
    newlink->data = d;                  // запоминаем данные
    newlink->next = first;              // запоминаем значение first
    first = newlink;                    // first теперь указывает на новый элемент
}
void linklistNew::additemSecond(int d) {
    link8* newlink = new link8;         // выделяем память
    newlink->data = d;                  // запоминаем данные
    newlink->next = first;              // запоминаем значение first
    if (first == NULL) {
        first = newlink;                // first теперь указывает на новый элемент
    } else {
        link8 *count = first;
        while(count->next != NULL){
            count = count->next;
        }
        count->next = newlink;
    }
}
void linklistNew::displayFirst() {
    link8* current = first;              // начинаем с первого элемента
    while(current) {                    // пока есть данные
        cout << current->data << endl;  // печатаем данные
        current = current->next;        // двигаемся к следующему элементу
    }
}
void linklistNew::displaySecond() {
    link8* current = first;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

///////////////////////////////////////////////////////////
// Task 11
const int MAXSIZE = 10;
const int NUMARRAYS = 5;
class pwdArray {
private:
    int* ap[MAXSIZE];      // Массив указателей на массивы 
    int coff;
public:
    pwdArray(int coffenc) : coff(coffenc) {};
    void setData() {
        for(int j = 0; j < NUMARRAYS; j++) {        // создаем NUMARRAYS массивов
            *(ap + j) = new int[MAXSIZE];           // no MAXSIZE целых чисел в каждом
            for(int k = 0; k < MAXSIZE; k++) {
                *(*(ap + j)+k) = (j+k)*coff;        // ap[i][k]
            }
        }
    }
    void getData() {
        for (int i = 0; i < NUMARRAYS; ++i) {
            for (int j = 0; j < MAXSIZE; ++j) {
                cout << setw(6) << ap[i][j] << " ";
            }
            cout << endl;
        } 
    }
    int& operator[](int number) {
        if(number < 0 || number >= MAXSIZE*NUMARRAYS) {cout << "\nОшибочный индекс!"; exit(1);}
        cout << "ENDL" << endl;
        for (int i = 0; i < NUMARRAYS; ++i) {
            for (int j = 0; j < MAXSIZE; ++j) {
                if ((MAXSIZE*i + j) == number) {
                    return ap[i][j];
                }
            }
        }
    }
};

///////////////////////////////////////////////////////////
// Task 12
const int MAXSIZE12 = 100;                  // Размер массивов fmemory и pmemory
static float fmemory[MAXSIZE12] = {0.0};    // Массив для хранения значений типа float
static int fmem_top = 0;                    // Индекс для указания на следующее доступное место в fmemory
static int pmemory[MAXSIZE12] = {0};        // Массив для хранения индексов (указателей)
static int pmem_top = 0;                    // Индекс массива pmemory
class Float {
public:
    int addr;                               // Индекс массива fmemory
    Float(float value) {
        if (fmem_top < MAXSIZE12) {
            fmemory[fmem_top] = value;      // Сохраняем значение типа float в fmemory
            addr = fmem_top;                // Сохраняем адрес (индекс) в addr
            fmem_top++;                     // Увеличиваем fmem_top для указания на следующее доступное место
        } else {
            std::cout << "Out of memory for Float objects!" << std::endl;
            exit(1);
        }
    }
    int operator&() {
        return addr;                        // Возвращаем адрес (индекс) массива fmemory
    }
};
class ptrFloat {
public:
    int addr;                               // Индекс массива pmemory
    ptrFloat(int address) {
        if (pmem_top < MAXSIZE12) {
            pmemory[pmem_top] = address;
            addr = pmem_top;
            pmem_top++;
        } else {
            std::cout << "Out of memory for ptrFloat objects!" << std::endl;
            exit(1);
        }
    }
    float& operator*() {
        if (addr < 0 || addr >= MAXSIZE12) {
            std::cout << "Invalid address!" << std::endl;
            exit(1);
        }
        return fmemory[pmemory[addr]]; // Возвращаем значение типа float по адресу
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    /*1. Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float. После того как числа 
    будут помещены в массив, программа должна подсчитать их среднее арифметическое и вывести результат на дисплей. Используйте указатели
    везде, где только возможно. */
    int len1 = 0; 
    float* mas1;
    // float mas1[100];             // массив чисел
    char enter;
    while (enter!='n') {
        cout << "Введите число через Enter: ";
        cin >> *(mas1 + len1++);  
        // cin >> mas[len1++];      // analog               
        cout << "Продолжить ввод (y/n): ";
        cin >> enter;
    }
    float arifmet = 0;
    for (int i=0; i < len1; i++) {
        arifmet += *(mas1 + i);
        //arifmet += mas1[i];       // analog
        cout << "!! " << arifmet << endl;
    }        
    cout << "Среднее арифметическое = " << arifmet/len1;

    /*2. Используйте класс String из примера NEWSTR этой главы. Добавьте к нему метод upit(), который будет переводить символы строки в
    верхний регистр. Вы можете использовать библиотечную функцию toupper(), которая принимает отдельный символ в качестве аргумента и 
    возвращает символ, переведенный в верхний регистр (если это необходимо). Эта функция использует заголовочный файл Cctype. Добавьте 
    в функцию main() необходимые строки для тестирования метода upit(). */
    String newStr = "Этот текст написан в нижнем регистре";
    newStr.upit();
    newStr.display();

    /*3. Используйте массив указателей на строки, представляющие собой названия дней недели, из примера PTROSTR этой главы. Напишите 
    функции для сортировки этих строк в алфавитном порядке, используя в качестве основы функции bsort() и order() из программы PTRSORT 
    этой главы. Сортировать необходимо указатели на строки, а не сами строки. */
    const int DAYS = 7;
    char* arrptrs[DAYS] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };    // массив указателей на строки
    cout << "\nНеупорядоченный:\n ";
    for(int j = 0; j < DAYS; j++)
        cout << *(arrptrs + j) << endl;
    bsort(arrptrs, DAYS);
    cout << "\nУпорядоченный:\n ";
    for(int j = 0; j < DAYS; j++)
        cout << *(arrptrs + j) << endl;

    /*4. Добавьте деструктор в программу LINKLIST. Он должен удалять все элементы списка при удалении объекта класса linklist. Элементы 
    должны удаляться по очереди, в соответствии с их расположением в списке. Протестируйте деструктор путем вывода сообщения об удалении
    каждого из элементов списка; удалено должно быть также количество элементов, какое было положено в список (деструктор вызывается 
    автоматически для каждого существующего объекта). */
    linklist li;        // создаем переменную-список
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);     // добавляем туда несколько чисел
    li.display();       // показываем список

    /*5. Предположим, что в функции main() определены три локальных массива одинакового размера и типа (скажем, float). Первые два уже 
    инициализированы значениями. Напишите функцию addarrays(), которая принимает в качестве аргументов адреса трех массивов, складывает 
    соответствующие элементы двух массивов и помещает результат в третий массив. Четвертым аргументом этой функции может быть 
    размерность массивов. На всем протяжении программы используйте указатели. */
    float masOne[3] = {1, 12.5, 25};
    float masTwo[3] = {5, 75.5, 40};
    float masThree[3];
    int count = 3;
    float* ptrOne;
    ptrOne = masOne;
    float* ptrTwo;
    ptrTwo = masTwo;
    float* ptrThree;
    ptrThree = masThree;
    //addarrays(masOne, masTwo, masThree, count);
    addarrays(ptrOne, ptrTwo, ptrThree, count);     // аналогично
    for (int i = 0; i < count; i++) {
        cout << *(masOne + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << *(masTwo + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << *(masThree + i) << " ";
    }
    cout << endl;

    /*6. Создайте свою версию библиотечной функции strcmp(s1, s2), которая сравнивает две строки и возвращает -1, если s1 идет первой 
    по алфавиту, 0, если в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. Назовите вашу функцию compstr(). Она 
    должна принимать в качестве аргументов два указателя на строки char*, сравнивать эти строки посимвольно и возвращать число int. 
    Напишите функцию main() для проверки работы вашей функции с разными строками. Используйте указатели во всех возможных ситуациях. */
    const char * firstLine = "First line";
    //const char * firstLine = "Second line";
    const char * secondLine = "Second line";
    cout << "Line " << compstr(firstLine, secondLine) << " is over alphabet !" << endl;

    /*7. Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя не только имя человека, но и сведения 
    о его зарплате в виде поля salary типа float. Вам будет необходимо изменить методы setName() и printName() на setData() и printData(),
    включив в них возможность ввода и вывода значения salary, как это можно сделать с именем. Вам также понадобится метод getSalary(). 
    Используя указатели, напишите функцию salsort(), которая сортирует указатели массива persPtr по значениям зарплаты. Попробуйте 
    вместить всю сортировку в функцию salsort(), не вызывая других функций, как это сделано в программе PERSORT. При этом не забывайте, 
    что операция -> имеет больший приоритет, чем операция *, и вам нужно будет написать
        if((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
        { / меняем указатели местами / } */
    person* persPtr[100];       // массив указателей
    int countElement = 0;       // количество элементов в массиве
    char choice;
    do {
        persPtr[countElement] = new person;    // создаем новый объект
        persPtr[countElement]->setData();      // вводим имя
        countElement++;        // увеличиваем количество
        cout << "Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
        cin >> choice;
    } while(choice == 'y');
    for(int j = 0; j < countElement; j++) {
        cout << "\nИнформация о номере " << j + 1;
        persPtr[j]->printData();
    }
    cout << endl;
    salsort(persPtr, countElement); 
    for(int j = 0; j < countElement; j++) {
        cout << "\nИнформация о номере " << j + 1;
        persPtr[j]->printData();
    }
    cout << endl;

    /*8. Исправьте функцию additem() из программы LINKLIST так, чтобы она добавляла новый элемент в конец списка, а не в начало. Это 
    будет означать, что первый вставленный элемент будет выведен первым и результат работы программы будет следующим:
        25
        36
        49
        64
        Для того чтобы добавить элемент, вам необходимо будет пройти по цепи до конца списка, а затем изменить указатель последнего 
    элемента так, чтобы он указывал на новый элемент. */
    linklistNew li8;        // создаем переменную-список
    li8.additemSecond(25);
    li8.additemSecond(36);
    li8.additemSecond(49);
    li8.additemSecond(64);     // добавляем туда несколько чисел
    li8.displaySecond();       // показываем список 

    /*9. Допустим, что нам нужно сохранить 100 целых чисел так, чтобы иметь к ним легкий доступ. Допустим, что при этом у нас есть 
    проблема: память нашего компьютера так фрагментирована, что может хранить массив, наибольшее количество элементов в котором равно 
    десяти (такие проблемы действительно появляются, хотя обычно это происходит с объектами, занимающими большое количество памяти). 
    Вы можете решить эту проблему, определив 10 разных массивов по 10 элементов в каждом и массив из 10 указателей на эти массивы. 
    Массивы будут иметь имена a0, a1, a2 и т. д. Адрес каждого массива будет сохранен в массиве указателей типа int*, который называется
    ар. Вы сможете получить доступ к отдельному целому используя выражение ap[j][к], где j является номером элемента массива указателей,
    а к — номером элемента в массиве, на который этот указатель указывает. Это похоже на двумерный массив, но в действительности является
    группой одномерных массивов. Заполните группу массивов тестовыми данными (скажем, номерами 0, 10, 20 и т. д.), а затем выведите их, 
    чтобы убедиться, что все работает правильно. */
    const int ARRAY_SIZE = 10;
    const int ARRAY_COUNT = 5;
    int a0[ARRAY_SIZE] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int a1[ARRAY_SIZE] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    int a2[ARRAY_SIZE] = {200, 210, 220, 230, 240, 250, 260, 270, 280, 290};
    int a3[ARRAY_SIZE] = {300, 310, 320, 330, 340, 350, 360, 370, 380, 390};
    int a4[ARRAY_SIZE] = {400, 410, 420, 430, 440, 450, 460, 470, 480, 490};
    int* ap[ARRAY_COUNT];      // Массив указателей на массивы
    ap[0] = a0;
    ap[1] = a1;
    ap[2] = a2;
    ap[3] = a3;
    ap[4] = a4;
    for (int i = 0; i < ARRAY_COUNT; ++i) {
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            cout << setw(6) << ap[i][j] << " ";
        }
        cout << endl;
    }

    /*10 Описанный в упражнении 9 подход нерационален, так как каждый из 10 массивов объявляется отдельно, с использованием отдельного 
    имени, и каждый адрес получают отдельно. Вы можете упростить программу, используя операцию new, которая позволит вам выделить память
    для массивов в цикле и одновременно связать с ними указатели:
        for(j = 0; j < NUMARRAYS; j++)      // создаем NUMARRAYS массивов
            *(ар + j) = new int[MAXSIZE];   // no MAXSIZE целых чисел в каждом
        Перепишите программу упражнения 9, используя этот подход. Доступ к отдельному элементу массивов вы сможете получить, используя 
    то же выражение, что и в упражнении 9, или аналогичное выражение с указателями: *(*(ap10 + j)+k). */
    const int MAXSIZE = 10;
    const int NUMARRAYS = 5;
    int* ap10[NUMARRAYS];                           // Массив указателей на массивы
    for(int j = 0; j < NUMARRAYS; j++) {            // создаем NUMARRAYS массивов
        *(ap10 + j) = new int[MAXSIZE];             // no MAXSIZE целых чисел в каждом
        for(int k = 0; k < MAXSIZE; k++) {
            *(*(ap10 + j)+k) = (j+k)*10;            // ap10[i][k]
        }
    }
    for (int i = 0; i < NUMARRAYS; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            cout << setw(6) << ap10[i][j] << " ";
        }
        cout << endl;
    }

    /*11. Создайте класс, который позволит вам использовать 10 отдельных массивов из упражнения 10 как один одномерный массив, допуская 
    применение операций массива. То есть мы можем получить доступ к элементам массива, записав в функции main() выражение типа a[j], а 
    методы класса могут получить доступ к полям класса, используя двухшаговый подход. Перегрузим операцию [] (см. главу 9 
    «Наследование»), чтобы получить нужный нам результат. Заполним массив данными и выведем их. Хотя для интерфейса класса использованы 
    операции индексации массива, вам следует использовать указатели внутри методов класса. */
    pwdArray mas(10);
    mas.setData();
    cout << "DATA 1" << endl;
    cout << "14 = " << mas[14] << endl;
    cout << "DATA 2" << endl;
    mas.getData();

    /*12. Указатели сложны, поэтому давайте посмотрим, сможем ли мы сделать работу с ними более понятной (или, возможно, более непонятной), используя их 
    симуляцию в классе. Для разъяснения действия наших доморощенных указателей мы смоделируем память компьютера с помощью массивов. Так как доступ к 
    массивам всем понятен, то вы сможете увидеть, что реально происходит, когда мы используем для доступа к памяти указатели. Мы будем использовать один 
    массив типа char для хранения всех типов переменных. Именно так устроена память компьютера: массив байтов (тип char имеет тот же размер), каждый из 
    которых имеет адрес (или, в терминах массива, индекс). Однако C++ не позволит нам хранить данные типа float или int в массиве типа char обычным путем
    (мы можем использовать объединения, но это другая история). Поэтому мы создадим симулятор памяти, используя отдельный массив для каждого типа данных, 
    которые мы хотим сохранить. В этом упражнении мы ограничимся одним типом float, и нам понадобится массив для него. Назовем этот массив fmemory. Однако
    значения указателей (адреса) тоже хранятся в памяти, и нам понадобится еще один массив для их хранения. Так как в качестве модели адресов мы 
    используем индексы массива, то нам потребуется массив типа int, назовем его pmemory, для хранения этих индексов. Индекс массива fmemory (назовем его 
    fmem_top) показывает на следующее по очереди доступное место, где можно сохранить значение типа float. У нас есть еще похожий индекс массива pmemory 
    (назовем его pmem_top). Не волнуйтесь о том, что наша «память» может закончиться. Мы предполагаем, что эти массивы достаточно большие, чтобы хранить 
    все, что мы захотим, и нам не надо заботиться об управлении памятью.
        Создадим класс Float, который мы будем использовать для моделирования чисел типа float, которые будет храниться в fmemory вместо настоящей памяти. 
    Класс Float содержит поле, значением которого является индекс массива fmemory, хранящего значения типа float. Назовем это поле addr. В классе также 
    должны быть два метода. Первый — это конструктор, имеющий один аргумент типа float для инициализации значения. Конструктор помещает значение 
    аргумента в элемент массива fmemory, на который указывает указатель fmem_top, а затем записывает значение fmem_top в массив addr. Это похоже на то, 
    как компоновщик и компилятор хранят обычные переменные в памяти. Второй метод является перегружаемой операцией &. Он просто возвращает значение 
    указателя (индекса типа int) в addr.
        Создадим второй класс ptrFloat. Объект этого класса содержит адрес (индекс) в pmemory. Метод класса инициализирует этот «указатель» значением типа 
    int. Второй метод перегружает операцию * (операция разыменования). Его действия более сложны. Он получает адрес из массива pmemory, в котором хранятся 
    адреса. Затем полученный адрес используется как индекс массива fmemory для получения значения типа float, которое располагалось но нужному нам адресу.
    float& ptrFloat::operator*() { 
        return fmemory[pmemory[addr]]; 
    }
    Таким образом мы моделируем действия операции разыменования (*). Заметим, что вам нужно возвращаться из этой функции по ссылке, чтобы можно было 
    использовать операцию * слева от знака равно. Классы Float и ptrFloat похожи, но класс Float хранит данные типа float в массиве, представляющем собой 
    память, а класс ptrFloat хранит поля типа int (являющиеся у нас указателями, но на самом деле индексами массива) в другом массиве, который тоже 
    представляет собой память. Это типичное использование этих классов в функции main(); 
        Float var1 = 1.234;             // определяем и инициализируем
        Float var2 = 5.678;             // две вещественные переменные
        ptrFloat ptr1 = &var1;          // определяем и инициализируем
        ptrFloat ptr2 = &var2;          // два указателя
        cout << " *ptr1 = " << *ptr1;   // получаем значения переменных
        cout << " *ptr2 = " << *ptr2;   // и выводим на экран
        *ptr1 = 7.123;                  // присваиваем новые значения
        *ptr2 = 8.456;                  // переменным, адресованным через указатели
        cout << " *ptr1 = " << *ptr1;   // снова получаем значения
        cout << " *ptr2 = " << *ptr2;   // и выводим на экран
    Заметим, что за исключением других имен типов переменных, это выглядит так же, как действия с настоящими переменными. Далее результат работы программы:
        *ptr1 = 1.234
        *ptr2 = 5.678
        *ptr1 = 7.123
        *ptr2 = 8.456
    Такой путь реализации указателей может показаться очень сложным, но здесь показана их внутренняя работа и работа операции адреса. Мы рассмотрели 
    природу указателей в различных ракурсах. */
    Float var1 = 1.234;             // определяем и инициализируем две вещественные переменные
    Float var2 = 5.678;             
    ptrFloat ptr1 = &var1;          // определяем и инициализируем два указателя
    ptrFloat ptr2 = &var2;          
    cout << " *ptr1 = " << *ptr1;   // получаем значения переменных и выводим на экран
    cout << " *ptr2 = " << *ptr2;   
    *ptr1 = 7.123;                  // присваиваем новые значения переменным, адресованным через указатели
    *ptr2 = 8.456;                  
    cout << " *ptr1 = " << *ptr1;   // снова получаем значения и выводим на экран
    cout << " *ptr2 = " << *ptr2;   

    return 0;
}