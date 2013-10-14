/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 8551.cpp
* Creation Date : 22-01-2013
* Last Modified : Tuesday 22 January 2013 04:21:04 PM IST
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
	int n,i,j;
	string s,fi;
	char c;
	scanf("%d",&n);
	//cin>>c;
	cin>>s;
	vector<int> v(4,0),arr;
	for(i=0;i<2*n;i+=2)
	{
		v[0]=v[1]=v[2]=v[3]=0;
		int x=(int)s[i]-65,y=(int)s[i+1]-65;
		v[x]=1;v[y]=1;
		for(j=0;j<4;j++)
			if(v[j]==0)
				arr.push_back(j);
		if(i==0)
		{
			fi=fi+(char)(65+arr[0]);
			fi=fi+(char)(65+arr[1]);
		}
		else
		{
			if((int)(fi[i-1]-65)==arr[0])
			{
				fi=fi+(char)(65+arr[1]);
				fi=fi+(char)(65+arr[0]);
			}
			else if((int)(fi[i-1]-65)==arr[1])
			{
				fi=fi+(char)(65+arr[0]);
				fi=fi+(char)(65+arr[1]);
			}
			else
			{
				fi=fi+(char)(65+arr[0]);
				fi=fi+(char)(65+arr[1]);
			}
		}
		arr.erase(arr.begin(),arr.end());
	}
	printf("%s\n",fi.c_str());
	return 0;
}
