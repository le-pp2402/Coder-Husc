#include <bits/stdc++.h>

using namespace std;

#define i64 long long
#define vi vector<int>
#define fi first
#define se second

int main() {
  
  cin.tie(0)->ios::sync_with_stdio(0);
  
  if (fopen("in", "r")) {
    freopen("in", "r", stdin);
  }

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
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ok &= (deg[i] >= 2);
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
