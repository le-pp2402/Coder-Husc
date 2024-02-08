#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  i64 n;
  cin >> n;
  n *= 8;
  vector<pair<i64, i64>> s;
  for (i64 i = 1; i * i <= n; i++) {
    if (n % i == 0 && (i + n / i) % 2 == 0) {
      // a - 2l + 1 = i
      // a + 2l - 1 = n/i
      // 2a = i + n/i =
      i64 a = (i + (n / i)) / 2;
      if ((n / i + 1 - a) % 2 == 0 && (a - 1) % 2 ==0) {
        i64 l = (n / i + 1 - a) / 2;
        i64 r = (a - 1) / 2;
        if (l != r) {
          s.push_back({ l, r });
        }
      }
    }
  }
  sort(s.begin(), s.end(), greater<pair<i64, i64>>());
  for (auto x : s) cout << x.first << ' ' << x.second << '\n';
}