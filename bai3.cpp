#include <iostream>
using namespace std;

class TamGiac {
    private:
        float a,b,c;
    public:
        void Nhap ();
        void Xuat ();
        float ChuVi ();
        void KiemTra ();
        float Max ();
};

int main () {
    TamGiac a;
    cout <<"\n\n\t\t=====NHAP TAM GIAC=====\n";
    a.Nhap();
    cout <<"\n\n\t\t=====XUAT TAM GIAC=====\n";
    a.Xuat();
    cout <<"\nChu vi tam giac la: "<<a.ChuVi();
    a.KiemTra();
    system("pause");
    system("cls");
    return 0;
}

void TamGiac::Nhap () {
    do {
        cout <<"\nNhap canh thu nhat: ";
        cin >> a;
        cout <<"\nNhap canh thu hai: ";
        cin >> b;
        cout <<"\nNhap canh thu ba: ";
        cin >> c;
        if (a<=0||b<=0||c<=0) {
            cout <<"\nCanh tam giac phai lon hon 0, vui long nhap lai!";
        } else if (a+b<=c||a+c<=b||b+c<=a) {
            cout <<"\n3 canh tren khong tao thanh 1 tam giac, vui long nhap lai!";
        }
    } while (a<=0||b<=0||c<=0||a+b<=c||a+c<=b||b+c<=a);
}

void TamGiac::Xuat () {
    cout <<"\nDo dai canh thu 1: "<<a;
    cout <<"\nDo dai canh thu 2: "<<b;
    cout <<"\nDo dai canh thu 3: "<<c;
}

float TamGiac::ChuVi() {
    return a+b+c;
}

float TamGiac::Max() {
    if (a>=b&&a>=c) {
        return a;
    } else if (b>=a&&b>=c) {
        return b;
    } else {
        return c;
    }
}

void TamGiac::KiemTra() {
    if (a==b && a==c && b==c) {
        cout <<"\nTam giac nay la tam giac deu";
    } else if (a==b||a==c||b==c) {
        if (Max()*Max()==a*a+b*b+c*c-Max()*Max()) {
            cout <<"\nTam giac nay la tam giac vuong can";
        } else {
            cout <<"\nTam giac nay la tam giac can";
        }
    } else if (Max()*Max()==a*a+b*b+c*c-Max()*Max()) {
        cout <<"\nTam giac nay la tam giac vuong";
    } else {
        cout <<"\nTam giac nay la tam giac thuong";
    }
}