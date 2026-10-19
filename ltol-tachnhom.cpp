#include<stdio.h>
long long mang[100020];
long long sonhom(int n ,int k){
    if( n <= k || (n+k)%2 != 0 ){
        return 1;
    }
    int x = (n+k)/2;
    int y = (n-k)/2;

    long long tong = sonhom(x , k) + sonhom(y,k);
    return tong;
}
int main(){
    int n , k ;
    scanf("%d%d" ,&n , &k) ;

    if (n == 0) {
        printf("0\n");
    } else {
        printf("%lld\n", sonhom(n, k));
    }
    return 0 ;
}