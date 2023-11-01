#include <iostream>
#include <iomanip>      // setw
#include <cstring>
#include <string>

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
public:
    employeSeven() : number(0), name("startEmploy") {};
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
    fraction masFrac[MAXSTR];
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
    }

    return 0;
}