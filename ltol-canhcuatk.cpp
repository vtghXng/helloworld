#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t ;
    cin >> t ;
    while( t-- )
    {
        int n ; 
        cin >> n ; 
        queue<pair<string,int>> Q;
        for( auto x : {"dangdungcntt","tienquanutc","quang123","maianh","nguyenminhduc2820"})
        {
            Q.push({x,1});
        }

        while( n > Q.front().second) 
        {
            n-=Q.front().second;
            Q.push(Q.front());
            Q.pop();
            Q.back().second*=2;
        }

        cout << Q.front().first << endl ;
    } 
}