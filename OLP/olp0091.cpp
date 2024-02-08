#include <bits/stdc++.h>

#ifdef DEBUG
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
typedef long long i64;
typedef vector<int> vi;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  i64 a, b, c;
  cin >> a >> b >> c;
  if (c % 2 != 0) {
    if (a < b) cout << "<";
    if (a == b) cout << "=";
    if (a > b) cout << ">";
  } else if (c % 2 == 0) {
    if (abs(a) < abs(b)) cout << "<";
    if (abs(a) == abs(b)) cout << "=";
    if (abs(a) > abs(b)) cout << ">";
  }
  return 0;
}
