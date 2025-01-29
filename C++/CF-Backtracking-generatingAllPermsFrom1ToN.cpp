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
void rec(vector<int>&vec , int start , vector<vector<int>>&mat)
{
   if(start == vec.size())
   {
      mat.push_back(vec);
      return;
   }
   for(int x = start ; x < vec.size() ; x++)
   {
      swap(vec[start],vec[x]);
      rec(vec,start+1,mat);
      swap(vec[start],vec[x]);
   }
}

int solve()
{
   int n;cin>>n;
   vector<int>vec;
   for(int x = 0 ; x < n ; x++)
   {
      vec.push_back(x+1);
   }
   vector<vector<int>> mat;
   rec(vec,0,mat);
   sort(mat.begin(),mat.end());
   for(auto x : mat)
   {
      for(int c = 0 ; c < x.size() ; c++)
      {
         if(c == x.size()-1) cout <<x[c];
         else cout << x[c] << " ";
      }
      cout << "\n";
   }
}

