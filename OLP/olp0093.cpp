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

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  
  #ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  const int N = 1000001;
  vector<i64> pr(N);
  for (int i = 0; i < N; i++) pr[i] = i;

  for (i64 i = 2; i < N; i++) {
    if (pr[i] == i) {
      for (i64 j = i * i; j < N; j += i) {
        pr[j] = i;
      }
    }
  }

  auto solve = [&] () {
    int n, m;
    cin >> n >> m;
    vi adj[n + 1];
    vi deg(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      deg[u]++;
      deg[v]++;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= (deg[i] % 2 == 0);
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  };
  
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}