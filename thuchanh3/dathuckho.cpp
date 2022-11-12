#include <iostream>
using namespace std;

class DaThuc 
{
    int n;
    int a[10];
    public:
        friend istream& operator>> (istream &is, DaThuc &x)
        {
            do 
            {
                is>>x.n;
            } while (x.n < 0);
            for (int i = 0; i <= x.n; i++)
            {
                is>>x.a[i];
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
        DaThuc operator+ (DaThuc x)
        {
            DaThuc kq;
            if (n > x.n)
            {
                kq.n = n;
            }
            else 
            {
                kq.n = x.n;
            }
            for (int i = 0; i <= kq.n; i++)
            {
                if (n >= i && x.n >= i)
                {
                    kq.a[i] = a[i] + x.a[i];
                } 
                else
                {
                    if (n >= i)
                    {
                        kq.a[i] = a[i];
                    }
                    else if (x.n >= i)
                    {
                        kq.a[i] = x.a[i];
                    }
                }
            }
            return kq;
        }
        DaThuc operator- (DaThuc x)
        {
            DaThuc kq;
            if (n > x.n)
            {
                kq.n = n;
            }
            else {
                kq.n = x.n;
            }
            for (int i = 0; i <= kq.n; i++)
            {
                if (n >= i && x.n >= i)
                {
                    kq.a[i] = a[i] - x.a[i];
                } 
                else
                {
                    if (n >= i)
                    {
                        kq.a[i] = a[i];
                    }
                    else if (x.n >= i)
                    {
                        kq.a[i] = -x.a[i];
                    }
                }
            }
            return kq;
        }
        DaThuc operator* (DaThuc x)
        {
            DaThuc kq;
            kq.n = n + x.n;
            for (int k = 0; k <= kq.n; k++)
            {
                kq.a[k] = 0;
            }
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= x.n; j++)
                {
                    kq.a[i + j] += a[i] * x.a[j];
                }
            }
            return kq;
        }
        void XuLy ()
        {
            DaThuc a,b;
            cin>>a>>b;
            int t;
            cin>>t;
            if (t == 1)
            {
                DaThuc kq;
                kq = a + b;
                cout <<kq;
            } 
            else if (t == 2)
            {
                DaThuc kq;
                kq = a - b;
                cout <<kq;
            }
            else if (t == 3)
            {
                DaThuc kq;
                kq = a * b;
                cout <<kq;
            }
        }
};

int main ()
{
    DaThuc a;
    a.XuLy();
    system("pause");
    system("cls");
    return 0;
}