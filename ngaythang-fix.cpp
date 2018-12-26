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

int STTDInYr(NgayThang n){
	int count = n.Ngay;
	for (int i = 1 ; i<= n.Thang - 1; i++){
		count = count + SoNgay(i,n.Nam);
	}
	return count;
}


//	int stttrongnam(ngaythang x); = STTDInYr(NgayThang n)
int NgayTuSTT(int stt,NgayThang n){
	
 	int thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 	stt = 0;
 	for (int i=1;i<n.Thang;i++)
 		stt += thang[i];
 	stt += n.Ngay;
 	if (n.Thang>2)
 	if (CheckNhuan(n.Nam)) stt+=1;
 	return stt;	
 }	
NgayThang ADD(NgayThang n,int x){

	
	int kq = x + STTDInYr(n);
	int nam = n.Nam;
	if(kq <= 365){
		return NgayTuSTT(kq,nam);
		}
		else 
			if(CheckNhuan(nam) == 1)
				if(kq == 366)
					return NgayTuSTT(kq,nam);
				else return NgayTuSTT(kq-366,nam+1);
			else return NgayTuSTT(kq-365,nam+1);
}



int main(){
	string st;
	NgayThang x;
	char t[4];
	do{
	cout<<"Nhap vao ngay thang (dd/mm/yyyy) : ";
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
	
	}
	while(NgayHopLe(x.Ngay,x.Thang,x.Nam) == 0);
	if(CheckNhuan(x.Nam)){
		cout<<"Nam " <<x.Nam<<" la nam nhuan!"<<endl;
		
	}
	else {
		cout<<"Nam "<<x.Nam<<" ko la nam nhuan!"<<endl;
	}
	if (NgayHopLe(x.Ngay,x.Thang,x.Nam))
	{
		int count = STTDInYr(x);
		cout<<"Ngay thu : " <<count<<endl;
	}
	else{
		cout<<"Ngay ko hop le!"<<endl;
	}
}
