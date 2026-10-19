#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    double x0 , y0 , r ; 
    double x , y ; 
    cin >> x0 >> y0 >> r ;
    cin >> x >> y ; 

    double dx = x - x0 ;
    double dy = y - y0 ;
    double d = sqrt( dx * dx + dy * dy ) ;

    double ansx , ansy ; 

    if( d <= r ) 
    {
        ansx = x ;
        ansy = y ;
    }

    else 
    {
        ansx = x0 + (dx*r)/d;
        ansy = y0 + (dy*r)/d;
    }

    cout << fixed << setprecision(3) << "(" << ansx << ", " << ansy << ")" <<endl ;
}