#include<bits/stdc++.h>
using namespace std ;

template<class T>
struct Queue 
{
    int n , cap , F , L ; 
    T*buf;

    Queue()
    {
        n=cap=F=L=0;
        buf=NULL;
    }

    ~Queue()
    {
        if(buf!=NULL) delete[] buf;
    }
    bool empty() {return n == 0;}
    int size() {return n;}
    void pop()
    {
        F = ( F + 1 )%cap;
        n--;
    }
    T &front(){return buf[F];}
    T &back(){return buf[(L?L:cap)-1];}
    void push(T x)
    {
        if( n == cap )
        {
            T*tem = buf ;
            int oldcap = cap;
            cap = cap?cap*2:1;
            buf=new T[cap];
            if(tem) {
                for(int i = 0; i < n; i++) {
                    buf[i] = tem[(F + i) % oldcap];
                }
                delete []tem;
            }
            F = 0;
            L = n;
        }
        buf[L] = x;
        L = (L + 1) % cap;
        n++;
    }
};

int main(){
    
    Queue<char> Q;
    string x = "cntt1" ;
    for( char c:x ) Q.push(c);

    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }

}