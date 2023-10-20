#include <iostream>

using namespace std;

// Task 1
/*class Int {
    int value;
public:
    Int() : value(0) {};                // конструктор значение = нулю
    Int(int number) : value(number) {}; // метод установки целого значения
    void showvalue() const {            // метод вывода значения
        cout << "Значение поля = " << value << endl; 
    }
    Int sum(const Int&) const;
};
Int Int::sum(const Int& two) const {
    Int temp;
    temp.value = value + two.value;
    return temp;
}*/

// Task 2
/*const char ESC = 27;
const double TOLL = 0.50;
class tollBooth {
private:
    unsigned int countCar;
    double profit;
public:
    tollBooth() : countCar(0), profit(0) {};
    void payingCar() {
        ++countCar;
        profit += TOLL;
    } 
    void nopayCar() {
        ++countCar;
    }
    void display() const {
        cout << "Проехало миашин = " << countCar << endl;
        cout << "Прибыль = " << profit << endl;  
    }
    ~tollBooth() = default;
};*/

//Task 3
/*class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {};
    Time(int hour, int minut, int sec) : hours(hour), minutes(minut), seconds(sec) {};
    void showTime() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    void sum(const Time&, const Time&);
    ~Time() = default;
};
void Time::sum(const Time& one, const Time& two) {
    unsigned long allSecsOne = one.hours * 3600 + one.minutes * 60 + one.seconds;
    unsigned long allSecsTwo = two.hours * 3600 + two.minutes * 60 + two.seconds;
    allSecsOne += allSecsTwo;

    hours = allSecsOne/3600;
    minutes = (allSecsOne - (hours * 3600))/60;
    seconds = allSecsOne - (hours * 3600) - (minutes * 60);
}*/

// Task 4
/*class employee {
    int number;
    float stipend;
public:
    employee() : number(0), stipend(0.0) {};
    void inputEmploy() {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите размер пособия сотрудника: ";
        cin >> stipend;
    }
    void showEmploy() const {
        cout << "Номер сотрудника: " << number << endl;
        cout << "Размер пособия сотрудника: " << stipend << endl;
        cout << "-----" << endl;
    }
};*/

// Task 5
/*class date {
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
};*/

// Task 6
/*enum etype { laborer, secretary, manager, accountant, executive, researcher };
class employee {
    int number;
    float stipend;
    etype character;
    date da;
public:
    employee() : number(0), stipend(0.0) {};
    void getemploy() {
        char symbol;
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите размер пособия сотрудника: ";
        cin >> stipend;
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
        cout << "Введите дату в формате 31/12/2002" << endl;
        int day, mounth, year;
        cin >> day >> symbol >> mounth >> symbol >> year;
        da.getdate(day, mounth, year);
    }
    void putemploy() const {
        cout << "Номер сотрудника: " << number << endl;
        cout << "Размер пособия сотрудника: " << stipend << endl;
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
        da.showdate();
        cout << "-----" << endl;
    }
};*/

