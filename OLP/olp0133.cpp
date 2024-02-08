#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#ifdef LOCAL
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;   
using vvi = vector<vi>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define isz(x) (int)x.size();
#define rall (x).rbegin(), (x).rend()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

#define int ll

void solve() {
  map<string, string> mp;
  string s;
  bool ok = false;
  while (getline(cin, s)) {
    if (s == "") {
      ok = true;
      continue;
    }
    if (ok) {
      cout << (mp.find(s) == mp.end() ? "eh" : mp[s]) << "\n";
    } else {
      bool pass = false;
      string t1 = "", t2 = "";
      for (char &c: s) {
        if (c == ' ') {
          pass = true;
          continue;
        }
        if (!pass) {
          t1 += c;
        } else {
          t2 += c;
        }
      }
      mp[t2] = t1;
    }
  }
}
signed main() {
  cin.tie(0); ios::sync_with_stdio(0);
  if (fopen("main.inp", "r")) {
    freopen("main.inp", "r", stdin);
  }
  solve();  
}