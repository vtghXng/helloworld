#include<stdio.h>
#include<math.h>

int main(){
    int n , k ; 
    int c1 = 0, c2 = 0 , c3 = 0 , c4 = 0 ;
    scanf("%d" ,&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" ,&k);
        if( k == 1 ) c1++;
        else if( k == 2) c2++;
        else if( k == 3) c3++;
        else if( k == 4) c4++;
    }

    int tongtax = 0 ;  
    // 4 nguoi 1 xe 
    tongtax += c4 ; 
    // 3 nguoi 1 xe them dc 1 ng 
    tongtax += c3 ;
    c1 -= c3 ;// nhom 1 ng vao 3 ng 
    if( c1 < 0 ) c1 = 0 ; // khong co nhom nao thi bo 

    
    tongtax += c2 / 2 ; // 2 ng 1 xe 
    if(c2%2 != 0 ){
        // du 1 nhom 2 ng can 1 xe 
        tongtax += 1 ; 
        // xe du 2 cho ; cho them 1 ng 
        c1 -= 2 ;
        if(c1<0) c1 = 0 ; 
    }
    //
    // nhom 1 : nhom 4 ng 1 xe 
    if(c1>0){
        tongtax += (c1+3)/4;
    }
    
    printf("%d\n" ,tongtax);
}