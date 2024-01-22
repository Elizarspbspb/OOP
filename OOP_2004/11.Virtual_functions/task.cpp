// Глава 11. Виртуальные функции
#include <iostream>
#include <string.h>     // для функций strcpy, strcat

using namespace std;

// Task 1
class publication {
private:
    string nameBook;
    float costBook;
public:
    virtual void getdata() {
        cout << "\nВведите название книги: "; cin >> nameBook;
        cout << "Введите стоимость книги: "; cin >> costBook;
    }
    virtual void putdata() const {
        cout << "\n Книга: " << nameBook;
        cout << "\n Цена: " << costBook << endl;
    }
    // Task 5
    virtual bool isOveersize() = 0;
};
class book : public publication {
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество страниц: "; cin >> pages;
    }
    void putdata() const {
        publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
    // Task 5
    bool isOveersize() {
        if (pages > 800)
            return 1;
        return 0;
    }
};
class tape : public publication {
    float minuts;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество минут: "; cin >> minuts;
    }
    void putdata() const {
        publication::putdata();
        cout << "Количество минут: " << minuts << endl;
    }
    // Task 5
    bool isOveersize() {
        if (minuts > 90)
            return 1;
        return 0;
    }
};

///////////////////////////////////////////////////////////

// Task 2
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(float fltfeet) {                   // переводит float в Distance
        feet = static_cast<int>(fltfeet);
        inches = 12*(fltfeet - feet);           // слева — дюймы
    }
    Distance(int ft, float in) { feet = ft; inches = in; }
    void showdist() { cout << feet << "\'-" << inches << '\"'; }
    friend Distance operator*(Distance, Distance);      // дружественный   
};
Distance operator*(Distance d1, Distance d2) {  // d1 + d2
    float one = d1.feet + d1.inches/12;
    float two = d2.feet + d2.inches/12;
    float multi = one * two;
    return Distance(multi);
}

