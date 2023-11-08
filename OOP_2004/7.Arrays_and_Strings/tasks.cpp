#include <iostream>
#include <iomanip>      // setw
#include <cstring>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

const int MAXSTR = 100;  // максимальная длина строки

///////////////////////////////////////////////////////////

// Task 1
char reversit(const char re[]) {
    char input[MAXSTR];
    for (int j = 0, i = strlen(re); i >= -1; --i, ++j) {
        input[j] = re[i];
        cout << input[j] << " ";
    }
    return *input;
}
/*void reversit(char s[]) {
    int len = strlen(s);
    for(int j = 0; j < len / 2; j++) {  // поменять все символы из первой половины
        char temp = s[j];               // на символы
        s[j] = s[len - j - 1];          // из второй половины
        s[len - j - 1] = temp;
    }
}*/

// Task 2
class employeSeven {
    long number;
    string name;
    // ИЛИ 
    // long number{};
    // string name{};
public:
    employeSeven() : number(0), name("startEmploy") {};
    // ИЛИ 
    // employeSeven() = default;
    void getdata() {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите имя сотрудника: ";
        cin >> name;
        //getline(cin, name, ' ');
    }
    void putdata() const {
        cout << "Номер сотрудника: " << number << endl;
        cout << "Имя сотрудника: " << name << endl;
        cout << "-----" << endl;
    }
};

// Task 3
class Distance {
    int feet;
    float inches;
public: 
    Distance() { feet = 0; inches = 0; }
    Distance(int ft, float in) : feet(ft), inches(in) {};
    void getdist() {
        cout << "\nВведите футы:";
        cin >> feet;
        cout << "Введите дюймы:";
        cin >> inches;
    }
    void showdist() { 
        cout << feet << "\'-" << inches << '\"' << "; "; 
    }
    void add_dist(Distance, Distance);
    void div_dist(Distance, int);
};
void Distance::add_dist(Distance d2, Distance d3) {   // сложение расстояний d2 и d3
    inches = d2.inches + d3.inches;      // сложить дюймы
    feet = 0;
    if(inches >= 12.0) {        // (для возможного переноса) если сумма превышает 12.0,
        inches -= 12.0;         // уменьшить число дюймов на 12.0 и увеличить число футов на 1
        feet++;
    }
    feet += d2.feet + d3.feet;   // сложить футы
}
void Distance::div_dist(Distance d2, int divisor) {
    float fltfeet = d2.feet + d2.inches / 12.0;
    float temp = fltfeet /= divisor;
    feet = int(fltfeet);
    inches = (temp - feet) * 12.0;
}

// Task 4
int maxint(int numbers[], int count) {
    int max = 0, index = 0;
    for (int i = 0; i < count; i++) {
        if (max < numbers[i]) {
            max = numbers[i];
            index = i;
        }
    }
    return index;
}

// Task 5
// class fractions from 11 and 12 exercises
//#include "../6.Objects_and_classes/tasks.cpp"
#include "../6.Objects_and_classes/tasks.h"

//Task 6
enum Suit { clubs, diamonds, hearts, spades };  // от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card {
    int number;
    Suit suit;
public:
    card() { }
    void set(int n, Suit s) { suit = s; number = n; }
    void display();
};
/////////////////////////////////////////////////////////////
void card::display() {
    if (number >= 2 && number <= 10)
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
        case clubs: cout << static_cast<char>(5); break;
        case diamonds: cout << static_cast<char>(4); break;
        case hearts: cout << static_cast<char>(3); break;
        case spades: cout << static_cast<char>(6); break;
    }
}

//Task 7
class Money{
public:
    long double mstold(string);
};
long double Money::mstold(string strFrom) {
    string strTo;
    long double mon = 0.0;
    for (int size = 0, sizeTwo = 0; size < strFrom.length(); size++) {
        if (strFrom[size] >= 48 && strFrom[size] <= 57) {
            strTo[sizeTwo++] = strFrom[size];
        } else if (strFrom[size] == '.') {
            strTo[sizeTwo++] = strFrom[size];
        }
    }
    mon = stold(strTo); // mon = _atold(strTo);
    return mon;
}

//Task 7
const int LIMIT = 100;      // максимальная длина строки
class safearay {
    int masSeven[LIMIT];
public:
    int putel(int index, int value) {
        if (index > LIMIT-1 || index < 0)
            return -1;
        masSeven[index] = value;
        return 0;
    }
    int getel(int index) const {
        if (index > LIMIT-1 || index < 0)
            return -1;
        return masSeven[index];
    }
};

