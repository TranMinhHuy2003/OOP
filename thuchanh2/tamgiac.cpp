#include <iostream>
#include <math.h>
#define Pi 3.14
using namespace std;

class Diem {
    float hoanh,tung;
    public:
        void Nhap () {
            cin>>hoanh>>tung;
        }
        void TinhTien (float goc, float d) {
            hoanh=d*cos(goc*Pi/180)+hoanh;
            tung=d*sin(goc*Pi/180)+tung;
        }
        void Xuat () {
            cout <<"("<<hoanh<<","<<tung<<")";
        }
};

class TamGiac {
    Diem a,b,c;
    public:
        void Nhap () {
            a.Nhap();
            b.Nhap();
            c.Nhap();
        }
        void TinhTien () {
            float goc,d;
            cin>>goc>>d;
            a.TinhTien(goc,d);
            b.TinhTien(goc,d);
            c.TinhTien(goc,d);
        }
        void Xuat () {
            a.Xuat();
            cout <<endl;
            b.Xuat();
            cout <<endl;
            c.Xuat();
        }

};

int main () {
    TamGiac a;
    a.Nhap();
    a.TinhTien();
    a.Xuat();
    system("pause");
    system("cls");
    return 0;
}