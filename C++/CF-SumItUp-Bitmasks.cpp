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


int main() {
   int t;cin>>t;
   while(t--)
   {
      int n,k;cin>>n>>k;
      vector<int>vec(n);
      set<vector<int>> st;
      for(auto& x :  vec) cin >> x;
      sort(vec.begin(),vec.end());

      for(int mask = 0 ; mask < (1ll << n) ; mask++)
      {
         vector<int> tmp;
         int sum = 0;
         for(int b = 0 ;b < n ; b++)
         {
            if((mask >> b)&1)
            {
               tmp.push_back(vec[b]);
               sum+=vec[b];
            }
         }
         if(sum == k)
         {
            st.insert(tmp);
         }
      }
      if(st.empty()) cout << "NONE\n";
      else{
         for(auto s : st)
         {
            for(auto x :s) cout << x<<" ";
            cout << endl;
         }
      }
      cout << endl;
   }
}
