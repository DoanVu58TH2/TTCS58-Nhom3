#include <stdio.h>
#include <vector>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;

fstream fi;
int n;
//DocFile
void DocFile(int a[10][10]){
	fi.open("dothi.txt",ios::in);
	fi>>n;
	
	for(int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++)
			fi>>a[i][j];
	}
	fi.close();
}

//Xuat du lieu

void XuatDoThi(int a[10][10]){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout <<a[i][j]<<" ";
		cout<<endl;			
	}
	fi.close();
}

void TaoMoi(int a[10][10],int &n){
	cout<<"Nhap n "; cin>>n;
	fi.open("dothi.txt",ios::out);
	fi<<n<<"\n";
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<"A["<<i<<"]["<<j<<"] : ";
			cin>>a[i][j];
			fi<<a[i][j]<<" ";
		}
		fi<<endl;
	}
	fi.close();
}
int main(){
	int a[10][10];

	DocFile(a);
	XuatDoThi(a);
	TaoMoi(a,n);
	XuatDoThi(a);
}
