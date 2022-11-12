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
                if (i == n - 1)
                {
                    cout <<"Eeee";
                }
                else 
                {
                    cout <<"Eeee,";
                }
            }
        }
};

int main ()
{
    giasuc *a[3];
    int b[3];
    int n;
    cin >> n;
    a[0] = new bo ();
    a[1] = new cuu ();
    a[2] = new de ();
    for (int i = 0 ; i < 3 ; i++)
    {
        a[i]->Nhap();
        b[i] = a[i]->GiveMilk() * a[i]->GetSoLuong() * n;
    }
    for (int i = 0 ; i < 3 ; i++)
    {
        a[i]->Keu(a[i]->GetSoLuong());
    }
    cout <<"\nBo: "<<b[0];
    cout <<"\nCuu: "<<b[1];
    cout <<"\nDe: "<<b[2];
    system ("pause");
    system ("cls");
    return 0;
}