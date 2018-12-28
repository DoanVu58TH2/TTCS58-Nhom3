#include <stdio.h>
#include <vector>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;

typedef struct {
	char sdt[11];
	char ten[20];
	char diachi[20];
	char gmail[20];
	char gioitinh[5];
} Contact;

FILE* f;
vector<Contact> db;
//
//void docDBTuFile();
//void ghiDBVaoFile();
//void ADD(Contact c);
//void XoaContact(char *sdt);
//void SuaContact(Contact contactMoi);
//void InContact(Contact c);
//void InDB();

void docDBTuFile(){
	db.clear();
	FILE *f;
	f = fopen("danhba.dat","rb");
	if(f!=NULL){
		while(!feof(f)){
			Contact c;
			fread(&c,sizeof(Contact),1,f);
			db.push_back(c);
		}
		fclose(f);
		db.pop_back();
	}
	fclose(f);
}

void ghiDBVaoFile(){
	int size = db.size();
	FILE *f;
	f = fopen("danhba.dat","wb");
	Contact c;
	for (int i = 0; i <size; i++){
		c = db[i];
		fwrite(&c,sizeof(Contact),1,f);
	}
	fclose(f);
}

void ADD(Contact c){
	db.push_back(c);
	ghiDBVaoFile();
}

void AddContact(){
	Contact Addnew;
	cout<<"Nhap ten : ";
	cin>>Addnew.ten;
	cout<<"Nhap sdt : ";
	cin>>Addnew.sdt;
	cout<<"Nhap dia chi : ";
	cin>>Addnew.diachi;
	cout<<"Nhap gmail : ";
	cin>>Addnew.gmail;
	cout<<"Nhap gioi tinh : ";
	cin>>Addnew.gioitinh;
	db.push_back(Addnew);	
	ghiDBVaoFile();
}
void InContact(Contact c){
	cout<<"So DT : "<<c.sdt<<endl;
	cout<<"Ten : "<<c.ten<<endl;
	cout<<"Gmail : "<<c.gmail<<endl;
	cout<<"Dia Chi : "<<c.diachi<<endl;
	cout<<"Gioi tinh : "<<c.gioitinh<<endl;
	cout<<"----------------------"<<endl;
}

void InDB(){
	int size = db.size();
	for(int i = 0; i < size ; i++){
		InContact(db[i]);
	}
}

void XoaContact(char *sdt){
	int a;
	
	int size=db.size();
	for(int i=0;i<size;i++){
		if(strcmp(db[i].sdt,sdt)==0){
			a=i;
			db.erase(db.begin()+a);
		}
	}
}

 
int main(){
	bool YN;
//	cout<<"=======***Tao Contact***======="<<endl;	
//	Contact c1;
//	strcpy(c1.sdt,"3456453");
//	strcpy(c1.ten, "hung");
//	strcpy(c1.gmail,"!@?ad");
//	strcpy(c1.diachi, "hung");
//	strcpy(c1.gioitinh, "nam");
//	Contact c2;
//	strcpy(c2.sdt,"123256");
//	strcpy(c2.ten, "tien");
//	strcpy(c2.gmail,"!@?ad");
//	strcpy(c2.diachi, "ádzxc");
//	strcpy(c2.gioitinh, "nu");
//	ADD(c1);
//	ADD(c2);
//	docDBTuFile();
	cout<<"=======***Danh Sach***======="<<endl;	
	docDBTuFile();
	InDB();
	cout<<"========================================================"<<endl;
	//Lua chon them DB
	cout<<"Ban Co Muon Them Danh Sach Khong??? (Y/N)"<<endl;
	cin>>YN ;
	if(YN == true){
		AddContact();	
		InDB();
	}
	//Lua chon xoa DB
	cout<<"Ban Co Muon Xoa Danh Sach Khong??? (Y/N)"<<endl;	
	cin>>YN;
	if(YN == true){
	char sdt[11];
	cout<<"nhap vao sdt can xoa : ";
	cin>>sdt;
	XoaContact(sdt);
	cout<<"danh ba sau khi sua la "<<endl;
			XoaContact(sdt);
			InDB();
		}
	
}

