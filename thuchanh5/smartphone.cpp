#include <iostream>
#include <string.h>
using namespace std;

class cpu
{
    protected:
        string ma_cpu;
        int loai_cpu;
        string hang;
        int socore;
        float xungnhip;
        int gianhap;
    public:
        int GetGia ()
        {
            return gianhap;
        }
        void Nhap ()
        {
            cin.ignore();
            cin >>ma_cpu;
        }
        void Xuat ()
        {
            cout <<"CPU: "<<ma_cpu<<" ";
            if (loai_cpu == 1)
            {
                cout <<"Alpha";
            }
            if (loai_cpu == 2)
            {
                cout <<"Beta";
            }
            if (loai_cpu == 3)
            {
                cout <<"Gamma";
            }
            cout <<" "<<hang<<" "<<socore<<" "<<xungnhip<<" "<<gianhap;
        }
};

class Alpha : public cpu
{
    public:
        Alpha ()
        {
            loai_cpu = 1;
            gianhap = 200;
            socore = 2;
            xungnhip = 1.8;
            hang = "Black";
        }
};

class Beta : public cpu
{
    public:
        Beta ()
        {
            loai_cpu = 2;
            gianhap = 400;
            socore = 4;
            xungnhip = 2.46;
            hang = "Black";
        }
};

class Gamma : public cpu
{
    public:
        Gamma ()
        {
            loai_cpu = 3;
            gianhap = 600;
            socore = 4;
            xungnhip = 2.6;
            hang = "White";
        }
};

class manhinh 
{
    protected:
        string mamanhinh;
        string hang;
        float kichthuoc;
        int gia;
        int dophangiai;
        int chongloa;
    public:
        manhinh ()
        {
            kichthuoc = 4.7;
        }
        ~manhinh ()
        {

        }
        int GetGia ()
        {
            if (dophangiai == 1)
            {
                gia = 200;
                return 200;
            }
            else if (dophangiai == 2 && chongloa == 1)
            {
                gia = 500;
                return 500;
            }
            else
            {
                gia = 300;
                return 300;
            }
        }
        void Nhap ()
        {
            cin.ignore();
            cin >>mamanhinh>>hang>>dophangiai;
            if (dophangiai == 2)
            {
                cin >>chongloa;
            }
        }
        void Xuat ()
        {
            cout <<"Man hinh: "<<mamanhinh<<" "<<hang<<" ";
            if (dophangiai == 1)
            {
                cout <<"HD";
            }
            if (dophangiai == 2)
            {
                cout <<"FullHD";
            }
            cout <<" "<<gia;
            if (chongloa == 1)
            {
                cout <<" Chong_loa";
            }
        }
};

class vo
{
    protected:
        string ma_vo;
        int loai_vo;
        string hang;
        int gia;
        int mau;
    public:
        int GetGia ()
        {
            return gia;
        }
        virtual void Nhap ()
        {
            cin.ignore();
            cin >>ma_vo>>mau;
        }
        virtual void Xuat ()
        {
            cout <<"Vo smartphone: "<<ma_vo<<" ";
            if (loai_vo == 1)
            {
                cout <<"Nhom";
            }
            if (loai_vo == 2)
            {
                cout <<"Nhua";
            }
            cout <<" "<<hang<<" ";
            if (mau == 1)
            {
                cout <<"Do";
            }
            if (mau == 2)
            {
                cout <<"Den";
            }
            if (mau == 3)
            {
                cout <<"Xanh";
            }
            cout <<" "<<gia;
        }
};

class vo_nhom : public vo
{
    public:
        vo_nhom ()
        {
            loai_vo = 1;
            gia = 400;
            hang = "Black";
        }
};

class vo_nhua : public vo
{
    public:
        vo_nhua ()
        {
            loai_vo = 2;
            gia = 200;
            hang = "White";
        }
};

class smartphone
{
    protected:
        string ma_smartphone;
        int dong_smartphone;
        long giaban;
        cpu* a;
        vo* b;
        manhinh* c;
    public:
        ~smartphone ()
        {

        }
        virtual void Nhap ()
        {
            cin.ignore();
            cin >>ma_smartphone;
        }
        virtual void Xuat ()
        {
            cout <<"Smartphone: "<<ma_smartphone<<" ";
            if (dong_smartphone == 1)
            {
                cout <<"Venus";
            }
            if (dong_smartphone == 2)
            {
                cout <<"Mars";
            }
            if (dong_smartphone == 3)
            {
                cout <<"Jupiter";
            }
            cout <<" "<<giaban;
            cout <<endl;
            a->Xuat();
            cout <<endl;
            c->Xuat();
            cout <<endl;
            b->Xuat();
        }
        virtual void TinhTien () = 0;
};

class Venus : public smartphone
{
    public:
    Venus ()
    {
        dong_smartphone = 1;
    }
    ~Venus ()
    {

    }
    void Nhap ()
    {
        smartphone :: Nhap();
        int icpu;
        cin >>icpu;
        if (icpu == 1)
        {
            a = new Alpha();
        }
        if (icpu == 2)
        {
            a = new Beta();
        }
        a->Nhap();
        c = new manhinh();
        c->Nhap();
        int ivo;
        cin >>ivo;
        if (ivo == 1)
        {
            b = new vo_nhom();
        }
        if (ivo == 2)
        {
            b = new vo_nhua();
        }
        b->Nhap();
    }
    void TinhTien ()
    {
        giaban = (a->GetGia() + b->GetGia() + c->GetGia()) * 1.3;
    }
};

class Mars : public smartphone
{
    public:
    Mars ()
    {
        dong_smartphone = 2;
    }
    ~Mars ()
    {

    }
    void Nhap ()
    {
        smartphone :: Nhap();
        int icpu;
        cin >>icpu;
        if (icpu == 1)
        {
            a = new Alpha();
        }
        if (icpu == 2)
        {
            a = new Beta();
        }
        if (icpu == 3)
        {
            a= new Gamma();
        }
        a->Nhap();
        c = new manhinh;
        c->Nhap ();
        b = new vo_nhom();
        b->Nhap();
    }
    void TinhTien ()
    {
        giaban = (a->GetGia() + b->GetGia() + c->GetGia()) * 1.5;
    }
};

class Jupiter : public smartphone
{
    public:
    Jupiter ()
    {
        dong_smartphone = 3;
    }
    ~Jupiter ()
    {

    }
    void Nhap ()
    {
        smartphone :: Nhap();
        a = new Gamma();
        a->Nhap();
        c = new manhinh;
        c->Nhap();
        b = new vo_nhom();
        b->Nhap();
    }
    void TinhTien ()
    {
        giaban = (a->GetGia() + b->GetGia() + c->GetGia()) * 1.8;
    }
};

int main ()
{
    int n;
    cin >>n;
    smartphone** DS = new smartphone* [n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cin >>loai;
        if (loai == 1)
        {
            DS[i] = new Venus();
        }
        if (loai == 2)
        {
            DS[i] = new Mars();
        }
        if (loai == 3)
        {
            DS[i] = new Jupiter();
        }
        DS[i]->Nhap();
        DS[i]->TinhTien();
    }
    for (int i = 0; i < n; i++)
    {
        DS[i]->Xuat();
    }
    system ("pause");
    system ("cls");
    return 0;
}