//Both approaches i.e. DP and Binary Search(nlogn-Most Efficient)
#include<bits/stdc++.h>
using namespace std;
int ceilInd(vector<int> &tail,int l,int r,int x)
{
	while(r>l)
	{
		int n=l+(r-l)/2;
		if(tail[n]>=x)
			r=n;
		else
			l=n+1;
	}
	return r;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<int> lis(n,1);
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			if(v[i]>v[j])
				lis[i]=max(1+lis[j],lis[i]);
		}
	}
	cout<<*max_element(lis.begin(),lis.end())<<endl;
	vector<int> tail(n);
	int l=1;
	tail[0]=v[0];
	for(int i=1;i<n;i++)
	{
		if(v[i]>tail[l-1])
		{
			tail[l]=v[i];
			l++;
		}
		else
			tail[ceilInd(tail,0,l,v[i])]=v[i];
	}
	cout<<l;
}