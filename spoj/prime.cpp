/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : prime.cpp
* Creation Date : 19-01-2013
* Last Modified : Saturday 19 January 2013 11:32:32 PM IST
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
	//cout<<"hii\n";
	//long long int lim=1000000000,a,b;
	//bool *prime=(bool*)calloc(lim,sizeof(bool));
	int x=32000;
	//prime[1]=1;
	//cout<<x<<endl;
	vector<int> prime;
	prime.push_back(2);
	int i,j,nt,pr=1,a,b;
	for(i=3;i<=x;i+=2)
	{
		pr=1;
		tr(prime,it)
		{
			if(i%(*it)==0)
			{
				pr=0;
				break;
			}
		}
		if(pr==1)
			prime.push_back(i);
	}
	scanf("%d",&nt);
	while(nt)
	{
		nt--;
		scanf("%d %d",&a,&b);
		if(a==1)a++;
		int x=sqrt(b);
		for(i=a;i<=b;i++)
		{
			pr=1;
			for(j=0;prime[j]<=x;j++){
				if(i==prime[j])break;
				if(i%prime[j]==0)
				{
					pr=0;
					break;
				}}
			if(pr==1)
				printf("%d\n",i);
		}
		cout<<"\n";
	}
	return 0;
}
