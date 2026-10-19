#include<bits/stdc++.h>
using namespace std;

struct node
{
    int elem ;
    vector<node*> child ;
    node(int n) // ham tao de quy
    {
        elem = n ; 
        for( int a = 1 ; a*a <= n ; a++)
        {
            if(n%a==0)
            {
                int m = (a-1)*(n/a+1) ;
                child.push_back(new node(m));
            }
        }
    }
};

void preorder(node *H)
{
    cout << H-> elem <<" ";
    for(auto c : H->child) preorder(c);
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

void postorder(node *H)
{
    for( auto c : H->child) postorder(c);
    cout << H->elem << " ";
}

int main()
{
    int n ;
    cin >> n ;
    node *H = new node(n) ;
    preorder(H); cout << "\n" ;
    inorder(H); cout << "\n" ;
    postorder(H); cout << "\n" ;
}