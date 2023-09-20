#include <iostream>

using namespace std;

const float PI = 3.14159F;  // вещественная константа
int count = 0;

// Task 1
float circarea(float);

// Task 2
double power(double n, int p = 2);

// Task 3
void zeroSmaller(int& low, int& high);

// Task 4
struct Distance {
    int feet;
    float inches;
};
void engldisp(Distance);
Distance checkDis(Distance, Distance);

// Task 5
long hms_to_secs(int, int, int);

// Task 6
struct Time {
    int hours;
    int minutes;
    int seconds;
};
long time_to_secs(Time&);
Time secs_to_time(long);

// Task 7
char power(char n, int p = 2);
int power(int n, int p = 2);
long power(long n, int p = 2);
float power(float n, int p = 2);
// ИЛИ template
template<typename T>
T powerT(T n, int p);

// Task 8
void swap(int&, int&);

// Task 9
template<typename T>
void swapT(T&, T&);

// Task 10
void showCount();

int main() {
    /*1. Вернитесь к рассмотрению примера CIRCAREA главы 2 «Основы программирования на C++». 
    Напишите функцию с именем circarea(), которая аналогичным образом вычисляет площадь круга. 
    Функция должна принимать один аргумент типа float и возвращать значение типа float. Напишите 
    функцию main(), которая просит пользователя ввести значение радиуса, вызывает функцию circarea(), 
    а затем отображает результат вычисления на экране. */
    // circarea.cpp     работа с переменными вещественного типа
    /*float rad, area;  // переменная вещественного типа
    cout << "Введите радиус окружности: "; // запрос
    cin >> rad;     // получение радиуса
    area = circarea(rad);
    cout << "Площадь круга равна " << area << endl; */

    /*2. Возведение числа n в степень р — это умножение числа n на себя р раз. Напишите функцию с именем 
    power(), которая в качестве аргументов принимает значение типа double для n и значение типа int для р 
    и возвращает значение типа double. Для аргумента, соответствующего степени числа, задайте значение
    по умолчанию, равное 2, чтобы при отсутствии показателя степени при вызове функции число n возводилось 
    в квадрат. Напишите функцию main(), которая запрашивает у пользователя ввод аргументов для функции 
    power(), и отобразите на экране результаты ее работы.*/
    /*double number, result;
    int powerOf;
    cout << "Введите число для возведения в степень: "; 
    cin >> number;  
    cout << "Введите степень для возведения числа: "; 
    cin >> powerOf;
    cout << "Результат операции = " << power(number, powerOf) << endl;
    //cout << "Результат операции = " << power(number) << endl;*/

    /*3. Напишите функцию с именем zeroSmaller(), в которую передаются с помощью ссылок два аргумента 
    типа int, присваивающую меньшему из аргументов нулевое значение. Напишите программу для проверки 
    работы функции. */
    /*int low = 10;
    int high = 20;
    cout << "low = " << low << "; high = " << high << endl;
    zeroSmaller(low, high);
    cout << "low = " << low << "; high = " << high << endl;*/

    /*4. Напишите функцию, принимающую в качестве аргументов два значения типа Distance и возвращающую 
    значение наибольшего из аргументов (необходимую информацию можно найти в примере RETSTRC). */
    /*Distance fi, se;
    fi.feet = 5;
    fi.inches = 10;
    se.feet = 8;
    se.inches = 12;
    engldisp(checkDis(fi, se));*/

    /*5. Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды. 
    Функция должна возвращать эквивалент переданного ей временного значения в секундах (типа long). 
    Создайте программу, которая будет циклически запрашивать у пользователя ввод значения часов, минут 
    и секунд и выводить результат работы функции на экран. */
    /*int hours, minutes, seconds;
    long fullSeconds = 0;
    char word, colon;
    while (word != 'n') {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> hours >> colon >> minutes >> colon >> seconds;
        fullSeconds = hms_to_secs(hours, minutes, seconds);
        cout << "Полное время в секундах: " << fullSeconds << endl;
        cout << "Продолжить ввод времени (y or n) : ";
        cin >> word; 
    }*/

    /*6. Модифицируйте программу, описанную в упражнении 11 главы 4 «Структуры», складывающую два 
    структурных значения типа time. Теперь программа должна включать в себя две функции. Первая, time_to_secs(), 
    принимает в качестве аргумента значение типа time и возвращает эквивалентное значение в секундах типа long. 
    Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long, а возвращает 
    эквивалентное значение типа time. */
    /*Time total_one, total_two, total_three;
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
    long total_seсs_one = time_to_secs(total_one);
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
    long total_seсs_two = time_to_secs(total_two);
    total_seсs_two += total_seсs_one;
    total_three = secs_to_time(total_seсs_two);
    cout << total_three.hours << ":" << total_three.minutes << ":" << total_three.seconds << endl;*/

    /*7. Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением 
    типа double, создайте перегруженные функции с этим же именем, принимающими в качестве аргумента 
    значения типа char, int, long и float. Напишите программу, вызывающую функцию power() со всеми 
    возможными типами аргументов.*/
    /*char num1 = 'a';
    int num2 = 5;
    long num3 = 3;
    float num4 = 4.5;
    int powerOf_1 = 3;
    cout << "Результат операции char = " << power(num1, powerOf_1) << endl;
    cout << "Результат операции int = " << power(num2, powerOf_1) << endl;
    cout << "Результат операции long = " << power(num3, powerOf_1) << endl;
    cout << "Результат операции float = " << power(num4, powerOf_1) << endl;
    cout << "Результат операции T = " << powerT(num1, powerOf_1) << endl;*/

    /*8. Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int 
    (обратите внимание, что изменяться должны значения переменных из вызывающей программы, а не 
    локальных переменных функции). Выберите способ передачи аргументов. Напишите вызывающую 
    программу main(), использующую данную функцию. */
    /*int one = 10; 
    int two = 20;
    cout << "one = " << one << "; two = " << two << endl;
    swap(one, two);
    cout << "one = " << one << "; two = " << two << endl;*/

    /*9. Переработайте программу из упражнения 8 так, чтобы функция swap() принимала 
    в качестве аргументов значения типа time (см. упражнение 6). */
    /*Time one, two; 
    one.hours = 14;
    one.minutes = 30;
    one.seconds = 40;
    two.hours = 8;
    two.minutes = 20;
    two.seconds = 50;
    cout << one.hours << ":" << one.minutes << ":" << one.seconds << endl;
    cout << two.hours << ":" << two.minutes << ":" << two.seconds << endl;
    swapT(one, two);
    cout << one.hours << ":" << one.minutes << ":" << one.seconds << endl;
    cout << two.hours << ":" << two.minutes << ":" << two.seconds << endl;*/

    /*10. Напишите функцию, которая при каждом вызове будет выводить на экран количество раз, 
    которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не 
    менее 10 раз. Попробуйте реализовать данную функцию двумя различными способами: с использованием
    глобальной переменной и статической локальной переменной для хранения числа вызовов функции. 
    Какой из способов предпочтительней? Почему для решения задачи нельзя использовать обычную 
    локальную переменную?   */
    /*for(int i=0; i<10; i++) {
        showCount();
    }*/

    /*11. */


    return 0;
}

