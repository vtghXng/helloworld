#include<bits/stdc++.h>
using namespace std ; 

template<class T>
struct node
{
    T elem;
    node<T> *prev , *next ;
    node(T e , node*P = 0 , node*N = 0)
    {
        elem = e ;
        prev = P ;
        next = N ;
    }
};

template<class T>
struct dlist
{
    int n ;
    node<T> *head , *trail ;
    dlist()
    {
        n=0;
        head = trail = 0 ; 
    }
    ~dlist()
    {
        while(n)
        {
            pop_front();
        }
    }
    int size()
    {
        return n ;
    }
    bool emtpy()
    {
        return n == 0 ;
    }
    T &front()
    {
        return head->elem ;
    }
    T &back()
    {
        return trail->elem;
    }
    void push_front(T x)
    {
        if( n == 0 ) head = trail = new node<T>(x) ;
        else
        {
            head = new node<T>(x,0,head) ;
            head->next->prev = head;
        }
        n++;
    }
    void push_back(T x)
    {
        if( n == 0 ) head = trail = new node<T>(x) ;
        else
        {
            trail = new node<T>(x,trail,0) ;
            trail->prev->next = trail;
        }
        n++;
    }    
    void pop_front()
    {
        if( n == 1 ) 
        {
            delete head ;
            head = trail = 0 ;
        }
        else
        {
            node<T>*p = head->next ;
            delete head ;
            p->prev = NULL ;
            head = p ;
        }
        n--;
    }
    void pop_back()
    {
        if( n == 1 ) 
        {
            delete head ;
            head = trail = 0 ;
        }
        else
        {
            node<T>*p = trail->prev ;
            delete trail ;
            p->next = NULL ;
            trail = p ;
        }
        n--;
    }
    void travel(bool xuoi = 1 )
    {
        if( xuoi ) 
        {
            for(node<T>*p = head ; p != 0 ; p = p->next )
            {
                cout << p->elem <<" " ;
            }
        }

        else 
        {
           for(node<T>*p = trail ; p != 0 ; p = p->prev )
            {
                cout << p->elem <<" " ;
            } 
        }
    }
};


int main()
{
    int a[] = { 65646 ,97,68,79,65,46,46,6,76,7,79,79,34,3,4,69,897,7,6,4,6,4};

    dlist<int> L ;
    for( auto x : a) x%2 ? L.push_front(x) : L.push_back(x);

    cout << "\ndanhsach xuoi :" ; L.travel() ;
    cout << "\ndanhsach nguoc:" ; L.travel(0) ;
}