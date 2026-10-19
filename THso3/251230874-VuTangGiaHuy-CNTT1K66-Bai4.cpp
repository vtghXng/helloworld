#include<bits/stdc++.h>
using namespace std ;

class vector3
{
    private:
        int x , y , z ;
    public:
        vector3( int a = 0 , int b = 0 , int c = 0)
        {
            x = a ; 
            y = b ; 
            z = c ;
        };
        ~vector3(){};

        vector3( const vector3 &p)
        {
            x = p.x ;
            y = p.y ;
            z = p.z ;
        }

        vector3 &operator=(const vector3 &r)
        {
            if( this != &r)
            {
                x = r.x ;
                y = r.y ;
                z = r.z ;
            }
            return *this ;
        }

        friend istream &operator>>( istream &is , vector3 &p)
        {
            is >> p.x >> p.y >> p.z ;
            return is ; 
        } 

        friend ostream &operator<<( ostream &os , const vector3 &r)
        {
            os << "(" <<r.x<<","<< r.y <<"," << r.z << ")" ;
            return os ;
        }

        vector3 operator+(const vector3 &p) const 
        {
            return vector3(x+p.x,y+p.y,z+p.z) ;
        }

        vector3 operator-(const vector3 &p) const 
        {
            return vector3(x-p.x,y-p.y,z-p.z) ;
        }

        int operator*(const vector3 &a) const
        {
            return x*a.x + y*a.y + z*a.z ;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector3 v1 , v2 ; 

    cin >> v1 >> v2 ;

    vector3 v3(v1) ;

    vector3 v4 = v2 ;

    cout << "tong v1 + v2" << (v1+v2) << endl ; 

    cout << "hieu v3 - v4" << (v3-v4) << endl ;

    cout << "Tich vo huong v1 va v2 :: " << (v1*v2) << endl ;

    cout << v1 << endl ;
    cout << v2 << endl ;
    cout << v3 << endl ;
    cout << v4 << endl ;

}