// Task 7
/*class angle {
    int grade;
    float minuts;
    char route;
public:
    angle(int gr, float min, char rout) : grade(gr), minuts(min), route(rout) {};
    void setAngle() {
        bool confirm = true;
        while (confirm) {
            while (confirm) {
                cout << "Введите градусы: ";
                cin >> grade;
                if (grade < 0) {
                    cout << "Введены отрицательные значения градусов. Введите значения повторно" << endl;
                    continue;
                } else if (grade > 180) {
                    cout << "Введены большие значения градусов. Введите значения повторно" << endl;
                    continue;
                }
                confirm = false;
            }
            confirm = true;
            while (confirm) {
                cout << "Введите минуты: ";
                cin >> minuts;
                if (minuts < 0) {
                    cout << "Введены отрицательные значения градусов. Введите значения повторно" << endl;
                    continue;
                } else if (minuts > 60) {
                    cout << "Введены большие значения минут. Преобразование 60 мин. = 1 гр." << endl;
                    int temp = 0;
                    temp = static_cast<int>(minuts)/60;
                    grade += temp;
                    minuts -= temp*60;
                }
                confirm = false;
            }
            confirm = true;
            while (confirm) {
                cout << "Введите направление (N, S, Е или W): ";
                cin >> route;
                if ((route != 'N') && (route != 'S') && (route != 'E') && (route != 'W')) {
                    continue;
                } else if (((route == 'N') || (route == 'S')) && grade > 90) {
                    cout << "Введены большие значения градусов для направлений N или S." << endl; 
                    cout << "Требуется повторный ввод градусов и минут" << endl;
                    break;
                } else if (((route == 'E') || (route == 'W')) && grade > 180) {
                    cout << "Введены большие значения градусов для направлений E или W." << endl; 
                    cout << "Требуется повторный ввод градусов и минут" << endl;
                    break;
                } else 
                    confirm = false;
            }
        }
    }
    void showAngle() const { // 179°59.9' Е
        cout << grade << "@" << minuts << '\'' << route << endl;
    }
}; */

// Task 8
class countObjects {
    static int allCount;
    int count;
public:
    countObjects(int c) : count(c){
        ++allCount;
    };
    void showObj() const {
        cout << "Мой порядковый номер: " << count << " из " << allCount << endl;
    }
};
int countObjects::allCount = 0;

// Task 9
/*class fraction {
    int dividend;
    int divisor;
public:
    fraction(int divid, int divis) : dividend(divid), divisor(divis) {};
    void showFrac() const {
        cout << dividend << "/" << divisor << endl;
    }
    void sumFrac(const fraction& one, const fraction& two) {
        dividend = one.dividend * two.divisor + one.divisor * two.dividend;
        divisor = one.divisor * two.divisor;
    }
};*/

class ship {
    countObjects 
};

