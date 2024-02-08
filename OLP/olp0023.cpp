// #include "debug.h"
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;
const int N = 200001;

vector<int> a[N];
vector<int> vis(N);

void dfs(int u) {
  vis[u] = true;
  for (int& x : a[u]) {
    if (vis[x] == false) dfs(x);
  }
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pii> edge(m + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edge[i + 1] = { x, y };
  }
  int q;
  cin >> q;
  while (q--) {
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= n; i++) vis[i] = false;
    int l, r;
    cin >> l >> r;
    for (int i = 1; i <= m; i++) {
      if (l <= i && i <= r) continue;
      a[edge[i].first].push_back(edge[i].second);
      a[edge[i].second].push_back(edge[i].first);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (vis[i] == false) {
      dfs(i);
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}