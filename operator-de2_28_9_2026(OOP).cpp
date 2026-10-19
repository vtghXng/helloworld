#include<bits/stdc++.h>
using namespace std ; 

class daythuc
{
    int n ; 
    float *p ;
    public: 
        friend void nhap(daythuc &d);
        friend ostream&operator<<(ostream &,daythuc &);
        void thongke();
};
void nhap(daythuc &d)
{
    cout <<"Nhap so phan tu";cin >> d.n ;
    d.p=new float[d.n];
    for( int i = 0 ; i < d.n ; i++ )
    {
        cout << "Nhap pt thu " << i+1 << ":" ;
        cin >> d.p[i];
    }
}
ostream&operator<<(ostream &os,daythuc &d)
{
    for( int i = 0 ; i < d.n ; i++)
    {
        cout << d.p[i] << " " ;
    }
    return os; 
}
void daythuc::thongke()
{
    int dem = 0 ; 
    for( int i = 0 ; i < n - 2 ; i++)
    {
        if(p[i]+p[i+2]==2*p[i+1]||p[i]+p[i+1]==2*p[i+2]||2*p[i]==p[i+1]+p[i+2])
        {
            dem++;
            cout<<p[i]<<" "<<p[i+1]<<" "<<p[i+2]<<endl; 
        }
    }
    cout << "\nCo " << dem << " bo lap thanh cap so cong \n" ; 
}
int main()
{
    daythuc dt ;
    nhap(dt);
    cout << dt << endl ;
    dt.thongke();
}