int main(int argc, char* argv[]) {
    /*1. Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл 
    for, который меняет местами первый и последний символы, затем следующие и т. д. до предпоследнего. 
    Строка должна передаваться в функцию reversit() как аргумент. Напишите программу для выполнения функции
    reversit(). Программа должна принимать строку от пользователя, вызывать функцию reversit(), а затем 
    выводить полученный результат. Используйте метод ввода, который позволяет использовать внутренние 
    пробелы. Протестируйте программу на примере фразы «Аргентина манит негра». */
    /*char input[MAXSTR];
    cout << "Введите строку текста" << endl;
    //cin >> input;             // работает до пробела
    cin.ignore();
    cin.get(input, MAXSTR);     // работает до новой строки
    cout << reversit(input) << endl;
    //reversit(input);            // перевернуть строку
    cout << "Перевернутая строка:" << input << endl; */

    /*2. Создайте класс employee, который содержит имя (объект класса string) и номер (типа long) служащего.
    Включите в него метод getdata(), предназначенный для получения данных от пользователя и помещения их в
    объект, и метод putdata(), для вывода данных. Предполагаем, что имя не может иметь внутренних пробелов.
    Напишите функцию main(), использующую этот класс. Вам нужно будет создать массив типа employee, а затем
    предложить пользователю ввести данные до 100 служащих. Наконец, вам нужно будет вывести данные всех служащих.*/
    /*employeSeven sotr[MAXSTR];
    char contin = 'y';
    int countEmploys = 0;
    do {
        sotr[countEmploys++].getdata();
        cout << "Добавить еще сотрудника (y or n) ? : ";
        cin >> contin;
    } while(contin != 'n');
    while(countEmploys >= 0) {
        sotr[countEmploys--].putdata();
    } */

    /*3. Напишите программу, вычисляющую среднее значение до 100 интервалов, введенных пользователем. 
    Создайте массив объектов класса Distance, как это было сделано в примере ENGLARAY этой главы. Для 
    вычисления среднего значения вы можете позаимствовать метод add_dist() из примера ENGLCON главы 6. 
    Вам также понадобится метод, который выделяет целую часть из значения Distance. 
    Вот одна из возможностей:
        void Distance::div_dist(Distance d2, int divisor) {
            float fltfeet = d2.feet + d2.inches / 12.0;
            float temp = fltfeet /= divisor;
            feet = int(fltfeet);
            inches = (temp - feet) * 12.0;
        }*/
    /*Distance num[MAXSTR];
    Distance result;
    char continuE;
    int count = 0;
    do {
        num[count].getdist();
        cout << "Добавить еще расстояние (y or n) ? : ";
        cin >> continuE;
        result.add_dist(result, num[count++]);
    } while(continuE != 'n');
    cout << endl << "Сумма всех длин: ";
    result.showdist();
    cout << endl << "Среднее значение: ";
    result.div_dist(result, count);
    result.showdist();
    cout << endl;
    while (count >= 0) {
        num[count--].showdist();
    } */

    /*4. Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять их в
    массиве типа int. Напишите функцию maxint(), которая, обрабатывая элементы массива один за другим, 
    находит наибольший. Функция должна принимать в качестве аргумента адрес массива и количество элементов 
    в нем, а возвращать индекс наибольшего элемента. Программа должна вызвать эту функцию, а затем вывести
    наибольший элемент и его индекс. (Смотрите программу SALES этой главы.) */
    /*string num;
    int numbers[MAXSTR];
    int count = 0, index = 0;
    while (count < 5) {
        ////cin >> numbers[count++];
        cin >> num;
        try {
            numbers[count] = stoi(num);     // stoi - from string to int; stof - from string to float
        } catch (invalid_argument const& e) {
            std::cerr << "Ошибка - Число не является целым!" << endl;
        } catch (out_of_range const& e) {
            std::cerr << "Ошибка - Число слишком велико или мало для целого типа!" << endl;
        }
        count++;
    }
    index = maxint(numbers, count);
    cout << "Индекс = " << index << "; Элемент: " << numbers[index] << endl; */

    /*5. Начните с класса fraction из упражнений 11 и 12 главы 6. Напишите функцию main(), которая получает
    случайные дробные числа от пользователя, сохраняет их в массиве типа fraction, вычисляет среднее 
    значение и выводит результат. */
    /*fraction masFrac[MAXSTR];
    fraction result(0, 1);
    char continuEFrac;
    int countFrac = 0;
    do {
        cout << "Введите дробь: ";
        masFrac[countFrac].enterFr();
        cout << "Ввести еще одну дробь (y/n)? ";
        cin >> continuEFrac;
        result.fadd(result, masFrac[countFrac++]);
    } while(continuEFrac != 'n');
    result.showFr();
    cout << endl;
    fraction divCount(countFrac, 1);
    result.fdiv(result, divCount);
    result.lowterms();
    cout << "Среднее значение = ";
    result.showFr();
    cout << endl;
    while(countFrac >= 0) {
        masFrac[--countFrac].showFr();
        cout << "; ";
    } */

    /*6. В игре бридж каждому из игроков раздают 13 карт, таким образом колода расходуется полностью. 
    Модифицируйте программу CARDARAY этой главы так, чтобы после перемешивания колоды она делилась на 
    четыре части по 13 карт каждая. Каждая из четырех групп карт затем должна быть выведена. */
    /*card deck[52];
    int j;
    cout << endl;
    for (j = 0; j < 52; j++) {      // создаем упорядоченную колоду карт
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    cout << "Исходная колода:\n";   // показываем исходную колоду
    for (j = 0; j < 52; j++) {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13))     // начинаем новую строку после каждой 13-й карты
            cout << endl;
    }
    srand(time(NULL));          // инициализируем генератор случайных чисел
    for (j = 0; j < 52; j++) {
        int k = rand() % 52;    // выбираем случайную карту
        card temp = deck[j];    // и меняем ее с текущей
        deck[j] = deck[k];
        deck[k] = temp;
    }
    cout << "\nПеремешанная колода:\n";     // показываем перемешанную колоду
    for (j = 0; j < 52; j++) {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            cout << endl;
    } */

    /* 7. Одним из недостатков C++ является отсутствие для бизнес-программ встроенного типа для денежных
    значений, такого, как $173 698 001.32. Такой денежный тип должен иметь возможность для хранения числа с
    фиксированной десятичной точкой точностью около 17 знаков, которого было бы достаточно для хранения 
    национального долга в долларах и центах. К счастью, встроенный тип C++ long double имеет точность 19 
    цифр, поэтому мы можем использовать его как базисный для класса money, даже используя плавающую точку. 
    Однако нам нужно будет добавить возможность ввода и вывода денежных значений с предшествующим им знаком
    доллара и разделенными запятыми группы по три числа: так проще читать большие числа. Первым делом при 
    разработке такого класса напишем метод mstold(), который принимает денежную строку, то есть строку, 
    представляющую собой некоторое количество денег типа "$1 234 567 890 123.99" в качестве аргумента и 
    возвращает эквивалентное ее значению число типа long double.
        Вам нужно будет обработать денежную строку как массив символов и, просматривая ее символ за символом,
    скопировать из нее только цифры (0-9) и десятичную точку в другую строку. Игнорируется все остальное,
    включая знак доллара и запятые. Затем вы можете использовать библиотечную функцию _atold() (заметим, 
    что здесь название функции начинается с символа подчеркивания — заголовочные файлы STDLIB.H или MATH.H)
    для преобразования новой строки к числу типа long double. Предполагаем, что денежное значение не может
    быть отрицательным. Напишите функцию main() для проверки метода mstold(), которая несколько раз получает
    денежную строку от пользователя и выводит соответствующее число типа long double. */
    /*string money;
    Money text;
    cout << "Введите денежную сумму ($1 234 567 890 123.99): ";
    getline(cin, money);
    cout << "Число = " << text.mstold(money) << endl; */

    /*8. Другим недостатком C++ является отсутствие автоматической проверки индексов массива на 
    соответствие их границам массива (это делает действия с массивами быстрыми, но менее надежными). 
    Мы можем использовать класс для создания надежного массива, который проверяет индексы при любой 
    попытке доступа к массиву. Напишите класс safearay, который использует массив типа int фиксированного
    размера (назовем его LIMIT) в качестве своей единственной переменной. В классе будет два метода. 
    Первый, putel(), принимает индекс и значение типа int как аргументы и вставляет это значение в массив
    по заданному индексу. Второй, getel(), принимает индекс как аргумент и возвращает значение типа int, 
    содержащееся в элементе с этим индексом.
        safearay sa1;           // описываем массив
        int temp = 12345;       // описываем целое
        sa1.putel(7, temp);     // помещаем значение temp в массив
        temp = sa1.getel(7);    // получаем значение из массива
    Оба метода должны проверять индекс аргумента, чтобы быть уверенными, что он не меньше 0 и не больше, 
    чем LIMIT-1. Вы можете использовать этот массив без опаски, что запись будет произведена в другие 
    части памяти. Использование методов для доступа к элементам массива не выглядит так наглядно, как 
    использование операции []. В главе 8 мы увидим, как перегрузить эту операцию, чтобы сделать работу 
    нашего класса safearay похожей на работу встроенных массивов. */
    safearay sa1;           // описываем массив
    int temp = 12345;       // описываем целое
    sa1.putel(7, temp);     // помещаем значение temp в массив
    temp = sa1.getel(7);    // получаем значение из массива

    return 0;
}