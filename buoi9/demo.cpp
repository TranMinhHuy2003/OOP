#include <iostream>
using namespace std;

class PhanSo
{
    int tu, mau;
    public:
        PhanSo ()
        {
            tu = 0;
            mau = 1;
        }
        PhanSo (int x, int y)
        {
            tu = x;
            mau = y;
        }
        friend PhanSo operator+ (PhanSo x, PhanSo y)
        {
            PhanSo kq;
            kq.tu = x.tu*y.mau + x.mau*y.tu;
            kq.mau = x.mau*y.mau;
            return kq;
        }
        /*PhanSo (int x)
        {
            tu = x;
            mau = 1;
        }*/
        void Xuat ()
        {
            cout <<tu<<"/"<<mau;
        }
};

float PhanSo::operator float ()
{
    return (float) tu / mau;
}

int main ()
{
    PhanSo a(2,3);
    PhanSo b(1,2);
    float kq = 3 + 5 + a;
    cout <<kq;
}