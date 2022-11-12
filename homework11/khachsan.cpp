#include <iostream>
using namespace std;

class phong 
{
    protected:
        int loaiphong;
        int sodem;
    public:
        phong ()
        {
            loaiphong = 0;
            sodem = 0;
        }
        phong (int a, int b)
        {
            loaiphong = a;
            sodem = b;
        }
        void Nhap ()
        {
            cin >> sodem;
        }
        void Xuat ()
        {
            if (loaiphong == 1)
            {
                cout <<"\nLoai phong: Deluxe";
            }
            if (loaiphong == 2)
            {
                cout <<"\nLoai phong: Premium";
            }
            if (loaiphong == 3)
            {
                cout <<"\nLoai phong: Business";
            }
            cout <<"\nSo dem: "<<sodem; 
        }
        long TinhDoanhThu ()
        {
            return 0;
        }
};

class deluxe : public phong
{
    int phidv, phiphucvu;
    public:
        deluxe ()
        {
            loaiphong = 1;
            sodem = 0;
            phidv = 0;
            phiphucvu = 0;
        }
        deluxe (int b, float c, float d)
        {
            loaiphong = 1;
            sodem = b;
            phidv = c;
            phiphucvu = d;
        }
        void Nhap ()
        {
            phong :: Nhap ();
            cin >> phidv >> phiphucvu;
        }
        long TinhDoanhThu ()
        {
            return sodem * 750000 + phidv + phiphucvu;
        }
};

class premium : public phong
{
    int phidv;
    public:
        premium ()
        {
            loaiphong = 2;
            sodem = 0;
            phidv = 0;
        }
        premium (int a, float b)
        {
            loaiphong = 2;
            sodem = a;
            phidv = b;
        }
        void Nhap ()
        {
            phong :: Nhap ();
            cin >>phidv;
        }
        long TinhDoanhThu ()
        {
            return sodem * 500000 + phidv;
        }
};

class business : public phong
{
    public: 
    business ()
    {
        loaiphong = 3;
        sodem = 0;
    }
    business (int a)
    {
        loaiphong = 3;
        sodem = a;
    }   
    long TinhDoanhThu ()
    {
        return sodem * 300000;
    }
};

int main ()
{
    int n;
    cout <<"\nNhap so luong phong: ";
    cin >>n;
    phong** dsphong = new phong* [n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cout <<"\nNhap loai phong: ";
        cin >>x;
        if (x == 1)
        {
            dsphong[i] = new deluxe;
        }
        if (x == 2)
        {
            dsphong[i] = new premium;
        }
        if (x == 3)
        {
            dsphong[i] = new business;
        }
        dsphong[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        cout <<"\n\tTHONG TIN PHONG THU "<<i + 1;
        dsphong[i]->Xuat ();
    }
    system ("pause");
    system ("cls");
    return 0;
}