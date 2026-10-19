#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s1[1000001];
    int check[26] = {0};
    if( fgets( s1 , sizeof(s1) , stdin) == NULL) return 0 ; 

    size_t len = strlen(s1);
    if( len > 0 && s1[ len - 1 ] == '\n'){
        s1[ len - 1 ] = '\0' ; 
        len-- ; 
    }

    int i ;
    for( i = 0 ; s1[i] != '\0' ; i++){
        if( s1[i] >= 'a' && s1[i] <= 'z'){
            check[s1[i] - 'a'] = 1 ; 
        }
    }
    
    for( i = 0 ; i < 26 ; i++){
        if(check[i] == 0 ){
            printf("%c" , i + 'a');
        }
    }
    printf("\n");
    return 0 ; 
}