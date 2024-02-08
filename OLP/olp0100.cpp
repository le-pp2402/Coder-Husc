#include <bits/stdc++.h>

#ifdef DEBUG
#include "debuge.cpp"
#else
#define debug(...) 0
#endif

using namespace std;

using i64 = long long;
using vi = vector<i64>;
using pii = pair<int, int>;

struct TPoint {
  i64 x, y;
};
using ld = long double;
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  
  #ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  const int N = 100001;
  auto solve = [&] () {
    int n;
    cin >> n;
    vi par(N), sz(N);
    for (int i = 0; i < N; i++) {
      par[i] = i;
      sz[i] = 1;
    }
    function<int(int)> find_set = [&] (int u) {
      return ((u == par[u]) ? u : par[u] = find_set(par[u]));
    };
    auto union_sets = [&] (int u, int v) {
      u = find_set(u);
      v = find_set(v);
      if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
      }
    };
    map<string, int> mp;
    int cur = 1;
    for (int i = 0; i < n; i++) {
      string s, t;
      cin >> s >> t;
      if (mp[t] == 0) mp[t] = cur++;
      if (mp[s] == 0) mp[s] = cur++;
      int u = mp[t];
      int v = mp[s];
      union_sets(u, v);
      u = find_set(u);
      cout << sz[u] << '\n';
    }
  };
  
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}