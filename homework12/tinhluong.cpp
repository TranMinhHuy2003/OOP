#include <iostream>
#include <string.h>
using namespace std;

class nhanvien
{
    protected:
        string ten;
        string ngaysinh;
        long luongcoban;
    public:
        virtual void Nhap ()
        {
            cin.ignore();
            cout <<"\nNhap ho ten: ";
            getline (cin,ten);
            cout <<"\nNhap ngay thang nam sinh: ";
            getline (cin,ngaysinh);
            cout <<"\nNhap luong co ban: ";
            cin >>luongcoban;
        }
        virtual void Xuat ()
        {
            cout <<"\nHo ten nhan vien: " <<ten;
            cout <<"\nNgay thang nam sinh: "<<ngaysinh;
            cout <<"\nLuong co ban: " <<luongcoban;
        }
        virtual long TinhLuong () = 0;
        int TimKiemNhanVien (string x)
        {
            if (ten == x)
            {
                return 1;
            }
            return 0;
        }
};

class nvvp : public nhanvien
{
    int songaylamviec;
    long trocap;
    public:
        void Nhap ()
        {
            nhanvien :: Nhap ();
            cout <<"\nNhap so ngay lam viec: ";
            cin >>songaylamviec;
            cout <<"\nNhap so tien tro cap: ";
            cin >>trocap;
        }
        void Xuat ()
        {
            nhanvien :: Xuat ();
            cout <<"\nSo ngay lam viec: "<<songaylamviec;
            cout <<"\nTien tro cap: "<<trocap;
        }
        long TinhLuong ()
        {
            return luongcoban + songaylamviec * 200000 + trocap;
        }
};

class nvsx : public nhanvien
{
    int sosanpham;
    public:
        void Nhap ()
        {
            nhanvien :: Nhap ();
            cout <<"\nNhap so san pham: ";
            cin >>sosanpham;
        }
        void Xuat ()
        {
            nhanvien :: Xuat ();
            cout <<"\nSo san pham: "<<sosanpham;
        }
        long TinhLuong ()
        {
            return luongcoban + sosanpham * 2000;
        }
};

class nvql : public nhanvien
{
    int hesochucvu;
    long thuong;
    public:
        void Nhap ()
        {
            nhanvien :: Nhap ();
            cout <<"\nNhap he so chuc vu: ";
            cin >>hesochucvu;
            cout <<"\nNhap tien thuong: ";
            cin >>thuong;
        }
        void Xuat ()
        {
            nhanvien :: Xuat ();
            cout <<"\nHe so chuc vu: "<<hesochucvu;
            cout <<"\nTien thuong: "<<thuong;
        }
        long TinhLuong ()
        {
            return luongcoban * hesochucvu + thuong;
        }
};

class congty
{
    nhanvien* DSnhanvien[100];
    int n;
    public:
        friend istream& operator>> (istream &is, congty &x)
        {
            cout <<"\nNhap so luong nhan vien: ";
            is >>x.n;
            int loai;
            for (int i = 0; i < x.n; i++)
            {
                cout <<"\nNhap loai nhan vien (1_nhan vien van phong, 2_nhan vien san xuat, 3_nhan vien quan ly): ";
                is >>loai;
                if (loai == 1)
                {
                    x.DSnhanvien[i] = new nvvp;
                }
                if (loai == 2)
                {
                    x.DSnhanvien[i] = new nvsx;
                }
                if (loai == 3)
                {
                    x.DSnhanvien[i] = new nvql;
                }
                x.DSnhanvien[i]->Nhap();
            }
            return is;
        }
        friend ostream& operator<< (ostream &os, congty x)
        {
            for (int i = 0; i < x.n; i++)
            {
                os <<"\n\tNHAN VIEN THU "<<i+1;
                x.DSnhanvien[i]->Xuat();
            }
            return os;
        }
        void TinhLuong (int &tong)
        {
            for (int i = 0; i < n; i++)
            {
                cout <<"\nLuong cua nhan vien thu "<<i+1<<" la: "<<DSnhanvien[i]->TinhLuong();
                tong += DSnhanvien[i]->TinhLuong();
            }
        }
        void TimKiem (string x)
        {
            for (int i = 0; i < n; i++)
            {
                if (DSnhanvien[i]->TimKiemNhanVien(x) == 1)
                {
                    DSnhanvien[i]->Xuat();
                }
            }
        }
};

int main ()
{
    int tong = 0;
    congty a;
    cin >>a;
    a.TinhLuong(tong);
    cout <<a;
    cout <<"\nTong luong cua cong ty la: "<<tong;
    string x;
    cin.ignore();
    cout <<"\n\nNhap ho ten nhan vien can tim kiem: ";
    getline (cin,x);
    a.TimKiem(x);
    system ("pause");
    system ("cls");
    return 0;
}