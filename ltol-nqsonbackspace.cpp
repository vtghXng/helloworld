#include<stdio.h>
#include<string.h>

char ktv[1000004];
char ktr[1000004];

int main(){
    if( fgets(ktv , 1000005 , stdin ) == NULL) return 0 ; 
    int j = 0;
    int i ;
    for ( i = 0 ; ktv[i] != '\0' ; i++){
        if( ktv[i] == '\n' || ktv[i] == '\r') continue;

        if( ktv[i] == '#'){
            if(j>0) j--;
        }
        else {
            ktr[j] = ktv[i];
            j++;
        }
    }
    ktr[j] = '\0' ;
    printf("%s" , ktr);
}