#include <iostream>
#include <string.h>
using namespace std;

class KichThuoc {
    private:
        int dai,rong;
    public:
        void Nhap ();
        void Xuat ();
        int TinhDienTich ();
};

class CanHo {
    private:
        string tenchuho;
        KichThuoc kichthuoc;
        int SoLuongNguoi;
    public:
        void Nhap ();
        int TinhDienTich ();
        int SoSanh (CanHo a);
};

int main () {
    CanHo a,b;
    cout <<"\n\n\t\t=====NHAP CAN HO THU 1=====\n";
    a.Nhap();
    cout <<"\nDien tich can ho la: "<<a.TinhDienTich();
    cin.ignore();
    cout <<"\n\n\t\t=====NHAP CAN HO THU 2=====\n";
    b.Nhap();
    cout <<endl<<a.SoSanh(b);
    system("pause");
    system("cls");
    return 0;
}

void KichThuoc::Nhap () {
    do {
        cout <<"\nNhap chieu dai: ";
        cin>>dai;
        if (dai<=0) {
            cout <<"\nChieu dai khong hop le, vui long nhap lai!";
        }
    } while (dai<=0);
    do {
        cout <<"\nNhap chieu rong: ";
        cin>>rong;
        if (rong<=0||rong>dai) {
            cout <<"\nChieu rong khong hop le, vui long nhap lai!";
        }
    } while (rong<=0||rong>dai);
}

void KichThuoc::Xuat () {
    cout <<"\nChieu dai: "<<dai;
    cout <<"\nChieu rong: "<<rong;
}

int KichThuoc::TinhDienTich () {
    return dai*rong;
}

void CanHo::Nhap () {
    cout <<"\nNhap ten chu ho: ";
    getline (cin,tenchuho);
    cout <<"\n\t\tNhap kich thuoc can ho";
    kichthuoc.Nhap();
    cout <<"\nNhap so luong nguoi co ho khau trong can ho do: ";
    cin >>SoLuongNguoi;
}

int CanHo::TinhDienTich () {
    return kichthuoc.TinhDienTich();
}

int CanHo::SoSanh (CanHo a) {
    if (SoLuongNguoi>a.SoLuongNguoi) {
        return 1;
    } else if (SoLuongNguoi<a.SoLuongNguoi) {
        return 2;
    } else {
        return 0;
    }
}