//This program contains both the solutions i.e. Recursive and Dynamic Programming
#include<bits/stdc++.h>
using namespace std;
int recurF(string s1,string s2,int m,int n)
{
	if(m==0)
		return n;
	else if(n==0)
		return m;
	else if(s1[m-1]==s2[n-1])
		return recurF(s1,s2,m-1,n-1);
	else
	{
		return 1+min(recurF(s1,s2,m-1,n),min(recurF(s1,s2,m-1,n-1),recurF(s1,s2,m,n-1)));
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.length();
	int n=s2.length();
	cout<<recurF(s1,s2,m,n)<<endl;
	vector<vector<int>> dp(m+1,vector<int>(n+1));
	for(int i=0;i<=m;i++)
		dp[i][0]=i;
	for(int i=0;i<=n;i++)
		dp[0][i]=i;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
		}
	}
	cout<<dp[m][n];
}