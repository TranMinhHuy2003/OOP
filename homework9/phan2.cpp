#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

class DaThuc 
{
    int n;
    int a[100];
    public:
        DaThuc ()
        {
            n = 0;
            a[0] = 0;
        }
        DaThuc KhoiTaoDaThucBacn (int n)
        {
            DaThuc kq;
            kq.n = n;
            srand(time(0));
            for (int i = 0; i <= kq.n; i++)
            {
                int c = rand() % 10;
                kq.a[i] = c;
            }
            return kq;
        }
        int GiaTriBieuThuc (int x)
        {
            int sum = 0;
            for (int i = 0 ; i <= n ; i++)
            {
                sum += a[i]*pow(x,i); 
            }
            return sum;
        }
        friend istream& operator>> (istream &is, DaThuc &x)
        {
            cout <<"\nNhap bac da thuc: ";
            is >>x.n;
            for (int i = 0 ; i <= x.n; i++)
            {
                cout <<"\nNhap a["<<i<<"]: ";
                is >>x.a[i];
            }
            return is;
        }
        friend ostream& operator<< (ostream &os, DaThuc x)
        {
            for (int i = 0; i <= x.n; i++)
            {
                if (x.a[i] != 0)
                {
                    if (x.a[0] == 0 && i == 1)
                    {
                        os<<x.a[i]<<"x^"<<i;
                    }
                    else if (x.a[i]>0 && i != 0)
                    {
                        os<<"+"<<x.a[i]<<"x^"<<i;
                    }
                    else 
                    {
                        os<<x.a[i]<<"x^"<<i;
                    }
                }
            }
            return os;
        }
        DaThuc (int x)
        {
            n = 0;
            a[0] = x;
        }
        friend DaThuc operator+ (DaThuc a, DaThuc b)
        {
            DaThuc kq;
            if (a.n > b.n)
            {
                kq.n = a.n;
            }
            else 
            {
                kq.n = b.n;
            }
            for (int i = 0; i <= kq.n; i++)
            {
                if (a.n >= i && b.n >= i)
                {
                    kq.a[i] = a.a[i] + b.a[i];
                } 
                else
                {
                    if (a.n >= i)
                    {
                        kq.a[i] = a.a[i];
                    }
                    else if (b.n >= i)
                    {
                        kq.a[i] = b.a[i];
                    }
                }
            }
            return kq;
        }
};

int main ()
{
    DaThuc a,b;
    cin >>a;
    b = b.KhoiTaoDaThucBacn(5);
    cout <<"\nDa thuc thu 1: "<<a<<endl;
    cout <<"\nDa thuc thu 2: "<<b<<endl;
    int x;
    cout <<"\nNhap x: ";
    cin >>x;
    cout <<"\nGia tri da thuc thu 1: "<<a.GiaTriBieuThuc(x);
    cout <<"\nGia tri da thuc thu 2: "<<b.GiaTriBieuThuc(x);
    DaThuc kq = a + b + 5;
    cout <<"\nTong 2 da thuc: "<<kq;
    system ("pause");
    system ("cls");
    return 0;
}