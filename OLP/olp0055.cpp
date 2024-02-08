/**
 * author:  Le Phi Phat
 * created: 2023
**/
#include <bits/stdc++.h>

#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  vector<string> vec;
  unordered_map<string, int> ump;
  string s;
  while (cin >> s) {
    ump[s]++;
    vec.push_back(s);
  }
  int n = vec.size();
  set<string> se;
  for (int i = 0; i < n; i++) {
    int sz = vec[i].size();
    for (int j = 1; j < sz - 1; j++) {
      string a = vec[i].substr(0, j);
      string b = vec[i].substr(j);
      if (ump[a] && ump[b]) {
        se.insert(vec[i]);
        break;
      }
    }
  }
  for (auto& x : se) cout << x << '\n';
}