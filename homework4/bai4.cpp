#include <iostream>
#include <string>
#define Max 100
using namespace std;

class SinhVien {
    string ten;
    int id;
    float diemtb;
    int gioitinh;
    public:
        SinhVien ();
        SinhVien (string a, int b, float c, int d);
        SinhVien (const SinhVien&x);
        void Nhap ();
        void Xuat ();
        int SoSanhDiemtb (SinhVien a);
        int KiemTraNamNu (SinhVien a);
};

class LopHoc {
    int n;
    SinhVien a[Max];
    public:
        void Nhap ();
        SinhVien TimSinhVienGioiNhat ();
        int KiemTraNamNu ();
};

int main () {
    LopHoc a;
    a.Nhap();
    SinhVien b=a.TimSinhVienGioiNhat();
    cout <<"\n\t\tTHONG TIN SINH VIEN GIOI NHAT TRONG LOP\n";
    b.Xuat();
    cout <<endl;
    if (a.KiemTraNamNu()==1) {
        cout <<"\nTrong lop, cac ban nam nu ngoi xen ke";
    } else {
        cout <<"\nTrong lop, cac ban nam nu khong ngoi xen ke";
    }
    system("pause");
    system("cls");
    return 0;
}

SinhVien::SinhVien () {
    ten="Nguyen Van A";
    id=24116;
    diemtb=9.5;
    gioitinh=1;
}

SinhVien::SinhVien (string a, int b, float c, int d) {
    ten=a;
    id=b;
    diemtb=c;
    gioitinh=d;
}

SinhVien::SinhVien (const SinhVien&x) {
    ten=x.ten;
    id=x.id;
    diemtb=x.diemtb;
    gioitinh=x.gioitinh;
}

void SinhVien::Nhap () {
    cin.ignore();
    cout <<"\nNhap ten sinh vien: ";
    getline (cin,ten);
    cout <<"\nNhap ma so sinh vien: ";
    cin >>id;
    cout <<"\nNhap diem trung binh: ";
    cin >>diemtb;
    cout <<"\nNhap gioi tinh: ";
    cin >>gioitinh;
}

void SinhVien::Xuat () {
    cout <<"\nTen sinh vien: "<<ten;
    cout <<"\nMa sinh vien: "<<id;
    cout <<"\nDiem trung binh tich luy: "<<diemtb;
    if (gioitinh==1) {
        cout <<"\nGioi tinh: Nam";
    } else {
        cout <<"\nGioi tinh: Nu";
    }
}

int SinhVien::SoSanhDiemtb (SinhVien a) {
    if (diemtb>a.diemtb) {
        return 1;
    } else if (diemtb<a.diemtb) {
        return 0;
    } else {
        return 2;
    }
}

int SinhVien::KiemTraNamNu (SinhVien a) {
    if (gioitinh!=a.gioitinh) {
        return 1;
    }
    return 0;
}

void LopHoc::Nhap () {
    do {
        cout <<"\nNhap so sinh vien trong lop: ";
        cin >>n;
        if (n<0||n>Max) {
            cout <<"\nSo luong sinh vien khong hop le, vui long nhap lai!";
        }
    } while (n<0||n>Max);
    for (int i=0; i<n; i++) {
        cout <<"\n\t\tNHAP SINH VIEN THU "<<i+1<<endl;
        a[i].Nhap();
    }
}

SinhVien LopHoc::TimSinhVienGioiNhat() {
    SinhVien max=a[0];
    for (int i=1; i<n; i++) {
        if (a[i].SoSanhDiemtb(max)==1) {
            max=a[i];
        }
    }
    return max;
}

int LopHoc::KiemTraNamNu () {
    for (int i=0; i<n-1; i++) {
        if (a[i].KiemTraNamNu(a[i+1])==0) {
            return 0;
        }
    }
    return 1;
}