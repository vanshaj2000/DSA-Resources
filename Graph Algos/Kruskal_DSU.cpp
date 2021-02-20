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
vector<int> parent;
vector<int> size;
bool cusComp(vector<int> a,vector<int> b)
{
    return a[2]<b[2];
}
void make_set(int n)
{
    for(int i=0;i<n;i++)
    {
        parent.push_back(i);
        size.push_back(1);
    }
}
int find_set(int v)
{
    if(parent[v]==v)
        return v;
    return parent[v]=find_set(parent[v]);     //This is called path compression
}
void union_set(int a,int b)
{
    if(size[a]>=size[b])
    {
        parent[b]=a;
        size[a]+=size[b];
    }
    else
    {
        parent[a]=b;
        size[b]+=size[a];
    }
}
int main()
{
    parent.clear();
    size.clear();
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int vno;
	int n;
	cin>>n>>vno;
	vector<vector<int>> v(vno,vector<int>(3));
	for(int i=0;i<vno;i++)
		cin>>v[i][0]>>v[i][1]>>v[i][2];
    sort(v.begin(),v.end(),cusComp);
    /*for(int i=0;i<vno;i++)
        cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;*/
    make_set(n);
    vector<vector<int>> ans;
    ll cost=0;
    for(int i=0;i<vno;i++)
    {
        //cout<<"Hello "<<cost<<endl;
        if(ans.size()==n-1)
            break;
        if(find_set(v[i][0])!=find_set(v[i][1]))
        {
            union_set(v[i][0],v[i][1]);
            ans.push_back(v[i]);
            cost+=v[i][2];
        }
    }
    cout<<cost<<endl;
    for(int i=0;i<n-1;i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    return 0;
}