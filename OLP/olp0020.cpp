// #include "debug.h"
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

vector<i64> dp(61);
i64 len(i64 n) {
  return (i64)log10(n) + 1;
}
i64 run(i64 n, i64 k) {
  if (n == 0) return -1;

  if (k <= len(n)) {
    string ret = to_string(n);
    return ret[k - 1] - '0';
  }
  if (n <= 60 && k > dp[n - 1] + len(n))
    return run(n - 1, k - dp[n - 1] - len(n));
  else
    return run(n - 1, k - len(n));
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  i64 N, K;
  cin >> N >> K;
  dp[1] = 1;
  for (i64 i = 2; i <= 60; i++) {
    dp[i] = len(i) + dp[i - 1] * 2LL;
  }
  // debug(dp);
  cout << run(N, K);

  return 0;
}