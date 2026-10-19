#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    long long n , nho = 0 ;
    cin >> n ;
    int dem = 0 ;
    list<long long> L ( 1,1ll ); 
    while (n>0)
    {
        nho = 0 ; 
        for( auto it = L.rbegin() ; it != L.rend() ; it++)
        {
            nho+=*it*n;
            *it=nho%10;
            nho/=10;
        }
        for(;nho;nho/=10)
        {
            L.push_front(nho%10);
        }
        n--;

        while (L.back()==0)
        {
            dem++;
            L.pop_back();
        }
        
    }

    for( auto x : L) cout << x ;
    cout << string(dem,'0') ;
}