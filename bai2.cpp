#include <iostream>
using namespace std;

class SinhVien {
    private:
        float nmlt;
        float toan;
    public:
        void Nhap ();
        void Xuat ();
        float dtb();
        void xeploai();
        void sosanh (SinhVien a);
        void kiemtra();
        int Tienhoclai();
};

int main () {
    SinhVien a,b;
    cout <<"\n\n\t\t=====NHAP SINH VIEN=====\n";
    a.Nhap();
    cout <<"\n\n\t\t=====XUAT SINH VIEN=====\n";
    a.Xuat();
    cout <<"\nDiem trung binh: "<<a.dtb();
    a.xeploai();
    cout <<"\n\n\t\t=====NHAP SINH VIEN DE SO SANH=====\n";
    b.Nhap();
    a.sosanh(b);
    a.kiemtra();
    cout <<"\nTien hoc lai cua sinh vien la: "<<a.Tienhoclai()<<" (d)";
    system("pause");
    system("cls");
    return 0;
}

void SinhVien::Nhap() {
    do {
        cout <<"\nNhap diem nhap mon lap trinh: ";
        cin>>nmlt;
        if (nmlt<0) {
            cout <<"\nDiem phai lon hon hoac bang 0, vui long nhap lai!";
        }
    } while (nmlt<0);
    do {
        cout <<"\nNhap diem toan: ";
        cin>>toan;
        if (toan<0) {
            cout <<"\nDiem phai lon hon hoac bang 0, vui long nhap lai!";
        }
    } while (toan<0);
}

void SinhVien::Xuat() {
    cout <<"\nDiem nhap mon lap trinh: "<<nmlt;
    cout <<"\nDiem toan: "<<toan; 
}

float SinhVien::dtb() {
    return (toan+nmlt)/2;
}

void SinhVien::xeploai() {
    if (dtb()>=8) {
        cout <<"\nLoai: Gioi";
    } else if (dtb()>=5&&toan>=5&&nmlt>=5) {
        cout <<"\nLoai: Kha";
    } else {
        cout <<"\nLoai: Yeu";
    }
}

void SinhVien::sosanh(SinhVien a) {
    if (dtb()>a.dtb()) {
        cout <<"\nDiem trung binh cua sinh vien thu 1 cao hon sinh vien thu 2";
    } else if (dtb()<a.dtb()) {
        cout <<"\nDiem trung binh cua sinh vien thu 2 cao hon sinh vien thu 1";
    } else {
        cout <<"\nDiem trung binh cua 2 sinh vien bang nhau";
    }
}

void SinhVien::kiemtra() {
    if (dtb()>=8) {
        cout <<"\nSinh vien thu 1 duoc hoc bong";
    } else {
        cout <<"\nSinh vien thu 1 khong duoc hoc bong";
    }
}

int SinhVien::Tienhoclai() {
    if (toan<5&&nmlt<5) {
        return 8000000;
    } else if (toan<5||nmlt<5) {
        return 4000000; // 1 tín chỉ 1000000d
    } else {
        return 0;
    }
}