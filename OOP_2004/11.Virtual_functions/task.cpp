// Глава 11. Виртуальные функции
#include <iostream>
#include <string.h>     // для функций strcpy, strcat
#include <strstream>    // Task 6
#include <cmath>        // Task 7

using namespace std;

// Task 1
class publication {
private:
    string nameBook;
    float costBook;
public:
    virtual void getdata() {
        cout << "\nВведите название книги: "; cin >> nameBook;
        cout << "Введите стоимость книги: "; cin >> costBook;
    }
    virtual void putdata() const {
        cout << "\n Книга: " << nameBook;
        cout << "\n Цена: " << costBook << endl;
    }
    // Task 5
    virtual bool isOveersize() = 0;
};
class book : public publication {
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество страниц: "; cin >> pages;
    }
    void putdata() const {
        publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
    // Task 5
    bool isOveersize() {
        if (pages > 800)
            return 1;
        return 0;
    }
};
class tape : public publication {
    float minuts;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество минут: "; cin >> minuts;
    }
    void putdata() const {
        publication::putdata();
        cout << "Количество минут: " << minuts << endl;
    }
    // Task 5
    bool isOveersize() {
        if (minuts > 90)
            return 1;
        return 0;
    }
};

///////////////////////////////////////////////////////////

// Task 2
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(float fltfeet) {                   // переводит float в Distance
        feet = static_cast<int>(fltfeet);
        inches = 12*(fltfeet - feet);           // слева — дюймы
    }
    Distance(int ft, float in) { feet = ft; inches = in; }
    void showdist() { cout << feet << "\'-" << inches << '\"'; }
    friend Distance operator*(Distance, Distance);      // дружественный   
};
Distance operator*(Distance d1, Distance d2) {  // d1 + d2
    float one = d1.feet + d1.inches/12;
    float two = d2.feet + d2.inches/12;
    float multi = one * two;
    return Distance(multi);
}

///////////////////////////////////////////////////////////
// Task 6, 7

const int MAXSTR = 100;     // максимальная длина строки
class bMoney {
    long double money;
    char streams[MAXSTR] = "$";
    string strFrom;
public:
    bMoney();
    bMoney(char s[]);
    explicit bMoney(long double);       // explicit - запрет скрытого преобразования типов данных long double в bMoney 
    void putmoney();
    void getmoney();
    long double mstold(string);
    char ldtoms(long double);
    /*bMoney operator+(bMoney);                     // bMoney = bMoney + bMoney
    bMoney operator-(bMoney);                       // bMoney = bMoney - bMoney
    bMoney operator*(long double);                  // bМоnеу = bMoney * long double
    long double operator/(bMoney);                  // long double = bMoney / bMoney
    bMoney operator/(long double);                  // bMoney = bMoney / long double */
    //bMoney operator*(long double, bMoney);        // ERROR
    friend bMoney operator*(long double, bMoney);      // long double * bMoney   // умножать число на деньги
    friend bMoney operator/(long double, bMoney);      // long double / bMoney   // делить число на деньги
    // Task 7
    friend bMoney round(bMoney);
};
bMoney operator*(long double time, bMoney two) {
    bMoney three;
    three.money = time * two.money;
    return three;
}
bMoney operator/(long double time, bMoney two) {
    bMoney three;
    three.money = time / two.money;
    return three;
}
// Task 7
bMoney round(bMoney round) {
    long double cel;
    long double drob = modfl(round.money, &cel);
    bMoney three;
    if(drob >= 0.5) {
        three.money = cel + 1;
    } else {
        three.money = cel;
    }
    return three;
}
//
bMoney::bMoney() : money(0) {}
bMoney::bMoney(char s[]) : money(0) {}
bMoney::bMoney(long double mon) : money(mon) {} // неявный конструктор преобразования long double в bMoney
void bMoney::putmoney() {
    cout << "Введите строку с числом " << endl;
    cin >> strFrom;
    mstold(strFrom);
}
long double bMoney::mstold(string strTo) {
    long double mon = 0.0;
    for (int size = 0, sizeTwo = 0; size < strFrom.length(); size++) {
        if (strFrom[size] >= 48 && strFrom[size] <= 57) {
            strTo[sizeTwo++] = strFrom[size];
        } else if (strFrom[size] == '.') {
            strTo[sizeTwo++] = strFrom[size];
        }
    }
    mon = mstold(strTo);
}
void bMoney::getmoney() {
    cout << ldtoms(money) << streams << endl;
}
char bMoney::ldtoms(long double doubleFrom) {
    if (doubleFrom > 9999999999999990.00)
        return *"Very big number !";
    ostrstream ustring;
    ustring << doubleFrom;
    string len = ustring.str();
    for (int i = 0; i < len.length(); i++)
        streams[i+1] = ustring.str()[i];
    return *streams;    
}
/*bMoney bMoney::operator+(bMoney two) {
    bMoney three;
    three.money = money + two.money;
    return three;
}
bMoney bMoney::operator-(bMoney two) {
    bMoney three;
    three.money = money - two.money;
    return three;
}
bMoney bMoney::operator*(long double time) {
    bMoney three;
    three.money = money * time;
    return three;
}
long double bMoney::operator/(bMoney two) {
    long double count;
    count = money / two.money;
    return count;
}
bMoney bMoney::operator/(long double two) {
    bMoney three;
    three.money = money / two;
    return three;
}*/

