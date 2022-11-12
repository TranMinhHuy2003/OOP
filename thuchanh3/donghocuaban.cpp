#include <iostream>
#include <cmath>
using namespace std;

class Time
{
    int gio,phut,giay;
    public:
        friend istream& operator>> (istream &is, Time &x)
        {
            is>>x.gio>>x.phut>>x.giay;
            return is;
        }
        friend ostream& operator<< (ostream &os, Time x)
        {
            os<<x.gio<<"h "<<x.phut<<"p "<<x.giay<<"s";
            return os;
        }
        void ChuanHoa ()
        {
            if (giay < 0)
            {
                if (giay < -60)
                {
                    giay = giay * (-1);
                } 
                else 
                {
                    giay = 60 + giay;
                    phut = phut - 1;
                }
            }
            if (phut < 0)
            {
                if (phut < -60)
                {
                    phut = phut * (-1);
                }
                else
                {
                    phut = 60 + phut;
                    gio = gio - 1;
                }
            }
            if (gio < 0)
            {
                gio = gio * (-1);
            }
            if (giay >= 60)
            {
                int t = giay;
                giay = t % 60;
                phut = phut + t / 60;
            }
            if (phut >= 60)
            {
                int t = phut;
                phut = t % 60;
                gio = gio + t / 60;
            }
            if (gio > 24)
            {
                gio = gio % 24;
            }
        }
        Time operator+ ()
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay + 1;
            return kq;
        }
        Time operator- ()
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay - 1;
            return kq;
        }
        Time operator+ (int x)
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay + x;
            return kq;
        }
        Time operator- (int x)
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay - x;
            return kq;
        }
        void Menu ()
        {
            Time a;
            cin>>a;
            a.ChuanHoa();
            while (true) 
            {
                int luachon;
                cin>>luachon;
                if (luachon==1) 
                {
                    a = a + 1;
                } 
                else if (luachon==2) 
                {
                    a = a - 1;
                } 
                else if (luachon==3) 
                {
                    int x;
                    cin>>x;
                    a = a + x;
                } 
                else if (luachon==4) 
                {
                    int x;
                    cin>>x;
                    a = a - x;
                }
                else if (luachon==-1)
                {
                    a.ChuanHoa();
                    cout <<a;
                    break;
                }
            }
        }
};

int main () 
{
    Time a;
    a.Menu();
    system("pause");
    system("cls");
    return 0;
}