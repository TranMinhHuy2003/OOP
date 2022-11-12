#include <iostream>
#include <string>
using namespace std;

class DiemSo {
    float nmlt;
    float oop;
    public: 
        DiemSo () {
            nmlt=10;
            oop=10;
            cout <<1;
        }
        DiemSo (float a, float b) {
            nmlt=a;
            oop=b;
            cout <<2;
        }
        DiemSo (const DiemSo &a) {
            nmlt=a.nmlt;
            oop=a.oop;
            cout <<3;
        }
};

class SinhVien {
    string ten;
    string mssv;
    DiemSo diem;
    public:
        SinhVien () {
            ten="Nguyen Van A";
            mssv="12345";
            cout <<4;
        }
        SinhVien (string a, string b, float c, float d) : diem(c,d), ten(a), mssv(b) {
            cout <<5;
        }
        SinhVien (string a, string b, DiemSo x) : diem(x), ten(a), mssv(b) {
            cout <<6;
        }
        SinhVien (const SinhVien &x) : diem(x.diem), ten(x.ten), mssv(x.mssv) {
            cout <<7;
        }
};

int main () {
    SinhVien a;
    SinhVien b("Nguyen Van A", "12345", 10, 10);
    DiemSo d;
    SinhVien c ("Tran Van B", "34467", d);
    SinhVien e (c);
    system("pause");
    system("cls");
    return 0;
}