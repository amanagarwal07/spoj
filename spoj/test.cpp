#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	string ans="";
	string a="1";
	int test,i,flag,check,l,m,k;
	cin>>test;
	while(1)
	{
		ans=ans+a;
		if(a=="9")
			a="10";
		if(ans.length()>test)
			break;
		flag=1;
		l=a.length();
		k=l>>1;
		check=0;
		for(i=0;i<l;i++)
		{
			if(a[i]!='9')
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			a[0]='1';
			for(i=1;i<l;i++)
				a[i]='0';
			a[l]='1';
			a[l+1]='\0';
			check=1;
		}
		flag=0;
		if(check!=1)
		{
			for(i=0;i<k;i++)
			{
				if(a[i]<a[l-1-i])
					flag=-1;
				else if(a[i]>a[l-1-i])
					flag=1;
				a[l-1-i]=a[i];
			}

			if(!(l&1))
				m=k-1;
			else m=k;
			if(flag==0||flag==-1)
			{
				i=0;
				while(a[m-i]=='9')
				{
					a[m-i]='0';
					a[l-1-m+i]='0';
					i++;
				}

				a[m-i]++;
				a[l-1-m+i]=a[m-i];
			}
		}
	}
	cout<<ans[test]<<endl;
	return 0;
}

