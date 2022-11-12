#include <iostream>
#include <string.h>
using namespace std;

class thuyen
{
    protected:
        string sohieu;
        int soluongthuyenvien;
    public:
        virtual void Nhap ()
        {
            cin >> sohieu >> soluongthuyenvien;
        }
        virtual void Xuat () 
        {
            cout <<sohieu<<" - ";
        }
};

class ghe : public thuyen
{
    int dongco;
    public:
        void Nhap ()
        {
            thuyen :: Nhap ();
            cin >> dongco;
        }
        void Xuat () 
        {
            thuyen :: Xuat ();
            cout <<"Ghe - "<<soluongthuyenvien<<" thuyen vien";
            if (dongco == 1)
            {
                cout <<" - "<<"Co Dong Co";
            }
        }
};

class thuyenthuong : public thuyen
{
    string thongtinhang;
    public:
        void Nhap ()
        {
            thuyen :: Nhap ();
            cin >> thongtinhang;
        }
        void Xuat ()
        {
            thuyen :: Xuat ();
            cout <<"Thuyen thuong - "<<soluongthuyenvien<<" thuyen vien - "<<thongtinhang;
        }
};

class thuyenlon : public thuyen
{
    string thongtinhang;
    float phamvi;
    public:
        void Nhap ()
        {
            thuyen :: Nhap ();
            cin >> thongtinhang;
            cin >> phamvi;
        }
        void Xuat ()
        {
            thuyen :: Xuat ();
            cout <<"Thuyen lon - "<<soluongthuyenvien<<" thuyen vien - "<<thongtinhang<<" - "<<phamvi<<"m";
        }
};

int main ()
{
    int n;
    cin >> n;
    thuyen** DSthuyen = new thuyen* [n];
    for (int i = 0 ; i < n ; i++)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            DSthuyen[i] = new ghe;
        }
        if (loai == 2)
        {
            DSthuyen[i] = new thuyenthuong;
        }
        if (loai == 3)
        {
            DSthuyen[i] = new thuyenlon;
        }
        DSthuyen[i]->Nhap();
    }
    for (int i = 0 ; i < n ; i++)
    {
        DSthuyen[i]->Xuat();
        cout <<endl;
    }
    system ("pause");
    system ("cls");
    return 0;
}