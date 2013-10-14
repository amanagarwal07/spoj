#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<set>
#include<map>
typedef long long int LL;
typedef unsigned long long int ULL;
#define sf(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define SET(v, val) memset(v, val, sizeof(v))
inline void read_int (int &n)
{
	n = 0;
	int i = getchar_unlocked();
	while (i < '0' || i > '9')
		i = getchar_unlocked();

	while (i >= '0' && i <= '9')
	{
		n = (n << 3) + (n << 1) + (i - '0');
		i = getchar_unlocked();
	}

}
typedef struct Node
{
	int key,priority,size;
	Node *left,*right;
	Node(int k){key=k;size=1;priority=rand();left=right=NULL;}
}stud;


int TreeSize(Node* T)  
{  
	return T==NULL?0:T->size;  
}  
Node* Updatesize(Node* root)  
{  
	if(root)  
	{  
		root->size = 1 + TreeSize(root->left) + TreeSize(root->right);  
	}  
	return root;
}  
Node* rotRight(Node* root)
{
	Node* pivot=root->left;
	root->left=pivot->right;
	pivot->right=root;
	pivot->right=Updatesize(pivot->right);  
	pivot=Updatesize(pivot);
	return pivot;
}
Node* rotLeft(Node* root)
{
	Node* pivot=root->right;
	root->right=pivot->left;
	pivot->left=root;
	pivot->left=Updatesize(pivot->left);  
	pivot=Updatesize(pivot);
	return pivot;
}
Node* insert( Node *root , Node *novo )
{      
	if( root == NULL ) return novo;           
	if( root -> key < novo -> key )
	{         
		root -> right = insert( root -> right , novo );
		if( root -> right -> priority > root -> priority ) root = rotLeft( root ); 
	}
	else if(root -> key > novo -> key)
	{				                       
		root -> left = insert( root -> left , novo );
		if( root -> left -> priority > root -> priority ) root = rotRight( root ); 
	}
	root=Updatesize(root);
	return root;
}
Node* erase( Node* root , int key ){
	if( root == NULL ){ return root; }
	if( root -> key < key ) root -> right = erase( root -> right , key );
	else if( root -> key > key ) root -> left = erase( root -> left , key );
	else{
		if( root->left!=NULL )
		{
			if(root->right!=NULL )
			{
				if(root->left->priority <root->right-> priority )
				{
					root=rotLeft(root);  
					root->left=erase(root->left,key);
				}
				else
				{
					root=rotRight(root); 
					root->right=erase(root->right,key);
				}
			}
			else
			{ 
				Node* aux=root->left;  
				delete root; 
				return aux;
			}
		}
		else
		{
			if(root->right!=NULL)
			{
				Node* aux=root->right;  
				delete root; 
				return aux;
			}
			else
			{ 
				delete root;  
				return NULL;
			}
		}
	}
	root=Updatesize(root);
	return root;
}

Node* find_kth(Node* root,int k)
{
	if (TreeSize(root) <k) 
		return  NULL; 
	int  ans = 1 + TreeSize(root->left); 
	if (ans == k) 
		return  root;
	if (ans <k) 
		return  find_kth (root -> right, k - ans) ;
	return  find_kth (root->left,k); 
}
int count(Node* root,int x)
{
	if(root==NULL)
		return 0;
	if(root->key<x)
		return 1+TreeSize(root->left)+count(root->right,x);
	return count(root->left,x);
}
int main()
{
	stud *treap=NULL;
	int t,n;
	read_int(t);
	char c[5];
	while(t--)
	{
		scanf("%s%d",c,&n);
		if(c[0]=='I')
			treap=insert(treap,new Node(n));
		else if(c[0]=='D')
			treap=erase(treap,n);
		else if(c[0]=='K')
		{
			Node* aux = find_kth (treap, n);
			if (aux!=NULL) 
				printf ("%d\n",aux->key);
			else  
				printf("invalid\n");
		}
		else if(c[0]=='C')	
		{
			int x=count(treap,n);
			cout<<x<<endl;
		}
	}
	return 0;
}
