#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef string STR;
typedef long long ll;
const int MAX = (int)1e5+1;


void solve() {
    int n;cin>>n;
    vector<int> vec(n);
    for(auto& x : vec) cin >>x; // o(n)

    bitset<MAX> dp;
    
    dp[0] = 1;

    for(int x : vec){
        dp |= (dp << x);
    } // o(MAX)

    vector<int> vec2;
    for(int x = 1 ; x<= MAX ; x++){
        if(dp[x]) vec2.push_back(x);
    }

    cout << vec2.size() << "\n";
    for(auto x : vec2) cout << x << " ";
        // Time = o(MAX)
        // space = o(N + MAX)

}

signed main() {
    FastIO;
    #ifdef USACO
        setIO("lineup");
    #endif
    solve();
    return 0;
 
}
