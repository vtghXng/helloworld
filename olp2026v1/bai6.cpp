#include<bits/stdc++.h>
using namespace std ;
#define ll long long

ll lcm(ll a , ll b )
{
    return a*b/__gcd(a,b) ; 
}

ll cnt1 (ll a , ll b , ll c , ll r )
{
    return r/a + r/b +r/c - r/lcm(a,b) - r/lcm(b,c) - r/lcm(a,c) - r/lcm(lcm(a,b),c) ;
}

ll cnt2 (ll)
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
     
    
}