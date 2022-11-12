#include <iostream>
#include <cmath>
using namespace std;

class ChuNhat {
    float dai,rong;
    static int dem;
    public:
        ChuNhat () {
            dai=2;
            rong=1;
            dem++;
        }
        ChuNhat (float x, float y) {
            dai=x;
            rong=y;
            dem++;
        }
        ChuNhat (const ChuNhat &x) {
            dai=x.dai;
            rong=x.rong;
            dem++;
        }
        static void count () {
            cout <<dem<<endl;
        }
        static float TinhTongBP (float x, float y) {
            return x*x+y*y;
        }
        float TinhDuongCheo () {
            return pow(TinhTongBP(dai,rong), 0.5);
        }
};

int ChuNhat::dem=0;

int main () {
    ChuNhat a;
    ChuNhat b(3,2);
    ChuNhat c(b);
    cout <<"\nSo luong doi tuong thuoc lop ChuNhat: ";
    ChuNhat::count();
    cout <<"\nDuong cheo = "<<b.TinhDuongCheo();
    system("pause");
    system("cls");
    return 0;
}