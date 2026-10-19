#include<bits/stdc++.h>
using namespace std;

int main()
{
    int L , l ; 
    cin >> L >> l ; 
    if( l >= L ) cout << 0 << endl; 
    else 
    {
        int cut = ( L -1 ) / l ;
        int cuts = (L - l ) + cut ;
        cout << cuts << endl ;
    }
}