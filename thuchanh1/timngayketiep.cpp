#include <iostream>
using namespace std;

class ThoiGian {
    int ngay, thang, nam;
    public:
        void Nhap ();
        void Xuat ();
        void XuatNgayKeTiep ();
        int KiemTra ();
};

int main () {
    ThoiGian t;
    t.Nhap();
    if (t.KiemTra()==0) {
        cout <<"ERROR";
    } else {
        t.XuatNgayKeTiep();
        t.Xuat();
    }
    system("pause");
    system("cls");
    return 0;
}

void ThoiGian::Nhap () {
    cin >>ngay;
    cin>>thang;
    cin>>nam;
}

void ThoiGian::Xuat () {
    cout <<ngay<<"/"<<thang<<"/"<<nam;
}

int ThoiGian::KiemTra () {
    int ngaymax;
    if (nam<=0 || thang<=0 || thang> 12 || ngay<=0 || ngay> 31)
    {
        return 0;
    }
    else
    {
        switch (thang)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              ngaymax=31;
              break;
            case 2:
                if ((nam%4==0 && nam%100!=0) || (nam%400==0))
                    ngaymax=29;
                else 
                    ngaymax=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ngaymax=30;
                break;
        }
        if (ngay<=ngaymax)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void ThoiGian::XuatNgayKeTiep () {
    if (ngay==31&&thang==12) {
        ngay=thang=1;
        nam+=1;
    } else if (thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12) {
        if (ngay==31) {
            ngay=1;
            thang+=1;
        } else {
            ngay+=1;
        }
    } else if (thang==4||thang==6||thang==9||thang==11) {
        if (ngay==30) {
            ngay=1;
            thang+=1;
        } else {
            ngay+=1;
        }
    } else if (thang==2) {
        if ((nam%4==0 && nam%100!=0) || (nam%400==0)) {
            if (ngay==29) {
                ngay=1;
                thang+=1;
            } else {
                ngay+=1;
            }    
        } else {
            if (ngay==28) {
                ngay=1;
                thang+=1;
            } else {
                ngay+=1;
            }
        }
    } else {
        ngay+=1;
    }
}