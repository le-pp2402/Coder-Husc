// v=0b-Q-uO2oYk
// #include "debug.h"
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int INF = 1e6;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  i64 a, b, k;
  cin >> a >> b >> k;
  
  while (k && !(a == 0 && b == 0)) {
    if (a == 0) {
      i64 z = min(k, b);
      k -= z;
      b -= z;
    }
    else {
      i64 z = min(k, a);
      k -= z;
      a -= z;
    }
  }
  cout << a << ' ' << b;
}