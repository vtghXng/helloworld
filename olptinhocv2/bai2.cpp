#include<bits/stdc++.h>
using namespace std ;

char s[] = "0000000000000000" ; 

void bit( int n )
{
    while(n>0)
    {
        int i = log2(n) ;
        s[15-i] = '1' ; 
        n -= pow(2,i);
    }
}

int main()
{
    int i , n ; 
    cin >> n ; 
    bit(n);
    for( i = 0 ; i < 16 ; i++){
        cout << s[i] ; 
        if( i == 7 ) cout << endl ;
    }
}