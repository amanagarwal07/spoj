/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
59.Bytelandian Information Agency
   _._._._._._._._._._._._._._._._._._._._._.*/
                                   
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
#include<list>
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
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define SET(v, val) memset(v, val, sizeof(v))
#include<queue>
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
list<int> *adj;
int tmp;
bool bfs(int neg,int src)
{
	int visited[5002]={0},c=0;
	visited[1]=1;
	queue <int> q;
	q.push(src);
	list<int>::iterator it;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(it=adj[x].begin();it!=adj[x].end();it++)
		{
			if(!visited[*it] && *it!=neg)
			{
				c++;
				visited[*it]=1;
				q.push(*it);
			}
		}
	}
	if(c!=tmp)
	{
		return false;
	}
	return true;
}
int main()
{
	int t=10,n,m;
	while(t--)
	{
		vector<int> arr;
		int ans=0;
		sf(n);
		tmp=n-2;
		sf(m);
		adj=new list<int>[5004];
		int x,y;
		REP(i,m)
		{
			sf(x);
			sf(y);
			adj[x].push_back(y);
		}
		FOR(i,2,n+1)
		{
			bool check=bfs(i,1);
			if(check==false)
			{
				ans++;
				arr.push_back(i);
			}
		}
		cout<<ans+1<<endl<<"1 ";
		int i;
		for(i=0;i<arr.size()-1;i++)
			cout<<arr[i]<<" ";
		cout<<arr[i]<<endl;
	}
	return 0;
}
