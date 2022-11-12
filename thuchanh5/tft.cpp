#include <iostream>
#include <string.h>
using namespace std;

class tuong 
{
    protected:
        string ten;
        int giatri;
        int he;
        int toc;
        int atk;
        int def;
        int loai;
        static int tonggiatri;
    public:
        tuong ()
        {

        }
        ~tuong ()
        {

        }
        virtual int satthuong () = 0;
        void Nhap ()
        {
            cin >>atk>>def;
        }
        void Xuat (int x, int i)
        {
            if (i == 0)
            {
                if (loai == 1)
                {
                    cout <<"Jarvan - sat thuong gay ra: "<<x;
                }   
                if (loai == 2)
                {
                    cout <<"Reksai - sat thuong gay ra: "<<x;
                }
                if (loai == 3)
                {
                    cout <<"Sivir - sat thuong gay ra: "<<x;
                }
                if (loai == 4)
                {
                    cout <<"Illaoi - sat thuong gay ra: "<<x;
                }
            }
            else
            {
                if (loai == 1)
                {
                    cout <<"\nJarvan - sat thuong gay ra: "<<x;
                }   
                if (loai == 2)
                {
                    cout <<"\nReksai - sat thuong gay ra: "<<x;
                }
                if (loai == 3)
                {
                    cout <<"\nSivir - sat thuong gay ra: "<<x;
                }
                if (loai == 4)
                {
                    cout <<"\nIllaoi - sat thuong gay ra: "<<x;
                }
            }
        }
        int GetLoai ()
        {
            return loai;
        }
        void XuLy (int x, int t, int y, int z)
        {
            if (he == 1)
            {
                if (x > 0)
                {
                    def += 15;
                }
                else if (t > 0)
                {
                    def += 30;
                }
            }
            if (toc == 2)
            {
                if (y > 0)
                {
                    atk += 30;
                }
            }
            if (toc == 1)
            {
                if (z > 0)
                {
                    atk += 15;
                    def += 15;
                }
            }
        }
        int GetGiaTri ()
        {
            return giatri;
        }
};

class Jarvan : public tuong
{
    public:
        Jarvan ()
        {
            loai = 1;
            toc = 1;
            he = 1;
            giatri = 1;
        }
        ~Jarvan ()
        {

        }
        int satthuong ()
        {
            return def * 2;
        }
};

class Reksai : public tuong
{
    public:
        Reksai ()
        {
            loai = 2;
            toc = 2;
            he = 1;
            giatri = 2;
        }
        ~Reksai ()
        {

        }
        int satthuong ()
        {
            return atk;
        }
};

class Sivir : public tuong
{
    public:
        Sivir ()
        {
            loai = 3;
            toc = 1;
            he = 0;
            giatri = 4;
        }
        ~Sivir ()
        {

        }
        int satthuong ()
        {
            return atk * 2;
        }
};

class Illaoi : public tuong
{
    public:
        Illaoi ()
        {
            loai = 4;
            toc = 2;
            he = 1;
            giatri = 1;
        }
        ~Illaoi ()
        {

        }
        int satthuong ()
        {
            return (atk + def) / 2;
        }
};

int main ()
{
    int dausi15 = 0;
    int dausi30 = 0;
    int dausi1 = 0;
    int dausi2 = 0;
    int dausi3 = 0;
    int tiencong = 0;
    int tiencong1 = 0;
    int tiencong2 = 0;
    int congnghe = 0;
    int congnghe1 = 0;
    int congnghe2 = 0;
    int n,m;
    int gt = 0;
    cin >>n>>m;
    tuong** DStuong = new tuong* [n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cin >>loai;
        if (loai == 1)
        {
            DStuong[i] = new Jarvan;
            congnghe1++;
            dausi1++;
            
        }
        if (loai == 2)
        {
            DStuong[i] = new Reksai;
            dausi2++;
            tiencong1++;
        }
        if (loai == 3)
        {
            DStuong[i] = new Sivir;
            congnghe2++;
        }
        if (loai == 4)
        {
            DStuong[i] = new Illaoi;
            dausi3++;
            tiencong2++;
        }
        if (dausi1 > 0 && dausi2 > 0)
        {
            dausi15++;
        }
        if (dausi1 > 0 && dausi2 > 0 && dausi3 > 0)
        {
            dausi30++;
        }
        if (tiencong1 > 0 && tiencong2 > 0)
        {
            tiencong++;
        }
        if (congnghe1 > 0 && congnghe2 > 0)
        {
            congnghe++;
        }
        gt += DStuong[i]->GetGiaTri();
        DStuong[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        DStuong[i]->XuLy(dausi15,dausi30,tiencong,congnghe);
    }
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < m; j++)
        {
            if (DStuong[i]->GetLoai() == 2)
            {
                if ((j + 1) % 4 == 0)
                {
                    x += DStuong[i]->satthuong() * 2;
                }
                else
                {
                    x += DStuong[i]->satthuong();
                }
            }
            else
            {
                x += DStuong[i]->satthuong();
            }
        }
        DStuong[i]->Xuat(x,i);
    }
    cout <<"\nTong gia tri: "<<gt;
    return 0;
}