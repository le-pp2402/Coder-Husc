#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  i64 R;
  cin >> R;
  i64 x = R + 1, y = 0;
  for (i64 i = 1; i <= R; i++) {
    i64 l = 0, r = 1e10;
    while (l + 1 < r) {
      i64 m = (l + r) / 2;
      if (m * m + i * i > R * R) {
        r = m;
      }
      else {
        l = m;
      }
    }
    if (r * r + i * i < x * x + y * y) {
      x = i;
      y = r;
    }
  }
  cout << x << ' ' << y;
}