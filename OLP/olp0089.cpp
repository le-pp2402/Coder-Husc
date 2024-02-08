#include <bits/stdc++.h>

#ifdef DEBUG
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
typedef long long i64;
typedef vector<int> vi;

const int N = 200001;

vector<int> st[N << 2];
vi a(N);

void build(int id, int l, int r) {
  if (l == r) {
    st[id].push_back(a[l]);
  } else {
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    merge(st[id << 1].begin(), st[id << 1].end(), st[id << 1 | 1].begin(),
          st[id << 1 | 1].end(), std::back_inserter(st[id]));
  }
}
int qry(int id, int l, int r, int u, int v, int dep) {
  if (u > r || v < l) return 0;
  if (u <= l && r <= v) {
    int i = lower_bound(st[id].begin(), st[id].end(), dep) - st[id].begin();
    int j = upper_bound(st[id].begin(), st[id].end(), dep) - st[id].begin();
    return j - i;
  }
  int m = (l + r) / 2;
  return qry(id << 1, l, m, u, v, dep) + qry(id << 1 | 1, m + 1, r, u, v, dep);
}

vi adj[N];
vi V = {0};
vi depth;
vi sz;
void dfs(int u, int d) {
  depth[u] = d;
  V.push_back(u);
  sz[u] = 1;
  for (int &i : adj[u]) {
    dfs(i, d + 1);
    sz[u] += sz[i];
  }
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  // freopen("in", "r", stdin);
  int n;
  cin >> n;
  depth.resize(n + 1);
  sz.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    adj[u].push_back(i);
  }
  dfs(1, 0);
  vi pos(n + 1);
  for (int i = 1; i <= n; i++) a[i] = depth[V[i]];
  for (int i = 1; i <= n; i++) pos[V[i]] = i;

  build(1, 1, n);
  int qr;
  cin >> qr;
  for (int i = 0; i < qr; i++) {
    int u, v;
    cin >> u >> v;
    cout << qry(1, 1, n, pos[u], pos[u] + sz[u] - 1, v) << '\n';
  }
  return 0;
}