#include<bits/stdc++.h>
using namespace std ;

class congty 
{
    private:
        string ten ; 
        int ntl ; 

    public:


        virtual void nhap()
        {
            cout << "Nhap ten cong ty : " ; 
            getline( cin >> ws , ten) ;
            cout << "Nhap nam thanh lap:";
            cin >> ntl ;
        }

        virtual void xuat() 
        {
            cout << ten << " || " << ntl ; 
        }

        int nam()
        {
            return ntl;
        }

};

class congtypm : public congty
{
    private:
        int sltv ;

    public: 
        void nhap() override 
        {
            congty::nhap();
            cout << "Nhap so luong lap trinh vien:";
            cin >> sltv ;
        }

        void xuat() override
        {
            congty::xuat();
            cout << " || " << sltv;  
        }

        int nam1()
        {
            return nam();
        }

        int ltv()
        {
            return sltv;
        }
};

class congtyvt : public congty
{
    private:
        int soto ;

    public: 
        void nhap() override 
        {
            congty::nhap();
            cout << "Nhap so luong o to:";
            cin >> soto ;
        }

        void xuat() override
        {
            congty::xuat();
            cout << " || " << soto;  
        }

        int nam2()
        {
            return nam();
        }

        int oto()
        {
            return soto ;
        }
};

int main()
{
    vector<congty*> ds; 
    int n , m ; 
    cout << "Nhap so luong cong ty phan mem:" ;
    cin >> n ; 
    congtypm *x = new congtypm[n] ;
    for( int i = 0 ; i < n ; i++)
    {
        x[i].nhap();
    } 
    cout << "Nhap so luong cong ty van tai:" ;
    cin >> m ; 
    congtyvt *y = new congtyvt[m] ;
    for( int i = 0 ; i < m ; i++)
    {
        y[i].nhap();
    }

    cout << "danh sach cong ty pm thanh lap sau nam 200 va co tren 20 ltv la :";
    for( int i = 0 ; i < n ; i++)
    {
        if( x[i].nam1() >= 2000 && x[i].ltv() >= 20 )
        {
            x[i].xuat();
            cout << endl ;
        }
    }

    cout << "danh sach cong ty pm thanh lap truoc nam 200 va co khong qua 10 oto la :";
    for( int i = 0 ; i < n ; i++)
    {
        if( y[i].nam2() <= 2000 && y[i].oto() <= 10 )
        {
            x[i].xuat();
            cout << endl ;
        }
    }


}