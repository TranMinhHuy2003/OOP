#include <iostream>
using namespace std;

class PhanSo
{
    private:
        int numerator, denominator;
    public:
        void getInput();
        void putOutput();
        void reducePhanSo();
        PhanSo sumPhanSo(PhanSo x);
        PhanSo diffPhanSo(PhanSo x);
        PhanSo mulPhanSo(PhanSo x);
        PhanSo divPhanSo(PhanSo x);
        void swapMinusPhanSo();
};


int main(void)
{
    PhanSo a, b;
    PhanSo temp;
    a.getInput();
    b.getInput();
    temp = a.sumPhanSo(b);
    temp.putOutput();
    temp = a.diffPhanSo(b);
    temp.putOutput();
    temp = a.mulPhanSo(b);
    temp.putOutput();
    temp = a.divPhanSo(b);
    temp.putOutput();
    
    
    return 0;
}

void PhanSo::getInput()
{
    cin>>numerator;
    do{
        cin>>denominator;
    }while(denominator == 0);
}

void PhanSo::putOutput()
{
    cout<<numerator<<"/"<<denominator<<endl;
}

void PhanSo::reducePhanSo()
{
    int temp;
    PhanSo other;
    other.numerator = numerator;
    other.denominator = denominator;
    while(other.denominator != 0)
    {
        temp = other.numerator % other.denominator;
        other.numerator = other.denominator;
        other.denominator = temp;
    }
    temp = other.numerator;
    numerator = numerator / temp;
    denominator = denominator / temp;
}

PhanSo PhanSo::sumPhanSo(PhanSo x)
{
    PhanSo temp;    
    temp.numerator = numerator * x.denominator + denominator * x.numerator;
    temp.denominator = denominator * x.denominator;
    temp.reducePhanSo();
    temp.swapMinusPhanSo();
    return temp;
}

PhanSo PhanSo::diffPhanSo(PhanSo x)
{
    PhanSo temp;
    temp.numerator = numerator * x.denominator - denominator * x.numerator;
    temp.denominator = denominator * x.denominator;
    temp.reducePhanSo();
    temp.swapMinusPhanSo();
    return temp;
}

PhanSo PhanSo::mulPhanSo(PhanSo x)
{
    PhanSo temp;
    temp.numerator = numerator * x.numerator;
    temp.denominator = denominator * x.denominator;
    temp.reducePhanSo();
    temp.swapMinusPhanSo();
    return temp;
}

PhanSo PhanSo::divPhanSo(PhanSo x)
{
    PhanSo temp;
    temp.numerator = numerator * x.denominator;
    temp.denominator = denominator * x.numerator;
    temp.reducePhanSo();
    temp.swapMinusPhanSo();
    return temp;
}

void PhanSo::swapMinusPhanSo()
{
    if(denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}