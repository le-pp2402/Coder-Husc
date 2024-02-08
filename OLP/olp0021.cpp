// #include "debug.h"
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

map<i64, vector<i64>> mp;
map<i64, int> cnt;

i64 f(i64 val, i64 num) {
  i64 ret = 0;
  for (int i = 0; i < num; i++) ret += mp[val][i];
  return ret;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  int N, W;
  cin >> N >> W;
  vector<i64> w(N), v(N);

  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
    mp[w[i]].push_back(v[i]);
    cnt[w[i]]++;
  }

  for (auto& [x, y] : mp) {
    sort(y.begin(), y.end(), greater<i64>());
  }

  i64 total = 0;
  for (int i = 0; i <= cnt[w[1]]; i++) {
    for (int j = 0; j <= cnt[w[1] + 1]; j++) {
      for (int k = 0; k <= cnt[w[1] + 2]; k++) {
        for (int z = 0; z <= cnt[w[1] + 3]; z++) {
          i64 a = w[1], b = w[1] + 1, c = w[1] + 2, d = w[1] + 3;
          if (a * i + b * j + c * k + d * z <= W) {
            total = max(total, f(a, i) + f(b, j) + f(c, k) + f(d, z));
          }
        }
      }
    }
  }
  cout << total << '\n';
  return 0;
}