#include <iostream>
#include <cmath>
using namespace std;
#define Max 100

class PhanSo {
    private:
        int tuso,mauso;
    public:
        void Nhap ();
        void Xuat ();
        PhanSo TinhTong(PhanSo a);
        PhanSo TinhHieu(PhanSo a);
        PhanSo TinhTich(PhanSo a);
        PhanSo TinhThuong(PhanSo a);
        void RutGon ();
        void ChuanHoa ();
};

int main () {
    PhanSo a,b;
    a.Nhap();
    b.Nhap();
    PhanSo c=a.TinhTong(b);
    PhanSo d=a.TinhHieu(b);
    PhanSo e=a.TinhTich(b);
    PhanSo f=a.TinhThuong(b);
    c.Xuat();
    cout <<endl;
    d.Xuat();
    cout <<endl;
    e.Xuat();
    cout <<endl;
    f.Xuat();
    cout <<endl;
    system("pause");
    system("cls");
    return 0;
}

void PhanSo::Nhap () {
    cin>>tuso;
    do {
        cin>>mauso;
    } while (mauso==0);
}

void PhanSo::Xuat () {
    cout <<tuso<<"/"<<mauso;
}

PhanSo PhanSo::TinhTong (PhanSo a) {
    PhanSo kq;
    kq.tuso=tuso*a.mauso+mauso*a.tuso;
    kq.mauso=mauso*a.mauso;    
    kq.RutGon();
    kq.ChuanHoa();
    return kq;
}

PhanSo PhanSo::TinhHieu (PhanSo a) {
    PhanSo kq;
    kq.tuso=tuso*a.mauso-mauso*a.tuso;
    kq.mauso=mauso*a.mauso;    
    kq.RutGon();
    kq.ChuanHoa();
    return kq;
}

PhanSo PhanSo::TinhTich (PhanSo a) {
    PhanSo kq;
    kq.tuso=tuso*a.tuso;
    kq.mauso=mauso*a.mauso;
    kq.RutGon();
    kq.ChuanHoa();
    return kq;
}

PhanSo PhanSo::TinhThuong (PhanSo a) {
    PhanSo kq;
    kq.tuso=tuso*a.mauso;
    kq.mauso=mauso*a.tuso;
    kq.RutGon();
    kq.ChuanHoa();
    return kq;
}

void PhanSo::RutGon () {
    int t;
    PhanSo a;
    a.tuso=tuso;
    a.mauso=mauso;
    while (a.mauso!=0) {
        t=a.tuso%a.mauso;
        a.tuso=a.mauso;
        a.mauso=t;
    }
    t=a.tuso;
    tuso=tuso/t;
    mauso=mauso/t;
}

void PhanSo::ChuanHoa () {
    if (mauso<0) {
        tuso*=-1;
        mauso*=-1;
    }
}