#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string STR;

STR current,remaining;
STR p;
set<STR> perms;
vector<bool> used;
set<string> uniquePermutations;
/*
    options are current string , remaining string
    for all valid options (didn't used , didn't appear twice in the same recursion level)
    do , recurse , undo
 */

void generatePermutations(string &current, string &remaining, vector<bool> &used) {
   if (current.size() == remaining.size()) {
      uniquePermutations.insert(current);
      return;
   }

   for (int i = 0; i < remaining.size(); i++) {
      if (used[i]) continue;

      if (i > 0 && remaining[i] == remaining[i - 1] && !used[i - 1]) continue;

      used[i] = true;
      current.push_back(remaining[i]);

      generatePermutations(current, remaining, used);

      current.pop_back();
      used[i] = false;
   }
}


int main(){
   string input;
   cin >> input;

   sort(input.begin(), input.end());

   string current = "";
   vector<bool> used(input.size(), false);
   generatePermutations(current, input, used);

   cout << uniquePermutations.size() << endl;
   for (const auto &perm : uniquePermutations) {
      cout << perm << endl;
   }
   return 0;

}