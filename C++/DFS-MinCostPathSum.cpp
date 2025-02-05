/* Use the slash-star style comments or the system won't see your
identification information */
/*
ID: marawan1
TASK: test
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pv(v) for(auto x : v) cout << x << " ";
#define all(v) v.begin(), v.end()

typedef string STR;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<long long> vll;
typedef map<ll , ll> mpll;
using namespace std;

const int N_=10e5+6,M=2*10e5+6;
int m,n,u,v,c;
vector<pair<int,int>> adj[N_];
bool vis[N_];
unordered_map<int,int>mp;
ll c1=LONG_LONG_MAX , c2=1;

void dfs(int u,ll cur)
{
    vis[u]=true;
    if(adj[u].size() == 1 && u !=0){
        c1 = min(c1,cur);
        return;
    }
    for (auto x : adj[u]) {
        if (!vis[x.first]) {
            dfs(x.first, cur + x.second);
        }
    }
}

void solve()
{
   // #define USACO;
   cin>>n;
   for(int x = 0 ;x < n-1 ; x++){
    cin >>u >> v >> c;
    adj[u].push_back({v,c});
    adj[v].push_back({u,c});

   }
   dfs(0,0);
   cout << c1;
}

int main() {
   FastIO;
#ifdef USACO
   setIO("lineup");
#endif
   solve();

}




