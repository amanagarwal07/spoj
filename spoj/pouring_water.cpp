/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
   pouring water
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
int gcd(int a, int b)
{
	while(b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int t,a,b,c,ta,tb,m1,m2;
	sf(t);
	while(t--)
	{
		sf(a);
		sf(b);
		sf(c);
		if(c>a && c>b)
		{
			cout<<"-1\n";
			continue;
		}
		else if(c==a || c==b)
		{
			cout<<"1\n";
			continue;
		}
		else if(c==0)
		{
			cout<<"0\n";
			continue;
		}
		else if(a==b)
		{
			cout<<"-1\n";
			continue;
		}
		else if(c % gcd(a,b) != 0)
		{
			printf("%d\n",-1);
			continue;
		}
		ta=0;
		tb=0;
		m1=0;
		m2=0;
		while(ta!=c && tb!=c)
		{
			if(ta==0)
			{
				ta=a;
				m1++;
			}
			else if(tb==b)
			{
				tb=0;
				m1++;
			}
				int sum=ta+tb;
				int minn=min(sum,b);
				tb=minn;
				ta=sum-minn;
				m1++;
		}
		ta=0;
		tb=0;
		while(ta!=c && tb!=c)
		{
			if(tb==0)
			{
				tb=b;
				m2++;
			}
			else if(ta==a)
			{
				ta=0;
				m2++;
			}
				int sum=ta+tb;
				int minn=min(sum,a);
				ta=minn;
				tb=sum-minn;
				m2++;
		}
		int ans=min(m1,m2);
		cout<<ans<<endl;
	}
	return 0;
}

