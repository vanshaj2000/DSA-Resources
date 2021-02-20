#include<bits/stdc++.h>
using namespace std;
bool dfsRec(vector<bool>& vis,vector<bool>& stck,vector<vector<int>>& v,int ver)
{
	vis[ver]=true;
	stck[ver]=true;
	for(int i=0;i<v[ver].size();i++)
	{
		int u=v[ver][i];
		if(vis[v[ver][i]]==false&&dfsRec(vis,stck,v,u))
			return true;
		else if(stck[u]==true)
			return true;
	}
	stck[ver]=false;
	return false;
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
	vector<bool> vis(n,false);
	vector<bool> stck(n,false);
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==false&&dfsRec(vis,stck,v,i))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"No Cycle Present";
	else
		cout<<"Cycle Present";
}