#include <iostream>
#include <iomanip>  // для использования setw
#include <ctype.h>  // для использования islower()

using namespace std;

int main() {
    // Задача 1.
    /* Считая, что кубический фут равен 7.481 галлона, написать программу,
        запрашивающую у пользователя число галлонов и выводящую на экран
        эквивалентный объем в кубических футах. */
    /*float gallon = 0;
    cout << "Enter number gallon = ";
    cin >> gallon; 
    cout << gallon / 7.481 << " foot;" << endl;*/

    // Задача 2.
    /* Напишите программу, выводящую следующую таблицу:
    1990      135
    1991     7290
    1992    11300
    1993    16200
    В программе использовать только один оператор с cout. */
    /*cout << 1920 << setw(6) << 135 << endl
         << 1921 << setw(6) << 7290 << endl
         << 1922 << setw(6) << 11300 << endl
         << 1923 << setw(6) << 16200 << endl;*/

    // Задача 3.
    /* Напишите программу, генерирующую следующий вывод:
        10
        20
        19
        Используйте представление числа 10 в виде целой константы. Для вывода
        числа 20 воспользуйтесь одной из арифметических операций с присваиванием, 
        а для вывода числа 19 — операцией декремента. */
    /*const int ten = 10;
    int two = 2;
    two *= ten;
    cout << ten << endl << two << endl << --two << endl;*/

    // Задача 4.
    /* Напишите программу, выводящую на экран ваше любимое стихотворение. 
    Для разбиения на строчки используйте подходящую управляющую последовательность. */
    //cout << "Сижу за решеткой в темнице сырой.\nВскормленный в неволе орел молодой,\nМой грустный товарищ, махая крылом,\nКровавую пищу клюет под окном,\n\nКлюет, и бросает, и смотрит в окно,\nКак будто со мною задумал одно.\nЗовет меня взглядом и криком своим\nИ вымолвить хочет: «Давай улетим!\n" << endl;

    // Задача 5.
    /* Библиотечная функция islower() принимает в качестве аргумента один символ (букву) и возвращает ненулевое целое значение 
    в том случае, если буква является строчной, и нулевое, если буква является заглавной. 
    Напишите программу, которая принимает букву от пользователя, а затем выводит нулевое или ненулевое значение в зависимости от того, 
    является ли буква строчной или нет. */
    /*char bet;
    cout << "Введите 1 букву: ";
    cin >> bet;
    islower(bet) == 0 ? cout << islower(bet) << " - Вы ввели заглавную букву " << bet << endl : cout << islower(bet) << " - Вы ввели строчную букву " << bet << endl;
    */

    // Задача 6.
    /* На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк — $0.172, за немецкую марку — $0.584, 
    а за японскую йену — $0.00955. Напишите программу, которая запрашивает денежную сумму в долларах, 
    а затем выводит эквивалентные суммы в других валютах.   */
    /*float dollar = 0.0;
    cout << "Введите сумму в долларах: ";
    cin >> dollar;
    cout << dollar << "$ = " << dollar / 1.487 << " фунтов стерлингов \n" 
         << dollar << "$ = " << dollar / 0.172 << " франк \n"
         << dollar << "$ = " << dollar / 0.584 << " немецких марок \n"
         << dollar << "$ = " << dollar / 0.00955 << " йен" << endl;*/

    // Задача 7.
    /* Температуру, измеренную в градусах по Цельсию, можно перевести в градусы по Фаренгейту путем умножения на 9/5 и сложения 
    с числом 32. Напишите программу, запрашивающую температуру в градусах по Цельсию и отображающую ее эквивалент по Фаренгейту. */
    /*float ctemp;  // температура по Цельсию
    cout << "Введите температуру по Цельсию: ";
    cin >> ctemp;
    float ftemp = ctemp * (9.0 / 5.0) + 32;
    cout << "Температура no Фаренгейту равна " << ftemp << '\n';*/

    // Задача 8.
    /* Манипулятор setfill() принимает в качестве аргумента один символ, который замещает все пробелы на незаполненных позициях поля 
    с помощью манипулятора setw(). Модифицируйте пример WIDTH так, чтобы символы, разделяющие пары значений из столбцов, были не
    пробелами, а точками, например  */
    /*long pop1 = 4789426, pop2 = 274124, pop3 = 9761;
    cout << setw(9) << "Город" << setw(12) << setfill('.') << "Население" << endl
         << setw(9) << "Москва" << setw(12) << pop1 << endl
         << setw(9) << "Киров" << setw(12) << pop2 << endl
         << setw(9) << "Угрюмовка" << setiosflags(ios::left) << setw(12) << pop3 << endl;*/

    // Задача 9.
    /* Две дроби а/b и c/d можно сложить следующим образом: a/b + c/d = (a*d + b*c)/(b*d)
    Например, 1/4 + 2/3 = (1*3 + 4*2)/4*3 = 11/12 
    Напишите программу, запрашивающую у пользователя значения двух дробей, а затем выводящую результат, также записанный в форме дроби.
        Введите первую дробь: 1/2
        Введите вторую дробь: 2/5
        Сумма равна 9/10                */
    /*int dividend_1, divisor_1, dividend_2, divisor_2 = 0; 
    char fraction;
    cout << "Введите первую дробь: ";
    cin >> dividend_1 >> fraction >> divisor_1;
    cout << "Введите первую дробь: ";
    cin >> dividend_2 >> fraction >> divisor_2;
    cout << "Сумма равна " << (dividend_1 * divisor_2 + divisor_1 * dividend_2) << fraction << (divisor_1 * divisor_2) << endl;*/

    // Задача 10.
    /* Устаревшая - 1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам. Для записи использовалась система, состоящая из знака £ и 
    трех десятичных значений, разделенных точками. Например, запись £5.2.8 обозначала 5 фунтов, 2 шиллинга и 8 пенсов. 
    Современная денежная система состоит только из фунтов и пенсов, причем один фунт равен 100 пенсам. В новой денежной
    системе указанная сумма будет обозначаться как £5.13. Напишите программу, которая будет преобразовывать сумму, 
    записанную в старом формате (фунты, шиллинги, пенсы), в новый формат (фунты, пенсы). 
        Введите количество фунтов: 7
        Заедите количество шиллингов: 17
        Введите количество пенсов: 9
        Десятичных фунтов: £7.89        */
    /*int funt, shil, pens = 0; 
    cout << "Введите количество фунтов: ";
    cin >> funt;
    cout << "Введите количество шиллингов: ";
    cin >> shil;
    cout << "Введите количество пенсов: ";
    cin >> pens;
    cout << "Десятичных фунтов: " << static_cast<char>(156) << funt + (static_cast<double>(12 * shil + pens) / 240) << endl; // 240 - 12 * 20.  */

    // Задача 12.
    /* Напишите программу, выполняющую действия, обратные тем, которые описаны в упражнении 10, то есть запрашивающую у пользователя 
    сумму, указанную в десятичных фунтах, и переводящую ее в старую систему 
        Введите число десятичных фунтов: 3.51
        Эквивалентная сумма в старой форме записи: £3.10.2      */
    /*float d_funt = 0; 
    cout << "Введите число десятичных фунтов: ";
    cin >> d_funt;
    int pounds = static_cast<int>(d_funt);
    float decfrac = d_funt - pounds;  // десятичная дробная часть
    cout << "Эквивалентная сумма в старой форме записи: " << static_cast<char>(156) << pounds << '.' << decfrac * 20 << endl; */

    return 0;
}