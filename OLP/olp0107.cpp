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
  #endif
  int n, m;
  cin >> n >> m;

  vi adj[n];
  vector<pii> edge;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge.push_back({u, v});
  }
  // kc tu 0 toi i
  constexpr i64 INF = LLONG_MAX;
  i64 dp[2][n] = {};
  for (int i = 0; i < n; i++) dp[0][i] = dp[1][i] = INF;
  deque<i64> dq;
  dp[0][0] = 0;
  // from 0 -> i 
  vi processed(n);
  dq.push_front(0);
  while (!dq.empty()) {
    i64 u = dq.back();
    dq.pop_back();
    if (processed[u]) continue;
    processed[u] = true;
    for (auto &v: adj[u]) {
      if (dp[0][v] > 1 + dp[0][u]) {
        dp[0][v] = dp[0][u] + 1;
        dq.push_front(v);  
      }   
    }
  }
  // from n - 1 -> i
  processed.assign(n, 0);
  dq.push_back(n - 1);
  dp[1][n - 1] = 0;
  while (!dq.empty()) {
    i64 u = dq.back();
    dq.pop_back();
    if (processed[u]) continue;
    processed[u] = true;
    for (auto &v: adj[u]) {
      if (dp[1][v] > 1 + dp[1][u]) {
        dp[1][v] = dp[1][u] + 1;
        dq.push_front(v);
      }
    }
  }
  for (int i = 0; i < n; i++) adj[i].clear();
  for (auto &[x, y]: edge) {
    if (dp[0][x] + 1 + dp[1][y] == dp[0][n - 1] || dp[1][x] + 1 + dp[0][y] == dp[0][n - 1]) {
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  for (int i = 0; i < n; i++) debug(adj[i]);
  constexpr i64 mod = 1000000007;
  vi calc(n);
  calc[0] = 1;
  processed.assign(n, 0);
  dq.push_back(0);
  while (!dq.empty()) {
    i64 u = dq.back();
    dq.pop_back();
    if (processed[u]) continue;
    processed[u] = true;
    for (auto &v: adj[u]) {
      if (processed[v]) continue;
      calc[v] = (calc[v] + calc[u]) % mod;
      dq.push_front(v);
    }
  }
  debug(calc);
  cout << calc[n - 1];
}