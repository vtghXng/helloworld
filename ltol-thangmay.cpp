#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k , m , s , f ;
    cin >> n ; 
    cin >> k >> m ;
    cin >> s >> f ; 

    queue<int> Q ; Q.push(s) ; 
    map<int,int> M = {{s,0}};

    while(Q.size() && M.find(f)==M.end()) 
    {
        int u = Q.front();
        Q.pop();

        for( auto x : {k,-m})
        {
            if( u + x > 0 && u + x <= n && M.count(u+x) == 0 )
            {
                Q.push(u+x);
                M[u+x] = M[u] + 1 ; 
            }
        }
    }

    if( M.count(f) == 0) 
    {
        cout << -1 << endl; 
    }

    else cout << M[f] ; 
}