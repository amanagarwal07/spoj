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
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define SET(v, val) memset(v, val, sizeof(v))
#define mp(a,b)    make_pair(a,b)
#define pb(n)      push_back(n)
#define PI 3.14159265

typedef vector <int> vi;

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
int main()
{
	int n,m,arr[10000],brr[10000];
	while(1)
	{
		sf(n);
		if(n==0)
			break;
		REP(i,n)
			sf(arr[i]);
		sf(m);
		REP(i,m)
			sf(brr[i]);
		
