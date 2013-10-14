/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
   transitive closure
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
int main()
{
	int t,n,tt=0,x,y;
	sf(t);
	while(t--)
	{
		tt++;
		int arr[101][101];
		SET(arr,0);
		sf(n);
		REP(i,n)
		{
			sf(x);
			sf(y);
			arr[x][y]=1;
		}
		int ans=0;
		REP(i,n)
		{
			REP(j,n)
			{
				if(arr[i][j]==1)
				{
					REP(k,n)
					{
						if(arr[j][k]==1 && arr[i][k]!=1)
						{
							arr[i][k]=1;
							ans++;
							j=min(j,k)-1;
							break;
						}
					}
				}
			}
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}
