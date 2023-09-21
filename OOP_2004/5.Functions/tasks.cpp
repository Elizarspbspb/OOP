#include <iostream>

using namespace std;

const float PI = 3.14159F;  // вещественная константа

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
int count = 0;
void showCount();

// Task 11
struct sterling {
    int pounds, shillings, pence;
};
sterling getAldMoney(int, int, int);
sterling sumMoney(sterling&, sterling&);
void showAldMoney(sterling&);

// Task 12
struct fraction {
    int dividend;
    int divisor;
};
fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);

int main() {
    /*1. Вернитесь к рассмотрению примера CIRCAREA главы 2 «Основы программирования на C++». 
    Напишите функцию с именем circarea(), которая аналогичным образом вычисляет площадь круга. 
    Функция должна принимать один аргумент типа float и возвращать значение типа float. Напишите 
    функцию main(), которая просит пользователя ввести значение радиуса, вызывает функцию circarea(), 
    а затем отображает результат вычисления на экране. */
    // circarea.cpp     работа с переменными вещественного типа
    float rad, area;  // переменная вещественного типа
    cout << "Введите радиус окружности: "; // запрос
    cin >> rad;     // получение радиуса
    area = circarea(rad);
    cout << "Площадь круга равна " << area << endl;

    /*2. Возведение числа n в степень р — это умножение числа n на себя р раз. Напишите функцию с именем 
    power(), которая в качестве аргументов принимает значение типа double для n и значение типа int для р 
    и возвращает значение типа double. Для аргумента, соответствующего степени числа, задайте значение
    по умолчанию, равное 2, чтобы при отсутствии показателя степени при вызове функции число n возводилось 
    в квадрат. Напишите функцию main(), которая запрашивает у пользователя ввод аргументов для функции 
    power(), и отобразите на экране результаты ее работы.*/
    double number;
    int powerOf;
    cout << "Введите число для возведения в степень: "; 
    cin >> number;  
    cout << "Введите степень для возведения числа: "; 
    cin >> powerOf;
    cout << "Результат операции = " << power(number, powerOf) << endl;
    //cout << "Результат операции = " << power(number) << endl;

    /*3. Напишите функцию с именем zeroSmaller(), в которую передаются с помощью ссылок два аргумента 
    типа int, присваивающую меньшему из аргументов нулевое значение. Напишите программу для проверки 
    работы функции. */
    int low = 10;
    int high = 20;
    cout << "low = " << low << "; high = " << high << endl;
    zeroSmaller(low, high);
    cout << "low = " << low << "; high = " << high << endl;

    /*4. Напишите функцию, принимающую в качестве аргументов два значения типа Distance и возвращающую 
    значение наибольшего из аргументов (необходимую информацию можно найти в примере RETSTRC). */
    Distance fi, se;
    fi.feet = 5;
    fi.inches = 10;
    se.feet = 8;
    se.inches = 12;
    engldisp(checkDis(fi, se));

    /*5. Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды. 
    Функция должна возвращать эквивалент переданного ей временного значения в секундах (типа long). 
    Создайте программу, которая будет циклически запрашивать у пользователя ввод значения часов, минут 
    и секунд и выводить результат работы функции на экран. */
    int hours, minutes, seconds;
    long fullSeconds = 0;
    char word, colon;
    while (word != 'n') {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> hours >> colon >> minutes >> colon >> seconds;
        fullSeconds = hms_to_secs(hours, minutes, seconds);
        cout << "Полное время в секундах: " << fullSeconds << endl;
        cout << "Продолжить ввод времени (y or n) : ";
        cin >> word; 
    }

    /*6. Модифицируйте программу, описанную в упражнении 11 главы 4 «Структуры», складывающую два 
    структурных значения типа time. Теперь программа должна включать в себя две функции. Первая, time_to_secs(), 
    принимает в качестве аргумента значение типа time и возвращает эквивалентное значение в секундах типа long. 
    Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long, а возвращает 
    эквивалентное значение типа time. */
    Time total_one, total_two, total_three;
    char colonT;
    bool good = false;
    while (good != true) {
        cout << "Введите время в формате часы:минуты:секунды (23:41:59): ";
        cin >> total_one.hours >> colonT >> total_one.minutes >> colonT >> total_one.seconds;
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
        cin >> total_two.hours >> colonT >> total_two.minutes >> colonT >> total_two.seconds;
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
    cout << total_three.hours << ":" << total_three.minutes << ":" << total_three.seconds << endl;

    /*7. Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением 
    типа double, создайте перегруженные функции с этим же именем, принимающими в качестве аргумента 
    значения типа char, int, long и float. Напишите программу, вызывающую функцию power() со всеми 
    возможными типами аргументов.*/
    char num1 = 'a';
    int num2 = 5;
    long num3 = 3;
    float num4 = 4.5;
    int powerOf_1 = 3;
    cout << "Результат операции char = " << power(num1, powerOf_1) << endl;
    cout << "Результат операции int = " << power(num2, powerOf_1) << endl;
    cout << "Результат операции long = " << power(num3, powerOf_1) << endl;
    cout << "Результат операции float = " << power(num4, powerOf_1) << endl;
    cout << "Результат операции T = " << powerT(num1, powerOf_1) << endl;

    /*8. Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int 
    (обратите внимание, что изменяться должны значения переменных из вызывающей программы, а не 
    локальных переменных функции). Выберите способ передачи аргументов. Напишите вызывающую 
    программу main(), использующую данную функцию. */
    int first = 10; 
    int second = 20;
    cout << "one = " << first << "; two = " << second << endl;
    swap(first, second);
    cout << "one = " << first << "; two = " << second << endl;

    /*9. Переработайте программу из упражнения 8 так, чтобы функция swap() принимала 
    в качестве аргументов значения типа time (см. упражнение 6). */
    Time one, two; 
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
    cout << two.hours << ":" << two.minutes << ":" << two.seconds << endl;

    /*10. Напишите функцию, которая при каждом вызове будет выводить на экран количество раз, 
    которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не 
    менее 10 раз. Попробуйте реализовать данную функцию двумя различными способами: с использованием
    глобальной переменной и статической локальной переменной для хранения числа вызовов функции. 
    Какой из способов предпочтительней? Почему для решения задачи нельзя использовать обычную 
    локальную переменную?   */
    for(int i=0; i<10; i++) {
        showCount();
    }

    /*11. Напишите программу, использующую структуру sterling, которая описана в упражнении 10 
    главы 4. Программа должна получать от пользователя значения двух денежных сумм, выраженных в 
    фунтах, шиллингах и пенсах, складывать эти значения и выводить результат на экран в том же 
    формате. Необходимо разработать три функции. Первая из них должна получать от пользователя 
    число фунтов, шиллингов и пенсов и возвращать соответствующее значение типа sterling. Вторая 
    функция должна принимать в качестве аргументов два значения типа sterling, складывать их и 
    возвращать значение, также имеющее тип sterling. Третья функция должна принимать аргумент 
    типа sterling и выводить его значение на экран. */
    int pounds1, shillings1, pence1, pounds2, shillings2, pence2;
    sterling oneM, twoM, sumM;
    cout << "Введите первую сумму £";
    cin >> pounds1 >> shillings1 >> pence1;
    cout << "Введите первую сумму £";
    cin >> pounds2 >> shillings2 >> pence2;
    oneM = getAldMoney(pounds1, shillings1, pence1);
    twoM = getAldMoney(pounds2, shillings2, pence2);
    sumM = sumMoney(oneM, twoM);
    showAldMoney(sumM);

    /* 12. Модифицируйте калькулятор, созданный в упражнении 12 главы 4, так, чтобы каждая 
    арифметическая операция выполнялась с помощью функции. Функции могут называться fadd(), 
    fsub(), fmul() и fdiv(). Каждая из функций должна принимать два структурных аргумента 
    типа fraction и возвращать значение того же типа. */
    fraction firstOp, secondOp, result; 
    char fraction, operation, contin = 'y';
    do {
        cout << "Введите первую дробь, операцию и вторую дробь: ";
        cin >> firstOp.dividend >> fraction >> firstOp.divisor >> operation >> secondOp.dividend >> fraction >> secondOp.divisor;
        switch(operation) {
            case '+':
                result = fadd(firstOp, secondOp);
                cout << result.dividend << "/" << result.divisor << endl;
                break;
            case '-':
                result = fsub(firstOp, secondOp);
                cout << result.dividend << "/" << result.divisor << endl;
                break;
            case '/':
                result = fdiv(firstOp, secondOp);
                cout << result.dividend << "/" << result.divisor << endl;
                break;
            case '*':
                result = fmul(firstOp, secondOp);
                cout << result.dividend << "/" << result.divisor << endl;
                break;
            default:
                cout << fraction << " - некорректная операция" << endl;
        }
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> contin;
    } while(contin != 'n');
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

// Task 11
sterling getAldMoney(int pounds, int shillings, int pence) {
    sterling money;
    money.pounds = pounds;
    money.shillings = shillings;
    money.pence = pence;
    return money;
}
sterling sumMoney(sterling& one, sterling& two) {
    sterling sumMoney;
    sumMoney.pence = one.pence + two.pence;
    if (sumMoney.pence > 11) {
        while (sumMoney.pence >= 12) {
            sumMoney.pence -= 12;
            two.shillings++;
        }
    }
    sumMoney.shillings = one.shillings + two.shillings;
    if (sumMoney.shillings > 19) {
        while (sumMoney.shillings >= 20) {
            sumMoney.shillings -= 20;
            two.pounds++;
        }
    }
    sumMoney.pounds = one.pounds + two.pounds;
    return sumMoney;
}
void showAldMoney(sterling& sumMoney) {
    cout << "Всего £" << sumMoney.pounds << " " << sumMoney.shillings << " " << sumMoney.pence << endl;
}

// Task 12
fraction fadd(fraction first, fraction second) {
    fraction operation;
    operation.dividend = first.dividend * second.divisor + first.divisor * second.dividend;
    operation.divisor = first.divisor * second.divisor;            
    return operation;
}
fraction fsub(fraction first, fraction second) {
    fraction operation;              
    operation.dividend = first.dividend * second.divisor - first.divisor * second.dividend;
    operation.divisor = first.divisor * second.divisor;            
    return operation;
}
fraction fmul(fraction first, fraction second) {
    fraction operation;
    operation.dividend = first.dividend * second.dividend;
    operation.divisor = first.divisor * second.divisor;            
    return operation;
}
fraction fdiv(fraction first, fraction second) {
    fraction operation;
    operation.dividend = first.dividend * second.divisor;
    operation.divisor = first.divisor * second.dividend;           
    return operation;
}