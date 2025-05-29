#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef string STR;
typedef long long ll;
const int MAX = (int)1e5+1;
const int inf = 0x3f3f3f;

void solve() {

    int n;cin>>n;
    vector<int> vec(n);
    for(auto& x : vec) cin >> x;

    vector<bool> dp(MAX);
    dp[0]=true;

    ll maxs = 0;
    int f = *min_element(vec.begin(),vec.end());
    for(auto x :vec){
        for(ll c = maxs ; c >= 0 ; c--){
            if(dp[c])
                dp[c+x]=true;
        }
        maxs+=x;
    }
    vector<int> vec2;
    for(ll x = f ; x <=maxs ; x++){
        if(dp[x]) vec2.push_back(x);
    }

    cout << vec2.size() << "\n";
    for(auto x : vec2) cout << x <<" ";

}

signed main() {
    FastIO;
    #ifdef USACO
        setIO("lineup");
    #endif
    solve();
    return 0;
 
}
