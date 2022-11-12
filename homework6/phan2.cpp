#include <iostream>
#include <string.h>
using namespace std;

class NhanVien {
    string ten;
    int id;
    float luong;
    static int stt;
    public: 
        NhanVien ()
        {
            ten="Nguyen Van A";
            id=1;
            luong=150240;
            stt++;
        }
        NhanVien (string a, int b, float c)
        {
            ten=a;
            id=b;
            luong=c;
            stt++;
        }
        NhanVien (string a, float b)
        {
            ten=a;
            id=stt;
            luong=b;
            stt++;
        }
        NhanVien (const NhanVien &x) 
        {
            ten=x.ten;
            id=x.id;
            luong=x.luong;
            stt++;
        }
        void Xuat ()
        {
            cout <<"\n\t\tTHONG TIN NHAN VIEN\n";
            cout <<"\nTen: "<<ten;
            cout <<"\nID: "<<id;
            cout <<"\nLuong: "<<luong;
        }
};

int NhanVien::stt=1;

int main () {
    NhanVien a,b;
    NhanVien c ("Nguyen A",20,100000);
    NhanVien d ("Tran B",21,150000);
    NhanVien e ("Le C",200000);
    NhanVien f ("Ho D",250000);
    NhanVien g (a);
    NhanVien h (b);
    a.Xuat();
    b.Xuat();
    c.Xuat();
    d.Xuat();
    e.Xuat();
    f.Xuat();
    g.Xuat();
    h.Xuat();
    system("pause");
    system("cls");
    return 0;
}