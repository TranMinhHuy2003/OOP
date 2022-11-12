#include <iostream>
using namespace std;

class Time
{
    int gio,phut,giay;
    public:
    Time ()
    {
        gio = 0;
        phut = 0;
        giay = 0;
    }
    void Nhap ()
    {
        do
        {
            cout <<"\nNhap gio: ";
            cin >> gio;
            if (gio < 0 || gio > 24)
            {
                cout <<"\nGio khong hop le, hay nhap lai!";
            }
        } while (gio < 0 || gio > 24);
        do
        {
            cout <<"\nNhap phut: ";
            cin >> phut;
            if (phut < 0 || phut > 60)
            {
                cout <<"\nPhut khong hop le, hay nhap lai!";
            }
        } while (phut < 0 || phut > 60);
        do
        {
            cout <<"\nNhap giay: ";
            cin >> giay;
            if (giay < 0 || giay > 60)
            {
                cout <<"\nGiay khong hop le, hay nhap lai!";
            }
        } while (giay < 0 || giay > 60);
    }
    void Xuat ()
    {
        cout <<endl<<gio<<"h"<<phut<<"p"<<giay<<"s";
    }
    Time ChuanHoa ()
    {
        int x = gio * 3600 + phut * 60 + giay;
        Time a;
        a.gio = x / 3600;
        int y = x - a.gio * 3600;
        a.phut = y / 60;
        a.giay = y - a.phut * 60;
        return a;
    }
    Time (int x)
    {
        gio = 0;
        phut = 0;
        giay = x;
    }
    friend Time operator+ (Time a, Time b)
    {
        Time kq;
        kq.gio = a.gio + b.gio;
        kq.phut = a.phut + b.phut;
        kq.giay = a.giay + b.giay;
        kq = kq.ChuanHoa();
        return kq;
    }
    friend Time operator- (Time a, Time b)
    {
        Time kq;
        kq.gio = a.gio - b.gio;
        kq.phut = a.phut - b.phut;
        kq.giay = a.giay - b.giay;
        kq = kq.ChuanHoa();
        return kq;
    }
};

int main ()
{
    Time a,b;
    a.Nhap();
    b.Nhap();
    Time kq = a + b ;
    kq.Xuat();
    system ("pause");
    system ("cls");
    return 0;
}