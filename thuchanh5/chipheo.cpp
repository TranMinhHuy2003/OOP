#include <iostream>
#define pi 3.14
using namespace std;

class chai
{
    public:
        virtual void Nhap () = 0;
        virtual float TinhDienTich () = 0;
        virtual float TinhLuongNuoc () = 0;
};

class chaihinhtru : public chai
{
    float chieucao;
    float bankinh;
    public: 
        void Nhap ()
        {
            cin >> chieucao >> bankinh;
        }
        float TinhDienTich ()
        {
            return 2*pi*bankinh*chieucao;
        }
        float TinhLuongNuoc ()
        {
            return pi*bankinh*bankinh*chieucao;
        }
};

class chaihinhhop : public chai
{
    float chieucao, chieudai, chieurong;
    public:
        void Nhap ()
        {
            cin >> chieucao >> chieudai >> chieurong;
        }
        float TinhDienTich ()
        {
            return 2*chieucao*(chieudai + chieurong) + 2*chieudai*chieurong;
        }
        float TinhLuongNuoc ()
        {
            return chieucao*chieudai*chieurong;
        }
};

class chailapphuong : public chai
{
    float dodaicanh;
    public:
        void Nhap ()
        {
            cin >> dodaicanh;
        }
        float TinhDienTich ()
        {
            return dodaicanh*dodaicanh*6;
        }
        float TinhLuongNuoc ()
        {
            return dodaicanh*dodaicanh*dodaicanh;
        }
};

int main ()
{
    int n;
    cin >>n;
    chai** DSChai = new chai* [n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            DSChai[i] = new chaihinhtru;
        }
        if (loai == 2)
        {
            DSChai[i] = new chaihinhhop;
        }
        if (loai == 3)
        {
            DSChai[i] = new chailapphuong;
        }
        DSChai[i]->Nhap();
    }
    float dientich = 0;
    float luongnuoc = 0;
    for (int i = 0 ; i < n ; i++)
    {
        dientich += DSChai[i]->TinhDienTich();
        luongnuoc += DSChai[i]->TinhLuongNuoc();
    }
    cout <<"Dien tich chai vo: "<<dientich;
    cout <<"\nLuong nuoc tren mat dat: "<<luongnuoc*0.1;
    system ("pause");
    system ("cls");
    return 0;
}