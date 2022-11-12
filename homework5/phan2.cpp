#include <iostream>
using namespace std;

class Diem {
    int hoanh;
    int tung;
    public:
        Diem () {
            hoanh=0;
            tung=0;
            cout <<1;
        }
        Diem (int a, int b) {
            hoanh=a;
            tung=b;
            cout <<2;
        }
        Diem (const Diem &x) {
            hoanh=x.hoanh;
            tung=x.tung;
            cout <<3;
        }
};

class TamGiac {
    Diem A,B,C;
    public:
        TamGiac () {
            cout <<4;
        }
        TamGiac (int xA, int yA, int xB, int yB, int xC, int yC) : A(xA,yA),B(xB,yB),C(xC,yC) {
            cout <<5;
        }
        TamGiac (Diem x, Diem y, Diem z) : A(x),B(y),C(z) {
            cout <<6;
        }
        TamGiac (const TamGiac &x) : A(x.A), B(x.B), C(x.C) {
            cout <<7;
        }
};

int main () {
    Diem x,y,z;
    TamGiac a;
    TamGiac b(1,2,3,4,5,6);
    TamGiac c(x, y, z);
    TamGiac d (c);
    system("pause");
    system("cls");
    return 0;
}