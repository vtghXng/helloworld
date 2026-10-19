#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    long a , b , c ; 
    int t ; 
    cin >> t ;
    while (t--)
    {
        cin >> a >> b >> c ; 
        if( c > max(a,b) && c % __gcd(a,b) != 0 )
        {
            cout << -1 << endl ;
            continue;
        }

        if( c == 0 ) 
        {
            cout << -1 << endl ;
            continue;
        }

        if( c==a || c == b )
        {
            cout << 1 << endl ; 
            continue;
        }

        long binha = a ; 
        long binhb = 0 ;
        long dem1 = 1 ; 
        while( binha != c && binhb != c )
        {
            long buoc = min( binha , b - binhb) ;
            binhb += buoc;
            binha -= buoc;
            dem1++;

            if( binha == c || binhb == c )
            {
                break;
            }

            if( binha == 0 ) 
            {
                binha = a ; dem1++ ;
            }

            if( binhb == b ) 
            {
                binhb = 0 ; dem1++ ;
            }
        }

        binha = 0 ; 
        binhb = b ;
        long dem2 = 1 ; 
        while( binha != c && binhb != c )
        {
            long buoc = min( binhb , a - binha) ;
            binha += buoc;
            binhb -= buoc;
            dem2++;

            if( binha == c || binhb == c )
            {
                break;
            }

            if( binha == a ) 
            {
                binha = 0 ; dem2++ ;
            }

            if( binhb == 0 ) 
            {
                binhb = b ; dem2++ ;
            }

        }
        cout << min(dem1,dem2) << endl ;
    }
    

}