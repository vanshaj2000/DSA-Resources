#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vno;
	int n;
	cin>>n>>vno;
	vector<pair<int,int>> v;
	vector<int> weight(vno);
	for(int i=0;i<vno;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b});
		weight[i]=c;
	}
	//for(int i=0;i<vno;i++)
		//cout<<weight[i]<<endl;
	vector<int> dist(n,INT_MAX-1);
	dist[0]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<vno;j++)
		{
			if((dist[v[j].first]!=INT_MAX)&&dist[v[j].second]>(dist[v[j].first]+weight[j]))
				dist[v[j].second]=(dist[v[j].first]+weight[j]);
		}
	}
	int flag=0;
	for(int i=0;i<vno;i++)
	{
		if((dist[v[j].first]!=INT_MAX)&&dist[v[j].second]>(dist[v[j].first]+weight[j]))
			flag=1;
	}
	if(flag==0)
	{
		for(int i=0;i<n;i++)
			cout<<dist[i]<<endl;
	}
	else
		cout<<"Graph has negative cycle";
}