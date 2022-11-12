#include <iostream>
using namespace std;

class sophuc
{
    float a,b;
    public:
        sophuc ()
        {
            a = b = 0;
        }
        sophuc (float x, float y)
        {
            a = x;
            b = y;
        }
        friend istream& operator>> (istream &is, sophuc &x)
        {
            is >> x.a >>x.b;
            return is;
        }
        friend ostream& operator << (ostream &os, sophuc x)
        {
            os <<x.a;
            if (x.b > 0) os <<" + "<<x.b<<"i";
            else if (x.b < 0) os <<x.b<<"i";
            return os;
        }
        sophuc (float x)
        {
            a = x;
            b = 0;
        }
        friend sophuc operator+ (sophuc a,sophuc b)
        {
            sophuc tong;
            tong.a = a.a + b.a;
            tong.b = a.b + b.b;
            return tong;
        }
        sophuc& operator++ ()
        {
            *this = *this + 1;
            return *this;
        }
};

int main ()
{
    sophuc a(1,2);
    sophuc b;
    sophuc c(5);
    cin >>b;
    cout <<a+b<<endl;
    cout <<2+a+c<<endl;
    cout <<++a;
    return 0;
}