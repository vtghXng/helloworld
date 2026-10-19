#include<bits/stdc++.h>
using namespace std ; 

int main() {
    long n , k , res = 0; 
    cin >> n >> k ; 
    int a[n];
    for( auto &x : a ) cin >> x ;
    sort(a ,a+n,greater<int>());
    queue<int> Q ;
    for( auto x : a )
    {
        Q.push(x);
        if(Q.front() >= x+k) Q.pop();
        else res += x ; 
    }
    cout << Q.size()<<" "<< res ;
}