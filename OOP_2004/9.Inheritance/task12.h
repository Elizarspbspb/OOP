#include <iostream>

using namespace std;

// Task 7
class fraction {
protected:
    int dividend;
    int divisor;
    char symb;
public:
    fraction() { dividend = 0; divisor = 0; symb = '/'; }
    fraction(int divid, int divis) : dividend(divid), divisor(divis) {};
    void enterFr() {
        cin >> dividend >> symb >> divisor;
    }
    void showFr() const {
        cout << dividend << "/" << divisor;
    }
    void lowterms();
    // Task 7
    fraction operator+(fraction);
    fraction operator-(fraction);
    fraction operator*(fraction);
    fraction operator/(fraction);
};
void fraction::lowterms() {         // сокращение дроби
    long tnum, tden, temp, gcd;
    tnum = labs(dividend);          // используем неотрицательные значения (нужен cmath)
    tden = labs(divisor);
    if(tden == 0)               // проверка знаменателя на 0
        { cout << "Недопустимый знаменатель!"; exit(1); }
    else if(tnum == 0)      // проверка числителя на 0
        { dividend = 0; divisor = 1; return; }
    while(tnum != 0) {      // нахождение наибольшего общего делителя
        if(tnum < tden)     // если числитель больше знаменателя,
            { temp = tnum; tnum = tden; tden = temp; }      // меняем их местами
        tnum = tnum - tden;     // вычитание
    }
    gcd = tden;
    dividend = dividend / gcd; // делим числитель и знаменатель на полученный наибольший общий делитель
    divisor = divisor / gcd;
}
fraction fraction::operator+(fraction second) {
    int dividend2 = dividend * second.divisor + divisor * second.dividend;
    int divisor2 = divisor * second.divisor;
    return fraction(dividend2, divisor2);         
}
fraction fraction::operator-(fraction second) {        
    int dividend2 = dividend * second.divisor - divisor * second.dividend;
    int divisor2 = divisor * second.divisor; 
    return fraction(dividend2, divisor2);               
}
fraction fraction::operator*(fraction second) {
    int dividend2 = dividend * second.dividend;
    int divisor2 = divisor * second.divisor; 
    return fraction(dividend2, divisor2);               
}
fraction fraction::operator/(fraction second) {
    int dividend2 = dividend * second.divisor;
    int divisor2 = divisor * second.dividend;
    return fraction(dividend2, divisor2);               
}

// Task 11
class sterling {
protected:
    long pounds;
    int shillings, pence;
    double newMoney;
public:
    sterling() = default;
    sterling(double newMon) : newMoney(newMon) {}
    sterling(long po, int sh, int pe) : pounds(po), shillings(sh), pence(pe) {}
    long getNewMoney(long, int, int);
    sterling getAldMoney(double);
    void getSterling();
    void putSterling() const;
    sterling operator+(sterling);
    sterling operator-(sterling);
    sterling operator*(double);
    sterling operator/(sterling);
    sterling operator/(double);
    operator double() const {  
        return pounds + (static_cast<double>(12 * shillings + pence) / 240);    // 240 - 12 * 20.  
    }
};
long sterling::getNewMoney(long pounds, int shillings, int pence) {
    return pounds + (static_cast<double>(12 * shillings + pence) / 240);    // 240 - 12 * 20.  
}
/*sterling sterling::operator+(sterling s2) {
            return sterling(double(sterling(pounds, shillings, pense)) + double(s2));
}*/
sterling sterling::getAldMoney(double newMoney) {
    long poundsNew = static_cast<int>(newMoney);
    double decfrac = newMoney - poundsNew;  // десятичная дробная часть
    decfrac *= 240;
    int shil, pens;
    shil = static_cast<int>(decfrac) / 12;
    pens = static_cast<int>(decfrac) % 12;
    // Task 12
    pounds = poundsNew;
    shillings = shil;
    pence = pens;
    return sterling(pounds, shil, pens);
}
sterling sterling::operator+(sterling one) {
    sterling sumMoney;
    sumMoney.pence = pence + one.pence;
    if (sumMoney.pence > 11) {
        while (sumMoney.pence >= 12) {
            sumMoney.pence -= 12;
            one.shillings++;
        }
    }
    sumMoney.shillings = shillings + one.shillings;
    if (sumMoney.shillings > 19) {
        while (sumMoney.shillings >= 20) {
            sumMoney.shillings -= 20;
            one.pounds++;
        }
    }
    sumMoney.pounds = pounds + one.pounds;
    return sumMoney;
}
sterling sterling::operator-(sterling one) {
    sterling difMoney;
    difMoney.pence = pence;
    difMoney.shillings = shillings;
    difMoney.pounds = pounds;
    if (one.pence > difMoney.pence) {
        while (difMoney.pence <= one.pence) {
            difMoney.pence += 12;
            --difMoney.shillings;
        }
    }
    difMoney.pence -= one.pence;
    if (one.shillings > difMoney.shillings) {
        while (difMoney.shillings <= one.shillings) {
            difMoney.shillings += 20;
            --difMoney.pounds;
        }
    }
    difMoney.shillings -= one.shillings;
    difMoney.pounds -= one.pounds;
    return difMoney;
}
sterling sterling::operator*(double one) {
    double um = getNewMoney(pounds, shillings, pence);
    um *= one;
    return getAldMoney(um);
}
sterling sterling::operator/(sterling one) {
    double del1 = getNewMoney(pounds, shillings, pence);
    double del2 = getNewMoney(one.pounds, one.shillings, one.pence);
    del1 /= del2;
    return getAldMoney(del1);
}
sterling sterling::operator/(double one) {
    double um = getNewMoney(pounds, shillings, pence);
    um /= one;
    return getAldMoney(um);
}
void sterling::getSterling() {
    cout << "Введите количество фунтов: ";
    cin >> pounds;
    cout << "Введите количество шиллингов: ";
    cin >> shillings;
    cout << "Введите количество пенсов: ";
    cin >> pence;
}
void sterling::putSterling() const {
    cout << " £" << pounds << " " << shillings << " " << pence;
}