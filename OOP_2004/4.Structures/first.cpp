#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////
// parts.cpp
// структура для хранения информации о деталях изделий
struct part     // объявление структуры
{
    int modelnumber;    // номер модели изделия
    int partnumber;     // номер детали
    float cost;         // стоимость детали
};
//////////////////////////////////////////////////////////
struct Distance     // длина в английской системе
{
    int feet;
    float inches;
};
/////////////////////////////////////////////////////////
struct Room     // размеры прямоугольной комнаты
{
    // Вложенная структура
    Distance length;    // длина
    Distance width;     // ширина
};
/////////////////////////////////////////////////////////
// Пример карточной игры
struct card
{
    int number;
    int suit;
};
const int clubs = 0;    // масти
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
const int jack = 11;    // достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////

int main()
{
    part part1;     // определение структурной переменной
    part1.modelnumber = 6244;   // инициализация полей
    part1.partnumber = 373;     // переменной part1
    part1.cost = 217.55F;       // вывод значений полей на экран
    cout << "Модель1 " << part1.modelnumber;
    cout << ", деталь1 " << part1.partnumber;
    cout << ", стоимость1 $" << part1.cost << endl;

    // -------------------------------------------------

    part part2 = { 6244, 373, 217.55F };
    part part3;     // объявление переменной
    cout << "Модель2 " << part2.modelnumber;
    cout << ", деталь2 " << part2.partnumber;
    cout << ", стоимость2 $" << part2.cost << endl;
    part3 = part2;  // присваивание структурных переменных148
    cout << "Модель3 " << part3. modelnumber;
    cout << ", деталь3 " << part3.partnumber;
    cout << ", стоимость3 $" << part3.cost << endl;

    // -------------------------------------------------

    Distance d1, d3;            // определения двух переменных
    Distance d2 = { 11, 6.25 }; // определение с инициализацией
    cout << "\nВведите число футов: "; cin >> d1.feet;  // ввод полей переменной d1
    cout << "Введите число дюймов: "; cin >> d1.inches;
    d3.inches = d1.inches + d2.inches; // сложение дюймов d1 и d2 и присвоение результата d3
    d3.feet = 0;                // с возможным заемом
    if(d3.inches >= 12.0) {     // если сумма больше 12.0,
        d3.inches -= 12.0;      // то уменьшаем число дюймов на 12.0
        d3.feet++;              // увеличиваем число футов на 1
    }
    d3.feet += d1.feet + d2.feet;   // сложение футов
    cout << d1.feet << "\'-" << d1.inches << "\" + ";
    cout << d2.feet << "\'-" << d2.inches << "\" = ";
    cout << d3.feet << "\'-" << d3.inches << "\"\n";

    // -------------------------------------------------

    Room dining;                // переменная dining типа Room
    dining.length.feet = 13;    // задание параметров комнаты
    dining.length.inches = 6.5;
    dining.width.feet = 10;
    dining.width.inches = 0.0;
    Room dining = { {13, 6.5}, {10, 0.0} }; // инициализация вложенной структуры
    float l = dining.length.feet + dining.length.inches / 12; // преобразование длины и ширины в вещественный формат
    float w = dining.width.feet + dining.width.inches / 12;
    cout << "Площадь комнаты равна " << l * w << " квадратных футов\n";

    // -------------------------------------------------

    card temp, chosen, prize;       // три карты
    int position;
    card card1 = { 7, clubs };      // инициализация карты 1
    cout << "Карта 1: 7 треф\n";
    card card2 = { jack, hearts };  // инициализация карты 2
    cout << "карта 2: валет червей\n";
    card card3 = { ace, spades };   // инициализация карты 3
    cout << "Карта 3: туз пик\n ";
    prize = card3;  // запоминание карты 3
    cout << "Меняем местами карту 1 и карту 3...\n";
    temp = card3; card3 = card1; card1 = temp;
    cout << "Меняем местами карту 2 и карту 3...\n";
    temp = card3; card3 = card2; card2 = temp;
    cout << "Меняем местами карту 1 и карту 2...\n";
    temp = card2; card2 = card1; card1 = temp;
    cout << "На какой позиции (1, 2 или 3) теперь туз пик? ";
    cin >> position;
    switch(position) {
        case 1: 
            chosen = card1; break;
        case 2: 
            chosen = card2; break;
        case 3: 
            chosen = card3; break;
    }
    if(chosen.number == prize.number && chosen.suit == prize.suit)
        cout << "Правильно! Вы выиграли!\n";
    else
        cout << "Неверно. Вы проиграли.\n";

    return 0;
}