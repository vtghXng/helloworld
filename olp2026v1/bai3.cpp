#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a , b , c , d ; 
    cin >> a >> b >> c >> d ;

    double pa = (double)a/b , pb = (double)c/d ;

    double kq = pa / ( 1 - (1-pa)*(1-pb)) ;
    
    cout << fixed << setprecision(6) << kq ;
     
    
}