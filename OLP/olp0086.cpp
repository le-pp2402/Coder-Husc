#include <bits/stdc++.h>

#ifdef DEBUG
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
typedef long long i64;
typedef vector<int> vi;

struct q {
  int l, r, id;
};

vi a;
vi st;
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
  } else {
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
  }
}

void upd(int id, int l, int r, int pos, int val) {
  if (l == r) {
    st[id] = val;
    a[l] = val;
  } else {
    int m = (l + r) >> 1;
    if (pos <= m)
      upd(id << 1, l, m, pos, val);
    else
      upd(id << 1 | 1, m + 1, r, pos, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
  }
}
int get(int id, int l, int r, int u, int v) {
  if (u > r || v < l) return 0;
  if (u <= l && r <= v) return st[id];
  int m = (l + r) >> 1;
  return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  // freopen("in", "r", stdin);
  int n, qr;
  cin >> n >> qr;
  vi nxt(n);
  a.assign(n, 0);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = i;
    } else {
      nxt[mp[a[i]]] = i;
      mp[a[i]] = i;
    }
  }
  a.assign(n, -2);
  for (int i = 0; i < n; i++) {
    if (a[i] == -2) {
      for (int j = 0, ii = i;; j++, ii = nxt[ii]) {
        a[ii] = (j >= 3 ? 0 : j);
        if (j == 2) a[ii] = -1;
        if (nxt[ii] == 0) break;
      }
    }
    debug(a);
  }
  debug(a);
  debug(nxt);
  st.assign(n << 2, 0);
  build(1, 0, n - 1);
  vector<q> qry(qr);
  for (int i = 0; i < qr; i++) {
    cin >> qry[i].l >> qry[i].r;
    qry[i].l--;
    qry[i].r--;
    qry[i].id = i;
  }
  sort(qry.begin(), qry.end(), [](q q1, q q2) { return q1.l <= q2.l; });
  vi res(qr);
  for (int i = 0, x = 0; i < n; i++) {
    debug(i, a);
    if (x < qr && i < qry[x].l) {
      upd(1, 0, n - 1, i, 0);
      for (int j = 0, ii = nxt[i]; j < 3; ii = nxt[ii], j++) {
        if (ii == 0) break;
        if (j == 0 || j == 1)
          upd(1, 0, n - 1, ii, j);
        else
          upd(1, 0, n - 1, ii, -1);
        debug(a);
      }
    } else {
      while (x < qr && qry[x].l == i) {
        res[qry[x].id] = get(1, 0, n - 1, qry[x].l, qry[x].r);
        x++;
      }
      if (x < qr && i < qry[x].l) {
        upd(1, 0, n - 1, i, 0);
        for (int j = 0, ii = nxt[i]; j < 3; ii = nxt[ii], j++) {
          if (ii == 0) break;
          if (j == 0 || j == 1)
            upd(1, 0, n - 1, ii, j);
          else
            upd(1, 0, n - 1, ii, -1);
        }
        debug(a);
      }
    }
  }
  for (int i = 0; i < qr; i++) cout << res[i] << '\n';
  return 0;
}