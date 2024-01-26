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
    mon = stold(strTo);
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
// Task 8

class Token {           // Абстрактный базовый класс
public:
    virtual float getNumber() = 0;       // чистая виртуальная функция
    virtual char getOperator() = 0;
};
class Operator : public Token {
private:
    char oper;                  // Операторы +, -, *, /
public:
    Operator(char s) : oper(s) {}   // конструктор устанавливает значение
    char getOperator();             // получить значение
    float getNumber();              // просто некая функция
};
class Number : public Token {
private:
    float fnum;                 // число
public:
    Number(float f) : fnum(f) {}    // конструктор устанавливает значение
    float getNumber();              // получить значение
    char getOperator();             // просто некая функция
};
// Калькулятор
const int LEN = 80;         // максимальная длина выражения
const int MAXCALC = 40;
class Stack {
private:
    char st[MAXCALC];       // массив данных
    int top;                // количество сохраненных данных
public:
    Token multi;
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
    /*publication* pubarr[100];       // массив указателей на публикации
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
    cout << endl; */

    /*3. В классе Distance, как показано в примерах FRENGL и FRISQ из этой главы, создайте перегружаемую операцию умножения *, чтобы 
    можно было умножать два расстояния. Сделайте эту функцию дружественной, тогда можно будет использовать выражение типа Wdist = 7.5*dist2. 
    Вам понадобится конструктор с одним аргументом для перевода величин из формата чисел с плавающей запятой в формат Distance. Напишите 
    какой-либо main() на свое усмотрение для того, чтобы несколькими способами проверить работу этой перегружаемой операции.*/
    /*Distance dist1(10, 2);
    Distance dist2(10, 5);
    Distance dist3;
    dist3 = dist1 * dist2;
    dist3 = 7.5*dist3;
    dist3.showdist();
    dist3 = 10.0 *dist3; */

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
    /*const int ASIZE = 10;                   // размер массива
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
    cout << endl; */

    /*5. Взяв за основу программу из упражнения 1 этой главы, добавьте метод типа bool, называющийся isOveersize(), к классам book и tape. 
    Допустим, книга, в которой больше 800 страниц, или кассета со временем проигрывания более 90 минут, будут считаться объектами с превышением 
    размера. К этой функции можно обращаться из main(), а результат ее работы выводить в виде строки «Превышение размера!» для соответствующих 
    книг и кассет. Допустим, объекты классов book и tape должны быть доступны через указатели на них, хранящиеся в массиве типа publication. 
    Что в этом случае вам нужно добавить в базовый класс publication? Вы можете привести примеры компонентов этого базового класса? */
    /*publication* pubarr[100];       // массив указателей на публикации
    int n = 0;                      // число публикаций в массиве
    char choice;                    
    do {
        cout << "\nВводить данные для книги (b) или для пленки (t)?";
        cin >> choice;
        if(choice == 'b')
            pubarr[n] = new book;
        else
            pubarr[n] = new tape;
        pubarr[n++]->getdata();
        cout << "Продолжать (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    for(int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        if (pubarr[j]->isOveersize() == 1)
            cout << "«Превышение размера!»" << endl;
    } */

    /*6. Возьмите за основу программу из упражнения 8 главы 8, где было перегружено пять арифметических операций для работы с денежным 
    форматом. Добавьте два оператора, которые не были перегружены в том упражнении:
        long double * bMoney // умножать число на деньги
        long double / bMoney // делить число на деньги
    Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева — обычное число. Убедитесь,
    что main() позволяет пользователю ввести две денежные строки и число с плавающей запятой, а затем корректно выполняет все семь 
    арифметических действий с соответствующими парами значений. */
    //bMoney mon1; 
    /*const long double number = 12;
    bMoney mon2(10);
    bMoney mon3;
    //mon3 = number * mon2;
    mon3 = number / mon2;
    cout << number << " * ";
    mon2.getmoney(); 
    cout << " = "; 
    mon3.getmoney(); */

    /*7. Как и в предыдущем упражнении, возьмите за основу программу из упражнения 8 главы 8. На этот раз от вас требуется добавить 
    функцию, округляющую значение bMoney до ближайшего доллара: mo2 = round(mo1); Как известно, значения, не превышающие $0.49, 
    округляются вниз, а числа от $0.50 и более округляются вверх. Можно использовать библиотечную функцию modfl(). Она разбивает 
    переменную типа long double на целую и дробную части. Если дробная часть меньше 0.50, функция просто возвращает целую часть числа. 
    В противном случае возвращается увеличенная на 1 целая часть. В main() проверьте работоспособность функции путем передачи в нее 
    последовательно значений, одни из которых меньше $0.49, другие - больше $0.50. */
    /*bMoney mo1(2.39);
    bMoney mo2(4.89);
    bMoney mo3 = round(mo1);    // 2
    bMoney mo4 = round(mo2);    // 5
    mo3.getmoney();
    mo4.getmoney(); */

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


    return 0;
}