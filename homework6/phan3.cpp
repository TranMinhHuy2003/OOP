#include <iostream>
#include <string.h>
using namespace std;

class DuKhach {
    static int maso;
    int id;
    int cccd;
    string ten;
    int namsinh;
    int namgannhat;
    public:
        void Nhap ()
        {
            id=maso;
            cout <<"\nNhap so cmnd (cccd): ";
            cin>>cccd;
            cin.ignore();
            cout <<"\nNhap ten: ";
            getline(cin,ten);
            cout <<"\nNhap nam sinh: ";
            cin>>namsinh;
            cout <<"\nNhap nam gan nhat ghe tham KDL: ";
            cin>>namgannhat;
            maso++;
        }
        bool CheckYear (int x) {
            if ((x%400==0)||(x%4==0&&x%100!=0)) {
                return true;
            }
            return false;
        }
        void KiemTraNamSinh () {
            bool t=CheckYear(namsinh);
            if (t) {
                cout <<"\nNam sinh la nam nhuan";
            } else {
                cout <<"\nNam sinh khong la nam nhuan";
            }
        }
        void KiemTraNamGanNhat () {
            bool t=CheckYear(namgannhat);
            if (t) {
                cout <<"\nNam gan nhat ghe KDL cua du khach la nam nhuan";
            } else {
                cout <<"\nNam gan nhat ghe KDL cua du khach khong la nam nhuan";
            }
        }
};

int DuKhach::maso=1;

int main () {
    DuKhach a;
    a.Nhap();
    a.KiemTraNamSinh();
    a.KiemTraNamGanNhat();
    system("pause");
    system("cls");
    return 0;
}