#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef string STR;
typedef long long ll;

const int N = 1e5+3;
const int M = 1e5+3;
const ll MOD = 1e9+7;
vector<vector<int>> dp(1e6+1 , vector<int>(2));

void solve() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        dp[n][1]=1;
        dp[n][0]=1;

        for(int x = n-1 ; x >= 0 ; x--){
            dp[x][1] = (4LL * dp[x+1][1] + dp[x+1][0]) % MOD;
            dp[x][0] = (2LL * dp[x+1][0] + dp[x+1][1]) % MOD;
        }
        cout << (dp[1][0] + dp[1][1]) % MOD << "\n";

    }
}

signed main() {
    FastIO;
    #ifdef USACO
        setIO("lineup");
    #endif
    solve();
    return 0;
 
}
