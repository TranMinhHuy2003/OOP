class Diem{
	int iX;
	int iY;
public:
	Diem(int x, int y)
	{
		iX=x;
		iY=y;
	}
	Diem(const Diem &x)
	{
		iX=x.iX;
		iY=x.iY;
	}
};
void main(){
	Diem a[10];	
}
