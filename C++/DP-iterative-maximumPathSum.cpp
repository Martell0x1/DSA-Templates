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

void solve() {
    int n,m;cin>>n>>m;
    vector grid(n,vector<int>(m,0));
    for(auto & r : grid) {
        for(auto & c : r) cin >> c;
    }
    vector dp(n+1,vector<int>(m+1,0));
    dp[0][0]=grid[0][0];
    for(int x = 1 ; x<m;x++)dp[0][x] = dp[0][x-1]+grid[0][x];
    for(int x = 1 ; x<n;x++)dp[x][0] = dp[x-1][0]+grid[x][0];

    for(int x = 1 ; x <n ; x++) {
        for(int c = 1 ; c < m ; c++) {
            dp[x][c] = max(dp[x-1][c],dp[x][c-1])+grid[x][c];
        }
    }
    cout << dp[n-1][m-1];
}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
