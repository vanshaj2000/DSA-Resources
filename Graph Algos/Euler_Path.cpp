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

//This algorithm is basically used to calculate ancestors very easily
void Euler_Tour(int ind,vector<vector<int>> &adj,vector<bool> &vis,int *time,vector<int> &time_in,vector<int> &time_out)
{
    vis[ind]=true;
    time_in[ind]=*time;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(vis[u]==false)
        {
            (*time)++;
            Euler_Tour(u,adj,vis,time,time_in,time_out);
        }
    }
    (*time)++;
    //cout<<*time<<endl;
    time_out[ind]=(*time);
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,e;
    cin>>n>>e;
    //cout<<"hemlo"<<endl;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    vector<int> time_in(n);
    vector<int> time_out(n);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int t=1;
    Euler_Tour(0,adj,vis,&t,time_in,time_out);
    //cout<<"j"<<endl;
    for(int i=0;i<n;i++)
        cout<<time_in[i]<<" "<<time_out[i]<<endl;
    return 0;
}