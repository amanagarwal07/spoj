/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 8551.cpp
* Creation Date : 22-01-2013
* Last Modified : Tuesday 22 January 2013 04:51:04 PM IST
* Created By :  Aman Agarwal
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
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int main()
{
	pair<char , char > check(char,char);
	int i,j;
	long n;
	char c,d;
	scanf("%ld",&n);
	//cin>>c;
	//cin>>s;
	char s[2*n+1],fi[2*n+1];
	scanf("%s",s);
	for(i=0;s[i]!='\0';i+=2)
	{
		pair<char , char> temp;
		temp=check(s[i],s[i+1]);
		c=temp.first;
		d=temp.second;
		if(i==0)
		{
			fi[i]=c;
			fi[i+1]=d;
		}
		else
		{
			fi[i]=c;
			fi[i+1]=d;
			if(fi[i]==fi[i-1])
				swap(fi[i],fi[i+1]);
		}
	}
	for(i=0;fi[i]!='\0';i++)
	printf("%c",fi[i]);
	cout<<endl;
	return 0;
}
pair < char, char >check(char first, char second)
{
	pair < char, char >r;
	if (first == 'A' && second == 'B') {
		r.first = 'C';
		r.second = 'D';
		return r;
	}
	if (first == 'A' && second == 'C') {
		r.first = 'B';
		r.second = 'D';
		return r;
	}
	if (first == 'A' && second == 'D') {
		r.first = 'C';
		r.second = 'B';
		return r;
	}
	if (first == 'B' && second == 'A') {
		r.first = 'C';
		r.second = 'D';
		return r;
	}
	if (first == 'B' && second == 'C') {
		r.first = 'A';
		r.second = 'D';
		return r;
	}
	if (first == 'B' && second == 'D') {
		r.first = 'C';
		r.second = 'A';
		return r;
	}
	if (first == 'C' && second == 'A') {
		r.first = 'B';
		r.second = 'D';
		return r;
	}
	if (first == 'C' && second == 'B') {
		r.first = 'A';
		r.second = 'D';
		return r;
	}
	if (first == 'C' && second == 'D') {
		r.first = 'A';
		r.second = 'B';
		return r;
	}
	if (first == 'D' && second == 'A') {
		r.first = 'B';
		r.second = 'C';
		return r;
	}
	if (first == 'D' && second == 'B') {
		r.first = 'A';
		r.second = 'C';
		return r;
	}
	if (first == 'D' && second == 'C') {
		r.first = 'A';
		r.second = 'B';
		return r;
	}
}
