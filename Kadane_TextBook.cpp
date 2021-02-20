#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int res=v[0];
	int maxE=v[0];
	for(int i=0;i<n;i++)
	{
		maxE=max(maxE+v[i],v[i]);
		res=max(res,maxE);
	}
	cout<<res;
}