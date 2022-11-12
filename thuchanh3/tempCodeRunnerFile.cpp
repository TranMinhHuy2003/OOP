#include <iostream>
#include <cmath>
#include <string.h>
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
            os<<x.gio<<" "<<x.phut<<" "<<x.giay;
            return os;
        }
        void ChuanHoa ()
        {
            gio = abs(gio);
            phut = abs(phut);
            giay = abs(giay);
            if (gio > 24)
            {
                gio = gio % 24;
            }
        }
        static Time GiaySangTime (int x)
        {
            Time a;
            a.gio = x / 3600;
            int y = x - a.gio * 3600;
            a.phut = y / 60;
            a.giay = y - a.phut * 60;
            return a;
        }
        Time operator++ ()
        {
            int y = gio * 3600 + phut * 60 + giay + 1;
            return Time::GiaySangTime(y);
        }
        Time operator-- ()
        {
            int y = gio * 3600 + phut * 60 + giay - 1;
            return Time::GiaySangTime(y);
        }
        Time operator+ (int x)
        {
            int y = gio * 3600 + phut * 60 + giay + x;
            return Time::GiaySangTime(y);
        }
        Time operator- (int x)
        {
            int y = gio * 3600 + phut * 60 + giay - x;
            return Time::GiaySangTime(y);
        }
        void XuLy ()
        {
            Time a;
            cin>>a;
            a.ChuanHoa();
            int n;
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                string x;
                int b;
                cin>>x;
                if (x == "++")
                {
                    a++;
                }
                if (x == "--")
                {
                    a--;
                }
                if (x == "+" || x == "-")
                {
                    cin >>b;
                    if (x == "+")
                    {
                        a = a + b;
                    }
                    if (x == "-")
                    {
                        a = a - b;
                    }
                }
            }
            cout <<a;
        }
};

int main () 
{
    Time a;
    a.XuLy();
    system("pause");
    system("cls");
    return 0;
}