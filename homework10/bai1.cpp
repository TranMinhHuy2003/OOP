#include <iostream>
#include <cmath>
using namespace std;

class DaThuc 
{
    int n;
    float *a;
    public:
        DaThuc ()
        {
            n = 0;
            a = new float [n + 1];
            a[0] = 0;
        }
        DaThuc KhoiTaoDaThucBacn (int n, float a[])
        {
            DaThuc kq;
            kq.n = n;
            kq.a = new float [n + 1];
            for (int i = 0; i <= kq.n; i++)
            {
                kq.a[i] = a[i];
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
            x.a = new float [x.n];
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
                    if (x.a[i]>0 && i != 0)
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
            a = new float [n + 1];
            a[0] = x;
        }
        friend DaThuc operator+ (DaThuc a, DaThuc b)
        {
            DaThuc kq;
            if (a.n > b.n)
            {
                kq.a = new float [a.n + 1];
                kq.n = a.n;
            }
            else 
            {
                kq.a = new float [b.n + 1];
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
    float c[6] = {2,3.5,-4.5,0,3,8};
    b = b.KhoiTaoDaThucBacn(5,c);
    cout <<"\nDa thuc thu 1: "<<a<<endl;
    cout <<"\nDa thuc thu 2: "<<b<<endl;
    DaThuc kq = a + b;
    cout <<"\nTong 2 da thuc: "<<kq;
    system ("pause");
    system ("cls");
    return 0;
}