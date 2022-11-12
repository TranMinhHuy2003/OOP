#include <iostream>
using namespace std;

class ChuNhat {
    private:
        float dai;
        float rong;
    public:
        void Nhap ();
        void Xuat ();
        float chuvi ();
        void sosanh (ChuNhat a);
        int Kiemtra ();
};

int main () {
    ChuNhat a,b;
    cout <<"\n\n\t\t=====NHAP HINH CHU NHAT=====\n";
    a.Nhap();
    cout <<"\n\n\t\t=====XUAT HINH CHU NHAT=====\n";
    a.Xuat();
    cout <<"\n\nChu vi hinh chu nhat: "<<a.chuvi();
    cout <<"\n\n\t\t=====NHAP HINH CHU NHAT CAN SO SANH=====\n";
    b.Nhap();
    a.sosanh(b);
    if (a.Kiemtra()==1) {
        cout <<"\nHinh chu nhat thu 1 la hinh vuong";
    } else {
        cout <<"\nHinh chu nhat thu 1 khong la hinh vuong";
    }
    system("pause");
    system("cls");
    return 0;
}

void ChuNhat::Nhap() {
    do {
        cout <<"\nNhap chieu rong hinh chu nhat: ";
        cin >>rong;
        if (rong<=0) {
            cout <<"\nChieu rong hinh chu nhat phai la so duong, vui long nhap lai!";
        }
    } while (rong<=0);
    do {
        cout <<"\nNhap chieu dai hinh chu nhat: ";
        cin >>dai;
        if (dai<rong) {
            cout <<"\nChieu dai hinh chu nhat khong hop le, vui long nhap lai!";
        }
    } while (dai<rong);
}

void ChuNhat::Xuat() {
    cout <<"\nChieu dai hinh chu nhat: "<<dai;
    cout <<"\nChieu rong hinh chu nhat: "<<rong;
}

float ChuNhat::chuvi() {
    return 2*dai+2*rong;
}

void ChuNhat::sosanh(ChuNhat a) {
    if (2*(dai+rong)>2*(a.dai+a.rong)) {
        cout <<"\nChu vi hinh chu nhat thu 1 lon hon chu vi hinh chu nhat thu 2";
    } else if (2*(dai+rong)<2*(a.dai+a.rong)) {
        cout <<"\nChu vi hinh chu nhat thu 2 lon hon chu vi hinh chu nhat thu 1";
    } else {
        cout <<"\nChu vi 2 hinh chu nhat bang nhau";
    }
}

int ChuNhat::Kiemtra() {
    if (dai==rong) {
        return 1;
    } else {
        return 0;
    }
}