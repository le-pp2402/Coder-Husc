#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int N = 3e5 + 1;
pair<i64, i64> st[N << 2];
vector<pair<i64, i64>> a;
void build(int id, int l, int r) {
  if (l == r) {
    st[id].first = a[l].second;
    st[id].second = l;
  }
  else {
    int m = (l + r) / 2;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    if (st[id << 1].first >= st[id << 1 | 1].first) {
      st[id].first = st[id << 1].first;
      st[id].second = st[id << 1].second;
    }
    else {
      st[id].first = st[id << 1 | 1].first;
      st[id].second = st[id << 1 | 1].second;
    }
  }
}
void upd(int id, int l, int r, int p) {
  if (l == r) {
    st[id].first = -1;
  }
  else {
    int m = (l + r) / 2;
    if (p <= m) upd(id << 1, l, m, p);
    else upd(id << 1 | 1, m + 1, r, p);
    if (st[id << 1].first >= st[id << 1 | 1].first) {
      st[id].first = st[id << 1].first;
      st[id].second = st[id << 1].second;
    }
    else {
      st[id].first = st[id << 1 | 1].first;
      st[id].second = st[id << 1 | 1].second;
    }
  }
}
pair<i64, i64> qry(int id, int l, int r, int u, int v) {
  if (u > r || v < l) return { -1, 0 };
  if (u <= l && r <= v) return st[id];
  else {
    int m = (l + r) / 2;
    pair<i64, i64> L = qry(id << 1, l, m, u, v);
    pair<i64, i64> R = qry(id << 1 | 1, m + 1, r, u, v);
    if (L.first >= R.first) {
      return L;
    }
    else {
      return R;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("in", "r")) {
    freopen("in", "r", stdin);
  }
  int n, m;
  cin >> n >> m;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  build(1, 1, n);
  vector<i64> c(m);
  for (int i = 0; i < m; i++) cin >> c[i];
  sort(c.begin(), c.end());
  i64 total = 0;
  for (int i = 0; i < m; i++) {
    int j = (int)(lower_bound(a.begin(), a.end(), make_pair(c[i] + 1, 0LL)) - a.begin() - 1);
    if (j == 0) continue;
    pair<i64, i64> g = qry(1, 1, n, 1, j);
    total += max(0LL, g.first);
    upd(1, 1, n, (int)g.second);
  }
  cout << total << '\n';
}