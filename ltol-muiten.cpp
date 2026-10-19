#include<iostream>
#include<string>
using namespace std ;
int main(){
    int i = - 1 ; 
    int n ;
    cin >> n ; 
    
    for( int t = n ; t != n + 1 ; t = t + i ){
        cout << string(2*(n-t),' ')<<string(t,'*')<<"\n";
        if( t == 1 ) i = -i ; 
    }

}