#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
    float phanthuc;
    float phanao;
    public:
        void Nhap();
        void Xuat();
        SoPhuc Cong2SoPhuc (SoPhuc a);
        SoPhuc Tru2SoPhuc (SoPhuc a);
        SoPhuc Nhan2SoPhuc (SoPhuc a);
        SoPhuc Chia2SoPhuc (SoPhuc a);
        SoPhuc Nhan1SoVoiSoPhuc (float x);
        float TinhModuleSoPhuc ();
};

int main () {
    SoPhuc a,b;
    a.Nhap();
    b.Nhap();
    if (a.TinhModuleSoPhuc()==0||b.TinhModuleSoPhuc()==0) {
        cout <<"\nERROR";
        return 0;
    }
    SoPhuc A;
    A=(a.Cong2SoPhuc(b)).Nhan2SoPhuc((b.Cong2SoPhuc(a.Nhan1SoVoiSoPhuc(-2)))).Chia2SoPhuc((a.Cong2SoPhuc(b.Nhan1SoVoiSoPhuc(-4))));
    A.Xuat();
    system("pause");
    system("cls");
    return 0;
}

void SoPhuc::Nhap() {
    cin >>phanthuc;
    cin >>phanao;
}

void SoPhuc::Xuat() {
    if (phanao>0) {
        if (phanthuc==0) {
            cout <<phanao<<"i";
        } else {
            cout <<phanthuc<<" + "<<phanao<<"i";
        }
    } else if (phanao==0) {
        cout <<phanthuc;
    } else if(phanao<0) {
        if (phanthuc==0) {
            cout <<phanao<<"i";
        } else if (phanthuc<0) {
            cout <<phanthuc<<" - "<<-1*phanao<<"i";
        }
    } 
}

SoPhuc SoPhuc::Cong2SoPhuc(SoPhuc a) {
    SoPhuc b;
    b.phanthuc=phanthuc+a.phanthuc;
    b.phanao=phanao+a.phanao;
    return b;
}

SoPhuc SoPhuc::Tru2SoPhuc(SoPhuc a) {
    SoPhuc b;
    b.phanthuc=phanthuc-a.phanthuc;
    b.phanao=phanao-a.phanao;
    return b;
}

SoPhuc SoPhuc::Nhan2SoPhuc(SoPhuc a) {
    SoPhuc b;
    b.phanthuc=phanthuc*a.phanthuc-phanao*a.phanao;
    b.phanao=phanthuc*a.phanao+phanao*a.phanthuc;
    return b;
}

SoPhuc SoPhuc::Chia2SoPhuc(SoPhuc a) {
    SoPhuc b;
    b.phanthuc=(phanthuc*a.phanthuc+phanao*a.phanao)/(a.phanthuc*a.phanthuc+a.phanao*a.phanao);
    b.phanao=(a.phanthuc*phanao-phanthuc*a.phanao)/(a.phanthuc*a.phanthuc+a.phanao*a.phanao);
    return b;
}

SoPhuc SoPhuc::Nhan1SoVoiSoPhuc(float x) {
    SoPhuc b;
    b.phanthuc=x*phanthuc;
    b.phanao=x*phanao;
    return b;
}

float SoPhuc::TinhModuleSoPhuc() {
    return pow(phanthuc*phanthuc+phanao*phanao,0.5);
}
