#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;

const int N = 5e5+1;
void solve() {
    int n;cin>>n;
    int dp[n][n][2];
    vector<int>vec(n);

    for(auto& x : vec) cin >> x;


    for(int x = 0 ; x < n ; x++){
        dp[x][x][0] = vec[x];
        dp[x][x][1] =0;
    }

    for(int c = 2 ;c <= n ; c++){
        for(int x = 0 ; x +c-1 <n ; x++){
            int j = x+c-1;

            dp[c][j][0] = max(
                vec[c] + dp[c+1][j][1],
                vec[c] + dp[c][j-1][1]
            );

            dp[c][j][1] = max(
                dp[c+1][j][0],
                dp[c][j-1][0]
            );
        }
    }
    cout <<dp[0][n-1][0];
    

}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
