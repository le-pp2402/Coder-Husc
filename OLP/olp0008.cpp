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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(a.begin(), a.end());
  sort(b.begin(), b.end());
  map<int, int> mp;
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i % k == k - 1) cnt++;
    mp[b[i]] = cnt;
  }
  for (int i = 0; i < n; i++) {
    b[i] = mp[a[i]];
  }
  reverse(b.begin(), b.end());
  debug(b);
  vector<int> ANS(n + 1, INF);
  for (int i = 0; i < n; i++) {
    auto j = upper_bound(ANS.begin(), ANS.end(), b[i]) - ANS.begin();
    if (b[i] <= ANS[j]) {
      ANS[j] = b[i];
    }
  }
  debug(ANS);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (ANS[i] != INF) {
      ans = max(ans, i + 1);
    }
  }
  cout << n - ans;
}