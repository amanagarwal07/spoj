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
#define sf(a) read_int(a)
#define pf(a) printf("%d",a);
#define sz(a) int((a).size())
#include<queue>
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
int nb,arr[2001][2001];
bool bipartite(int s,int color[])
{
	color[s]=1;
	queue <int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=1;v<=nb;v++)
		{
			if(arr[u][v] && color[v]==0)
			{
				color[v]=2;
				q.push(v);
			}
			else if(color[u]==color[v] && arr[u][v])
				return false;
		}
	}
	return true;
}
int main()
{
	int n,ni,t=0,x,y;
	sf(n);
	while(n--)
	{
		SET(arr,0);
		t++;
		sf(nb);
		sf(ni);
		REP(i,ni)
		{
			sf(x);
			sf(y);
			arr[x][y]=1;
			arr[y][x]=1;
		}
		int *color=new int [2001];
		SET(color,0);
		bool check;
		for(int i=1;i<=nb;i++)
		{
			check=true;
			if(!color[i])
				check=bipartite(i,color);
			if(check==false)
				break;
		}
		if(check==true)
			cout<<"Scenario #"<<t<<":\n"<<"No suspicious bugs found!\n";
		else
			cout<<"Scenario #"<<t<<":\n"<<"Suspicious bugs found!\n";
	}
}