///////////////////////////////////////////////////////////
// Task 11

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
    // Task 11
    linklist(const linklist& other) {           // Конструктор копирования
        first = nullptr;                        // Инициализируем первый элемент нового списка
        link* otherCurrent = other.first;       // Указатель на первый элемент другого списка
        link* lastCopied = nullptr;             // Указатель на последний скопированный элемент
        while (otherCurrent) {
            link* newlink = new link;   // Создаем новый элемент
            newlink->data = otherCurrent->data;
            newlink->next = nullptr;  // Новый элемент будет последним в новом списке
            if (!first) {        // Добавляем элемент в новый список
                first = newlink;
            } else {
                lastCopied->next = newlink;
            }
            lastCopied = newlink;               // Переходим к следующему элементу
            otherCurrent = otherCurrent->next;
        }
    }
    linklist& operator=(const linklist& other) {    // Оператор присваивания
        if (this != &other) {       // Проверка на самоприсваивание
            link* current = first;
            while (current) {           // Очищаем текущий список
                link* temp = current;
                current = current->next;
                delete temp;
            }
            first = nullptr;     // Копируем элементы из другого списка
            link* otherCurrent = other.first;
            link* lastCopied = nullptr;
            while (otherCurrent) {
                link* newlink = new link;
                newlink->data = otherCurrent->data;
                newlink->next = nullptr;
                if (!first) {
                    first = newlink;
                } else {
                    lastCopied->next = newlink;
                }
                lastCopied = newlink;
                otherCurrent = otherCurrent->next;
            }
            return *this; 
        }
    }
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

