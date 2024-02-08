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
    int n, m;
    cin >> n >> m;
    vi deg(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      deg[u]++;
      deg[v]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) if (deg[i] < 2) cnt++;
    cout << (cnt + 1) / 2;
  };
  
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}