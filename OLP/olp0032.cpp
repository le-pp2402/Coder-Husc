// v=0b-Q-uO2oYk

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, pair<int, int>>;

const int K = 100002;
i64 a[K];
i64 st[K << 2];

void Build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
  }
  else {
    int m = (l + r) / 2;
    Build(id * 2, l, m);
    Build(id * 2 | 1, m + 1, r);
    st[id] = st[id * 2] ^ st[id * 2 + 1];
  }
}
i64 qry(int id, int l, int r, int u, int v) {
  if (u > r || v < l) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m = (l + r) / 2;
  return qry(id * 2, l, m, u, v) ^ qry(id * 2 + 1, m + 1, r, u, v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[n] = a[n] ^ a[i];
  Build(1, 0, n);

  int q;
  cin >> q;
  while (q--) {
    i64 l, r;
    cin >> l >> r;
    l--, r--;
    int sz = n + 1;
    i64 ans = 0;
    if ((r - l + 1) <= sz) {
      if (l % sz < r % sz || l == r) {
        ans = qry(1, 0, n, l % sz, r % sz);
      }
      else {
        ans = qry(1, 0, n, l % sz, n) ^ qry(1, 0, n, 0, r % sz);
      }
    }
    else {
      ans = qry(1, 0, n, l % sz, n) ^ qry(1, 0, n, 0, r % sz);
      r -= (sz - r % sz + 1);
      l += sz - l % sz;
      i64 ti = (r - l + 1) / sz;
      if (ti % 2 == 1) {
        ans ^= qry(1, 0, n, 0, n);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