int main(int argc, char* argv[]) 
{
    /*1. Пусть имеется та же издательская компания, которая описана в упражнении 1 главы 9, которая продает и книги, и аудио версии 
    печатной продукции. Как и в том упражнении, создайте класс publication, хранящий название (фактически, строку) и цену (типа float) 
    публикации. Создайте два порожденных класса: book, в котором происходит изменение счетчика страниц (типа int), и tape, в котором 
    происходит изменение счетчика записанных на кассету минут. Каждый из классов должен иметь метод getdata(), запрашивающий информацию 
    у пользователя, и putdata() для вывода данных на экран. 
    2. Напишите main(), где создавался бы массив указателей на класс publication. Это очень похоже на то, что мы делали в текущей 
    главе на примере VIRTPERS. В цикле запрашивайте у пользователя данные о конкретной книге или кассете, используйте new для создания 
    нового объекта book или tape. Сопоставляйте указатель в массиве с объектом. Когда пользователь закончит ввод исходных данных, 
    выведите результат для всех введенных книг и кассет, используя цикл for и единственное выражение pubarr[j]->putdata(); для вывода 
    данных о каждом объекте из массива */
    publication* pubarr[100];       // массив указателей на публикации
    publication* books;
    int n = 0;                      // число публикаций в массиве
    char choice;                    
    do {
        cout << "\nВводить данные для книги (b) или для пленки (t)?";
        cin >> choice;
        if(choice == 'b') {
            pubarr[n] = new book;
            books = new book;
        }
        else {
            pubarr[n] = new tape;
            books = new tape;
        }
        pubarr[n++]->getdata();
        books->getdata();
        cout << "Продолжать (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    for(int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        books->putdata();
    }
    cout << endl;

    /*3. В классе Distance, как показано в примерах FRENGL и FRISQ из этой главы, создайте перегружаемую операцию умножения *, чтобы 
    можно было умножать два расстояния. Сделайте эту функцию дружественной, тогда можно будет использовать выражение типа Wdist = 7.5*dist2. 
    Вам понадобится конструктор с одним аргументом для перевода величин из формата чисел с плавающей запятой в формат Distance. Напишите 
    какой-либо main() на свое усмотрение для того, чтобы несколькими способами проверить работу этой перегружаемой операции.*/
    Distance dist1(10, 2);
    Distance dist2(10, 5);
    Distance dist3;
    dist3 = dist1 * dist2;
    dist3 = 7.5*dist3;
    dist3.showdist();
    dist3 = 10.0 *dist3;

    /*4. Как уже говорилось, классы можно заставлять вести себя как массивы. Пример показывает один из способов создания такого класса. */
    class Array {                       // моделирует обычный массив C++
    private:
        int* ptr;                       // указатель на содержимое Array
        int size;                       // размер Array
    public:
        Array(): ptr(0), size(0) { }
        Array(int s) {
            size = s;                   // аргумент - размер Array
            ptr = new int[s];           // выделить память под Array
        }
        ~Array() { cout << "\nДЕСТРУКТОР" << endl; delete[] ptr; }
        int& operator[](int j) {            // перегружаемая операция
            return *(ptr + j);              // списка индексов
        }  
        Array& operator=(Array& S) {        // присвоение       
            cout << "\nПРИРАВНИВАНИЕ" << endl; 
            size = S.size;
            ptr = new int[size];            // нужен если объект создан без аргументов Array one;
            for(int i=0; i < size; i++) {
                *(ptr + i) = *(S.ptr + i);
            }
            return *this;                   // вернуть этот объект
        }
        Array(Array& mas) {                 // конструктор копирования
            cout << "\nКОНСТРУКТОР КОПИРОВАНИЯ" << endl;
            size = mas.size;
            // ptr = mas.ptr;   // ERROR
            ptr = new int[size];
            for(int j = 0; j < size; j++) {   // копировать содержимое в
                *(ptr + j) = *(mas.ptr + j);
            } 
        }
    };
    /*int main() {
        const int ASIZE = 10;               // размер массива
        Array arr(ASIZE);                   // создать массив
        for(int j = 0; j < ASIZE; j++)      // заполнить его j^2
            arr[j] = j*j;
        for(j = 0; j < ASIZE; j++)          // вывести его содержимое
            cout << arr[j] << ' ';
        cout << endl;
        return 0;
    }
    Результат работы программы:
        0 1 4 9 16 25 36 49 64 81
    Взяв за основу приведенную программу, добавьте перегружаемое присваивание и перегружаемый конструктор копирования к классу Array. 
    Затем добавьте к main() выражение Array arr2(arr1); и arr3 = arr1; для проверки того, что перегружаемые операции работают. 
    Конструктор копирования должен создать новый объект Array со своим собственным местом в памяти, выделенным для хранения элементов 
    массива. И конструктор копирования, и оператор присваивания должны копировать содержимое старого объекта класса Array в новый. 
    Что будет, если вы присвоите объект Array одного размера объекту Array другого размера? */
    const int ASIZE = 10;                   // размер массива
    Array arr(ASIZE);                       // создать массив
    for(int j = 0; j < ASIZE; j++)          // заполнить его j^2
        arr[j] = j*j;
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arr[j] << ' ';
    cout << endl << "Второй массив после приравнивания:" << endl;
    //Array arrTwo(ASIZE); 
    Array arrTwo; 
    arrTwo = arr;                           // присваивание
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arrTwo[j] << ' ';
    cout << endl;
    cout << endl << "Третий массив после копирования:" << endl;
    Array arrOne(arrTwo);                   // копирование
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arrOne[j] << ' ';
    cout << endl;

    /*5. Взяв за основу программу из упражнения 1 этой главы, добавьте метод типа bool, называющийся isOveersize(), к классам book и tape. 
    Допустим, книга, в которой больше 800 страниц, или кассета со временем проигрывания более 90 минут, будут считаться объектами с превышением 
    размера. К этой функции можно обращаться из main(), а результат ее работы выводить в виде строки «Превышение размера!» для соответствующих 
    книг и кассет. Допустим, объекты классов book и tape должны быть доступны через указатели на них, хранящиеся в массиве типа publication. 
    Что в этом случае вам нужно добавить в базовый класс publication? Вы можете привести примеры компонентов этого базового класса? */
    publication* pubarr5[100];       // массив указателей на публикации
    int n5 = 0;                      // число публикаций в массиве
    char choice5;                    
    do {
        cout << "\nВводить данные для книги (b) или для пленки (t)?";
        cin >> choice5;
        if(choice5 == 'b')
            pubarr5[n5] = new book;
        else
            pubarr5[n5] = new tape;
        pubarr5[n5++]->getdata();
        cout << "Продолжать (y/n)?";
        cin >> choice5;
    } while(choice5 == 'y');
    for(int j = 0; j < n5; j++) {
        pubarr5[j]->putdata();
        if (pubarr5[j]->isOveersize() == 1)
            cout << "«Превышение размера!»" << endl;
    }

    /*6. Возьмите за основу программу из упражнения 8 главы 8, где было перегружено пять арифметических операций для работы с денежным 
    форматом. Добавьте два оператора, которые не были перегружены в том упражнении:
        long double * bMoney // умножать число на деньги
        long double / bMoney // делить число на деньги
    Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева — обычное число. Убедитесь,
    что main() позволяет пользователю ввести две денежные строки и число с плавающей запятой, а затем корректно выполняет все семь 
    арифметических действий с соответствующими парами значений. */
    //bMoney mon1; 
    const long double number = 12;
    bMoney mon2(10);
    bMoney mon3;
    //mon3 = number * mon2;
    mon3 = number / mon2;
    cout << number << " * ";
    mon2.getmoney(); 
    cout << " = "; 
    mon3.getmoney();

    /*7. Как и в предыдущем упражнении, возьмите за основу программу из упражнения 8 главы 8. На этот раз от вас требуется добавить 
    функцию, округляющую значение bMoney до ближайшего доллара: mo2 = round(mo1); Как известно, значения, не превышающие $0.49, 
    округляются вниз, а числа от $0.50 и более округляются вверх. Можно использовать библиотечную функцию modfl(). Она разбивает 
    переменную типа long double на целую и дробную части. Если дробная часть меньше 0.50, функция просто возвращает целую часть числа. 
    В противном случае возвращается увеличенная на 1 целая часть. В main() проверьте работоспособность функции путем передачи в нее 
    последовательно значений, одни из которых меньше $0.49, другие - больше $0.50. */
    bMoney mo1(2.39);
    bMoney mo2(4.89);
    bMoney mo3 = round(mo1);    // 2
    bMoney mo4 = round(mo2);    // 5
    mo3.getmoney();
    mo4.getmoney();

    /*8. Помните программу PARSE из главы 10? Попробуйте доработать ее, чтобы она могла вычислять значения математических выражений с 
    рациональными числами, например типа float, а не только с одноразрядными числами:
        3.14159 / 2.0 + 75.25 * 3.333 + 6.02
    Во-первых, нужно развить стек до такой степени, чтобы он мог хранить и операторы (типа char), и числа (типа float). Но как, 
    спрашивается, можно хранить в стеке значения двух разных типов? Ведь стек — это, по сути дела, массив. Надо еще учесть, что типы 
    char и float даже не совпадают по размеру! Даже указатели на разные типы данных (char* и float*) компилятор не позволит хранить в 
    одном массиве, несмотря на то, что они одинакового размера. Единственный способ хранить в массиве два разных типа указателей — 
    сделать эти типы наследниками одного и того же базового класса. При этом базовому классу даже нет нужды иметь какие-то собственные 
    данные, это может быть абстрактный класс, из которого никакие объекты создаваться не будут. Конструкторы могут хранить значения в 
    порожденных классах обычным способом, но должна иметься специальная чистая виртуальная функция для того, чтобы извлечь эти значения. 
    Представляем возможный сценарий работы над этим вопросом:
    class Token {           // Абстрактный базовый класс
    public:
        virtual float getNumber()= 0;       // чистая виртуальная функция
        virtual char getOperator()= 0;
    };
    class Operator : public Token {
    private:
        char oper;                  // Операторы +, -, *, /
    public:
        Operator(char);             // конструктор устанавливает значение
        char getOperator();         // получить значение
        float getNumber();          // просто некая функция
    };
    class Number : public Token {
    private:
        float fnum;                 // число
    public:
        Number(float);              // конструктор устанавливает значение
        float getNumber();          // получить значение
        char getOperator();         // просто некая функция
    };
    Token* atoken[100];             // содержит типы Operator* и Number*
    Виртуальные функции базового класса должны быть реализованы во всех порожденных классах, в противном случае классы становятся 
    абстрактными. Таким образом, классу Operand нужна функция getNumber(), несмотря на то, что она фиктивная. Классу Number нужна функция 
    getOperand(), несмотря на то, что она тоже фиктивная. Поработайте над этим каркасом, сделайте его реально работающей программой, 
    добавив класс Stack, содержащий объекты класса Token, и функцию main(), в которой бы заносились в стек и извлекались из него разные 
    арифметические операторы и числа в формате с плавающей запятой. */
    // task8.cpp

    /*9. Внесем некоторое разнообразие в пример HORSE из главы 10, создав класс для внесения в него лошадей экстракласса. Предположим, 
    что любая лошадь, которая на скачках к середине дистанции находится впереди всех, становится практически непобедимой. Относительно 
    класса лошадей создадим порожденный класс comhorse (для конкурентоспособной лошади). Перегрузим функцию horse_tick() в этом классе 
    таким образом, чтобы каждая лошадь могла проверять, является ли она ведущей и нет ли поблизости соперников (скажем, ближе, чем на 
    0.1 форлонг (1/80 часть мили или 20.1 м.)). Если есть, то ей следует немного ускориться. Может быть, не настолько, чтобы побеждать 
    на всех скачках, но в достаточной мере для того, чтобы оставаться конкурентоспособной. Как каждая лошадь узнает, где находятся 
    остальные? Моделирующий ее объект должен иметь доступ к области памяти, в которой хранятся данные о соперниках. В программе HORSE 
    это hArray. Будьте внимательны: вы создаете класс для передовой лошади, он должен быть наследником класса всех лошадей. Поэтому 
    классу comhorse потребуется перегрузить hArray. Вам может потребоваться создать еще один производный класс, comtrack, для 
    отслеживания позиции лошади. Можно непрерывно проверять, лидирует ли ваша лошадь, и если она впереди всех, но лишь ненамного, 
    следует ее немного ускорить. */
    // task9.cpp

    /*10. Упражнение 4 в главе 10 включало в себя добавление к классу linklist перегружаемого деструктора. Допустим, мы заполняем объект
    этого класса данными, а затем присваиваем один класс целиком другому, используя стандартный оператор присваивания:
        list2 = list1;
    Допустим, что впоследствии мы удалим объект класса list1. Можем ли мы все еще использовать list2 для доступа к введенным данным? 
    Увы, нет, так как при удалении list1 все его ссылки были удалены. Единственное, что было известно объекту linklist про удаленный 
    объект, это указатель на него. Но его удалили, указатель в list2 стал недееспособным, и все попытки получить доступ к данным 
    приведут к получению мусора вместо данных, а в худшем случае — к зависанию программы. Один из способов избежать этих проблем — 
    перегрузить оператор присваивания, чтобы он вместе с объектом копировал бы все его ссылки. Но тогда придется пройти по всей цепочке,
    поочередно копируя все ссылки. Как отмечалось ранее, следует также перегружать конструктор копирования. Чтобы была возможность 
    удалять объекты linklist в main(), можно создавать их с помощью указателя и new. В таком случае проще будет проверять работу новых 
    операций. Не переживайте, если обнаружите, что в процессе копирования порядок следования данных изменился. Понятно, что копирование 
    всех данных не является самым эффективным решением проблемы с точки зрения экономии памяти. Сравните этот подход с представленным в 
    примере STRIMEM (глава 10), где использовался только один набор данных для всех объектов, и хранилась информация о том, сколько 
    объектов указывали на эти данные. */
    linklist li;        // создаем переменную-список
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);     // добавляем туда несколько чисел
    li.display();       // показываем список
    linklist liTwo;        // создаем переменную-список
    cout << "---------" << endl;
    liTwo = li;
    liTwo.display();       // показываем список

    /*11. В 8 задаче */


    return 0;
}