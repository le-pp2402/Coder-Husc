#include <bits/stdc++.h>

using namespace std;

int par[10001];
int sz[10001];
int fi(int u) {
  return ((par[u] == u) ? u : (par[u] = fi(par[u])));
}
void union_sets(int u, int v) {
  u = fi(u);
  v = fi(v);
  if (u != v) {
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
  }
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  for (int i = 0; i < 10001; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  int q;
  cin >> q;
  while (q--) {
    int op, x, y;
    cin >> x >> y >> op;
    if (op == 1) {
      union_sets(x, y);
    }
    else {
      x = fi(x);
      y = fi(y);
      cout << (x == y) << '\n';
    }
  }
}