#include<bits/stdc++.h>
using namespace std ;

class diem
{
    private:
        double x , y ; 
    public:
        diem( double a = 0 , double b =0 )
        {
            x = a ; 
            y = b ; 
        };
        ~diem(){};

        friend istream &operator>>(istream &is , diem &p)
        {
            is >> p.x >> p.y ;
            return is ; 
        }

        friend ostream &operator<<(ostream &os , const diem &r )
        {
            os << "(" << r.x << "," << r.y << ")" ; 
            return os ;
        }

        diem &operator=(const diem &p)
        {
            if( this != &p)
            {
                x = p.x ; 
                y = p.y ; 
            }
            return *this;
        }

        double kc(const diem &p) const
        {
            return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
        }
};

class tamgiac {
    private:
        diem d1 , d2 , d3 ; 
    public : 
        tamgiac( diem d4 = 0 , diem d5 = 0 , diem d6 = 0 )
        {
            d1 = d4 ; 
            d2 = d5 ;
            d3 = d6 ;
        }

        double chuvi() const
        {
            double a = d1.kc(d2);
            double b = d2.kc(d3);
            double c = d3.kc(d1);
            return a + b + c ;
        }

        bool kiemTraTamGiac() const {
            double a = d1.kc(d2);
            double b = d2.kc(d3);
            double c = d3.kc(d1);
            
            return (a + b > c) && (a + c > b) && (b + c > a);
        }

        double dientich() const
        {
            double a = d1.kc(d2);
            double b = d2.kc(d3);
            double c = d3.kc(d1);
            double p =( a + b + c )/2; 

            return sqrt(p*(p-a)*(p-b)*(p-c));
        }

        bool operator>(const tamgiac &p) const
        {
            return this->dientich() > p.dientich() ;
        }

        friend istream &operator>>(istream &is , tamgiac &p)
        {
            is >> p.d1 >> p.d2 >> p.d3 ; 
            return is ; 
        }

        friend ostream &operator<<(ostream &os , const tamgiac &r)
        {
            os << "Toa do cac dinh" << r.d1 << "," << r.d2 << "," << r.d3 ;
            os << "Chu vi tam giac la : " << r.chuvi() ; 
            os << "Dien tich tam giac la : " << r.dientich() ; 
            return os;
        }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    tamgiac A ,B ;
        cout << "Nhap toa do 3 dinh Tam Giac A (x1 y1 x2 y2 x3 y3): ";
    do {
        cin >> A;
        if (!A.kiemTraTamGiac()) {
            cout << " 3 diem tren khong tao thanh tam giac! Vui long nhap lai.\n\n";
        }
    } while (!A.kiemTraTamGiac());

    // Nhập và kiểm tra tam giác B
        cout << "\nNhap toa do 3 dinh Tam Giac B (x1 y1 x2 y2 x3 y3): ";
    do {
        cin >> B;
        if (!B.kiemTraTamGiac()) {
            cout << "3 diem tren khong tao thanh tam giac! Vui long nhap lai.\n\n";
        }
    } while (!B.kiemTraTamGiac());

    cout << A <<endl;

    cout << B << endl ; 

    if( A > B ) cout << "Tam giac A > Tam Giac B " << endl; 
    else if( B > A ) cout << "Tam giac B > Tam Giac A " << endl;
    else cout << "Hai tam giac ban nhau" << endl;

}