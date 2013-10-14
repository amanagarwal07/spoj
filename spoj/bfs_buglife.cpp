#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<list>
typedef long long int LL;
typedef unsigned long long int ULL;
#define sf(a) read_int(a)
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
#define REP(i, n) for (int i = 1 ; i < =n ; i ++)
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
int bipartite(int,int[]);
list<int> *adj;//adjacency matrix for bfs
int main()
{
	int n,nb,ni,x,y,t=0;
	sf(n);
	while(n--)
	{
		t++;
		sf(nb);//no of bugs=no of nodes
		sf(ni);//no of interactios=no of edges
		adj=new list<int>[5000];
		while(ni--)
		{
			sf(x);//edge from x to y
			sf(y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int color[5000];
		SET(color,-1);
		int check;
		for(int i=1;i<=nb;i++)
		{
			if(color[i]==-1)
				check=bipartite(i,color);
			if(check==-1)
				break;
		}
		if(check==-1)
			cout<<"Scenario #"<<t<<":\n"<<"Suspicious bugs found!\n";
		else
			cout<<"Scenario #"<<t<<":\n"<<"No suspicious bugs found!\n";
	}
	return 0;
}
int bipartite(int s,int color[])
{
	queue<int> q;
	color[s]=1;
	q.push(s);
	list<int>::iterator i;
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		for(i=adj[s].begin();i!=adj[s].end();++i)
		{
			if(color[*i]==-1)
			{
				color[*i]=1-color[s];
				q.push(*i);
			}
			else if(color[*i]==color[s])
				return -1;
		}
	}
	return 1;
}
