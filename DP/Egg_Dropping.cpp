#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f,e;
	cin>>f>>e;
	vector<vector<int>> dp(f+1,vector<int>(e+1));
	for(int i=1;i<=e;i++)
	{
		dp[0][i]=0;
		dp[1][i]=1;
	}
	for(int i=2;i<=f;i++)
		dp[i][1]=i;
	for(int i=2;i<=f;i++)
	{
		for(int j=2;j<=e;j++)
		{
			dp[i][j]=INT_MAX;
			for(int k=1;k<=i;k++)
				dp[i][j]=min(dp[i][j],1+max(dp[i-1][j-1],dp[i-k][j]));
		}
			
	}
	cout<<dp[f][e];
}