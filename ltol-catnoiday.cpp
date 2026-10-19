#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    long long i , k , n ;
    cin >> k >> n ;
    long long gt = 1 ;
    for( i = 1 ; i <= k ; i++ )
    {
        gt*=2;
    }

    if( n == gt )
    {
        cout << 0 ;
        return 0 ;
    }

    int dem = 0 ;

    while (n % gt != 0) {
        gt /= 2;
        dem++;
    }

    long long temp = n ; 
    int check = 0 ;
    while( temp > 0 )
    {
        if( temp % 2 == 1 )
        {
            check++;
        }
        temp/=2;
    }

    dem += (check-1);
    cout << dem ;
}