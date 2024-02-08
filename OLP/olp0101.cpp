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
  
  auto solve = [&] () {
    int n, m;
    cin >> n >> m;
    vi par(n), sz(n);
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      union_sets(u, v);
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, sz[i]);
    cout << ans << '\n';
  };
  
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}