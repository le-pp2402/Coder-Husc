#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double a, b, c, S;
  cin >> a >> b >> c >> S;
  if (a + b + c == 0) {
    cout << setprecision(6) << fixed << 0.0 << ' ' << 0.0 << ' ' << 0.0;
  }
  else {
    cout << setprecision(6) << fixed << S / (a + b + c) * a << ' ' << S / (a + b + c) * b << ' ' << S / (a + b + c) * c << '\n';
  }
  return 0;
}