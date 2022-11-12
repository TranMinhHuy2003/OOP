#include <iostream>
using namespace std;

class dausi
{
    protected:
        int loai;
    public:
        dausi ()
        {

        }
        ~dausi ()
        {

        }
        virtual void Nhap () = 0;
        virtual int TraVe () = 0;
        int GetLoai ()
        {
            return loai;
        }
};

class Malphite : public dausi
{
    protected:
        int phongthu;
    public:
        Malphite ()
        {
            loai = 1;
        }
        ~Malphite ()
        {

        }
        void Nhap ()
        {
            cin >> phongthu;
        }
        int TraVe ()
        {
            return phongthu + 10;
        }
};

class ChoGath : public dausi
{
    protected:
        int phongthu;
    public:
        ChoGath ()
        {
            loai = 2;
        }
        ~ChoGath ()
        {

        }
        void Nhap ()
        {
            cin >> phongthu;
        }
        int TraVe ()
        {
            return phongthu + 10;
        }
};



int main ()
{
    int n;
    cin >> n;
    dausi *a[1000];
    for (int i = 0 ; i < n ; i++)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            a[i] = new Malphite();
        }
        else if (loai == 2)
        {
            a[i] = new ChoGath();
        }
        a[i]->Nhap();
    }
    int m;
    cin >> m;
    int i = 0;
    int smMalphite, smChoGath;
    int k;
    while (i < n)
    {
        smChoGath = 0;
        smMalphite = 0;
        k = 0;
        if (a[i]->GetLoai() == 1)
        {
            smMalphite = a[i]->TraVe() * 2 * m;
            cout <<"Malphite - Sat thuong duoc giam: " << smMalphite;
        }
        else if (a[i]->GetLoai() == 2)
        {
            k = a[i]->TraVe();
            for (int j = 0 ; j < m ; j++)
            {
                smChoGath += k;
                k += 5;
            }
            cout <<"\nCho'Gath - Sat thuong duoc giam: " << smChoGath;
        }
        i++;
    }
    system ("pause");
    system ("cls");
    return 0;
}