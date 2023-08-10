// cardenum.cpp
// карточная игра с использованием перечислений
#include <iostream>
using namespace std;

enum direction { north, south, east, west };

const int jack = 11;    // именованные достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;
enum Suit { clubs = 1, diamonds, hearts, spades };
//////////////////////////////////////////////////////////
struct card
{
    int number; // достоинство карты
    Suit suit;  // масть
};
//////////////////////////////////////////////////////////
int main()
{
    card temp, chosen, prize;       // определение карт
    int position;
    card card1 = { 7, clubs };      // инициализация card1
    cout << "Карта 1: 7 треф\n";
    card card2 = { jack, hearts };  // инициализация card2
    cout << "Карта 2: валет червей\n";
    card card3 = { ace, spades };   // инициализация card3
    cout << "Карта 3: туз пик\n";
    prize = card3;                  // запоминаем карту 3
    cout << "Меняем местами карту 1 и карту 3\n";
    temp = card3; card3 = card1; card1 = temp;
    cout << "Меняем местами карту 2 и карту 3\n";
    temp = card3; card3 = card2; card2 = temp;
    cout << "Меняем местами карту 1 и карту 2\n";
    temp = card2; card2 = card1; card1 = temp;
    cout << "На какой позиции (1, 2 или 3) теперь туз пик? ";
    cin >> position;
    switch(position)
    {
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
        cout << "Неверно. Вы проиграли.\n ";

    direction dir = south;
    cout << dir; // only 1
    return 0;
}