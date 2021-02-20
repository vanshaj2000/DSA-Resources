#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,W;
	cin>>n>>w;
	vector<int> v(n);
	vector<int> w(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cin>>w[i];
	vector<vector<int>> (W+1,vector<int>(n1+1,0));
	for(int i=1;i<=W;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(w[j]<=i)
				dp[i][j]=max(dp[i][j-1],dp[i-w[j-1]][j]+v[j-1]);
			else
				dp[i][j]=dp[i][j-1];
		}
	}
	cout<<dp[W][n];
}