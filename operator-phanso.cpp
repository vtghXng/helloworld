#include<bits/stdc++.h>
using namespace std ; 

class ps 
{
    private:
        int ts , ms ;
    public:
        ps( int a = 0 , int b = 0 )
        {
            ts = a ; 
            ms = (b==0)?1 : b ;
            rutgon();
        }
        ~ps(){};

        friend istream &operator>>(istream &is,ps &p)
        {
            is >> p.ts >> p.ms ;
            p.rutgon();
            return is ;
        }

        friend ostream &operator<<(ostream &os,ps &r)
        {
            os << r.ts << "/" << r.ms ;
            return os;
        }

        void rutgon()
        {
            int ucln = __gcd(ts,ms);
            this->ts /= ucln ;
            this->ms /= ucln;

            if( this->ms < 0 )
            {
                this->ts *= -1 ;
                this->ms *= -1 ;
            }
        }

        ps operator+(const ps &r) const
        {
            int msc = ms * r.ms ;
            int psm = ts * r.ms + ms * r.ts ;

            return ps(psm,msc);
        }

        ps operator-(const ps &r) const
        {
            int msc = ms * r.ms ;
            int psm = ts * r.ms - ms * r.ts ;

            return ps(psm,msc);
        }

        ps operator*(const ps &r) const
        {
            return ps(ts*r.ts,ms*r.ms);
        }

        ps operator/(const ps &r) const
        {
            return ps(ts*r.ms,ms*r.ts);
        }

        bool operator==(const ps &r)
        {
            return( ts*r.ms == ms*r.ts );
        }

        ps &operator=(const ps &r)
        {
            if( this != &r)
            {
                ts = r.ts ;
                ms = r.ms ;
            }
            return *this ;
        }

        bool operator>=(const ps &r)
        {
            return ts*r.ms>=ms*r.ts ;
        }

        bool operator!=(const ps &r)
        {
            return ts*r.ms!=ms*r.ts ;
        }

        bool operator<=(const ps &r)
        {
            return ts*r.ms<=ms*r.ts ;
        }

        bool operator>(const ps &r)
        {
            return ts*r.ms>ms*r.ts ;
        }

        bool operator<(const ps &r)
        {
            return ts*r.ms<ms*r.ts ;
        }
};

int main()
{
    ps A ,B , C , D , E , F;
    cin >> A ;
    B = A ;
    cout << A << endl ; 
    cout << B << endl ;
    C = A + B ;
    D = A / B ;
    E = A * B ;
    F = A - B ;
    cout << C << endl;
    cout << D << endl;
    cout << E << endl;
    cout << F << endl;

}