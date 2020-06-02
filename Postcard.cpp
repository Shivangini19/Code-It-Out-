#include <iostream>
using namespace std;

int main() {
	string s;
	int k;
	cin>>s;
	cin>>k;
	int l=s.length();
	int n=0,sn=0,c=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='*')
		
		sn++;
		else if(s[i]=='?')
		c++;
		else
		n++;
	}
	//cout<<sn<<c<<n;
	string res="";
	for(int i=0;i<l;i++)
	{
		if(s[i]!='?'&&s[i]!='*')
		res+=s[i];
	}
	//cout<<res;
	if(n==k)
	{
	cout<<res;
	return 0;
	}
	
	if(sn==0&&k>n)
	{
		cout<<"Impossible";
		return 0;
	}
	if(k<(n-(sn+c)))
	{
		cout<<"Impossible";
		return 0;
	}
	int add=0,del=0;
if(k<n)
del=n-k;
if(k>n)
add=k-n;
int p[l];
for(int i=0;i<l;i++)
{
	if(s[i]=='?')
	{
	if(del)
	{
		p[i-1]=0;
		del--;
		}
		p[i]=0;
	}
	else	if(s[i]=='*')
		{
			if(add)
			{
		p[i-1]+=add;
		add=0;
		}
		if(del)
		{
			p[i-1]=0;
			del--;
		}
	
	p[i]=0;
		}
	else
	p[i]=1;
	}
	for(int i=0;i<l;i++)
	{
		while(p[i]>0)
		{
		cout<<s[i];
		p[i]--;
		}
	}
	
	
	
	return 0;
}
