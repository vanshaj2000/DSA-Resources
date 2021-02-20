/*Imp Question
Recursion sol-max(arr[i]+min(sol(arr,i+2,j),sol(arr,i+1,j-1)),arr[i]+min(sol(arr,i+1,j-1),sol(arr,i,j-2)))
Build dp from this*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<vector<int>> dp(n,vector<int>(n));
	for(int i=0;i<n-1;i++)
		dp[i][i+1]=max(v[i],v[i+1]);
	for(int g=3;g<n;g=g+2)
	{
		for(int i=0;i+g<n;i++)
		{
			int j=i+g;
			dp[i][j]=max((v[i]+min(dp[i+2][j],dp[i+1][j-1])),(v[j]+min(dp[i+1][j-1],dp[i][i-2])));
		}
	}
	cout<<dp[0][n-1];
}