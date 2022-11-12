#include <iostream>
using namespace std;

class CongTy 
{
    string ten;
    int luongcanban, sosanpham, songaylam, luong;
    static int SANPHAM;
    static int NGAYLAM;
    public:
        void Nhap (int n)
        {
            cin >> ten;
            if (n == 1)
            {
                cin >> luongcanban >> sosanpham;
                luong = luongcanban + sosanpham * 5;
                SANPHAM += sosanpham;
            }
            else if (n == 2)
            {
                cin >> songaylam;
                luong = songaylam * 100;
                NGAYLAM += songaylam;
            }
            else if (n == 3)
            {
                luong = 100 + SANPHAM * 2 + NGAYLAM * 40;
            }
        }
        void Xuat ()
        {
            cout << ten << ": " << luong << endl;
        }

};

int CongTy::SANPHAM = 0;
int CongTy::NGAYLAM = 0;

int main ()
{
    CongTy a[100];
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        a[i].Nhap(x);
    }
    for (int i = 0 ; i < n ; i++)
    {
        a[i].Xuat();
    }
    system ("pause");
    system ("cls");
    return 0;
}