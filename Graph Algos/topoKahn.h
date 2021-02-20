vector<int> topoKahn(vector<int> inDeg,vector<vector<int>> v)
{
	int n=v.size();
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(inDeg[i]==0)
			q.push(i);
	}
	vector<int> ans;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		ans.push_back(u);
		for(int i=0;i<v[u].size();i++)
		{
			inDeg[v[u][i]]--;
			if(inDeg[v[u][i]]==0)
				q.push(v[u][i]);
		}
	}
	return ans;
}