#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NgayThang{
	int Ngay,Thang,Nam;
};

int CheckNhuan(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	}
		return 0;
}

int SoNgay(int mm,int year){	
	int daymax;
	switch(mm){
		case 1: case 3: case 5: case 7: case 8: case 10 : case 12:
			daymax= 31;
			break;
		case 4: case 6 : case 9 : case 11 :
			daymax = 30;
			case 2:
				if(CheckNhuan(year))
					daymax = 29;
				else daymax = 28;
				break;
	}
	return daymax;
}

int NgayHopLe(int Day,int MM, int YY){
	int a = 1;
	if(!(YY > 0 && MM)){
		a = 0;
	}
	if(!(MM >=1 && MM <=12)){
		a = 0;
	}
	if(!(Day >= 1 && Day <= SoNgay(MM,YY))){
		a = 0;
	}
	return a;
}

int STTDayInYear(int dd, int mm,int yy){
	int count = dd;
	for (int i = 1 ; i<= mm - 1; i++){
		count = count + SoNgay(i,yy);
	}
	return count;
}

void CongThem(NgayThang &N){
	int n;
	cout <<"\nNhap vao so nguyen duong : ";
	cin >>n;
	while(n != 0){
		if((N.Ngay<31 &&(N.Thang==1 || N.Thang==3 || N.Thang==5 || N.Thang==7 || N.Thang==8 || N.Thang==10 || N.Thang==12)) || (N.Ngay < 30 && (N.Thang==4 || N.Thang==6||N.Thang == 9))|| (N.Ngay<29 && CheckNhuan(N.Nam))|| (N.Ngay<28 && CheckNhuan(N.Nam)==false) )
			N.Ngay++;
		else{
			if(N.Thang < 12){
				N.Thang++;
				N.Ngay = 1;	
			}
			else{
				N.Nam++;
				N.Thang = 1;
				N.Ngay = 1;
			}
}	n--;
	}
}

void TruRa(NgayThang &N){
	int n;
	cout <<"\nNhap vao so nguyen duong : ";
	cin >>n;
		while(n != 0)
		{
			if( N.Ngay> 1 )
				N.Ngay--;
			else
			{
				if(N.Thang >1)
				{
					N.Thang--;
					if(N.Thang == 1 || N.Thang == 3 || N.Thang == 5 || N.Thang == 7 || N.Thang == 8 || N.Thang ==10 || N.Thang == 12)
						N.Ngay = 31;
					else
						if(N.Thang == 4 || N.Thang == 6 || N.Thang == 9 || N.Thang == 11)
						N.Ngay = 30;
						else
							{
							if(CheckNhuan(N.Nam))
							N.Ngay = 29;
							else
							N.Ngay = 28;
						}
		
				}
				else{
				N.Nam --;
				N.Thang = 12;
				N.Ngay = 31;
			}
			}
				n--;
		}
}

void InNgay(NgayThang n){
	cout<<n.Ngay<<"/"<<n.Thang<<"/"<<n.Nam;
}
int main(){
	string st;
	NgayThang x;
	char t[4];
	
	cout<<"Nhap vao Ngay thang (dd/mm/yyyy) : ";
	getline(cin,st);
	
	t[0] = st[0];
	t[1] = st[1]; 
	x.Ngay = atoi(t);
	
	t[0] = st[3];
	t[1] =st[4];
	x.Thang = atoi(t);
	
	t[0] = st[6];
	t[1] = st[7];
	t[2] = st[8];
	t[3] = st[9];
	x.Nam = atoi(t);
	
	if(CheckNhuan(x.Nam)){
		cout<<"Nam " <<x.Nam<<" la Nam nhuan!"<<endl;
		
	}
	else {
		cout<<"Nam "<<x.Nam<<" ko la Nam nhuan!"<<endl;
	}
	if (NgayHopLe(x.Ngay,x.Thang,x.Nam))
	{
		int count = STTDayInYear(x.Ngay,x.Thang,x.Nam);
		cout<<"Ngay thu : " <<count<<endl;
	}
	else{
		cout<<"\nNgay ko hop le!"<<endl;
	}
	
	
	CongThem(x);
	cout<<"\nNgay sau khi cong them la :";
	InNgay(x);
	TruRa(x);
	cout<<"\nNgay sau khi tru ra la : ";
	InNgay(x);
}
