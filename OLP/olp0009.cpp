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

i64 c[33][33];
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  if (fopen("i", "r")) {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
  }
  for (int i = 0; i <= 30; i++) {
    c[0][i] = 1;
    c[i][i] = 1;
  }

  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j < i; j++) {
      c[j][i] = c[j][i - 1] + c[j - 1][i - 1];
    }
  }
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64& x : a) cin >> x;
  sort(a.begin(), a.end());
  i64 total = 0;
  for (int i = 1; i <= min(n, k); i++) {
    total += c[i][n] * c[i - 1][k - 1];
  }
  cout << max(total, 1LL) << ' ' << a[n - 1] * (k);
}