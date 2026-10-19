#include<stdio.h>
#include<stdlib.h>

long long dequy( int n ){
    if( n <= 1 ) return 1 ; 
    return n * dequy(n-1);
}

long long dequy2( int k ){
    if( k <= 1 ) return 1 ; 
    return k * dequy2( k -1 ); 
}

long long dequy3( int n , int k  ){
    if( n < k ) return 1 ; 
    long long t = n - k ; 
    long long tich = 1 ; 
    for( int i = 1 ; i <= t ; i++){
     tich *= i ;
    }

    return tich ; 
}


long long tonguoc( int n , int k ){
    long long chapk = (dequy(n))/((dequy2(k)*dequy3(n,k)));
    int dem = 0 ;
    for( int j = 1 ; j <= chapk ; j++ ){
        if(chapk%j==0){
            dem++;
        }
    }
    return dem ; 
}
int main(){
    int n , k ; 
    int i ; 
    int x ; 
    scanf("%d" ,&x);
    for(i = 0; i < x; i++) {
            scanf("%d %d", &n, &k);
            printf("%lld\n", tonguoc(n, k)); 
        }
    }