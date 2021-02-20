#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vno;
	int n;
	cin>>n>>vno;
	vector<int> inDeg(n,0);
	vector<vector<int>> v(n);
	for(int i=0;i<vno;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		inDeg[b]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(inDeg[i]==0)
		{
			//cout<<i<<endl;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=0;i<v[u].size();i++)
		{
			inDeg[v[u][i]]--;
			if(inDeg[v[u][i]]==0)
				q.push(v[u][i]);
		}
	}
}