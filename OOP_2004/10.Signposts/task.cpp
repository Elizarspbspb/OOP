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

class pwdArray {
private:
    const int MAXSIZE = 10;
public:
    int* ap[MAXSIZE];      // Массив указателей на массивы
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    /*1. Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float. После того как числа 
    будут помещены в массив, программа должна подсчитать их среднее арифметическое и вывести результат на дисплей. Используйте указатели
    везде, где только возможно. */
    /*int len1 = 0; 
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
    cout << "Среднее арифметическое = " << arifmet/len1; */

    /*2. Используйте класс String из примера NEWSTR этой главы. Добавьте к нему метод upit(), который будет переводить символы строки в
    верхний регистр. Вы можете использовать библиотечную функцию toupper(), которая принимает отдельный символ в качестве аргумента и 
    возвращает символ, переведенный в верхний регистр (если это необходимо). Эта функция использует заголовочный файл Cctype. Добавьте 
    в функцию main() необходимые строки для тестирования метода upit(). */
    /*String newStr = "Этот текст написан в нижнем регистре";
    newStr.upit();
    newStr.display();*/

    /*3. Используйте массив указателей на строки, представляющие собой названия дней недели, из примера PTROSTR этой главы. Напишите 
    функции для сортировки этих строк в алфавитном порядке, используя в качестве основы функции bsort() и order() из программы PTRSORT 
    этой главы. Сортировать необходимо указатели на строки, а не сами строки. */
    /*int DAYS = 7;
    char* arrptrs[DAYS] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };    // массив указателей на строки
    cout << "\nНеупорядоченный:\n ";
    for(int j = 0; j < DAYS; j++)
        cout << *(arrptrs + j) << endl;
    bsort(arrptrs, DAYS);
    cout << "\nУпорядоченный:\n ";
    for(int j = 0; j < DAYS; j++)
        cout << *(arrptrs + j) << endl; */

    /*4. Добавьте деструктор в программу LINKLIST. Он должен удалять все элементы списка при удалении объекта класса linklist. Элементы 
    должны удаляться по очереди, в соответствии с их расположением в списке. Протестируйте деструктор путем вывода сообщения об удалении
    каждого из элементов списка; удалено должно быть также количество элементов, какое было положено в список (деструктор вызывается 
    автоматически для каждого существующего объекта). */
    /*linklist li;        // создаем переменную-список
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);     // добавляем туда несколько чисел
    li.display();       // показываем список */

    /*5. Предположим, что в функции main() определены три локальных массива одинакового размера и типа (скажем, float). Первые два уже 
    инициализированы значениями. Напишите функцию addarrays(), которая принимает в качестве аргументов адреса трех массивов, складывает 
    соответствующие элементы двух массивов и помещает результат в третий массив. Четвертым аргументом этой функции может быть 
    размерность массивов. На всем протяжении программы используйте указатели. */
    /*float masOne[3] = {1, 12.5, 25};
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
    cout << endl; */

    /*6. Создайте свою версию библиотечной функции strcmp(s1, s2), которая сравнивает две строки и возвращает -1, если s1 идет первой 
    по алфавиту, 0, если в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. Назовите вашу функцию compstr(). Она 
    должна принимать в качестве аргументов два указателя на строки char*, сравнивать эти строки посимвольно и возвращать число int. 
    Напишите функцию main() для проверки работы вашей функции с разными строками. Используйте указатели во всех возможных ситуациях. */
    /*const char * firstLine = "First line";
    //const char * firstLine = "Second line";
    const char * secondLine = "Second line";
    cout << "Line " << compstr(firstLine, secondLine) << " is over alphabet !" << endl; */

    /*7. Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя не только имя человека, но и сведения 
    о его зарплате в виде поля salary типа float. Вам будет необходимо изменить методы setName() и printName() на setData() и printData(),
    включив в них возможность ввода и вывода значения salary, как это можно сделать с именем. Вам также понадобится метод getSalary(). 
    Используя указатели, напишите функцию salsort(), которая сортирует указатели массива persPtr по значениям зарплаты. Попробуйте 
    вместить всю сортировку в функцию salsort(), не вызывая других функций, как это сделано в программе PERSORT. При этом не забывайте, 
    что операция -> имеет больший приоритет, чем операция *, и вам нужно будет написать
        if((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
        { / меняем указатели местами / } */
    /*person* persPtr[100];   // массив указателей
    int countElement = 0;      // количество элементов в массиве
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
    cout << endl; */

