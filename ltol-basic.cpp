#include<bits/stdc++.h>
using namespace std ; 

bool snt(long long a)
{
    if( a == 0 || a == 1 ) return false ;
    if( a%2 == 0 || a%3 == 0 ) return false; 
    for( long long i = 2 ; i*i <= a ; i++ )
    {
        if( a%i == 0 ) return false ;
    }
    return true ; 
}

int main()
{
    long long a ; 
    cin >> a ;
    cout << (snt(a) ? "YES" : "NO") ;
}