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


void setIO(STR name)
{
   // ofstream f(name+".in");
   ifstream infile(name+".in");
   if(!infile.good()) ofstream outfile(name+".in");
   freopen((name+".in").c_str(),"r",stdin);
   freopen((name+".out").c_str(),"w",stdout);
}

__int128 read(){
   __int128 x = 0 , f = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){
      if(ch == '-') f=-1;
      ch = getchar();
   }
   while(ch >= '0' && ch <= '9'){
      x = x* 10 + ch - '0';
      ch = getchar();
   }
   return x * f;
}
void print(__int128 x){
   if(x < 0){
      putchar('-');
      x*=-1;
   }
   if(x > 9)print(x/10);
   putchar(x %10 + '0');
}
 
const int MOD = 1e9+7;
void solve(){
    // #define InpFile
    int h,w;cin>>h>>w;
    vector<STR> grid(h);
    for(auto &x : grid) cin >> x;

    vector<vector<int>> dp(h,vector<int>(w,0));
    dp[0][0]=1;

    auto isValid = [&](int i , int j) -> bool {
        return i < h && j < w && grid[i][j] != '#';
    };

    for(int x = 0 ; x < h ; x++){
        for(int y = 0 ; y < w ; y++){
            if(isValid(x,y)){
                if(x > 0) dp[x][y] = (dp[x][y] + dp[x-1][y]) %MOD;

                if(y > 0) dp[x][y] = (dp[x][y] + dp[x][y-1]) %MOD;
            }
        }
    }
}

int main() {
   FastIO;
#ifdef InpFile
   setIO("inputFile");
#endif
   solve();
 
}
 
 
