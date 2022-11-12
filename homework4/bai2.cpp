#include <iostream>
#include <string>
using namespace std;

class DienThoai {
    string maso;
    float sotien;
    bool bluetooth;
    public:
        DienThoai ();
        DienThoai (string a, float b, bool c);
        DienThoai (const DienThoai &x);
};

int main () {
    DienThoai a;
    DienThoai b("1234",100000,1);
    DienThoai c(b);
    system("pause");
    system("cls");
    return 0;
}

DienThoai::DienThoai () {
    maso="1234";
    sotien=100000;
    bluetooth=1;
}

DienThoai::DienThoai (string a, float b, bool c) {
    maso=a;
    sotien=b;
    bluetooth=c;
}

DienThoai::DienThoai (const DienThoai&x) {
    maso=x.maso;
    sotien=x.sotien;
    bluetooth=x.bluetooth;
}