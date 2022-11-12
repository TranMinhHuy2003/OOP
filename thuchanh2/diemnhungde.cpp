#include <iostream>
using namespace std;

class Diem {
    float hoanh,tung;
    public:
        void Nhap () {
            cin>>hoanh>>tung;
        }
        void NhanDoi () {
            hoanh=hoanh*2;
            tung=tung*2;
        }
        void GanVeGocToaDo () {
            hoanh=0;
            tung=0;
        }
        void TinhTien (int o, int d) {
            if (o==0) {
                hoanh=hoanh+d;
            } else {
                tung=tung+d;
            }
        }
        void Xuat () {
            cout <<"("<<hoanh<<","<<tung<<")";
        }
        void Menu () {
            int dem;
            cin>>dem;
            while (dem!=0) {
                int x;
                cin>>x;
                if (x==1) {
                    NhanDoi();
                } else if (x==2) {
                    GanVeGocToaDo();
                } else if (x==3) {
                    int o,d;
                    cin>>o>>d;
                    TinhTien(o,d);
                } 
                dem--;
            }
        }
};

int main () {
    Diem a;
    a.Nhap();
    a.Menu();
    a.Xuat();
    system ("pause");
    system ("cls");
    return 0;
}