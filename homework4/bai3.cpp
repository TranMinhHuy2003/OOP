#include <iostream>
#include <cmath>
using namespace std;
#define Max 100      

class PhanSo {
    private:
        float tuso,mauso;
    public:
        void Nhap ();
        void Xuat ();
        int TimMax (PhanSo a);
        PhanSo TinhTong (PhanSo a);
};

class MangPhanSo {
    private:
        int n;
        PhanSo a[Max];
    public:
        void Nhap ();
        PhanSo TimMax ();
        PhanSo TinhTong ();
};

int main () {
    MangPhanSo a;
    a.Nhap();
    PhanSo b=a.TimMax();
    cout <<"\nPhan so lon nhat trong mang la: ";
    b.Xuat();
    PhanSo c=a.TinhTong();
    cout <<"\nTong cac phan so trong mang la:";
    c.Xuat();
    system("pause");
    system("cls");
    return 0;
}

void PhanSo::Nhap () {
    cout <<"\nNhap tu so: ";
    cin>>tuso;
    do {
        cout <<"\nNhap mau so: ";
        cin>>mauso;
        if (mauso==0) {
            cout <<"\nMau so phai khac 0, hay nhap lai!";
        }
    } while (mauso==0);
}

void PhanSo::Xuat () {
    cout <<tuso<<"/"<<mauso;
}

int PhanSo::TimMax (PhanSo a) {
    float f1, f2;
    f1=float(tuso)/float(mauso);
    f2=float(a.tuso)/float(a.mauso);
    if (f1>f2) {
        return 1;
    } else {
        return 0;
    }
}

PhanSo PhanSo::TinhTong (PhanSo a) {
    PhanSo kq;
    kq.tuso=tuso*a.mauso+mauso*a.tuso;
    kq.mauso=mauso*a.mauso;
    return kq;
}

void MangPhanSo::Nhap() {
    do {
        cout <<"\nNhap so luong phan so: ";
        cin >>n;
    } while (n<=0||n>Max);
    cout <<"\n\n\t\t=====NHAP MANG PHAN SO=====\n";
    for (int i=0; i<n; i++) {
        cout <<"\n\t\tNhap phan so thu "<<i+1;
        a[i].Nhap ();
    }
}

PhanSo MangPhanSo::TimMax () {
    PhanSo max=a[0];
    for (int i=1; i<n; i++) {
        if (a[i].TimMax(max)==1) {
            max=a[i];
        }
    }
    return max;
}

PhanSo MangPhanSo::TinhTong() {
    PhanSo kq=a[0];
    for (int i=1; i<n; i++) {
        kq=kq.TinhTong(a[i]);
    }
    return kq;
}