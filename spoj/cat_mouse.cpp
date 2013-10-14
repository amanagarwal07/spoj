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
	int n,m,k;
	int x1,y1,x2,y2,x3,y3;
	sf(n);
	sf(m);
	sf(k);
	while(k--)
	{
		sf(x1);//mouse
		sf(y1);
		sf(x2);//cat1
		sf(y2);
		sf(x3);//cat2
		sf(y3);
		int flag=0;
		if((x1==x2 && y1==y2)||(x1==x3 && y1==y3))
			flag=1;
		//checking 1st diagonal
		int a,b,c,d;
		for(int i=1;i<101;i++)
		{
			a=x1+i,b=y1+i,c=x1-i,d=y1-i;
			if((a==x2 && b==y2 && c==x3 && d==y3) || (a==x3 && b==y3 && c==x2 && d==y2))
			{
				flag=1;
				break;
			}
			a=x1+i,b=y1-i,c=x1-i,d=y1+i;
			if((a==x2 && b==y2 && c==x3 && d==y3) || (a==x3 && b==y3 && c==x2 && d==y2))
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
