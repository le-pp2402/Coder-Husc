#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int N = 55;
vector<int> a[N];
vector<int> num(N);
vector<int> edge[N];
map<pii, bool> mp;

void init() {
  for (int i = 0; i < N; i++) {
    a[i].clear();
    edge[i].clear();
    num[i] = 0;
  }
}
int dfsTimer = 0;
void dfs(int u, int v) {
  num[u] = ++dfsTimer;
  for (int& i : a[u]) {
    if (i == v) continue;
    if (num[i]) {
      if (mp[{min(u, i), max(u, i)}] == false)
        edge[u].push_back(i);
      mp[{min(u, i), max(u, i)}] = true;
    }
    else {
      edge[u].push_back(i);
      dfs(i, u);
    }
  }
}
void solve() {
  init();
  mp.clear();
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 0; i < n; i++) {
    if (deg[i + 1] == 1) {
      cout << "NO\n";
      return;
    }
  }
  dfs(1, 1);
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j : edge[i]) {
      cout << i << ' ' << j << '\n';
    }
  }
  dfsTimer = 0;
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  if (fopen("i", "r")) {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
  }
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}