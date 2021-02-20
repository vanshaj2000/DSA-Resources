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
//Hamiltonian cycle ia a cycle in which every node is visited once and we reach at starting block
//Bitmasking is used here
/*
    If you want to understand only the recursive approach, remove the dp array and
    remove line 30 and 31 and in the last return just return ans
*/
int tsp(int mask,int pos,vector<vector<int>> &adj,vector<vector<int>> &dp)
{
    int ans=INT_MAX;
    int n=adj.size();
    int vall=(1<<n)-1;
    if(mask==vall)//if we have reached mask 1111...
        return adj[pos][0];//returning the base when we have traveled every node
    if(dp[mask][pos]!=-1)
        return dp[mask][pos];
    for(int city=0;city<n;city++)//Checking for every city
    {
        if((mask&(1<<city))==0)//checking if its is visited
        {
            int temp=adj[pos][city]+tsp(mask|((1<<city)),city,adj,dp);//recursive call
            ans=min(ans,temp);
        }
    }
    return dp[mask][pos]=ans;
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
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        adj[x][y]=c;
        adj[y][x]=c;
    }
    vector<vector<int>> dp(1<<n,vector<int>(n,-1));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout<<adj[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<"Min weight hamiltonian cycle is "<<tsp(1,0,adj,dp);
    return 0;
}