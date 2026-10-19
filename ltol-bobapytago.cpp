#include<bits/stdc++.h>
using namespace std ;

bool check(long long a, long long &b)
{
    if( a <= 0 ) return false;
    long long r = sqrt(a);
    if( r * r == a )
    {
        b = r ;
        return true ;
    }
    return false ;
}

void check1(long long x , long long y , long long z, long long &d)
{
    long long ans ; 
    if(check(x*x+y*y,ans))
    {
        long long kq = abs(z - ans);
        if( d == -1 || kq < ans) d = kq ;
    }

    if (x > y && check(x * x - y * y, ans)) {
        long long kq = abs(z - ans);
        if (d == -1 || kq < d) d = kq;
    }
    if (y > x && check(y * y - x * x, ans)) {
        long long kq = abs(z - ans);
        if (d == -1 || kq < d) d = kq;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a , b , c ;
    cin >> a >> b >> c ; 

    long long d = -1 ;

    check1(a,b,c,d);
    check1(a,c,b,d);
    check1(b,c,a,d); 

    if( d != - 1 ) cout << d << endl ;
    else cout << "-1" << endl ;
}