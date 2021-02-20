#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> vis(n,false);
    int ans=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto best=pq.top();
        pq.pop();
        int to=best.second;
        int wt=best.first;
        if(vis[to])
            continue;
        ans+=wt;
        vis[to]=true;
        for(int i=0;i<adj[to].size();i++)
        {
            int u=adj[to][i].first;
            if(vis[u]==false)
                pq.push({adj[to][i].second,u});
        }
    }
    cout<<ans<<endl;
    return 0;
}