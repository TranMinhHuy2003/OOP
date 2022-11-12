#include <iostream>
#define pi 3.14
using namespace std;

class chunhat
{
    protected:
        int canh1, canh2;
    public:
        chunhat ()
        {
            canh1 = canh2 = 0;
        }
        chunhat (int a, int b)
        {
            canh1 = a;
            canh2 = b;
        }
        void Nhap ()
        {
            cin >> canh1 >> canh2;
        }
        void Xuat ()
        {
            cout <<"\nCanh 1: "<<canh1;
            cout <<"\nCanh 2: "<<canh2;
        }
        int TinhChuVi ()
        {
            return canh1 + canh2;
        }
};

class tamgiac : public chunhat
{
    int canh3;
    public:
        tamgiac ()
        {
            canh3 = 0;
        }
        tamgiac (int a, int b, int c) : chunhat (a,b)
        {
            canh3 = c;
        }
        void Nhap ()
        {
            chunhat :: Nhap ();
            cin >>canh3;
        }
        void Xuat ()
        {
            chunhat :: Xuat ();
            cout <<"\nCanh 3: "<<canh3;
        }
        int TinhChuVi ()
        {
            return chunhat :: TinhChuVi() + canh3;
        }
        int SoSanh (int x)
        {
            if (TinhChuVi() > x)
            {
                return 1;
            } 
            else if (TinhChuVi() < x)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class Diem 
{
    protected:
        int x;
        int y;
    public:
        Diem ()
        {
            x = y = 0;
        }
        Diem (int a, int b)
        {
            x = a;
            y = b;
        }
        void Nhap ()
        {
            cin >> x >> y;
        }
        void Xuat ()
        {
            cout <<"\nDiem: ("<<x<<","<<y<<")";
        }
};

class hinhtron : public Diem
{
    float r;
    public:
        hinhtron ()
        {
            r = 0;
        }
        hinhtron (int a, int b, int c) : Diem (a,b)
        {
            r = c;
        }
        void Nhap ()
        {
            Diem :: Nhap ();
            cin >>r;
        }
        void Xuat ()
        {
            Diem :: Xuat ();
            cout <<"\nBan kinh: "<<r;
        }
        float TinhChuVi ()
        {
            return 2 * pi * r;
        }
};

int main ()
{
    chunhat a;
    a.Nhap ();
    tamgiac b(1,2,3);
    tamgiac c;
    c.Nhap ();
    cout <<b.SoSanh (c.TinhChuVi());
    system ("pause");
    system ("cls");
    return 0;
}