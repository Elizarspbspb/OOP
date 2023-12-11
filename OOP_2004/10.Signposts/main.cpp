// Глава 10. Указатели
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    int var1 = 11;
    int var2 = 22;
    int var3 = 33;      // напечатаем адреса этих переменных
    cout << &var1 << endl << &var2 << endl << &var3 << endl;

    //////////////////////////////////////////////////////////////

    int* ptr;           // это переменная-указатель на целое
    ptr = &var1;        // присвоим ей значение адреса var1
    cout << ptr << endl;    // покажем адрес
    cout << *ptr << endl;   // показываем содержимое переменной через указатель
    ptr = &var2;        // присвоим ей значение адреса var2
    cout << ptr << endl;    // покажем адрес
    cout << *ptr << endl;   // показываем содержимое переменной через указатель

    ptr = &var1;            // пусть ptr указывает на var1
    *ptr = 37;              // то же самое, что var1 = 37;
    var2 = *ptr;            // то же самое, что var2 = var1;
    cout << var1 << " - " << var2 << endl;   // убедимся, что var1 и var2 равно 37

    //////////////////////////////////////////////////////////////

    return 0;
}