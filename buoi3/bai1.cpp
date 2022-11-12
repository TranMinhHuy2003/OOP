#include <iostream>
#include <string.h>
using namespace std;

class NgaySinh {
    private:
        int ngay,thang,nam;
    public:
        void Nhap ();
        void Xuat ();
        int TinhTuoiSV ();
        void CapNhat (int x, int y);
};

class SinhVien {
    private:
        string ten;
        string mssv;
        NgaySinh ngaysinh;
    public:
        void Nhap ();
        void Xuat ();
        int TinhTuoiSV();
        int SoSanh (SinhVien a);
        void CapNhat (int x, int y);
};

int main () {
    SinhVien a,b;
    int x,y;
    cout <<"\n\n\t\t=====NHAP SINH VIEN THU 1=====\n";
    a.Nhap();
    cout <<"\nTuoi cua sinh vien: "<<a.TinhTuoiSV();
    cin.ignore();
    cout <<"\n\n\t\t=====NHAP SINH VIEN THU 2=====\n";
    b.Nhap();
    if (a.SoSanh(b)==1) {
        cout <<"\nTuoi cua sinh vien thu 1 lon hon tuoi cua sinh vien thu 2";
    } else if (a.SoSanh(b)==0) {
        cout <<"\nTuoi cua sinh vien thu 1 nho hon tuoi cua sinh vien thu 2";
    } else {
        cout <<"\nTuoi cua sinh vien thu 1 bang tuoi cua sinh vien thu 2";
    }
    cout <<"\n\n\t\t=====CAP NHAT LAI NGAY THANG NAM SINH CUA SINH VIEN THU 1=====\n";
    cout <<"\nNhap ngay sinh: ";
    cin>>x;
    cout <<"\nNhap thang sinh: ";
    cin>>y;
    a.CapNhat(x,y);
    cout <<"\n\n\t\t=====XUAT SINH VIEN THU 1=====\n";
    a.Xuat();
    system("pause");
    system("cls");
    return 0;
}

void NgaySinh::Nhap () {
    do {
        cout <<"\nNhap ngay sinh: ";
        cin >> ngay;
        if (ngay<1||ngay>31) {
            cout <<"\nNgay khong hop le, vui long nhap lai!";
        }
    } while (ngay<1||ngay>31);
    do {
        cout <<"\nNhap thang sinh: ";
        cin >> thang;
        if (thang<1||thang>12) {
            cout <<"\nThang khong hop le, vui long nhap lai!";
        }
    } while (thang<1||thang>12);
    cout <<"\nNhap nam sinh: ";
    cin >> nam;
}

void NgaySinh::Xuat() {
    cout <<ngay<<"/"<<thang<<"/"<<nam;
}

int NgaySinh::TinhTuoiSV () {
    return 2022-nam;
}

void NgaySinh::CapNhat (int x, int y) {
    if (x>=1&&x<=31) {
        ngay=x;
    }
    if (y>=1&&y<=12) {
        thang=y;
    }
}

void SinhVien::Nhap () {
    cout <<"\nNhap ten sinh vien: ";
    getline (cin,ten);
    cout <<"\nNhap MSSV: ";
    getline (cin,mssv);
    ngaysinh.Nhap();
}

void SinhVien::Xuat () {
    cout <<"\nTen sinh vien: "<<ten;
    cout <<"\nMSSV: "<<mssv;
    cout <<"\nNgay thang nam sinh: ";
    ngaysinh.Xuat();
}

int SinhVien::TinhTuoiSV () {
    return ngaysinh.TinhTuoiSV();
}

int SinhVien::SoSanh (SinhVien a) {
    if (ngaysinh.TinhTuoiSV()>a.ngaysinh.TinhTuoiSV()) {
        return 1;
    } else if (ngaysinh.TinhTuoiSV()<a.ngaysinh.TinhTuoiSV()) {
        return 0;
    } else {
        return 2;
    }
}

void SinhVien::CapNhat(int x, int y) {
    ngaysinh.CapNhat(x,y);
}