// Task 1
float circarea(float rad) {
    float area = PI * rad * rad;    // вычисление площади круга
    return area;
}

// Task 2
double power(double n, int p) {
    double result = 1.0;
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
    // РЕКУРСИЯ
    /*if (p == 0) {
        return 1;
    } else if (p == 1) {
        return n;
    } else if (p < 3 && p > 1) {
        return n * n;
    } else {
        return (n * power(n, p-1));
    }*/
}

// Task 3
void zeroSmaller(int& low, int& high) {
    if(low < high) {
        low = 0;
    } else if(low > high) {
        high = 0;
    }
}

// Task 4
// engldisp() выводит структуру типа Distance в футах и дюймах
void engldisp(Distance dd) {
    cout << dd.feet << "\'-" << dd.inches << "\"";
}
Distance checkDis(Distance fi, Distance se) {
    if (fi.feet > se.feet) {
        return fi;
    }
    if (fi.feet < se.feet) {
        return se;
    }
    if (fi.inches > se.inches) {
        return fi;
    } else {
        return se;
    }
}

// Task 5
long hms_to_secs(int hours, int minutes, int seconds){
    long totalseсs;
    if(hours >= 24 || hours < 0) {
        cout << "Неправильно введены часы !" << endl;
        return 0;
    } else if(minutes >= 60 || minutes < 0) {
        cout << "Неправильно введены минуты !" << endl;
        return 0;
    } else if(seconds >= 60 || seconds < 0) {
        cout << "Неправильно введены секунды !" << endl;
        return 0;
    }
    totalseсs = hours * 3600 + minutes * 60 + seconds;
    return totalseсs;
}

// Task 6
long time_to_secs(Time& total) {
    return total.hours * 3600 + total.minutes * 60 + total.seconds;
}
Time secs_to_time(long total_seсs) {
    Time total;
    total.hours = total_seсs/3600;
    total.minutes = (total_seсs - (total.hours * 3600))/60;
    total.seconds = total_seсs - (total.hours * 3600) - (total.minutes * 60);
    return total;
}

// Task 7
char power(char n, int p) {
    char result = '\0';
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
}
int power(int n, int p) {
    int result = 1;
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
}
long power(long n, int p) {
    long result = 1;
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
}
float power(float n, int p) {
    float result = 1.0;
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
}
// ИЛИ 
template<typename T>
T powerT(T n, int p) {
    T result = 1.0;
    for(int j = 0; j < p; j++)
        result *= n;    
    return result;
}

// Task 8
void swap(int& one, int& two) {
    int temp = one;
    one = two;
    two = temp;
}

// Task 9
template<typename T>
void swapT(T& one, T& two) {
    T temp = one;
    one = two;
    two = temp;
}

// Task 10
void showCount() {
    static int countStatic = 0;
    cout << count++ << " : " << countStatic++ << endl;
}