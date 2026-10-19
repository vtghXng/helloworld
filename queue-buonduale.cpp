#include<bits/stdc++.h>
using namespace std ;
using ll = long long ; 

struct tuidua {
    long long soluong ; 
    long long hong ;
};

int main()
{
    queue<tuidua> Q ;
    long long tong = 0 ; 
    long long n , m , k , i ; 
    cin >> n >> k >> m ; 
    
    long long a[n] ;
    for( i = 1 ; i <= n ; i++) cin >> a[i];

    for( long long ngay = 1 ; ngay <= n || !Q.empty() ; ngay++)
    {
        if (ngay <= n && a[ngay] > 0) {
            Q.push({a[ngay], ngay + k}); 
        }

        while (!Q.empty() && Q.front().hong <= ngay) {
            Q.pop();
        }

        long long sucthuhoach = m ; 

        while (!Q.empty() && sucthuhoach > 0) {
            if (Q.front().soluong <= sucthuhoach) {
                tong += Q.front().soluong; 
                sucthuhoach -= Q.front().soluong;        
                Q.pop();                              
            }

            else {
                tong += sucthuhoach;                  
                Q.front().soluong -= sucthuhoach;        
                sucthuhoach = 0;                                
            }
        }
    }
    cout << tong << endl ;
}