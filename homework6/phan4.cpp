#include <iostream>
#include <string.h>
using namespace std;

class XeMay {
    int id;
    string ten;
    string hieu;
    int bangso;
    static int Bangso;
    public:
        XeMay ()
        {
            id=1;
            ten="Nguyen Van A";
            hieu="Yamaha";
            bangso=Bangso;
            Bangso++;
        }
        XeMay (int a, string b, string c) {
            id=a;
            ten=b;
            hieu=c;
            bangso=Bangso;
            Bangso++;
        }
        XeMay (const XeMay &x) {
            id=x.id;
            ten=x.ten;
            hieu=x.hieu;
            bangso=x.Bangso;
            Bangso++;
        }
        void Xuat () {
            cout <<"\n\t\tTHONG TIN XE MAY\n";
            cout <<"\nID: "<<id;
            cout <<"\nTen chu xe: "<<ten;
            cout <<"\nHieu xe: "<<hieu;
            cout <<"\nBang so xe: "<<bangso;
        }
};

int XeMay::Bangso=10000;

int main () {
    XeMay a;
    XeMay b (2, "Tran Van B", "Honda");
    XeMay c (b);
    a.Xuat();
    b.Xuat();
    c.Xuat();
    system("pause");
    system("cls");
    return 0;
}