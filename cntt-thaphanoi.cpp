// #include<bits/stdc++.h>
// using namespace std ; 

// map<pair<int,int>,long long> C ;

// long long tohop(int k , int n){
//     if( k <= 0 or k >= n) return 1 ;
//     if (C[{k ,n}]) return C[{k ,n}];
//     else if(C[{k,n}]==0ll) C[{k,n}] = tohop(k-1,n-1) + tohop(k,n-1);
//     return C[{k,n}] ;
// }

// int main() {
//     int n ; 
//     cin >> n ; 
//     for(int  i = 0 ; i<= n ; i++)
//     {
//         for(int j = 0 ; j <= i ; j++) cout << tohop(j,i)<< " ";
//         cout <<"\n" ;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
// int b = 1 ;
// void thaphn( int n , char A , char B , char C)
// {
//     if( n > 1 ) thaphn(n-1,A,C,B) ; 
//     cout <<"\nBuoc" << b++ << " Chuyen dia " << n << " tu " << A << " sang " <<B;
//     if( n > 1) thaphn(n-1,C,B,A);
// }

int tach(int n , int k){
    if(n%k or n <= k ) return 1 ;
    return tach(n/2-2,k) + tach(n/2+2,k);
}

int main(){
    int n , k ; 
    cin >> n >> k ; 

    // thaphn( n , 'A' , 'B' , 'C');

    cout << tach(n,k);
}