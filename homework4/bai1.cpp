#include <iostream>
using namespace std;

class NgaySinh {
    int ngay,thang,nam;
    public:
        NgaySinh ();
        NgaySinh (int a, int b, int c);
        NgaySinh (const NgaySinh &x);
};

int main () {
    NgaySinh a;
    NgaySinh b(17,3,2022);
    NgaySinh c(b);
    system("pause");
    system("cls");
    return 0;
}

NgaySinh::NgaySinh() {
    ngay=17;
    thang=3;
    nam=2022;
}

NgaySinh::NgaySinh(int a, int b, int c) {
    ngay=a;
    thang=b;
    nam=c;
}

NgaySinh::NgaySinh(const NgaySinh &x) {
    ngay=x.ngay;
    thang=x.thang;
    nam=x.nam;
}