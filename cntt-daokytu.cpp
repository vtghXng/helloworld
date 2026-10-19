#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Daokytu(char s1[20] , char s2[20] ){
    int n = strlen(s1);
    int i , j ; 
    for(int i = 0 ,  j = n - 1  ; i <= n - 1 && j >= 0 ; i++ , j-- ){
        s2[i] = s1[j];
        s2[n]='\0';
    }
    printf("%s" , s2);
    return 0 ; 
}

int main(){
    char s1[20] , s2[20] ; 
    fgets(s1 , sizeof(s1) , stdin) ;
    getchar();

    Daokytu(s1 , s2);

}