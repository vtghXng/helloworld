#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef struct monhoc{
	string ma, ten;
	int tc ; 
	float diem;
};

istream & operator>>(istream &nhap , monhoc &x)
        {
            cout << "Nhap ma mon hoc\n" ; getline(nhap,x.ma) ; 
            cout << "Nhap ten mon hoc\n" ; getline(nhap,x.ten) ; 

            cout << "Nhap so tin chi \n" ; cin >> x.tc ;
            cout << "Nhap diem tin chi\n" ; cin >> x.diem;

        return nhap; 
}

ostream & operator<<(ostream &xuat , monhoc &x)
{
    cout << "Ma" << "Ten MonHoc" << "TinC" << "Diem" << endl;
    xuat << setw(5) << x.ma << setw(5) << x.ten << setw(5) << x.tc << setw(5) << x.diem ;
    return xuat ;
}

bool operator>(const monhoc &m1 , const monhoc &m2){
    
}

int main()
{
    monhoc A ;
    cin >> A ;
    cout << A ;
}