#include<bits/stdc++.h>
using namespace std ;

template<class T>
struct node
{
    T elem ; 
    node *next ;
    node( T e , node<T>*N=0)
    {
        elem = e ;
        next = N ;
    }
};

template<class T>
struct slist_iterator 
{
    node<T> *curr;
    public:
        slist_iterator()
        {
            curr = NULL ;
        }

        slist_iterator(node<T> *p)
        {
            curr = p ;
        }

        node<T> *getcurr()
        {
            return curr ;
        }

        slist_iterator<T> &operator=(slist_iterator<T> p)
        {
            this->curr = p.getcurr();
            return *this;
        }

        bool operator!=(slist_iterator<T> p)
        {
            return curr!=p.getcurr();
        }

        slist_iterator<T> operator++()
        {
            curr=cur->next;
            return curr;
        }

        slist_iterator<T> operator++(int)
        {
            node<T> *temp = curr;
            curr=curr->next;
            return temp;
        }

        T &operator*()
        {
            return curr->elem;
        }
};

template<class T>
struct slist
{
    int n ;
    node<T> *head , *trail ;
    slist()
    {
        n = 0 ;
        head=trail=NULL;
    }

    ~slist()
    {
        while(n>0)
        pop_front();
    }

    bool empty()
    {
        return n == 0 ;
    }

    int size()
    {
        return n ; 
    }

    T&front()
    {
        return head->elem;
    }

    T&back()
    {
        return trail->elem;
    }

    void push_front(T x)
    {
        if(n)
        {
            head = new node<T>(x,head);
        }
        else head=trail=new node<T>(x);
        n++;
    }

    void push_back(T x)
    {
        if(n)
        {
            trail=trail->next=new node<T>(x);
        }
        else head = trail = new node<T>(x) ;  
        n++;
    }

    void pop_front()
    {
        node<T>*p = head ;
        head=p->next;
        delete p;
        if( n== 1 ) trail = 0 ;
        n--;
    } 

    void pop_back()
    {
        if( n == 1 ) return pop_front();
        node<T>*p = head ;
        while(p->next!=trail) p = p -> next ;
        delete trail;
        p->next=0;
        trail=p;
        n--;
    }

    // void travel()
    // {
    //     for(node<T>*p=head;p;p=p->next) cout<<p->elem<<" ";
    // }

    typedef slist_iterator<T> iterator;
    iterator begin()
    {
        return head ;
    }

    iterator end()
    {
        return NULL ;
    }

    void insert(iterator it,T x)
    {
        node<T> *p = it.getcurr();
        p->next=new node<T>(p->elem,p->next);
        p->elem=x;
        n++;
    }

    void erase(iterator it)
    {
        node<T> *p = it.getcurr();
        if( p == head ) return pop_front();
        if( p == trail) return pop_back();
        p->elem=p->next->elem;
        p->next=p->next->next;
        n--;
    }

    void sort()
    {
        for( node<T>*p = head ; p ; p->next)
        {
            
        }
    }

};

int main()
{
    slist<int> L ;
    for( auto x : {45,86,8,96,74,3,6,8,44,66,1,66,77,55,5}) x%2 ? L.push_front(x) : L.push_back(x) ;

    cout<< "\nL :" ; for( auto x : L) cout << x << " ";
    
}