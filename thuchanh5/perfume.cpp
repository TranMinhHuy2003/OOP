#include <iostream>
#include <string.h>
using namespace std;

class info_khach
{
    string ma;
    string ten;
    string diachi;
    string sdt;
    public:
        void Nhap ()
        {
            cout <<"\nNhap ma khach hang: ";
            getline (cin,ma);
            cout <<"\nNhap ho ten khach hang: ";
            getline (cin,ten);
            cout <<"\nNhap dia chi: ";
            getline (cin,diachi);
            cout <<"\nNhap so dien thoai: ";
            getline (cin,sdt);
        }
        void Xuat ()
        {
            cout <<"\nThong tin khach hang: "<<ma<<" "<<ten<<" "<<diachi<<" "<<sdt;
        }
};

class nuochoa
{
    protected:
        string maso;
        int loai;
        long dungtich;
        long gia;
    public: 
        nuochoa ()
        {

        }
        ~nuochoa ()
        {

        }
        void Nhap ()
        {
            cout <<"\nNhap  ma so: ";
            getline (cin,maso);
            cout <<"\nNhap dung tich: ";
            cin >>dungtich;
        }
        virtual long TinhGia () = 0;
        void Xuat ()
        {
            cout <<"\nNuoc hoa: "<<maso<<" ";
            if (loai == 1)
            {
                cout <<"hoa hong ";
            }
            else 
            {
                cout <<"hoa cuc ";
            }
            cout <<dungtich<<" "<<gia;
        }
};

class hoahong : public nuochoa
{
    public:
        hoahong ()
        {
            loai = 1;
        }
        ~hoahong ()
        {

        }
        long TinhGia ()
        {
            gia = dungtich * 20;
            return dungtich * 20;
        }
};

class hoacuc : public nuochoa
{
    public: 
        hoacuc ()
        {
            loai = 2;
        }
        ~hoacuc ()
        {

        }
        long TinhGia ()
        {
            gia = dungtich * 15;
            return dungtich * 15;
        }
};

class daugoi
{
    protected:
        string maso;
        int loai;
        long dungtich;
        long gia;
        int tieuchuan;
    public:
        daugoi ()
        {

        }
        ~daugoi ()
        {

        }
        void Nhap ()
        {
            cin.ignore();
            cout <<"\nNhap ma so: ";
            getline (cin,maso);
            if (loai == 2)
            {
                cout <<"\nNhap tieu chuan: ";
                cin >>tieuchuan;
            }
            cout <<"\nNhap dung tich: ";
            cin >>dungtich;
        }
        virtual long TinhGia () = 0;
        void Xuat ()
        {
            cout <<"\nDau goi: "<<maso<<" ";
            if (loai == 1)
            {
                cout <<"toc kho ";
            }
            else 
            {
                cout <<"toc dau ";
                cout <<"Tieu chuan kiem dinh: "<<tieuchuan<<" ";
            }
            cout <<dungtich<<" "<<gia;
        }
};

class tockho : public daugoi
{
    public:
        tockho ()
        {
            loai = 1;
        }
        ~tockho ()
        {

        }
        long TinhGia ()
        {
            gia = dungtich * 20;
            return dungtich * 20;
        }
};

class tocdau : public daugoi 
{
    public:
        tocdau ()
        {
            loai = 2;
        }
        ~tocdau ()
        {

        }
        long TinhGia ()
        {
            if (tieuchuan == 1)
            {
                gia = dungtich * 30;
                return dungtich * 30;
            }
            gia = dungtich * 40;
            return dungtich * 40;
        }
};

class suatam 
{
    protected:
        string maso;
        int loai;
        long dungtich;
        long gia;
    public:
        suatam ()
        {

        }
        ~suatam ()
        {

        }
        void Nhap ()
        {
            cin.ignore();
            cout <<"\nNhap  ma so: ";
            getline (cin,maso);
            cout <<"\nNhap dung tich: ";
            cin >>dungtich;
        }
        virtual long TinhGia () = 0;
        void Xuat ()
        {
            cout <<"\nSua tam: "<<maso<<" ";
            if (loai == 1)
            {
                cout <<"da kho ";
            }
            else 
            {
                cout <<"da nhon ";
            }
            cout <<dungtich<<" "<<gia;
        }
};

