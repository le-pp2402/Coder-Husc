// v=0b-Q-uO2oYk
#include <bits/stdc++.h>
// #include "debug.h"

using namespace std;

using i64 = long long;

const int INF = 1e6;

vector<i64> e2;

i64 m;

i64 powf(i64 a, i64 b) {
  if (b == 0) return 1;
  i64 ret = powf(a, b / 2);
  if (b % 2 == 0)
    return ret * ret % m;
  return (ret * ret % m) * (a % m) % m;
}
i64 rs(i64 x, i64 n, i64 m) {
  if (n == 0) return 1;
  i64 exp = 0, cur = n;
  for (i64 i = 0; i < 65 && cur - e2[i] >= 0; i++) {
    cur -= e2[i];
    exp = i;
  }
  // cout << exp << '\n';
  i64 ans = 1, cnt = 0;
  for (i64 i = 0; i < exp - 1; i++) {
    ans = (ans * ((1LL + powf(x, 1LL << i)) % m)) % m;
    cnt += (1LL << i);
  }
  return (ans % m + powf(x, cnt + 1LL) * rs(x, n - cnt - 1LL, m) % m) % m;
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  for (i64 i = 0; i < 65; i++) {
    e2.push_back(1LL << i);
  }
  // for (int i = 0; i < 63; i++) cout << e2[i] << '\n';
  i64 x, n;
  cin >> x >> n >> m;
  cout << rs(x, n, m);
  return 0;
}
