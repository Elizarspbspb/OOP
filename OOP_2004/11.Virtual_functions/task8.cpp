#include <iostream>
#include <string.h>
#include <stdlib.h>    
#include <iomanip> 
#include <sstream>

using namespace std;

class Token {           // Абстрактный базовый класс
public:
    virtual float getNumber() = 0;       // чистая виртуальная функция
    virtual char getOperator() = 0;
};
class Operator : public Token {
private:
    char oper;                  // Операторы +, -, *, /
public:
    Operator(char s) : oper(s) {}   // конструктор устанавливает значение
    char getOperator() override {            // получить значение
        return oper;
    }             
    float getNumber() override {             // просто некая функция
        return 0.0;
    }              
};
class Number : public Token {
private:
    float fnum;                 // число
public:
    Number(float f) : fnum(f) {}    // конструктор устанавливает значение
    float getNumber() override {             // получить значение
        return fnum;
    }              
    char getOperator() override {            // просто некая функция
        return '=';
    }             
};
// Калькулятор
const int LEN = 80;         // максимальная длина выражения
const int MAXCALC = 40;
class Stack {
private:
    Token* multi[LEN];                          // Указатель на базовый класс
    int top;                                    // количество сохраненных данных
public:
    Stack() { top = 0; }
    void push(Token *var) { multi[++top] = var; }           // поместить в стек
    Token* pop() { return multi[top--]; }                   // взять из стека 
    int gettop() { return top; }                            // узнать количество элементов
};
class express {
private:
    Stack s;        // стек данных
    char* pStr;     // строка для ввода
    int len;        // длина строки
public:
    express(char* ptr) {
        pStr = ptr;             // запоминаем указатель на строку
        len = strlen(pStr);     // устанавливаем длину
    }
    void parse();               // разбор выражения
    double solve();                // получение результата
};
void express::parse() { // добавляем данные в стек
    char ch;            // символ из строки
    double lastval;       // последнее значение
    char lastop;        // последний оператор
    double newnum = 0;
    double drob = 0;
    bool flag = 0;
    for(int j = 0; j < len; j++) {  // для всех символов в строке
        ch = pStr[j];   // получаем символ
        if(ch >= '0' && ch <= '9') {  // если это цифра,
            newnum = atof(pStr+j);                //Преобразование строки в число типа double
            Number nuh(newnum);
            s.push(&nuh); 
            std::ostringstream oss;
            oss << newnum;
            string snew = oss.str();
            j += snew.size() - 1;
            std::cout << "! = " << newnum << " = " << snew << "; " << j << std::endl;
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if(s.gettop() == 1) {           // если это первый оператор,
                Operator oper(ch);
                s.push(&oper);               // помещаем его в стек
            } else {
                lastval = s.pop()->getNumber();      // получаем предыдущее число
                lastop = s.pop()->getOperator();       // получаем предыдущий оператор
                if((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-')) {  // если это * или /, а предыдущий был + или -, то
                    Operator oper(lastop);
                    Number nuh(lastval);
                    s.push(&oper);         // отменяем последние два взятия из стека
                    s.push(&nuh);
                }
                else {      // помещаем в стек результат операции
                    switch(lastop) {
                        case '+': {
                            double one = s.pop()->getNumber() + lastval; 
                            Number nuh(one); s.push(&nuh); 
                            break;
                        }
                        case '-': { Number nuh1(s.pop()->getNumber() - lastval); s.push(&nuh1); break; }
                        case '*': { Number nuh2(s.pop()->getNumber() * lastval); s.push(&nuh2); break; }
                        case '/': { Number nuh3(s.pop()->getNumber() / lastval); s.push(&nuh3); break; }
                        default: { cout << "\nНеизвестный оператор"; exit(1); }
                    }
                }
                Operator oper(ch);
                s.push(&oper);     // помещаем в стек текущий оператор
            }
        }
    }
    std::cout << "-- " << s.gettop() << endl;
    while(s.gettop() > 1) {
        lastval = s.pop()->getNumber();          // получаем предыдущее значение
        cout << "lastval = " << lastval << endl;
        switch(s.pop()->getOperator()) {           // получаем предыдущий оператор
            case '+': { Number nuh(s.pop()->getNumber() + lastval); s.push(&nuh); break; }
            case '-': { Number nuh(s.pop()->getNumber() - lastval); s.push(&nuh); break; }
            case '*': { Number nuh(s.pop()->getNumber() * lastval); s.push(&nuh); break; }
            case '/': { Number nuh(s.pop()->getNumber() / lastval); s.push(&nuh); break; }
            default: { cout << "\nНеизвестный оператор"; exit(1); }
        }
    }
    std::cout << "result = " << s.pop()->getNumber() << endl;
}
double express::solve() {      // убираем данные из стека
    double lastval;           // предыдущее значение
    while(s.gettop() > 1) {
        lastval = s.pop()->getNumber();          // получаем предыдущее значение
        cout << "lastval = " << lastval << endl;
        switch(s.pop()->getOperator()) {           // получаем предыдущий оператор
            case '+': { Number nuh(s.pop()->getNumber() + lastval); s.push(&nuh); break; }
            case '-': { Number nuh(s.pop()->getNumber() - lastval); s.push(&nuh); break; }
            case '*': { Number nuh(s.pop()->getNumber() * lastval); s.push(&nuh); break; }
            case '/': { Number nuh(s.pop()->getNumber() / lastval); s.push(&nuh); break; }
            default: { cout << "\nНеизвестный оператор"; exit(1); }
        }
        
    }
    return double(s.pop()->getNumber()); // последний оператор в стеке - это результат
}

///////////////////////////////////////////////////////////

int main(int argc, char* argv[]) 
{
    char ans;           // 'д' или 'н'
    char string[LEN];   // строка для разбора
    cout << "\nВведите арифметическое выражение в виде 2+3*4/3-2"
            "\nЧисла должны быть из одной цифры"
            "\nНе используйте пробелы и скобки";
    do {
        cout << "\nВыражение: ";
        cin >> string;                              // вводим строку
        express* eptr = new express(string);        // создаем объект для разбора
        eptr->parse();                              // разбираем
        cout << "\nРезультат: " << eptr->solve() << endl;   // решаем
        delete eptr;                                // удаляем объект
        cout << "Еще одно выражение (y/n)? ";
        cin >> ans;
    } while(ans == 'y');

    return 0;
}