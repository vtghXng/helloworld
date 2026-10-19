#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long c , a , b ; 
    cin >> c >> a >> b ;
    cout << min(c,a+b) << " " << a+b - min(c,a+b) ;
    
}