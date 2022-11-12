#include <iostream>
#include <cmath>
#define Max 100
using namespace std;

class PhanSo {
    private:
        int tu,mau;
    public: 
        void Nhap ();
        void Xuat ();
        int UCLN ();
        PhanSo RutGon ();
};

void PhanSo::Nhap () {
    cin>>tu;
    do {
        cin>>mau;
        if (mau==0) {
            cout <<"\nMau so phai khac 0, vui long nhap lai!";
        }
    } while (mau==0);
}

void PhanSo::Xuat () {
    cout <<tu<<"/"<<mau;
}

int PhanSo::UCLN () {
    tu=abs(tu);
    mau=abs(mau);
    if (tu==0||mau==0) {
        return tu+mau;
    }
    while (tu!=mau) {
        if (tu>mau) {
            tu=tu-mau;
        } else {
            mau=mau-tu;
        }
    }
    return tu;
}

PhanSo PhanSo::RutGon () {
    PhanSo a;
    a.tu=tu;
    a.mau=mau;
    a.tu=a.tu/UCLN();
    a.mau=a.mau/UCLN();
    return a;
}

int main () {
    int n;
    PhanSo a[Max];
    cin >>n;
    for (int i=0; i<n; i++) {
        a[i].Nhap();
    }
    for (int i=0; i<n; i++) {
        PhanSo b=a[i].RutGon();
        b.Xuat();
        cout <<endl;
    }
    system("pause");
    system("cls");
    return 0;
}