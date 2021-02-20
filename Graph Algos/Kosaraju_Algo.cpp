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
void dfsP(vector<bool>& vis,vector<vector<int>>& v,int ver)
{
	vis[ver]=true;
	cout<<ver;
	for(int i=0;i<v[ver].size();i++)
	{
		int u=v[ver][i];
		if(vis[v[ver][i]]==false)
		{
			cout<<" ";
			dfsP(vis,v,v[ver][i]);
		}
	}
}
int main()
{
	int vno;
	int n;
	cin>>n>>vno;
	vector<vector<int>> v(n);
	vector<vector<int>> t(n);
	for(int i=0;i<vno;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		t[b].push_back(a);
	}
	stack<int> s;
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++)
	{
		if(vis[i]==false)
			dfsRec(vis,s,v,i);
	}
	vector<bool> vis2(n,false);
	while(!s.empty())
	{
		if(vis2[s.top()]==false)
		{
			dfsP(vis2,t,s.top());
			s.pop();
			cout<<endl;
		}
		else
			s.pop();
	}
}