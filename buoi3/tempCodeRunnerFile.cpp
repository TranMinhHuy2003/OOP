#include <iostream>
using namespace std;
#define Max 100

class PhanSo {
    private:
        float tuso,mauso;
    public:
        void Nhap ();
        void Xuat ();
        int TimMax (PhanSo a);
};

int main () {
    int n;
    PhanSo a[Max];
    do {
        cout <<"\nNhap so luong phan so: ";
        cin >>n;
    } while (n<=0||n>Max);
    cout <<"\n\n\t\t=====NHAP MANG PHAN SO=====\n";
    for (int i=0; i<n; i++) {
        cout <<"\n\t\tNhap phan so thu "<<i+1;
        a[i].Nhap ();
    }
    PhanSo max=a[0];
    
    for (int i=1; i<n; i++) {
        if (a[i].TimMax(max)==1) {
            max=a[i];
        }
    }
    cout <<"\nPhan so lon nhat trong mang la: ";
    max.Xuat();
    system("pause");
    system("cls");
    return 0;
}

void PhanSo::Nhap () {
    cout <<"\nNhap tu so: ";
    cin>>tuso;
    cout <<"\nNhap mau so: ";
    cin>>mauso;
}

void PhanSo::Xuat () {
    cout <<tuso<<"/"<<mauso;
}

int PhanSo::TimMax (PhanSo a) {
    if (tuso*a.mauso>mauso*a.tuso) {
        return 1;
    } else {
        return 0;
    }
}