#include <iostream>
#include <string>
using namespace std;

class HocSinh {
    string ten;
    float diemtoan;
    float diemvan;
    public:
        void Nhap();
        void Xuat(float x);
        float TinhDiemtb();
};

int main () {
    HocSinh a;
    a.Nhap();
    float x=a.TinhDiemtb();
    a.Xuat(x);
    system("pause");
    system("cls");
    return 0;
}

void HocSinh::Nhap() {
    getline (cin,ten);
    do {
        cin>>diemtoan;
        cin>>diemvan;
    } while (diemtoan<0||diemtoan>10||diemvan<0||diemvan>10);
}

float HocSinh::TinhDiemtb() {
    return (diemtoan+diemvan)/2;
}

void HocSinh::Xuat(float x) {
    cout <<"Thong tin hoc sinh:";
    cout <<"\nHo ten: "<<ten;
    cout <<"\nDiem toan: "<<diemtoan;
    cout <<"\nDiem van: "<<diemvan;
    cout <<"\nDiem trung binh: "<<x;
}