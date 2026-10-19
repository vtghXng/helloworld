#include<bits/stdc++.h>
using namespace std;

struct node
{
    string elem ;
    vector<node*> child ;
    node(string e) // ham tao de quy
    {
        elem = e; 
    }
};

node *find(node *p,string x)
{
    if( p->elem==x) return p ;
    for(auto c : p->child)
    {
        node*f = find(c,x);
        if(f) return f ;
    }
    return 0 ;
}

void add(node *h,string x,string y)
{
    node *p = find(h,x);
    p->child.push_back(new node(y));
}

void inorder(node *H)
{
    if(H->child.size()>0)
    {
        inorder(H->child[0]);
    }
    cout << H->elem << " " ;
    for( int i = 1 ; i < H->child.size() ; i++)
    {
        inorder(H->child[i]);
    }
}

int mostchil(node *H)
{
    int k = H->child.size();
    for(auto c:H->child)
    {
        k = max(k,mostchil(c));
    }
    return k ;
}

int high(node *H)
{
    if(H->child.size()==0) return 1 ;
    int k = 0 ; 
    for(auto c:H->child)
    {
        k=max(k,high(c));
    }
    return k+1 ;
}

int main()
{
    node*H = 0 ;
    int n ;
    cin >> n ;
    for( int i = 1 ; i< n ; i++)
    {
        string x , y ;
        cin >> x >> y ;
        if( H == 0 ) H = new node(x);
        add(H,x,y);
    }
    inorder(H);
    cout<<"\n"<<mostchil(H);
    cout<<"\n"<<high(H);
}