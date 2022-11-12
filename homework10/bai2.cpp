#include <iostream>
using namespace std;

class MangNguyen 
{
    int in;
    int *a;
    public:
        MangNguyen ()
        {
            in = 0;
            a = new int [in + 1];
            a[0] = 0;
        }
        MangNguyen (int n, int so[])
        {
            in = n;
            a = new int [in + 1];
            for (int i = 0; i <= in; i++)
            {
                a[i] = so[i];
            }
        }
        MangNguyen (const MangNguyen &arr)
        {
            delete a;
            in = arr.in;
            a = new int [in + 1];
            for (int i = 0 ; i <= in; i++)
            {
                a[i]  = arr.a[i];
            }
        }
        friend istream& operator>> (istream &is, MangNguyen &m)
        {
            cout <<"\nNhap bac cua mang: ";
            is >> m.in;
            m.a = new int [m.in];
            for (int i = 0; i <= m.in; i++)
            {
                is >> m.a[i];
            }
            return is;
        }
        MangNguyen operator= (MangNguyen arr)
        {
            delete a;
            in = arr.in;
            a = new int [in + 1];
            for (int i = 0 ; i <= in; i++)
            {
                a[i]  = arr.a[i];
            }
            return *this;
        }
        int operator[] (int x)
        {
            return a[x];
        }
        ~MangNguyen ()
        {
            delete a;
        }
};

int main ()
{
    MangNguyen a;
    cout <<a[0];
    system ("pause");
    system ("cls");
    return 0;
}