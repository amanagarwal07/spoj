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

int gcd(int a, int b){if(b == 0)return a;else return gcd(b,a % b);}
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
#define mod 1000000007
void multiply(int F[2][2],int M[2][2])
{
	int x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
	int y =  ((F[0][0]*M[0][1])%mod +( F[0][1]*M[1][1])%mod)%mod;
	int z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
	int w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
void power(int F[2][2],int n)
{
	if(n==0 || n==1)
		return;
	int M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if(n&1)
		multiply(F,M);
}
int fib(int n)
{
	int F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1);
	return F[0][0];
}
int main()
{
	int t,n;
	sf(t);
	while(t--)
	{
		sf(n);
		if(n==0)
		{
			cout<<"1\n";
			continue;
		}
		int x=fib(n);
		int y=fib(n-1);
		double z=(1+sqrt(5))/2;
		z=z*x;
		z=z+y+0.5;
		int ans=z;
		ans%=mod;
		cout<<ans<<endl;
	}
}

