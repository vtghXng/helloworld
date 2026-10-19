#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x ,y ;
    cin >> x >> y ;
    vector<long long> A , B , C  ;
    for( auto c : x ) A.push_back(c-'0');
    reverse(A.begin(),A.end());
    for( auto c : y ) B.push_back(c-'0');
    reverse(B.begin(),B.end());
    C.resize(A.size()+B.size()-1,0);
    for(int i = 0 ; i < A.size() ; i++)
    for(int j = 0 ; j < B.size() ; j++) C[i+j]+=A[i]*B[j] ;
    long long nho = 0 ;
    for(auto &x : C)
    {
        nho+=x;
        x=nho%10;
        nho/=10;
    }
    for(;nho;nho/=10) C.push_back(nho%10);
    reverse(C.begin(),C.end());
    for(int i = 0 ; i < C.size() ; i++) cout << C[i] ;
}