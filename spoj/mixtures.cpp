//matrix chain multiplication
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
#include<climits>
int main()
{
	int n,arr[101],m[101][101],tmp[101][101];
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k,l,q;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<n;i++)
		{
			m[i][i]=0;
			tmp[i][i]=arr[i];
		}
		for(l=2;l<=n;l++)
		{
			for(i=0;i<=n-l;i++)
			{
				j=i+l-1;
				m[i][j]=9999999;
				for(k=i;k<j;k++)
				{
					q=m[i][k]+m[k+1][j]+tmp[i][k]*tmp[k+1][j];
					if(q<m[i][j])
					{
						m[i][j]=q;
						tmp[i][j]=(tmp[i][k]+tmp[k+1][j])%100;
					}
				}
			}
		}
		cout<<m[0][n-1]<<endl;
	}
	return 0;
}
