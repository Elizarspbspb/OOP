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