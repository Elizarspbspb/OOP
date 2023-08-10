#include <iostream>
using namespace std;

// Task 1
struct phone        // объявление структуры phone
{
    int sity;       // код города
    int station;    // номер телефонной станции
    int abonent;    // номер абонента
};

// Task 2
struct point        // coordinates
{
    int x;      
    int y;      
};

// Task 3
struct Distance     // длина в английской системе
{
    int feet;
    float inches;
};

// Task 3
struct Volume
{
    Distance length;      
    Distance width; 
    Distance height;     
};

// Task 4
struct employee {
    int number;
    float stipend;
};

// Task 5
struct date {
    int day;
    int mounth;
    int year;
};

// Task 6
enum etype { laborer, secretary, manager, accountant, executive, researcher };

// Task 7
struct employee_new {
    int number;
    float stipend;
    etype emp;
    date time;
};

// Task 8
struct fraction {
    int dividend;
    int divisor;
};

// Task 9
struct time1 {
    int hours;
    int minutes;
    int seconds;
};

// Task 10
struct sterling {
    int pounds, shillings, pence;
};

int main() {
    /*1. Номер телефона, например (212) 767—8900, можно условно разделить на три части: 
    код города (212), номер телефонной станции (767) и номер абонента (8900). Напишите программу 
    с использованием структуры, позволяющую раздельно хранить эти три части телефонного номера. 
    Назовите структуру phone. Создайте две структурные переменные типа phone. Инициализацию одной из них 
    произведите сами, а значения для другой запросите с клавиатуры. Затем выведите содержимое обеих 
    переменных на экран. Результат работы программы должен выглядеть приблизительно так:
        Введите код города, номер станции и номер абонента:
        415 555 1212
        Мой номер (212) 767-8900
        Ваш номер (415) 555-1212    */
    phone tp1, tp2;
    tp1 = {212, 767, 8900};
    cout << "Введите код города, номер станции и номер абонента: ";
    cin >> tp2.sity >> tp2.station >> tp2.abonent;
    cout << "Мой номер (" << tp1.sity << ") " << tp1.station << "-" << tp1.abonent << endl;
    cout << "Мой номер (" << tp2.sity << ") " << tp2.station << "-" << tp2.abonent << endl;

    /*2. Расположение точки на плоскости можно задать с помощью двух координат: x и y. Например, 
    если точка имеет координаты (4, 5), то это значит, что она отстоит на 4 единицы справа 
    от вертикальной оси и на 5 единиц вверх от горизонтальной оси. Сумма двух точек определяется 
    как точка, имеющая координаты, равные сумме соответствующих координат слагаемых. Напишите программу, 
    использующую для интерпретации точки на плоскости структуру с названием point. Определите три 
    переменные типа point, и две из них инициализируйте с помощью значений, вводимых с клавиатуры. 
    Затем присвойте третьей переменной значение суммы первых двух переменных и выведите результат 
    на экран. Результат работы программы может выглядеть следующим образом:
        Введите координаты точки p1: 3 4
        Введите координаты точки p2: 5 7
        Координаты точки p1 + p2 равны 8.11 */
    point p1, p2, p3;
    cout << "Введите координаты точки 1: ";
    cin >> p1.x >> p1.y;
    cout << "Введите координаты точки 2: ";
    cin >> p2.x >> p2.y;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    cout << "Координаты точки p1 + p2 равны " << p3.x << '.' << p3.y << endl;

    /*3. Создайте структуру с именем Volume, содержащую три поля типа Distance из примера englstrc, для 
    хранения трех измерений помещения. Определите переменную типа Volume, инициализируйте ее, вычислите 
    объем, занимаемый помещением, и выведите результат на экран. Для подсчета объема переведите каждое из
    значений типа Distance в значение типа float, равное соответствующей длине в футах и хранимое в отдельной
    переменной. Затем для вычисления объема следует перемножить три полученные вещественные переменные. */
    Volume amount = { {16, 3.5}, {12, 6.25}, {8, 1.75} };
    // преобразование длины, ширины и высоты в вещественный формат
    float len = amount.length.feet + amount.length.inches / 12;
    float wid = amount.width.feet + amount.width.inches / 12;
    float hei = amount.height.feet + amount.height.inches / 12;
    // вычисление объема помещения
    cout << "Объем = " << len*wid*hei << endl;

    /*4. Создайте структуру с именем employee, содержащую два поля: номер сотрудника типа int и величину 
    его пособия в долларах типа float. Запросите с клавиатуры данные о трех сотрудниках, сохраните их в 
    трех структурных переменных типа employee и выведите информацию о каждом из сотрудников на экран. */
    employee mas[3];
    for(int i = 0; i < 3; i++) {
        cout << "Введите номер сотрудника: ";
        cin >> mas[i].number;
        cout << "Введите размер пособия сотрудника: ";
        cin >> mas[i].stipend;
    }
    for(int i = 0; i < 3; i++) {
        cout << "Номер сотрудника: " << mas[i].number << endl;
        cout << "Размер пособия сотрудника: " << mas[i].stipend << endl;
        cout << "-----" << endl;

    }

    /*5. Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. Попросите 
    пользователя ввести день, месяц и год в формате 31/12/2002, сохраните введенное значение в 
    структурной переменной, а затем извлеките данные из этой переменной и выведите их на экран в том же
    формате, в каком они вводились.*/
    date time;
    char symbol;
    cout << "Введите дату в формате 31/12/2002" << endl;
    cin >> time.day >> symbol >> time.mounth >> symbol >> time.year;
    cout << "День = " << time.day << endl;
    cout << "Месяц = " << time.mounth << endl;
    cout << "Год = " << time.year << endl;
    cout << "Символ разделения = " << symbol << endl;

    /*6. Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов 
    данных выводят их внутреннее представление в виде целых чисел. Для того чтобы преодолеть это ограничение, 
    вы можете использовать конструкцию switch, с помощью которой устанавливается соответствие между 
    значением переменной перечисляемого типа и ее внутренним представлением. Пусть, например, в программе 
    определен перечисляемый тип данных etype, отражающий должность сотрудника:
        enum etype { laborer, secretary, manager, accountant, executive, researcher };
    Напишите программу, которая сначала по первой букве должности, введенной пользователем, определяет 
    соответствующее значение переменной, помещает это значение в переменную типа etype, а затем выводит полностью
    название должности, первую букву которой ввел пользователь. Взаимодействие программы с пользователем может 
    выглядеть следующим образом:    
        Введите первую букву должности
        (laborer, secretary, manager, accountant, executive, researcher); a 
        полное название должности: accountant
    Возможно, вам понадобится два ветвления switch: одно — для ввода значения, другое — для вывода. */
    etype character;
    char symbol;
    cout << "Введите первую букву должности" << endl << 
    "(laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> symbol;
    switch(symbol) {
        case 'l':
            character = laborer; break;
        case 's':
            character = secretary; break;
        case 'm':
            character = manager; break;
        case 'a':
            character = accountant; break;
        case 'e':
            character = executive; break;
        case 'r':
            character = researcher; break;
        default:
            cout << "ERROR SYMBOL" << endl;
    }
    cout << "полное название должности: ";
    switch(character) {
        case laborer:
            cout << "laborer" << endl; break;
        case secretary:
            cout << "secretary" << endl; break;
        case manager:
            cout << "manager" << endl; break;
        case accountant:
            cout << "accountant" << endl; break;
        case executive:
            cout << "executive" << endl; break;
        case researcher:
            cout << "researcher" << endl; break;
        default:
            cout << "ERROR SYMBOL" << endl;
    }

    /*7. Добавьте поля типа enum etype (упражнение 6) и struct date (упражнение 5) в структуру employee
    из упражнения 4. Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о 
    каждом из трех сотрудников: его номер, величину зарплаты, его должность и дату принятия на работу. 
    Программа должна хранить введенные значения в трех переменных типа employee и выводить их содержимое на экран. */
    employee_new worker;
    char symbol, letter;
    cout << "Введите номер сотрудника: ";
    cin >> worker.number;
    cout << "Введите величину зарплаты сотрудника: ";
    cin >> worker.stipend;
    cout << "Введите первую букву должности сотрудника: ";
    cin >> letter;
    switch(letter) {
        case 'l':
            worker.emp = laborer; break;
        case 's':
            worker.emp = secretary; break;
        case 'm':
            worker.emp = manager; break;
        case 'a':
            worker.emp = accountant; break;
        case 'e':
            worker.emp = executive; break;
        case 'r':
            worker.emp = researcher; break;
        default:
            cout << "ERROR SYMBOL" << endl;
    }
    cout << "Введите дату принятия на работу сотрудника в формате 31/12/2002: ";
    cin >> worker.time.day >> symbol >> worker.time.mounth >> symbol >> worker.time.year;
    cout << "----------" << endl;
    cout << worker.number << endl;
    cout << worker.stipend << endl;
    cout << worker.time.day << "/" << worker.time.mounth << "/" << worker.time.year << endl;
    switch(worker.emp) {
        case laborer:
            cout << "laborer" << endl; break;
        case secretary:
            cout << "secretary" << endl; break;
        case manager:
            cout << "manager" << endl; break;
        case accountant:
            cout << "accountant" << endl; break;
        case executive:
            cout << "executive" << endl; break;
        case researcher:
            cout << "researcher" << endl; break;
        default:
            cout << "ERROR worker" << endl;
    }

    /* 8. Вернитесь к упражнению 9 главы 2 «Основы программирования на C++». В этом упражнении требуется 
    написать программу, которая хранит значения двух дробей в виде числителя и знаменателя, а затем 
    складывает эти дроби согласно арифметическому правилу. Измените эту программу так, чтобы значения 
    дробей хранились в структуре fraction, состоящей из двух полей типа int, предназначенных для хранения 
    числителя и знаменателя. Все значения дробей должны храниться в переменных типа fraction. */
    fraction first, second; 
    char frac;
    cout << "Введите первую дробь: ";
    cin >> first.dividend >> frac >> first.divisor;
    cout << "Введите вторую дробь: ";
    cin >> second.dividend >> frac >> second.divisor;
    cout << "Сумма равна " << (first.dividend * second.divisor + first.divisor * second.dividend) << frac << (first.divisor * second.divisor) << endl;

    /* 9. Создайте структуру с именем time. Три ее поля, имеющие тип int, будут называться hours, minutes и 
    seconds. Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды. 
    Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение. 
    Программа должна хранить время в структурной переменной типа time и выводить количество секунд в введенном 
    времени, определяемое следующим образом:
        long totalseсs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds */
    time1 totaltime;
    char colon;
    bool good = false;
    while (good != true) {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> totaltime.hours >> colon >> totaltime.minutes >> colon >> totaltime.seconds;
        if(totaltime.hours >= 24 || totaltime.hours < 0) {
            cout << "Неправильно введены часы !" << endl;
        } else if(totaltime.minutes >= 60 || totaltime.minutes < 0) {
            cout << "Неправильно введены минуты !" << endl;
        } else if(totaltime.seconds >= 60 || totaltime.seconds < 0) {
            cout << "Неправильно введены секунды !" << endl;
        } else {
            good = true;
        }
    }
    long totalseсs = totaltime.hours * 3600 + totaltime.minutes * 60 + totaltime.seconds;
    cout << "Общее количество секунд: " << totalseсs << endl;

    /* 10. Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе, 
    описанной в упражнениях 8 и 11 главы 3 «Циклы и ветвления». Поля структуры могут быть названы 
    pounds, shillings и pence и иметь тип int. Программа должна запрашивать у пользователя значение
    денежной суммы в новых десятичных фунтах (значение должно храниться в переменной типа double), 
    затем переводить эту сумму в старую систему, сохранять переведенное значение в переменной типа 
    sterling и выводить на экран полученную сумму в фунтах, шиллингах и пенсах. */
    double new_money;
    cout << "Введите денежную сумму в новых фунтах: ";
    cin >> new_money;
    sterling ald_money;
    ald_money.pounds = static_cast<int>(new_money);
    float decfrac = new_money - ald_money.pounds;  // десятичная дробная часть
    decfrac *= 240;
    ald_money.shillings = static_cast<int>(decfrac) / 12;
    ald_money.pence = static_cast<int>(decfrac) % 12;
    cout << ald_money.pounds << "." << ald_money.shillings << "." << ald_money.pence << endl;
    
    /* 11. Используя структуру time из упражнения 9, напишите программу, которая получает от пользователя 
    два значения времени в формате 12:59:59, сохраняет их в переменных типа struct time, затем переводит 
    оба значения в секунды, складывает их, переводит сумму в исходный формат, сохраняет его в переменной 
    типа time и выводит полученный результат на экран в формате 12:59:59. */
    time1 total_one, total_two, total_three;
    char colon;
    bool good = false;
    while (good != true) {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> total_one.hours >> colon >> total_one.minutes >> colon >> total_one.seconds;
        if(total_one.hours >= 24 || total_one.hours < 0) {
            cout << "Неправильно введены часы !" << endl;
        } else if(total_one.minutes >= 60 || total_one.minutes < 0) {
            cout << "Неправильно введены минуты !" << endl;
        } else if(total_one.seconds >= 60 || total_one.seconds < 0) {
            cout << "Неправильно введены секунды !" << endl;
        } else {
            good = true;
        }
    }
    long total_seсs_one = total_one.hours * 3600 + total_one.minutes * 60 + total_one.seconds;
    good = false;
    while (good != true) {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> total_two.hours >> colon >> total_two.minutes >> colon >> total_two.seconds;
        if(total_two.hours >= 24 || total_two.hours < 0) {
            cout << "Неправильно введены часы !" << endl;
        } else if(total_two.minutes >= 60 || total_two.minutes < 0) {
            cout << "Неправильно введены минуты !" << endl;
        } else if(total_two.seconds >= 60 || total_two.seconds < 0) {
            cout << "Неправильно введены секунды !" << endl;
        } else {
            good = true;
        }
    }
    long total_seсs_two = total_two.hours * 3600 + total_two.minutes * 60 + total_two.seconds;
    total_seсs_two += total_seсs_one;
    total_three.hours = total_seсs_two/3600;
    total_three.minutes = (total_seсs_two - (total_three.hours * 3600))/60;
    total_three.seconds = total_seсs_two - (total_three.hours * 3600) - (total_three.minutes * 60);
    cout << total_three.hours << ":" << total_three.minutes << ":" << total_three.seconds << endl;

    /*12. Переработайте программу-калькулятор для дробей, описанную в упражнении 12 главы 3 так, чтобы каждая
    из дробей хранилась как значение переменной типа struct fraction, по аналогии с упражнением 8 этой главы. */
    fraction first, second; 
    char fraction, operation, contin = 'y';
    do {
        cout << "Введите первую дробь, операцию и вторую дробь: ";
        cin >> first.dividend >> fraction >> first.divisor >> operation >> second.dividend >> fraction >> second.divisor;
        switch(operation) {
            case '+':
                cout << first.dividend * second.divisor + first.divisor * second.dividend << "/" << first.divisor * second.divisor << endl;
                break;
            case '-':
                cout << first.dividend * second.divisor - first.divisor * second.dividend << "/" << first.divisor * second.divisor << endl;
                break;
            case '/':
                cout << first.dividend * second.divisor << "/" << first.divisor * second.dividend << endl;
                break;
            case '*':
                cout << first.dividend * second.dividend << "/" << first.divisor * second.divisor << endl;
                break;
            default:
                cout << fraction << " - некорректная операция" << endl;
        }
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> contin;
    } while(contin != 'n');

    return 0;
}