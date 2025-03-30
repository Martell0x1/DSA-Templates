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

const int N =5, M= 1e3+1 , inf = 0x3f3f3f3f;
vector<int> vec = {1,5,10,25,50};

int dp[M][5];
int cc(int x , int n) {
    if(x == 0) return 1;
    if(n == -1) return 0;
    int& ret = dp[n][x];

    if(ret != -1) return ret;
    int op1 = (vec[n] <= x ? cc(x-vec[n],n):0);
    int op2 = cc(x,n-1);
    return ret=op1+op2;
}

void solve() {
    int n;cin>>n;
    int dp[1003]= {},ans=0;
    for(int x = 0 ; x < n ; x++) {
        int k;cin>>k;
        for(int l = 0;l<k;l++) {
            dp[k] = max(dp[k],dp[l]+1);
        }
        ans=max(ans,dp[x]);
    }
    cout << ans+1;
}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
