#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , q , i , j ;
    cin >> n >> q ; 

    int a[105][105] ; 

    for( i = 1 ; i <= n ;i++){
        for( j = 1 ; j <= n ; j++){
            cin >> a[i][j] ;
        }
    }

    while(q--){
        int u , v ;
        cin >> u >> v ;

        long long tong = 0 ; 

        for( i = 1 ; i <= n ; i++){
            int j = i - ( u - v );
            if( j >= 1 && j <= n){
                tong += a[i][j];
            }
        }

        long long min1 = 1e9 ;

        for( i = 1 ; i <= n ; i++){
            int j = (u + v ) - i ;
            if( j >= 1 && j <= n){
                if( a[i][j] < min1 ){
                    min1 = a[i][j] ; 
                }
            }
        }

        cout << tong << " " << min1 << "\n" ; 
    }
}