#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s ;

    getline(cin,s);

    bool mark[10] = {}; 

    for( int i = 0 ; i < 9 ; i++)
    {
        mark[(int)(s[i]-'A')]=true;
    }

    for( char i = 'A' ; i <= 'J' ; i++ )
    {
        if( mark[(int)(i-'A')]!=true) 
        {
            cout << i ;
            break;
        } 
        
    }
    
}