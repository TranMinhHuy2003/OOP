#include <iostream>
#include <cmath>
using namespace std;

class ThoiGian {
    int ngay, thang, nam;
    public:
        int CheckDayOfmonth ()
        {
            if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
            {
                return 31;
            } 
            else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            {
                return 30;
            }
            else if (thang == 2)
            {
                if ((nam%4==0 && nam%100!=0) || (nam%400==0))
                {
                    return 29;
                }
            }
            return 28;
        }
        void Nhap () 
        {
            cin >>ngay;
            cin>>thang;
            cin>>nam;
        }
        void ChuanHoa ()
        {
            ngay = abs(ngay);
            thang = abs(thang);
            nam = abs(nam);
            thang = thang % 12;
            if (thang == 0)
            {
                thang = 12;
            }
            if (ngay > CheckDayOfmonth())
            {
                ngay = 1;
            }
        }
        void Xuat (int x)
        {
            cout <<x;
        }
        ThoiGian Tang (int x)
        {
            ThoiGian kq;
            kq.ngay = ngay + x;
            kq.thang = thang;
            kq.nam = nam;
            return kq;
        }
        ThoiGian Giam (int x)
        {
            ThoiGian kq;
            kq.ngay = ngay - x;
            kq.thang = thang;
            kq.nam = nam;
            return kq;
        }
        int ThoiGianSangNgay ()
        {
            if (thang < 3)
            {
                nam--; 
                thang += 12;
            }
            return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * thang - 457)/5 + ngay - 306;
        }
        int TinhSoNgay (ThoiGian x)
        {
            return abs(x.ThoiGianSangNgay() - ThoiGianSangNgay());
        }
        void Menu ()
        {
            ThoiGian t;
            t.Nhap();
            t.ChuanHoa();
            while (true) 
            {
                int luachon;
                cin>>luachon;
                if (luachon==1) 
                {
                    int x;
                    cin>>x;
                    t = t.Tang(x);
                } 
                else if (luachon==2) 
                {
                    int x;
                    cin>>x;
                    t = t.Giam(x);
                } 
                else if (luachon==3) 
                {
                    ThoiGian b;
                    b.Nhap();
                    b.ChuanHoa();
                    int a = t.TinhSoNgay(b);
                    cout <<a;
                    break;
                } 
            }
        }
};

int main () {
    ThoiGian a;
    a.Menu();
    system("pause");
    system("cls");
    return 0;
}