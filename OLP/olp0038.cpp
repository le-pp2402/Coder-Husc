#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1000000007;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int b, d;
    cin >> b >> d;
    i64 div = __gcd(b, d);
    int m = d / div;
    int n = b / div;
    cout << (b - 1) / m << '\n';
  }
  return 0;
}