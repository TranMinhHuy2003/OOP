#include <iostream>
#include <string.h>
using namespace std;

class Candidate {
    string ma;
    string hoten;
    string ngaysinh;
    int diemtoan;
    int diemvan;
    int diemanh;
    static int dem;
    int stt;
    public:
        void Nhap () {
            cin.ignore();
            getline (cin,ma);
            getline (cin,hoten);
            getline (cin, ngaysinh);
            do {
                cin >>diemtoan;
                cin >>diemvan;
                cin >>diemanh;
            } while (diemanh<0||diemanh>10||diemtoan<0||diemtoan>10||diemvan<0||diemvan>10);
            stt=dem;
            dem++;
        }
        int TinhTongDiem () {
            return diemanh+diemtoan+diemvan;
        }
        void Xuat () {
            cout << "-" << endl;
            cout << "STT " << stt << ":" << endl;
            cout << "Thong tin hoc sinh:" << endl;
            cout << "Ma: " << ma << endl;
            cout << "Ho ten: " << hoten << endl;
            cout << "Ngay sinh: " << ngaysinh << endl;
            cout << "Diem toan: " << diemtoan << endl;
            cout << "Diem van: " << diemvan << endl;
            cout << "Diem anh: " << diemanh << endl;
        }
};

int Candidate::dem=1;

int main () {
    int n;
    cin>>n;
    int dem=0;
    for (int i=0; i<n; i++) {
        Candidate a;
        a.Nhap();
        if (a.TinhTongDiem()>15) {
            a.Xuat();
            dem++;
        }
    }
    if (dem==0) {
        cout <<"Khong co thi sinh co tong diem lon hon 15"<<endl;
    }
    system("pause");
    system("cls");
    return 0;
}