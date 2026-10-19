#include<bits/stdc++.h>
using namespace std ;

int main(){
    long long n , x , y1 , y2 , z  ;
    cin >> n >> x >> y1 >> y2 >> z ;

    long long tao = n*x ;
    long long tao1 = n*y1 + y2 ;
    long long tao2 = z ;

    long long mintao = min({tao,tao1,tao2});

    cout << mintao << endl;
}