///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    /*1. Пусть имеется та же издательская компания, которая описана в упражнении 1 главы 9, которая продает и книги, и аудио версии 
    печатной продукции. Как и в том упражнении, создайте класс publication, хранящий название (фактически, строку) и цену (типа float) 
    публикации. Создайте два порожденных класса: book, в котором происходит изменение счетчика страниц (типа int), и tape, в котором 
    происходит изменение счетчика записанных на кассету минут. Каждый из классов должен иметь метод getdata(), запрашивающий информацию 
    у пользователя, и putdata() для вывода данных на экран. 
    2. Напишите main(), где создавался бы массив указателей на класс publication. Это очень похоже на то, что мы делали в текущей 
    главе на примере VIRTPERS. В цикле запрашивайте у пользователя данные о конкретной книге или кассете, используйте new для создания 
    нового объекта book или tape. Сопоставляйте указатель в массиве с объектом. Когда пользователь закончит ввод исходных данных, 
    выведите результат для всех введенных книг и кассет, используя цикл for и единственное выражение pubarr[j]->putdata(); для вывода 
    данных о каждом объекте из массива */
    /*publication* pubarr[100];       // массив указателей на публикации
    publication* books;
    int n = 0;                      // число публикаций в массиве
    char choice;                    
    do {
        cout << "\nВводить данные для книги (b) или для пленки (t)?";
        cin >> choice;
        if(choice == 'b') {
            pubarr[n] = new book;
            books = new book;
        }
        else {
            pubarr[n] = new tape;
            books = new tape;
        }
        pubarr[n++]->getdata();
        books->getdata();
        cout << "Продолжать (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    for(int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        books->putdata();
    }
    cout << endl; */

    /*3. В классе Distance, как показано в примерах FRENGL и FRISQ из этой главы, создайте перегружаемую операцию умножения *, чтобы 
    можно было умножать два расстояния. Сделайте эту функцию дружественной, тогда можно будет использовать выражение типа Wdist = 7.5*dist2. 
    Вам понадобится конструктор с одним аргументом для перевода величин из формата чисел с плавающей запятой в формат Distance. Напишите 
    какой-либо main() на свое усмотрение для того, чтобы несколькими способами проверить работу этой перегружаемой операции.*/
    /*Distance dist1(10, 2);
    Distance dist2(10, 5);
    Distance dist3;
    dist3 = dist1 * dist2;
    dist3 = 7.5*dist3;
    dist3.showdist();
    dist3 = 10.0 *dist3; */

    /*4. Как уже говорилось, классы можно заставлять вести себя как массивы. Пример показывает один из способов создания такого класса. */
    class Array {                       // моделирует обычный массив C++
    private:
        int* ptr;                       // указатель на содержимое Array
        int size;                       // размер Array
    public:
        Array(): ptr(0), size(0) { }
        Array(int s) {
            size = s;                   // аргумент - размер Array
            ptr = new int[s];           // выделить память под Array
        }
        ~Array() { cout << "\nДЕСТРУКТОР" << endl; delete[] ptr; }
        int& operator[](int j) {            // перегружаемая операция
            return *(ptr + j);              // списка индексов
        }  
        Array& operator=(Array& S) {        // присвоение       
            cout << "\nПРИРАВНИВАНИЕ" << endl; 
            size = S.size;
            ptr = new int[size];            // нужен если объект создан без аргументов Array one;
            for(int i=0; i < size; i++) {
                *(ptr + i) = *(S.ptr + i);
            }
            return *this;                   // вернуть этот объект
        }
        Array(Array& mas) {                 // конструктор копирования
            cout << "\nКОНСТРУКТОР КОПИРОВАНИЯ" << endl;
            size = mas.size;
            // ptr = mas.ptr;   // ERROR
            ptr = new int[size];
            for(int j = 0; j < size; j++) {   // копировать содержимое в
                *(ptr + j) = *(mas.ptr + j);
            } 
        }
    };
    /*int main() {
        const int ASIZE = 10;               // размер массива
        Array arr(ASIZE);                   // создать массив
        for(int j = 0; j < ASIZE; j++)      // заполнить его j^2
            arr[j] = j*j;
        for(j = 0; j < ASIZE; j++)          // вывести его содержимое
            cout << arr[j] << ' ';
        cout << endl;
        return 0;
    }
    Результат работы программы:
        0 1 4 9 16 25 36 49 64 81
    Взяв за основу приведенную программу, добавьте перегружаемое присваивание и перегружаемый конструктор копирования к классу Array. 
    Затем добавьте к main() выражение Array arr2(arr1); и arr3 = arr1; для проверки того, что перегружаемые операции работают. 
    Конструктор копирования должен создать новый объект Array со своим собственным местом в памяти, выделенным для хранения элементов 
    массива. И конструктор копирования, и оператор присваивания должны копировать содержимое старого объекта класса Array в новый. 
    Что будет, если вы присвоите объект Array одного размера объекту Array другого размера? */
    /*const int ASIZE = 10;                   // размер массива
    Array arr(ASIZE);                       // создать массив
    for(int j = 0; j < ASIZE; j++)          // заполнить его j^2
        arr[j] = j*j;
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arr[j] << ' ';
    cout << endl << "Второй массив после приравнивания:" << endl;
    //Array arrTwo(ASIZE); 
    Array arrTwo; 
    arrTwo = arr;                           // присваивание
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arrTwo[j] << ' ';
    cout << endl;
    cout << endl << "Третий массив после копирования:" << endl;
    Array arrOne(arrTwo);                   // копирование
    for(int j = 0; j < ASIZE; j++)          // вывести его содержимое
        cout << arrOne[j] << ' ';
    cout << endl; */

    /*5. Взяв за основу программу из упражнения 1 этой главы, добавьте метод типа bool, называющийся isOveersize(), к классам book и tape. 
    Допустим, книга, в которой больше 800 страниц, или кассета со временем проигрывания более 90 минут, будут считаться объектами с превышением 
    размера. К этой функции можно обращаться из main(), а результат ее работы выводить в виде строки «Превышение размера!» для соответствующих 
    книг и кассет. Допустим, объекты классов book и tape должны быть доступны через указатели на них, хранящиеся в массиве типа publication. 
    Что в этом случае вам нужно добавить в базовый класс publication? Вы можете привести примеры компонентов этого базового класса? */
    /*publication* pubarr[100];       // массив указателей на публикации
    int n = 0;                      // число публикаций в массиве
    char choice;                    
    do {
        cout << "\nВводить данные для книги (b) или для пленки (t)?";
        cin >> choice;
        if(choice == 'b')
            pubarr[n] = new book;
        else
            pubarr[n] = new tape;
        pubarr[n++]->getdata();
        cout << "Продолжать (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    for(int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        if (pubarr[j]->isOveersize() == 1)
            cout << "«Превышение размера!»" << endl;
    } */

    /*6. Возьмите за основу программу из упражнения 8 главы 8, где было перегружено пять арифметических операций для работы с денежным 
    форматом. Добавьте два оператора, которые не были перегружены в том упражнении:
        long double * bMoney // умножать число на деньги
        long double / bMoney // делить число на деньги
    Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева — обычное число. Убедитесь,
    что main() позволяет пользователю ввести две денежные строки и число с плавающей запятой, а затем корректно выполняет все семь 
    арифметических действий с соответствующими нарами значений. */


    return 0;
}