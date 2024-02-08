#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int N = 10011;
vector<int> a[N], vis(N);
vector<int> low(N), num(N);
stack<int> s;
int ans = 0, DFSTimer = 0;
void dfs(int u) {
  num[u] = low[u] = ++DFSTimer;
  s.push(u);
  for (int& i : a[u]) {
    if (vis[i] == true) continue;
    if (num[i]) {
      low[u] = min(low[u], num[i]);
    }
    else {
      dfs(i);
      low[u] = min(low[u], low[i]);
    }
  }
  if (low[u] == num[u]) {
    ans++;
    int v = -1;
    while (v != u) {
      v = s.top();
      vis[v] = true;
      s.pop();
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u == v) continue;
    a[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == 0) dfs(i);
  }
  cout << ans;
  return 0;
}