#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int main()
{
	long long acode(string);
	string s;
	int len;
	long long ans;
	while(1)
	{
		cin>>s;
		if(s[0]=='0')
		break;
		ans=acode(s);
		cout<<ans<<endl;;
	}
}
long long acode(string s)
{
	int i;
	vector<int> v(s.length());
	if(s.length()==1)
		return 1;
	v[0]=1;
	if(s[1]=='0')
		v[1]=1;
	else if(s[0]<='2' && s[1]<='6')
		v[1]=2;
	else if(s[0]>'2')
		v[1]=1;
	else if(s[1]>'6')
		v[1]=1;
	for(i=2;i<s.length();i++)
	{
		if(s[i]=='0')
			v[i]=v[i-2];
		else if(s[i - 1] != '0' && s[i - 1] <= '2' && s[i] <= '6')
			v[i] = v[i - 1] + v[i - 2];
		else if(s[i - 1] == '1')
			v[i] = v[i - 1] + v[i - 2];
		else if(s[i] != '0')
			v[i] = v[i - 1];
	}
	return v[s.length()-1];
}
