#include<bits/stdc++.h>
using namespace std ;

set<int> dic;
vector<int> A[105]; // ds ke 

// A[1] : {2,6}
// A[2] : {1,6}

void dfs(int x)
{
    if(dic.count(x)!=0) return ; 
    dic.insert(x);
    for(auto y:A[x] ) dfs(x);
}

void nhap()
{
    int n , m ;
    
    cin >> n >> m ; 
    for( int i = 1 ; i <= m ; i++)
    {
        int u , v ; 
        cin >> u >> v ;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void xuat()
{
    int n , m ; 
    for( int i = 1 ; i <= n; i++)
    {
        cout<<"\nA["<<i<<"]" ; 
        for(auto x:A[i]) cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nhap();
    xuat();
    int x ; 
    cin >> x ; 
    dfs(x);

    cout << "\nNhung phan tu lien quan" << x << " : ";
    for( auto z:dic) cout << z << " "; 
}