#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int solve(int a,int b,int k,vector<int> &v)
{
    if(k==1)
        return accumulate(v.begin()+a,v.begin()+b+1,0);
    else if(b>a)
    {
        int mini=INT_MAX;
        for(int i=a;i<=b;i++)
            mini=min(mini,max(accumulate(v.begin()+a,v.begin()+i+1,0),solve(i+1,b,k-1,v)));
        return mini;
    }
    else
        return 0;
}
int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<solve(0,n-1,k,v)<<" ";
        vector<vector<int>> dp(k+1,vector<int>(n+1));
        for(int i=1;i<=n;i++)
            dp[1][i]=accumulate(v.begin(),v.begin()+i,0);
        for(int i=1;i<=k;i++)
            dp[i][1]=v[0];
        for(int i=2;i<=k;i++)
        {
            for(int j=2;j<=n;j++)
            {
                int mini=INT_MAX;
                for(int p=1;p<j;p++)
                    mini=min(mini,max(dp[i-1][p],accumulate(v.begin()+p,v.begin()+j,0)));
                dp[i][j]=mini;
            }
        }
        cout<<dp[k][n]<<endl;
    }
    return 0;
}