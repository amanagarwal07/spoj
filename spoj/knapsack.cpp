/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : knapsack.cpp
party schedule
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
typedef struct ptr
{
	int weight,value;
}stud;
int main()
{
	stud arr[105];
	int v[105][505],pb,np;//party budget no of parties
	bool keep[105][505];
	while(1)
	{
		sf(pb);
		sf(np);
		for(int i=0;i<=np;i++)
			for(int j=0;j<=pb;j++)
				keep[i][j]=0;
		SET(v,0);
		if(pb==0 && np==0)
			break;
		FOR(i,1,np+1)
		{
			sf(arr[i].weight);
			sf(arr[i].value);
		}
		int fee=0,value=0;
		for(int i=0;i<=np;i++)
		{
			for(int j=0;j<=pb;j++)
			{
				if(i==0 || j==0)
				    v[i][j]=0;
				else if(arr[i].weight<=j)
				{
					v[i][j]=max(v[i-1][j-arr[i].weight] + arr[i].value ,v[i-1][j]);
					if(v[i-1][j-arr[i].weight]+arr[i].value >v[i-1][j])
						keep[i][j]=1;
				}
				else
					v[i][j]=v[i-1][j];
			}
		}
		int j=v[np][pb],i;
		for(i=pb;i>=1;i--)
		{
			if(v[np][i]<j)
				break;
		}
		value=j;
		cout<<i+1<<" "<<value<<endl;
	}
	return 0;
}
