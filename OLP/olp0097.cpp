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
  const int mod = 1000000007;
  auto solve = [&] () {
    int n, k, u, v;
    cin >> n >> k >> u >> v;
    int graph[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> graph[i][j];
      }
    } 
    --u;
    --v;
    i64 dp[n][n][k + 1] = {};
    for (int i = 0; i < n; i++) dp[i][i][0] = 1;

    for (int k_ = 1; k_ <= k; k_++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int m = 0; m < n; m++) {
            if (graph[j][m]) {
              dp[i][j][k_] = (dp[i][j][k_] + dp[i][m][k_ - 1]) % mod;
            }
          }
        }
      }
    }
    cout << dp[u][v][k] << ' ';
  };
  
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}