int main(int argc, char* argv[]) {
    /*1. Создайте класс Int, имитирующий стандартный тип int. Единственное поле этого класса должно иметь 
    тип int. Создайте методы, которые будут устанавливать значение поля, равным нулю, инициализировать его 
    целым значением, выводить значение поля на экран и складывать два значения типа Int. Напишите программу,
    в которой будут созданы три объекта класса Int, два из которых будут инициализированы. Сложите два 
    инициализированных объекта, присвойте результат третьему, а затем отобразите результат на экране. */
    /*Int one(5), two(10), three;
    three = one.sum(two);
    three.showvalue();*/

    /*2. Представьте пункт для взимания платежей за проезд по автостраде. Каждая проезжающая машина должна 
    заплатить за проезд 50 центов, однако часть машин платит за проезд, а часть проезжает бесплатно. 
    В кассе ведется учет числа проехавших машин и суммарная выручка от платы за проезд. Создайте модель 
    такой кассы с помощью класса tollBooth. Класс должен содержать два поля. Одно из них, типа unsigned int,
    предназначено для учета количества проехавших автомобилей, а второе, имеющее тип double, будет содержать
    суммарную выручку от оплаты проезда. Конструктор должен инициализировать оба поля нулевыми значениями. 
    Метод payingCar() инкрементирует число машин и увеличивает на 0.50 суммарную выручку. Другой метод, 
    nopayCar(), увеличивает на единицу число автомобилей, но оставляет без изменения выручку. Метод display()
    выводит оба значения на экран. Там, где это возможно, сделайте методы константными. Создайте программу,
    которая продемонстрирует работу класса. Программа должна предложить пользователю нажать одну клавишу для
    того, что-бы сымитировать заплатившего автолюбителя, и другую клавишу, чтобы сымитировать недобросовестного
    водителя. Нажатие клавиши Esc должно привести к выдаче текущих значений количества машин и выручки и 
    завершению программы. */
    /*tollBooth ride;
    char symbol;
    cout << "\nВведите 1 для заплатившего автолюбителя, "
        << "\n 0 для недобросовестного водителя, "
        << "\n Esc для выхода " << endl;
    do {
        cin >> symbol;
        if(symbol == '1') {
            ride.payingCar();
        } else if (symbol == '0') {
            ride.nopayCar();
        }
    } while(symbol != ESC);
    ride.display();*/

    /*3. Создайте класс с именем time, содержащий три поля типа int, предназначенные для хранения часов, 
    минут и секунд. Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой
    конструктор — заданным набором значений. Создайте метод класса, который будет выводить значения полей на
    экран в формате 11:59:59, и метод, складывающий значения двух объектов типа time, передаваемых в 
    качестве аргументов. В функции main() следует создать два инициализированных объекта (подумайте, должны
    ли они быть константными) и один неинициализированный объект. Затем сложите два инициализированных 
    значения, а результат присвойте третьему объекту и выведите его значение на экран. 
    Где возможно, сделайте методы константными. */
    /*const Time one(12, 30, 45), two(6, 25, 20); 
    Time three;
    three.sum(one, two);
    three.showTime(); */

    /*4. Создайте класс employee, используя упражнение 4 главы 4. Класс должен включать поле типа int для 
    хранения номера сотрудника и поле типа float для хранения величины его оклада. Методы класса должны 
    позволять пользователю вводить и отображать данные класса. Напишите функцию main(), которая запросит 
    пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран. */
    /*employee one, two, three;
    one.inputEmploy();
    two.inputEmploy();
    three.inputEmploy();
    one.showEmploy();
    two.showEmploy();
    three.showEmploy();*/

    /*5. Взяв в качестве основы структуру из упражнения 5 главы 4, создайте класс date. Его данные должны 
    размещаться в трех полях типа int: month, day и year. Метод класса getdate() должен принимать значение 
    для объекта в формате 12/31/02, а метод showdate() — выводить данные на экран. */
    /*date time_1;
    char symbol;
    int day, mounth, year;
    cout << "Введите дату в формате 31/12/2002" << endl;
    //cin >> time_1.day >> symbol >> time_1.mounth >> symbol >> time_1.year;
    cin >> day >> symbol >> mounth >> symbol >> year;
    time_1.getdate(day, mounth, year);
    time_1.showdate();*/

    /*6. Расширьте содержание класса employee из упражнения 4, включив в него класс date и перечисление 
    etype (см. упражнение 6 главы 4). Объект класса date будет использоваться для хранения даты приема 
    сотрудника на работу. Перечисление будет использовано для хранения статуса сотрудника: лаборант, 
    секретарь, менеджер и т. д. Последние два поля данных должны быть закрытыми в определении класса 
    employee, как и номер и оклад сотрудника. Вам будет необходимо разработать методы getemploy() и 
    putemploy(), предназначенные соответственно для ввода и отображения информации о сотруднике. Возможно, 
    при создании методов вам понадобится ветвление switch для работы с перечисляемым типом etype. Напишите 
    функцию main(), которая попросит пользователя ввести данные о трех сотрудниках, а затем выведет эти 
    данные на экран.*/
    /*employee emp1, emp2, emp3;
    emp1.getemploy();
    emp1.putemploy();
    emp2.getemploy();
    emp2.putemploy();
    emp3.getemploy();
    emp3.putemploy();*/

    /*7. В морской навигации координаты точки измеряются в градусах и минутах широты и долготы. Например, 
    координаты бухты Папити на о. Таити равны 149 градусов 34.8 минут восточной долготы и 17 градусов 31.5
    минут южной широты. Это записывается как 149°34.8' W, 17°31.5' S. Один градус равен 60 минутам 
    (устаревшая система также делила одну минуту на 60 секунд, но сейчас минуту делят на обычные десятичные 
    доли). Долгота измеряется величиной от 0 до 180 градусов восточнее или западнее Гринвича. Широта 
    принимает значения от 0 до 90 градусов севернее или южнее экватора. Создайте класс angle, включающий 
    следующие три поля: типа int для числа градусов, типа float для числа минут и типа char для указания 
    направления (N, S, Е или W). Объект этого класса может содержать значение как широты, так и долготы. 
    Создайте метод, позволяющий ввести координату точки, направление, в котором она измеряется, и метод, 
    выводящий на экран значение этой координаты, например 179°59.9' Е. Кроме того, напишите конструктор, 
    принимающий три аргумента. Напишите функцию main(), которая сначала создает переменную с помощью 
    трехаргументного конструктора и выводит ее значение на экран, а затем циклически запрашивает 
    пользователя ввести значение координаты и отображает введенное значение на экране. Для вывода символа 
    градусов (°) можно воспользоваться символьной константой '\xF8'.*/
    /*angle abscissa(0, 0.0, 'W');
    angle ordinate(0, 0.0, 'N');
    abscissa.showAngle();
    ordinate.showAngle();
    abscissa.setAngle();
    ordinate.setAngle();
    abscissa.showAngle();
    ordinate.showAngle();*/

    /*8. Создайте класс, одно из полей которого хранит «порядковый номер» объекта, то есть для первого 
    созданного объекта значение этого поля равно 1, для второго созданного объекта значение равно 2 и т.д.
    Для того чтобы создать такое поле, вам необходимо иметь еще одно поле, в которое будет записываться 
    количество созданных объектов класса (это означает, что последнее поле должно относиться не к отдельным 
    объектам класса, а ко всему классу в целом. Вспомните, какое ключевое слово необходимо при описании 
    такого поля.). Каждый раз при создании нового объекта конструктор может получить значение этого поля и в
    соответствии с ним назначить объекту индивидуальный порядковый номер. В класс следует включить метод,
    который будет выводить на экран порядковый номер объекта. Создайте функцию main(), в которой будут созданы
    три объекта, и каждый объект выведет на экран свой порядковый номер, например: Мой порядковый номер: 2 и т.п.*/
    /*countObjects objects1(1);
    countObjects objects2(2);
    countObjects objects3(3);
    objects1.showObj();
    objects2.showObj();
    objects3.showObj(); */

    /*9. На основе структуры fraction из упражнения 8 главы 4 создайте класс fraction. Данные класса должны
    быть представлены двумя полями: числителем и знаменателем. Методы класса должны получать от пользователя
    значения числителя и знаменателя дроби в форме 3/5 и выводить значение дроби в этом же формате. Кроме 
    того, должен быть разработан метод, складывающий значения двух дробей. Напишите функцию main(), которая
    циклически запрашивает у пользователя ввод пары дробей, затем складывает их и выводит результат на экран.
    После каждой такой операции программа должна спрашивать пользователя, следует ли продолжать цикл.*/
    /*int dividend, divisor;
    char frac;
    cout << "Введите первую дробь: ";
    cin >> dividend >> frac >> divisor;
    fraction first(dividend, divisor);
    cout << "Введите вторую дробь: ";
    cin >> dividend >> frac >> divisor;
    fraction second(dividend, divisor);
    fraction third(0, 0);
    third.sumFrac(first, second); 
    third.showFrac();*/

    /*10. Создайте класс с именем ship, который будет содержать данные об учетном номере корабля и 
    координатах его расположения. Для задания номера корабля следует использовать механизм, аналогичный
    описанному в упражнении 8. Для хранения координат используйте два поля типа angle. Разработайте метод,
    который будет сохранять в объекте данные о корабле, вводимые пользователем, и метод, выводящий данные
    о корабле на экран. Напишите функцию  main(), создающую три объекта класса ship, затем запрашивающую 
    ввод пользователем информации о каждом из кораблей и выводящую на экран всю полученную информацию. */


    return 0;
}