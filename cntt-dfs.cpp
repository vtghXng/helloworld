#include<bits/stdc++.h>
using namespace std ;

// set<int> M = {7,8,6,9,4,2,1} ; // order set ; // <greater<int>>

// mutliset<int>
// unordered_set<int>

// unordered_multiset<int> 

#define toado pair<int,int>

set<toado> Dic ; 

void dfs( int u , int v )
{
    if(Dic.find({u,v})!=Dic.end()) return; 
    Dic.insert({u,v});
    if(u%2==0) dfs(v,u/2) ;
    if(v%2!=0) dfs(v/2+1,u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<"So phan tu " << M.size() << "\n" ;
    // for(auto x:M) cout << x <<" " ;

    int x,y ;
    cin >> x >> y ; 
    dfs(x,y) ;
    cout<<Dic.size();
    // for( auto x:Dic) cout << x.first << x.second << "\n" ;
}