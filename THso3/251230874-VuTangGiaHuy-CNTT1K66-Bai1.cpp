#include<bits/stdc++.h>
using namespace std ;

class sophuc
{
private:
    double thuc ; 
    double ao ; 
public:
    // Ham Khoi Tao
    sophuc(double a = 0 , double b = 0)
    {
        thuc = a;
        ao = b;
    };

    // Ham copy
    sophuc(const sophuc &r)
    {
        thuc = r.thuc;
        ao = r.ao;
    }
    
    // Nap chong xuat
    friend ostream &operator<<(ostream &os , const sophuc &p)
    {
        os << p.thuc << " + " << p.ao << "i" ;
        return os;
    }

    // nap chong nhap
    friend istream &operator>>(istream &is , sophuc &t)
    {
        is >> t.thuc >> t.ao ;
        return is ;
    }

    // toan tu gan 
    sophuc &operator=(const sophuc &r)
    {
        if( this != &r) {
            thuc = r.thuc ; 
            ao = r.ao ;
        }
        return *this;
    }

    // toan tu cong 
    sophuc operator+(const sophuc &r) const {
        return sophuc(thuc + r.thuc, ao + r.ao);
    }
    //toan tu hieu
    sophuc operator-(const sophuc &r) const {
        return sophuc(thuc - r.thuc, ao - r.ao);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sophuc A , B ;

    cin >> A ;
    cin >> B ; 
    
    sophuc C ; 
    C = A ;

    sophuc D(B) ;

    cout << A << endl; 
    cout << B << endl;
    cout << C <<endl ;
    cout << D <<endl;

    cout << "Tong A+B : " << (A + B) << endl;
    cout << "Hieu A-B : " << (A - B) << endl;

}