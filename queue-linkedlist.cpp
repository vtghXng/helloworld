#include<bits/stdc++.h>
using namespace std ; 

template<class T>
struct node
{
    T elem ; 
    node*next;
    node(T x){elem = x ; next = NULL;}
};
template<class T>
struct Queue
{
    int n ; 
    node<T> *F , *L ;
    Queue() {n=0 ; F = L = NULL;}
    ~Queue() {while(!empty()) pop();}
    int size(){return n;}
    int empty(){return n==0;}
    void push(T x)
    {
        if( n == 0 ) F = L = new node<T>(x);
        else L = L ->next = new node<T>(x);
        n++;
    }
    void pop()
    {
        node<T>*p=F;
        F=F->next;
        delete p ;
        n--;
        if(n==0) L = 0 ;
    }
    T &front(){return F -> elem;}
    T &back(){return L -> elem;}
};


int main()
{
    Queue<char> Q;
    string x = "cntt1" ;
    for( char c:x ) Q.push(c);

    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
}