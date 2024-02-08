#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define db         42
#endif

using i64 = long long;
using pii = pair<int, int>;
using arr = array<int, 3>;

#define fi first;
#define se second;

const i64 M = 1000000007;
const int N = 500001;

i64 f(i64 i) {
  if (i < 10) return i;
  i64 j = 0;
  while (i) {
    j += (i % 10);
    i /= 10;
  }
  return f(j);
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  if (fopen("i", "r")) {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
  }
  int q;
  cin >> q;
  while (q--) {
    i64 l, r;
    cin >> l >> r;
    i64 total = 0;
    if (r - l + 1 <= 27) {
      for (i64 i = l; i <= r; i++) total += f(i);
      cout << total << '\n';
      continue;
    }
    while (f(l) != 1) {
      total += f(l);
      l++;
    }
    while (f(r) != 9) {
      total += f(r);
      r--;
    }
    cout << total + (r - l + 1) / 9 * 45 << '\n';
  }
}