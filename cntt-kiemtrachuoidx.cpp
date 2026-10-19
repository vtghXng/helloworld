#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int doxung(char s[] , int start , int end ){
    if( start >= end ) return 1  ; 
    if( s[start] != s[end]) return 0 ; 
    return doxung( s , start + 1 , end - 1 );
}

int main(){
    char s[300];
    int n ; 
    scanf("%s" ,s);
    n = strlen(s);
    if(doxung(s , 0 , n - 1 ) == 1) printf("doixung");

    else printf("khong dx");

}