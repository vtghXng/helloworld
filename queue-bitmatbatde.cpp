#include<bits/stdc++.h>
using namespace std ;
using ll = long long ; 

int main(){
    
    queue<int> Q ; 
    int i , n , k ; 
    cin >> n >> k ;
    for( i = 1 ; i <= n ; Q.push(i++));
    while(Q.size()>1)
    {
        for( i = 1 ; i < k ; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
    }

    cout << Q.front();

}