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

#define fi first
#define se second

const i64 M = 1000000007;
const int INF = 1000000111;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  if (fopen("i", "r")) {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
  }
  int n, m;
  cin >> n >> m;
  if (n % m == 0) {
    cout << 0;
    return 0;
  }
  else {
    // n / m
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
      if (n * i % m == 0 && n * i / m < n) {
        ans++;
      }
    }
    cout << m - 1 - ans << '\n';
  }
}