    /*8. Исправьте функцию additem() из программы LINKLIST так, чтобы она добавляла новый элемент в конец списка, а не в начало. Это 
    будет означать, что первый вставленный элемент будет выведен первым и результат работы программы будет следующим:
        25
        36
        49
        64
        Для того чтобы добавить элемент, вам необходимо будет пройти по цепи до конца списка, а затем изменить указатель последнего 
    элемента так, чтобы он указывал на новый элемент. */
    /*linklistNew li;        // создаем переменную-список
    li.additemSecond(25);
    li.additemSecond(36);
    li.additemSecond(49);
    li.additemSecond(64);     // добавляем туда несколько чисел
    li.displaySecond();       // показываем список */

    /*9. Допустим, что нам нужно сохранить 100 целых чисел так, чтобы иметь к ним легкий доступ. Допустим, что при этом у нас есть 
    проблема: память нашего компьютера так фрагментирована, что может хранить массив, наибольшее количество элементов в котором равно 
    десяти (такие проблемы действительно появляются, хотя обычно это происходит с объектами, занимающими большое количество памяти). 
    Вы можете решить эту проблему, определив 10 разных массивов по 10 элементов в каждом и массив из 10 указателей на эти массивы. 
    Массивы будут иметь имена a0, a1, a2 и т. д. Адрес каждого массива будет сохранен в массиве указателей типа int*, который называется
    ар. Вы сможете получить доступ к отдельному целому используя выражение ap[j][к], где j является номером элемента массива указателей,
    а к — номером элемента в массиве, на который этот указатель указывает. Это похоже на двумерный массив, но в действительности является
    группой одномерных массивов. Заполните группу массивов тестовыми данными (скажем, номерами 0, 10, 20 и т. д.), а затем выведите их, 
    чтобы убедиться, что все работает правильно. */
    /*const int ARRAY_SIZE = 10;
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
    }*/

    /*10 Описанный в упражнении 9 подход нерационален, так как каждый из 10 массивов объявляется отдельно, с использованием отдельного 
    имени, и каждый адрес получают отдельно. Вы можете упростить программу, используя операцию new, которая позволит вам выделить память
    для массивов в цикле и одновременно связать с ними указатели:
        for(j = 0; j < NUMARRAYS; j++)      // создаем NUMARRAYS массивов
            *(ар + j) = new int[MAXSIZE];   // no MAXSIZE целых чисел в каждом
        Перепишите программу упражнения 9, используя этот подход. Доступ к отдельному элементу массивов вы сможете получить, используя 
    то же выражение, что и в упражнении 9, или аналогичное выражение с указателями: *(*(ap + j)+k). */
    /*const int MAXSIZE = 10;
    const int NUMARRAYS = 5;
    int* ap[NUMARRAYS];      // Массив указателей на массивы
    for(int j = 0; j < NUMARRAYS; j++) {        // создаем NUMARRAYS массивов
        *(ap + j) = new int[MAXSIZE];           // no MAXSIZE целых чисел в каждом
        for(int k = 0; k < MAXSIZE; k++) {
            *(*(ap + j)+k) = (j+k)*10;          // ap[i][k]
        }
    }
    for (int i = 0; i < NUMARRAYS; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            cout << setw(6) << ap[i][j] << " ";
        }
        cout << endl;
    } */

    /*11. Создайте класс, который позволит вам использовать 10 отдельных массивов из упражнения 10 как один одномерный массив, допуская 
    применение операций массива. То есть мы можем получить доступ к элементам массива, записав в функции main() выражение типа a[j], а 
    методы класса могут получить доступ к полям класса, используя двухшаговый подход. Перегрузим операцию [] (см. главу 9 
    «Наследование»), чтобы получить нужный нам результат. Заполним массив данными и выведем их. Хотя для интерфейса класса использованы 
    операции индексации массива, вам следует использовать указатели внутри методов класса. */
    const int NUMARRAYS = 5;
    pwdArray *mas[NUMARRAYS];

    return 0;
}