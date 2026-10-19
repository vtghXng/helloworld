#include<bits/stdc++.h>
using namespace std;
// map<int,char> Q = {{1,'+'},{1,'-'},{2,'/'},{2,'*'}};
map<char,int> Q = {{'+',1},{'-',1},{'/',2},{'*',2}};

int main()
{
    stack<char> S ;
    int tong = 0 ;
    string kt,kt1 = "" ; 
    cin >> kt ;
    for(char c : kt)
    if(c == '(' ) S.push(c) ;
    else if( '0' <= c and c <= '9') kt1+=c;
    else if( c == ')' )
    {
        while( S.top() != '(' )
        {
            kt1 += S.top() ; S.pop() ; 
        }
        S.pop();
    }
    else
    {
        while( S.size() && Q[S.top()] >= Q[c])
        {
            kt1+=S.top() ; S.pop();
        }
        S.push(c);
    }
    while (S.size())
    {
        kt1 += S.top() ; S.pop() ;
    }
    cout << kt1 << endl;
    stack<int> X;
    for( auto x : kt1)
    if( '0' <= x and x <= '9') X.push(x-'0');
    else
    {
        int b = X.top() ; X.pop();
        int a = X.top() ; X.pop();
        switch (x)
        {
            case '+' : X.push(a+b);break; 
            case '-' : X.push(a-b);break; 
            case '*' : X.push(a*b);break; 
            case '/' : X.push(a/b);break; 
        }
    }

    cout << X.top() ;
    
    
}