class danhon : public suatam 
{
    public:
        danhon ()
        {
            loai = 2;
        }
        ~danhon ()
        {

        }
        long TinhGia ()
        {
            gia = dungtich * 40;
            return dungtich * 40;
        }
};

class dakho : public suatam 
{
    public:
        dakho ()
        {
            loai = 1;
        }
        ~dakho ()
        {

        }
        long TinhGia ()
        {
            gia = dungtich * 20;
            return dungtich * 20;
        }
};

class goisanpham 
{
    protected:
        string ma;
        int loai;
        nuochoa* a;
        suatam* b;
        daugoi* c;
        long gia;
    public:
        goisanpham ()
        {

        }
        ~goisanpham ()
        {

        }
        virtual void Nhap ()
        {
            cin.ignore();
            cout <<"\nNhap ma so: ";
            getline (cin,ma);
        }
        void Xuat ()
        {
            cout <<"\nGoi san pham: "<<ma<<" ";
            if (loai == 1)
            {
                cout <<"Romantic";
            }
            if (loai == 2)
            {
                cout <<"Fresh-Air";
            }
            cout <<" "<<gia;
            a->Xuat();
            c->Xuat();
            b->Xuat();
        }
        virtual long TinhGia () = 0;
};

class romantic : public goisanpham
{
    public:
        romantic ()
        {
            loai = 1;
        }
        ~romantic ()
        {

        }
        void Nhap ()
        {
            goisanpham :: Nhap ();
            a = new hoahong;
            a->Nhap ();
            int x;
            cout <<"\nMoi chon loai dau goi: ";
            cin >>x;
            if (x == 1)
            {
                c = new tockho;
            }
            if (x == 2)
            {
                c = new tocdau;
            }
            c->Nhap ();
            cout <<"\nMoi chon loai sua tam: ";
            cin >>x;
            if (x == 1)
            {
                b = new dakho;
            }
            if (x == 2)
            {
                b = new danhon;
            }
            b->Nhap (); 
        }
        long TinhGia ()
        {
            gia = a->TinhGia() + b->TinhGia() + c->TinhGia();
            return gia;
        }
};

class freshair : public goisanpham
{
    public:
        freshair ()
        {
            loai = 2;
        }
        ~freshair ()
        {

        }
        void Nhap ()
        {
            goisanpham :: Nhap ();
            int x;
            cout <<"\nMoi chon loai nuoc hoa: ";
            cin >>x;
            if (x == 1)
            {
                a = new hoahong;
            }
            if (x == 2)
            {
                a = new hoacuc;
            }
            a->Nhap ();
            c = new tockho;
            c->Nhap ();
            cout <<"\nMoi chon loai sua tam: ";
            cin >>x;
            if (x == 1)
            {
                b = new dakho;
            }
            if (x == 2)
            {
                b = new danhon;
            }
            b->Nhap (); 
        }
        long TinhGia ()
        {
            gia = a->TinhGia() + b->TinhGia() + c->TinhGia();
            return gia;
        }
};

class donhang 
{
    string madonhang;
    info_khach a;
    string ngaylap;
    goisanpham *b;
    long gia;
    public:
        void Nhap ()
        {
            cin.ignore ();
            cout <<"\nNhap ma don hang: ";
            getline (cin,madonhang);
            cout <<"\nNhap ngay lap hoa don: ";
            getline (cin,ngaylap);
            cout <<"\n\tNhap thong tin khach hang";
            a.Nhap();
            cout <<"\n\tNhap thong so goi san pham";
            int loai;
            cout <<"\nNhap loai goi san pham: ";
            cin >>loai;
            if (loai == 1)
            {
                b = new romantic;
            }
            if (loai == 2)
            {
                b = new freshair;
            }
            b->Nhap ();
            gia = b->TinhGia ();
        }
        void Xuat ()
        {
            cout <<"\nDon hang: "<<madonhang<<" "<<ngaylap<<" "<<gia;
            a.Xuat();
            b->Xuat();
        }
};

int main ()
{
    int n;
    cout <<"\nNhap so luong don hang: ";
    cin >>n;
    donhang DSdonhang [100];
    for (int i = 0; i < n; i++)
    {
        cout <<"\n\tNhap thong tin don hang thu "<<i + 1;
        DSdonhang[i].Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        cout <<"\n\tThong tin don hang thu "<<i + 1;
        DSdonhang[i].Xuat();
    }
    system ("pause");
    system ("cls");
    return 0;
}