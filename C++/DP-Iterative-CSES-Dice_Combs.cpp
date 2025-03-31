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

vector p = {1,2,3,4,5,6};

void solve() {
    int n;cin>>n;
    int dp[n+1] = {};
    dp[0]=1;
    for(int x = 1 ; x <= n ;x++) {
        for(int c = 1 ; c <=  6; c++) {
            if(x-c >=0) {
                dp[x]+=dp[x-c];
                if(dp[x] > 1e9+7) dp[x]-=1e9+7;
            }
        }
    }
    cout << dp[n];
}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
