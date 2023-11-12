#include <iostream>
#include <iomanip>      // setw
#include <cstring>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////
class part
{
private:
    char partname[30];  // название
    int partnumber;     // номер
    double cost;        // цена
public:
    void setpart(const char pname[], int pn, double c) {
        strcpy(partname, pname);
        partnumber = pn;
        cost = c;
    }
    void showpart() {
        cout << "\nНазвание = " << partname;
        cout << ", номер = " << partnumber;
        cout << ", цена = $" << cost;
    }
};

///////////////////////////////////////////////////////////

class String {
private:
    enum { SZ = 80 };   // максимальный размер строки
    char str[SZ];       // сама строка
public: 
    String() { str[0] = '\0'; }                 // конструктор без параметров
    String(const char s[]) { strcpy(str, s); }  // конструктор с одним параметром
    void display() const { cout << str; }       // показ строки
    void concat(String s2) {                    // сложение строк
        if(strlen(str) + strlen(s2.str) < SZ)
            strcat(str, s2.str);                // библиотечная функция сложение строк
        else
            cout << "\nПереполнение!";
    }
};

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    const int MAX = 80;             // максимальный размер строки
    char str[MAX];                  // сама строка
    cout << "Введите строку: ";     // ввод строки
    cin >> str;
    cout << "Вы ввели: " << str << endl;// показ результата
    
    //////////////////////////////////////////////////////////////

    const int MAXSETW = 6;              // максимальный размер строки
    char strSet[MAXSETW];               // сама строка
    cout << "\nВведите строку: ";
    cin >> setw(MAXSETW) >> strSet;     // ввод не более чем MAX символов
    cout << "Вы ввели: " << strSet << endl;

    //////////////////////////////////////////////////////////////

    char strConstStr[] = "Я памятник себе воздвиг нерукотворный.";
    cout << strConstStr << endl;
    //char strConstSym[] = {'Я', ' ', ' п', 'а', ' м', 'я', 'т', 'н', 'и', 'к'};
    //cout << strConstSym << endl; 

    //////////////////////////////////////////////////////////////

    const int MAXSTR = 80;  // максимальная длина строки
    char strSTR[MAXSTR];    // сама строка
    cout << "\nВведите строку с пробелами: " << endl;
    cin.ignore();
    cin.get(strSTR, MAXSTR);
    cout << "Вы ввели: " << strSTR << endl;

    //////////////////////////////////////////////////////////////

    cout << "\nВведите несколько строк (завершение цикла символ $):\n";
    cin.ignore();
    cin.get(strSTR, MAXSTR, '$');
    cout << "Вы ввели:\n" << strSTR << endl;

    //////////////////////////////////////////////////////////////
    
    char strSTR2[MAXSTR]; // сама строка
    int j = 0;
    for(j = 0; j < strlen(strSTR); j++)
        strSTR2[j] = strSTR[j];  // символов из str1 в str2
    strSTR2[j] = '\0';
    cout << "-Копия строк:" << endl;
    cout << strSTR2 << endl;
    //strcpy(strSTR2, strSTR);    // Библиотечная функция копирования строки из <cstring>

    //////////////////////////////////////////////////////////////

    const int DAYS = 7;         // количество строк в массиве
    const int MAXLEN = 23;      // максимальная длина каждой из них
    // массив строк
    char star[DAYS][MAXLEN] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    // вывод всех строк на экран
    for(int j = 0; j < DAYS; j++)
        cout << star[j] << endl;

    //////////////////////////////////////////////////////////////

    part part1, part2, part3;
    part1.setpart("муфта", 4473, 217.55);
    part2.setpart("вороток", 9924, 419.25);
    cout << "\nПервая деталь: "; part1.showpart();
    cout << "\nВторая деталь: "; part2.showpart();
    cout << endl;
    part3 = part2;

    //////////////////////////////////////////////////////////////

    String s1("С Новым годом! ");       // конструктор с одним параметром
    String s2 = "С новым счастьем!";    // аналогично, но в другой форме
    String s3;                          // конструктор без параметров
    cout << "\ns1 ="; s1.display();
    cout << "\ns2 ="; s2.display();
    cout << "\ns3 ="; s3.display();     // показываем все строки
    s3 = s1;    // поместив массив в класс объекту может быть присвоено значение другого объекта
    cout << "\ns3 ="; s3.display();     // присвоение
    s3.concat(s2);  
    cout << "\ns3 ="; s3.display();
    cout << endl;

    //////////////////////////////////////////////////////////////

    string bs1("Рыба");
    string bs2 = "Мясо";
    string bs3;
    bs3 = bs1;
    cout << "bs3 >> " << bs3 << endl;
    bs3 = "Ни " + bs1 + " ни ";
    bs3 += bs2;
    cout << "bs3 >> " << bs3 << endl;
    bs1.swap(bs2);
    cout << bs1 << " не " << bs2 << endl;

    //////////////////////////////////////////////////////////////
    // ввод/вывод для класса string
    string full_name, nickname, address;
    string greeting("Здравствуйте, ");
    cout << "Введите Ваше ФИО: ";
    cin.ignore();       // очистить поток
    getline(cin.ignore(), full_name);
    cout << "Ваше ФИО: " << full_name << endl;
    cout << "Введите Ваш псевдоним: ";
    cin >> nickname;
    greeting += nickname;
    cout << greeting << endl;
    cout << "Введите Ваш адрес в несколько строк\n";
    cout << "Окончание ввода символ '$'\n";
    cin.ignore(); 
    getline(cin.ignore(), address, '$');
    cout << "Ваш адрес: " << address << endl;

    //////////////////////////////////////////////////////////////

    string spruce = "В лесу родилась елочка, в лесу она росла.";
    int number;
    number = spruce.find("елочка");
    cout << "Елочка найдена: " << number << endl;
    number = spruce.find_first_of("умка");
    cout << "Первый из умка: " << number << endl;
    number = spruce.find_first_not_of("абвгдАБВГД");
    cout << "Первый не из: " << number << endl;

    //////////////////////////////////////////////////////////////
    
    string str1("Все хорошо, прекрасная маркиза.");
    string str2("принцесса");
    string str3("Приветствую ");
    str1.erase(0, 12);                  // убираем "Все хорошо, "
    str1.replace(11, 7, str2);          // заменяем "маркиза" на "принцесса"
    str1.insert(0, str3);               // вставляем "Приветствую, "
    str1.erase(str1.size() - 1, 1);     // убираем '.'
    str1.append(3, '!');                // добавляем '!!!'
    int countSpace = str1.find(' ');       // ищем пробелы
    while(countSpace < str1.size()) {      // цикл по всем пробелам
        str1.replace(countSpace, 1, "/");  // заменяем пробел на '/'
        countSpace = str1.find(' ');       // ищем следующий пробел
    }
    cout << "str1: " << str1 << endl;

    //////////////////////////////////////////////////////////////

    string aName = "Иван";
    string userName;
    cout << "Введите Ваше имя: ";
    cin >> userName;
    if(userName == aName)
        cout << "Привет, Иван\n";
    else if(userName < aName)
        cout << "Ваше имя идет до имени Иван\n";
    else
        cout << "Ваше имя идет после имени Иван\n";
    int n = userName.compare(0, 2, aName, 0, 2);    
    // .compare - сравнивает первые две буквы слова «Иван» с первыми двумя userName
    cout << "Первые две буквы Вашего имени ";
    if(n == 0)
        cout << "совпадают ";
    else if(n < 0)
        cout << "идут до ";
    else
        cout << "идут после ";
    cout << aName.substr(0, 2) << endl;

    //////////////////////////////////////////////////////////////

    char charray[80];
    string word;
    cout << "Введите слово: ";
    cin >> word;
    int wlen = word.length();       // длина строки
    cout << "По одному символу: ";
    for(int j = 0; j < wlen; j++)
        cout << word.at(j);         // тут будет проверка на выход за пределы строки
        // cout << word[j];         // а тут проверки не будет
    word.copy(charray, wlen, 0);    // копируем строку в массив charray
    charray[wlen] = 0;
    cout << "\nМассив содержит: " << charray << endl;

    //////////////////////////////////////////////////////////////
    
    return 0;
}