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
constexpr int inf = 0x3f3f3f3f;
using namespace std;

void solve() {
    int n ,k;cin>>n>>k;
    int s[n];for(auto&x : s) cin >>x;

    vector dp(k+1,inf);
    dp[0]=0;
    for(int x = 1; x<= k ; x++) {
        for(auto it : s) {
            if(x-it >= 0) {
                dp[x] = min(dp[x-it]+1,dp[x]);
            }
        }
    }
    if(dp[k] == inf)  dp[k]=-1;
    cout << dp[k];
}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
