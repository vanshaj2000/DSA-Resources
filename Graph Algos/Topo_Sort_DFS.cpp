#include<bits/stdc++.h>
using namespace std;
void dfsRec(vector<bool>& vis,stack<int> &s,vector<vector<int>>& v,int ver)
{
	vis[ver]=true;
	for(int i=0;i<v[ver].size();i++)
	{
		int u=v[ver][i];
		if(vis[v[ver][i]]==false)
			dfsRec(vis,s,v,v[ver][i]);
	}
	s.push(ver);
}
int main()
{
	int vno;
	int n;
	cin>>n>>vno;
	vector<vector<int>> v(n);
	for(int i=0;i<vno;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	stack<int> s;
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++)
	{
		if(vis[i]==false)
			dfsRec(vis,s,v,i);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}