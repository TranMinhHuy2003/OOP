#include <iostream>
using namespace std;

class Quaternion
{
    int a,b,c,d;
    public:
        friend istream& operator>> (istream &is, Quaternion &x)
        {
            is >> x.a >> x.b >> x.c >> x.d;
            return is;
        }
        friend ostream& operator<< (ostream &os, Quaternion x)
        {
            os << "(" << x.a << "," << x.b << "," << x.c << "," << x.d << ")";
            return os;
        }
        Quaternion operator+ (Quaternion x)
        {
            Quaternion kq;
            kq.a = a + x.a;
            kq.b = b + x.b;
            kq.c = c + x.c;
            kq.d = d + x.d;
            return kq;
        }
        Quaternion operator- (Quaternion x)
        {
            Quaternion kq;
            kq.a = a - x.a;
            kq.b = b - x.b;
            kq.c = c - x.c;
            kq.d = d - x.d;
            return kq;
        }
};

int main() {
    Quaternion a, b;
    cin >> a >> b;
    cout << a + b;
    cout << endl;
    cout << a - b;
    system("pause");
    return 0;
}