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
        int TimMin (PhanSo a);
};

class MangPhanSo {
    private:
        int n;
        PhanSo a[Max];
    public:
        void Nhap ();
        PhanSo TimMax ();
        PhanSo TimMin ();
};

int main () {
    MangPhanSo a;
    a.Nhap();
    PhanSo c=a.TimMin();
    c.Xuat();
    cout <<endl;
    PhanSo b=a.TimMax();
    b.Xuat();
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

int PhanSo::TimMin (PhanSo a) {
    float f1, f2;
    f1=float(tuso)/float(mauso);
    f2=float(a.tuso)/float(a.mauso);
    if (f1<f2) {
        return 1;
    } else {
        return 0;
    }
}

void MangPhanSo::Nhap() {
    do {
        cin >>n;
    } while (n<=0||n>Max);
    for (int i=0; i<n; i++) {
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

PhanSo MangPhanSo::TimMin () {
    PhanSo min=a[0];
    for (int i=1; i<n; i++) {
        if (a[i].TimMin(min)==1) {
            min=a[i];
        }
    }
    return min;
}