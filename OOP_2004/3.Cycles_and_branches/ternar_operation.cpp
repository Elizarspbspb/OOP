// печать символа 'x' каждые 8 позиций с применением условной тернарной операции
#include <iostream>
using namespace std;
int main()
{
    for(int j = 0; j < 80; j++) // для каждой позиции
    {   
        char ch = (j % 8) ? ' ' : 'x'; // значение ch равно 'x', если номер позиции кратен 8, // в противном случае ch содержит пробел
        cout << ch;
    }
    return 0;
}