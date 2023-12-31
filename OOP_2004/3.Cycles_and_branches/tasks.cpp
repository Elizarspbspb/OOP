#include <iostream>
#include <iomanip> // для использования setw

using namespace std;

int main()
{
    /*  1. Предположим, вы хотите создать таблицу умножения на заданное число. Напишите программу,
    которая позволяет пользователю ввести это число, а затем генерирует таблицу размером 20 строк на 10 столбцов.
    Первые строки результата работы программы должны выглядеть примерно следующим образом:
        Введите число: 7
        7142128354249566370
        77849198105112119126133140
        147154161168175182189196203210 */
    /* Решение учебника
    for(int j = 1; j <= 200; j++) {  // цикл от 1 до 200
        cout << setw(5) << j*n << " ";  // вывести произведение
        if(j % 10 == 0) // через каждые 10 чисел
            cout << endl;   // начинать новую строку
    }   */
     // Альтернативное решение
    uint input_number_1, count = 1;
    cout << "Введите положительное число для таблицы умножения:";
    cin >> input_number_1;
    for(int line = 1; line <= 20; line++) {
        cout << setw(12) << line << " столбец: ";
        for(int column = 0; column < 10; column++) {
            cout << setw(5) << input_number_1 * count << " ";
            count++;
        }
        cout << endl;
    }

    /*  2. Напишите программу, предлагающую пользователю осуществить перевод температуры из шкалы Цельсия
    в шкалу Фаренгейта или наоборот, а затем осуществите преобразование. Используйте в программе переменные
    вещественного типа. Взаимодействие программы с пользователем может выглядеть следующим образом:
        Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта,
        2 для перевода шкалы Фаренгейта в шкалу Цельсия: 2
        Введите температуру по Фаренгейту: 70
        Значение по Цельсию: 21.111111 */
    uint choose;
    double temp;  // температура
    cout << "Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта, 2 для перевода шкалы Фаренгейта в шкалу Цельсия: ";
    cin >> choose;
    switch(choose) {
        case 1:
            cout << "Введите температуру по Цельсию: ";
            cin >> temp;
            cout << "Температура no Фаренгейту равна " << temp * (9.0 / 5.0) + 32 << '\n';
            break;
        case 2:
            cout << "Введите температуру по Фаренгейту: ";
            cin >> temp;
            cout << "Температура no Цельсию равна " << (temp - 32) * 5 / 9 << '\n';
            break;
        default:
            cout << "Некорректно выбран способ перевода" << endl;
            exit(0);
    }

    /*3. Операции ввода, такие, как cin, должны уметь преобразовывать последовательность символов в число.
    Напишите программу, которая позволяет пользователю ввести шесть цифр, а затем выводит результат
    типа long на экране. Каждая цифра должна считываться отдельно при помощи функции getche().
    Вычисление значения переменной производится путем умножения текущего ее значения на 10
    и сложения с последней введенной цифрой (чтобы из кода символа получить цифру, вычтите из него 48 или '0').
    Примером результата работы программы может служить следующий:
        Введите число: 123456
        Вы ввели число 123456 */
    char number = 'a';
    long result = 0;
    cout << "Введите цифры для формирования числа" << endl;
    while(number != '\n')  {
        cin >> number;
        result = (number-48)+result*10;
    }
    cout << "result = " << result << endl;

    /*4. Создайте эквивалент калькулятора, выполняющего четыре основных арифметических операции.
    Программа должна запрашивать ввод пользователем первого операнда, знака операции и второго операнда.
    Для хранения операндов следует использовать переменные вещественного типа. Выбрать операцию можно
    при помощи оператора switch. В конце программа должна отображать результат на экране. Результат работы
    программы с пользователем может выглядеть следующим образом:
        Введите первый операнд, операцию и второй операнд: 10 / 3
        Результат равен 3.333333
        Выполнить еще одну операцию (y/n)? y
        Введите первый операнд, операцию и второй операнд: 12 + 100
        Результат равен 112
        Выполнить еще одну операцию (y/n)? n */
    double num_1, num_2;
    char operation, contin = '+';
    do {
        cout << "Введите первый операнд, операцию и второй операнд: ";
        cin >> num_1 >> operation >> num_2;
        switch(operation) {
            case '+':
                cout << num_1 << operation << num_2 << "=" << num_1 + num_2 << endl;
                break;
            case '-':
                cout << num_1 << operation << num_2 << "=" << num_1 - num_2 << endl;
                break;
            case '/':
                cout << num_1 << operation << num_2 << "=" << num_1 / num_2 << endl;
                break;
            case '*':
                cout << num_1 << operation << num_2 << "=" << num_1 * num_2 << endl;
                break;
            default:
                cout << num_1 << operation << num_2 << "Некорректная операция" << endl;
        }
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> contin;
    } while(contin != 'n');

    /*5. При помощи цикла for изобразите на экране пирамиду из символов 'X'.
    Верхняя часть пирамиды должна выглядеть следующим образом:
        х
        ххх
        ххххх
        ххххххх
        ххххххххх
    Вся пирамида должна быть высотой 20 линий. Одним из способов ее построения может служить
    использование двух вложенных циклов, из которых внутренний будет заниматься печатанием
    символов 'X' и пробелов, а другой осуществлять переход на одну строку вниз. */
    for(int line = 1; line <= 20; line++) {
        for(int column = 0; column < line; column++)
            cout << "X";
        cout << endl;
    }

    /*6. Измените программу factor, чтобы она циклически запрашивала ввод пользователем числа
    и вычисляла его факториал, пока пользователь не введет 0 для завершения. При необходимости
    вы можете использовать соответствующие операторы программы factor в цикле do или while. */
    // factor.cpp
    // подсчет факториала числа с помощью цикла for
    char contin = '0';
    do {
        unsigned int numb;
        unsigned long fact = 1; // тип long для результата
        cout << "Введите целое число: ";
        cin >> numb;
        for(int j = numb; j > 0; j--)   // умножение 1 на
            fact *= j;  // numb, numb-1, ..., 2, 1
        cout << "Факториал числа равен " << fact << endl;
        cout << "Выполнить еще одну операцию (../0)? ";
        cin >> contin;
    } while(contin != '0');

    /*7. Напишите программу, рассчитывающую сумму денег, которые вы получите при вложении
    начальной суммы с фиксированной процентной ставкой дохода через определенное количество лет.
    Пользователь должен вводить с клавиатуры начальный вклад, число лет и процентную ставку. Например:
        Введите начальный вклад: 3000
        Введите число лет: 10
        Введите процентную ставку: 5.5
        Через 10 лет вы получите 5124.43 доллара.
    В конце первого года вы получите 3 000 + (3 000*0.055) = 3165 долларов.
    В конце следующего года вы получите 3 165 + (3 165*0.055) = 3339.08 долларов. Вычисление с циклом for. */
    double deposit, years, procent = 0;
    cout << "Введите начальный вклад: ";
    cin >> deposit;
    cout << "Введите число лет: ";
    cin >> years;
    cout << "Введите процентную ставку: ";
    cin >> procent;
    for(int i = 0; i < years; i++) {
        deposit += (deposit * (procent / 100));
    }
    cout << "Через " << years << " лет вы получите " << deposit << " доллара." << endl;

    /*8. Напишите программу, которая циклически будет запрашивать ввод пользователем двух денежных сумм,
    выраженных в фунтах, шиллингах и пенсах. Программа должна складывать введенные суммы и выводить на экран
    результат, также выраженный в фунтах, шиллингах и пенсах. После каждой итерации программа должна
    спрашивать пользователя, желает ли он продолжать работу программы. Рекомендуется использовать цикл do.
    Взаимодействие программы с пользователем:
        Введите первую сумму £5 10 6
        Введите первую сумму £3 2 6
        Всего £8 13 0
        Продолжить(y/n) ?
    Для того чтобы сложить две суммы, вам необходимо учесть заем одного шиллинга в том случае, если число
    пенсов окажется больше 11, и одного фунта, если число шиллингов окажется больше 19. */
    int funt1, shil1, pens1, funt2, shil2, pens2;
    char contin = '0';
    do {
        cout << "Введите первую сумму £";
        cin >> funt1 >> shil1 >> pens1;
        cout << "Введите первую сумму £";
        cin >> funt2 >> shil2 >> pens2;
        pens2 = pens1 + pens2;
        if (pens2 > 11) {
            while (pens2 >= 12) {
                pens2 -= 12;
                shil2++;
            }
        }
        shil2 = shil2 + shil1;
        if (shil2 > 19) {
            while (shil2 >= 20) {
                shil2 -= 20;
                funt2++;
            }
        }
        funt2 = funt2 + funt1;
        cout << "Всего £" << funt2 << " " << shil2 << " " << pens2 << endl;
        cout << "Продолжить(y/n) ? ";
        cin >> contin;
    } while(contin != 'n');

    /*9. Представьте, что вы собираетесь пригласить к себе шестерых гостей, но завашим столом могут разместиться
    всего лишь 4 человека. Сколькими способами можно разместить четырех из шести гостей за обеденным столом?
    Каждый из шести гостей может разместиться на первом стуле. Каждый из оставшихся пяти гостей может занять
    второй стул. На третьем стуле может разместиться один их четырех гостей, и на четвертом — один из трех оставшихся гостей.
    Двоим из гостей не достанется ни одного места. Таким образом, число возможных рассадок гостей за столом
    равно 6*5*4*3 = 360. Напишите программу, которая будет производить аналогичные вычисления для любого числа гостей
    и любого числа мест за столом (при этом предполагается, что число гостей не меньше числа мест).
    Вычисление можно организовать с помощью простого цикла for. */
    uint guest, chair, combination = 1;
    cout << "Введите число гостей: ";
    cin >> guest;
    cout << "Введите число мест: ";
    cin >> chair;
    if(chair>guest) {
        exit(0);
    }
    for(chair; chair != 0; chair--) {
        combination *= guest;
        guest--;
    }
    cout << "Число возможных рассадок гостей: " << combination << endl;

    /*10. Модифицируйте программу, описанную в упражнении 7, так, чтобы вместо вычисления текущей суммы
    на вашем счете она вычисляла, сколько лет потребуется для того, чтобы при заданной процентной ставке
    и величине начального вклада сумма на вашем счете достигла запрашиваемого вами значения. Для хранения
    найденного числа лет используйте переменную целого типа (можно отбросить дробную часть значения,
    полученного в результате расчета). Самостоятельно выберите тип цикла, подходящий для решения задачи. */
    double deposit, procent, income, years = 0;
    cout << "Введите процентную ставку: ";
    cin >> procent;
    cout << "Введите начальный вклад: ";
    cin >> deposit;
    cout << "Введите желаемую сумму дохода: ";
    cin >> income;
    while(deposit <= income) {
        deposit += (deposit / 100 * procent);
        years++;
    }
    cout << "Желаемая сумма " << income << " будет получена через " << years << " лет" << endl;

    /*11. Создайте калькулятор, выполняющий действия над денежными суммами, выраженными в фунтах,
    шиллингах и пенсах (см. упр. 10 и 12 главы 2). Калькулятор должен складывать и вычитать вводимые
    значения, а также производить умножение денежной суммы на вещественное число (операция умножения
    двух денежных сумм не имеет смысла, квадратных денежных единиц не существует.
    Деление одной денежной суммы на другую мы тоже не будем рассматривать). Организация взаимодействия
    с калькулятором описана в упражнении 4 этой главы. */
    double funt1, shil1, pens1, funt2, shil2, pens2;
    double number;
    char mark, contin = '+';
    do {
        cout << "Введите количество фунтов первой денежной суммы: ";
        cin >> funt1;
        cout << "Введите количество шиллингов первой денежной суммы: ";
        cin >> shil1;
        cout << "Введите количество пенсов первой денежной суммы: ";
        cin >> pens1;

        cout << "Введите операцию: ";
        cin >> mark;
        if(mark == '*') {
            cout << "Введите вещественное число для умножения: ";
            cin >> number;
            goto multiplication;
        }

        cout << "Введите количество фунтов второй денежной суммы: ";
        cin >> funt2;
        cout << "Введите количество шиллингов второй денежной суммы: ";
        cin >> shil2;
        cout << "Введите количество пенсов второй денежной суммы: ";
        cin >> pens2;
        switch(mark) {
            case '+':
                pens2 = pens1 + pens2;
                if (pens2 > 11) {
                    while (pens2 >= 12) {
                        pens2 -= 12;
                        shil2++;
                    }
                }
                shil2 = shil2 + shil1;
                if (shil2 > 19) {
                    while (shil2 >= 20) {
                        shil2 -= 20;
                        funt2++;
                    }
                }
                funt2 = funt2 + funt1;
                break;
            case '-':
                pens2 = pens1 - pens2;
                if (pens2 < 0) {
                    while (pens2 <= 0) {
                        pens2 += 12;
                        shil1--;
                    }
                }
                shil2 = shil1 - shil2;
                if (shil2 < 0) {
                    while (shil2 <= 0) {
                        shil2 += 20;
                        funt1--;
                    }
                }
                funt2 = funt1 - funt2;
                break;
            default:
                cout << funt1 << shil1 << pens1 << mark << funt2 << shil2 << pens2 << "Некорректная операция" << endl;
        }
        goto viewresult;

        multiplication:
            funt2 = funt1 * number;
            shil2 = shil1 * number;
            pens2 = pens1 * number;
            if (pens2 > 11) {
                while (pens2 >= 12) {
                    pens2 -= 12;
                    shil2++;
                }
            }
            if (shil2 > 19) {
                while (shil2 >= 20) {
                    shil2 -= 20;
                       funt2++;
                }
            }

        viewresult:
            cout << "Итоговый результат £" << funt2 << " . " << shil2 << " . " << pens2 << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> contin;
    } while(contin != 'n');
    
    /* 12. Создайте калькулятор, выполняющий четыре арифметических действия над дробями (см. упр. 9 гл. 2; упр. 4 гл. 3).
    Формулы, демонстрирующие выполнение арифметических операций над дробями, приведены ниже.
    Сложение:   a/b+c/d=(a*d+b*c)/(b*d)
    Вычитание:  a/b-c/d=(a*d-b*c)/(b*d)
    Умножение:  a/b*c/d=(a*c)/(b*d)
    Деление:    a/b/c/d = (a*d)/(b*c)
    Пользователь должен сначала ввести первый операнд, затем знак операции и второй операнд. 
    После вычисления результата программа должна отобразить его на экране и запросить пользователя 
    о его желании произвести еще одну операцию. */
    int a, b, c, d;
    char fraction, operation, contin = 'y';
    do {
        cout << "Введите первую дробь, операцию и вторую дробь: ";
        cin >> a >> fraction >> b >> operation >> c >> fraction >> d;
        switch(operation) {
            case '+':
                cout << a*d+b*c << "/" << b*d << endl;
                break;
            case '-':
                cout << a*d-b*c << "/" << b*d << endl;
                break;
            case '/':
                cout << a*d << "/" << b*c << endl;
                break;
            case '*':
                cout << a*c << "/" << b*d << endl;
                break;
            default:
                cout << fraction << " - некорректная операция" << endl;
        }
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> contin;
    } while(contin != 'n');

    return 0;
}