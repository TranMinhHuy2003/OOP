#include <iostream>
#include <cmath>
#define Max 100
using namespace std;

class Diem {
    float hoanh,tung;
    public:
        void Nhap () {
            cin>>hoanh>>tung;
        }
        float Polygon (Diem a) {
            return (hoanh*a.tung-tung*a.hoanh)/2;
        }
};

class DaGiac {
    Diem a[Max];
    int n;
    public:
        void Nhap () {
            do {
                cin>>n;
            } while (n<=2);
            for (int i=0; i<n; i++) {
                a[i].Nhap();
            }
        }
        float Polygon () {
            float sum=0;
            for (int i=0; i<n-1; i++) {
                sum+=a[i].Polygon(a[i+1]);
            }
            sum+=a[n-1].Polygon(a[0]);
            return abs(sum);
        }
};

int main () {
    DaGiac a;
    a.Nhap();
    cout <<a.Polygon();
    system("pause");
    system("cls");
    return 0;
}