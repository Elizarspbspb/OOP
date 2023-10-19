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
class date {
    int day;
    int mounth;
    int year;
public:
    date() : day(0), mounth(0), year(0) {};
    void getdate() {
    char symbol;
    cout << "Введите дату в формате 31/12/2002" << endl;
    cin >> time.day >> symbol >> time.mounth >> symbol >> time.year;
    }
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
    date time_1;
    char symbol;
    cout << "Введите дату в формате 31/12/2002" << endl;
    cin >> time_1.day >> symbol >> time_1.mounth >> symbol >> time_1.year;

    return 0;
}