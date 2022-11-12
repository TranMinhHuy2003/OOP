#include <iostream>
#include <string.h>
using namespace std;

class giasuc
{
    protected:
        int soluong;
    public:
        giasuc ()
        {

        }
        ~giasuc ()
        {

        }
        void Nhap ()
        {
            cin >> soluong;
        }
        int GetSoLuong ()
        {
            return soluong;
        }
        virtual int GiveMilk () = 0;
        virtual void Keu (int n) = 0;
        virtual void XuLy (int n, int &sua, int &soluong, int x)
        {
            int f0 = 0;
            int f1 = 0;
            int f2 = 0;
            int f3 = 0;
            for (int i = 0 ; i < n ; i++)
            {
                soluong = soluong + f3;
                f3 = f2;
                f2 = f1;
                f1 = f0;
                f0 = soluong / 2;
                sua = sua + soluong * x;
            }
            soluong += f0 + f1 + f2 + f3;
        }
};

class bo : public giasuc
{
    public:
        bo ()
        {

        }
        ~bo ()
        {

        }
        int GiveMilk ()
        {
            return 10;
        }
        void Keu (int n)
        {
            for (int i = 0 ; i < n ; i++)
            {
                cout <<"Booo,";
            }
        }
};

class cuu : public giasuc
{
    public:
        cuu ()
        {

        }
        ~cuu ()
        {

        }
        int GiveMilk ()
        {
            return 5;
        }
        void Keu (int n)
        {
            for (int i = 0 ; i < n ; i++)
            {
                cout <<"Beee,";
            }
        }
};

class de : public giasuc
{
    public:
        de ()
        {

        }
        ~de ()
        {

        }
        int GiveMilk ()
        {
            return 8;
        }
        void Keu (int n)
        {
            for (int i = 0 ; i < n ; i++)
            {
                cout <<"Eeee,";
            }
        }
};

class tho : public giasuc
{
    public:
        tho ()
        {

        }
        ~tho ()
        {

        }
        int GiveMilk ()
        {
            return 0;
        }
        void Keu (int n)
        {
            for (int i = 0 ; i < n ; i++)
            {
                if (i == n - 1)
                {
                    cout <<" ";
                }
                else 
                {
                    cout <<",";
                }
            }
        }
        void XuLy (int n, int &sua, int &soluong, int x)
        {
            int f0 = 0;
            int f1 = 0;
            for (int i = 0 ; i < n ; i++)
            {
                soluong = soluong + f1;
                f1 = f0;
                f0 = soluong / 2;
            }
            sua = 0;
            soluong += f0 + f1;
        }
};

int main ()
{
    giasuc *a[4];
    int b[4]={0,0,0,0};
    int c[4];
    int n;
    a[0] = new bo ();
    a[1] = new cuu ();
    a[2] = new de ();
    a[3] = new tho ();
    for (int i = 0 ; i < 4 ; i++)
    {
        a[i]->Nhap();
    }
    cin >> n;
    for (int i = 0 ; i < 4 ; i++)
    {
        a[i]->Keu(a[i]->GetSoLuong());
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        c[i] = a[i]->GetSoLuong();
        a[i]->XuLy(n,b[i],c[i],a[i]->GiveMilk());
    }
    cout <<"\nBo: "<<c[0]<<","<<b[0];
    cout <<"\nCuu: "<<c[1]<<","<<b[1];
    cout <<"\nDe: "<<c[2]<<","<<b[2];
    cout <<"\nTho: "<<c[3]<<","<<b[3];
    system ("pause");
    system ("cls");
    return 0;
}