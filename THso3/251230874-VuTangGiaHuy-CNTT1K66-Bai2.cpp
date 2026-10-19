#include<bits/stdc++.h>
using namespace std ;

class tacgia
{
    private:
        string ten ; 
        string quoctich ;
    public:
        tacgia(string ten1 = {} , string quoctich1 = {})
        {
            ten = ten1 ;
            quoctich = quoctich1 ;
        };
        ~tacgia(){};

        string qt() const 
        {
            return quoctich ;
        }

        friend istream &operator>>(istream &is, tacgia &r)
        {
            cout << "  Nhap ten tac gia: ";
            getline(is, r.ten);
            cout << "  Nhap quoc tich tac gia: ";
            getline(is, r.quoctich);
            return is;
        }

        friend ostream &operator<<(ostream &os , const tacgia &r)
        {
            os << r.ten << "(" << r.quoctich << ")" ; 
            return os ;
        }
};

class sach 
{
    private:
        string masach ;
        string tensach ;
        int nam ; 
        double gia ; 
        tacgia tg ;
    public : 
        string qt1 () const
        {
            return tg.qt() ;
        }

        friend istream &operator>>(istream &is , sach &p)
        {
            cout << "Nhap ma sach" ; getline(is,p.masach);
            cout << "Nhap ten sach" ; getline(is,p.tensach);
            cout << "Nhap nam xb" ; is >> p.nam ; 
            cout << "Nhap don gia" ; is >> p.gia ; is.ignore() ;
            cout << "Nhap tac gia" ; is >> p.tg ;

            return is ;
        }

        friend ostream &operator<<(ostream &os, const sach &p)
        {
            os << "Ma sach: " << p.masach << "\n"
            << "Ten sach: " << p.tensach << "\n"
            << "Nam XB: " << p.nam << "\n"
            << "Don gia: " << p.gia << "\n"
            << "Tac gia: " << p.tg << "\n";
            return os;
        }

        bool operator<(const sach &p) const
        {
            return this->nam < p.nam ;
        }

        bool operator>(const sach &p) const 
        {
            return this->gia > p.gia ;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << " Nhap so luong sach : " ;
    int n ; 
    cin >> n ; 
    cin.ignore();
    vector<sach>  ds(n) ;

    for( int i = 0 ; i < n ; i++)
    {
        cout << "Nhap cuon sach thu " << i + 1 << "///" ;
        cin >> ds[i] ;
    }
    // 
    sach giadau = ds[0] ;

    for( int i = 1 ; i < n ; i++)
    {
        if( giadau > ds[i])
        {
            giadau = ds[i] ;
        }
    }

    cout << "Sach co gia cao nhat la \n" << giadau ;
    // 

    sort(ds.begin(),ds.end());
    cout << "Danh sach tang dan nam san xuat la :\n" ;
    for (int i = 0; i < n; i++) {
        cout << ds[i] << "\n";
    }

    // 

    cout << "Danh sach in ra tac gia co quoc tich viet nam la \n" ;
    bool kq = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].qt1() == "Viet Nam") {
            cout << ds[i] << "\n";
            kq = true;
        }
    }
    if (!kq) {
        cout << "Khong co sach nao cua tac gia Viet Nam.\n";
    }
    return 0 ; 
}