#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string STR;

int S,t,sum=0;
vector<int>bars;
vector<int> path;
vector<vector<int>> all;
/*
       for all valid options:
           do
           recurse
           undo
   */

void rec(int i){
   if(i == S){
      if(sum == t){
         all.push_back(path);
      }
      return;
   }
   // take
   if(sum + bars[i] <= t) // if condition for pruning
   {
      sum+=bars[i];
      path.push_back(bars[i]);
      rec(i+1);
      sum-=bars[i];
      path.pop_back();
   }
   // leave
   rec(i+1);
}
int main(){
   cin >> S >> t;
   for(int x = 0 ; x< S ; x++) {
      int k;cin>>k;
      bars.push_back(k);
   }
   rec(0);
   for(vector<int> vec : all)
   {
      for(int x : vec) cout << x << " ";
      cout << "\n";
   }
}