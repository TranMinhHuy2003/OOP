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
        virtual void Nhap ()
        {
            cin >> sodem;
        }
        virtual void Xuat ()
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
        virtual long TinhDoanhThu ()
        {
            return 0;
        }
};

class deluxe : public phong
{
    int phidv, phiphucvu;
    static long dt_deluxe;
    public:
        deluxe ()
        {
            loaiphong = 1;
            sodem = 0;
            phidv = 0;
            phiphucvu = 0;
            dt_deluxe += sodem * 750000 + phidv + phiphucvu;
        }
        deluxe (int b, float c, float d)
        {
            loaiphong = 1;
            sodem = b;
            phidv = c;
            phiphucvu = d;
            dt_deluxe += sodem * 750000 + phidv + phiphucvu;
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
        static long GetDoanhThu ()
        {
            return dt_deluxe;
        }
};

class premium : public phong
{
    int phidv;
    static long dt_premium;
    public:
        premium ()
        {
            loaiphong = 2;
            sodem = 0;
            phidv = 0;
            dt_premium += sodem * 500000 + phidv;
        }
        premium (int a, float b)
        {
            loaiphong = 2;
            sodem = a;
            phidv = b;
            dt_premium += sodem * 500000 + phidv;
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
        static long GetDoanhThu ()
        {
            return dt_premium;
        }
};

class business : public phong
{
    static long dt_business;
    public: 
    business ()
    {
        loaiphong = 3;
        sodem = 0;
        dt_business += sodem * 300000;
    }
    business (int a)
    {
        loaiphong = 3;
        sodem = a;
        dt_business += sodem * 300000;
    }   
    long TinhDoanhThu ()
    {
        return sodem * 300000;
    }
    static long GetDoanhThu ()
    {
        return dt_business;?;
    }
};

long deluxe::dt_deluxe = 0;
long premium::dt_premium = 0;
long business::dt_business = 0;

int main ()
{
    deluxe a (3,100000,200000);
    deluxe b (5,200000,300000);
    premium c (3,150000);
    premium d (1,50000);
    business e (8);
    long deluxe_dt = deluxe::GetDoanhThu();
    long premium_dt = premium::GetDoanhThu();
    long business_dt = business::GetDoanhThu();
    if (deluxe_dt >= premium_dt && deluxe_dt >= business_dt)
    {
        cout <<"\nDoanh thu cua loai phong Deluxe la nhieu nhat";
    }
    else if (premium_dt >= deluxe_dt && premium_dt >= business_dt)
    {
        cout <<"\nDoanh thu cua loai phong Premium la nhieu nhat";
    }
    else if (business_dt >= premium_dt && business_dt >= deluxe_dt)
    {
        cout <<"\nDoanh thu cua loai phong Business la nhieu nhat";
    }
    system ("pause");
    system ("cls");
    return 0;
}