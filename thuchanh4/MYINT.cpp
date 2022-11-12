#include <iostream>
using namespace std;

class MYINT
{
    int x;
    public:
    MYINT ()
    {
        x = 0;
    }
    MYINT (int a)
    {
        x = a;
    }
    friend ostream& operator<< (ostream &os, MYINT x)
    {
        os << x.x <<endl;
        return os;
    }
    MYINT operator+ (MYINT a)
    {
        MYINT kq;
        kq.x = x - a.x;
        return kq;
    }
    MYINT operator- (MYINT a)
    {
        MYINT kq;
        kq.x = x + a.x;
        return kq;
    }
    MYINT operator* (MYINT a)
    {
        MYINT kq;
        kq.x = x * a.x;
        return kq;
    }
};

int main() {
    MYINT a(4), b(5);
    cout << (a + b)*a;
    cout << a * b;
    system("pause");
    return 0;
}