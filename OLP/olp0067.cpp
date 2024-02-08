#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
i64 frac[10];
int main() {
  frac[0] = 1;
  for (i64 i = 1; i < 10; i++)
    frac[i] = frac[i - 1] * i;
  i64 res = 0;
  int n;
  cin >> n;
  for (int i = 10; i < n; i++) {
    string num = to_string(i);
    i64 cur = 0;
    for (char &c: num)
      cur += frac[c - '0'];
    if (cur % i == 0) {
      res += i;
    }
  }
  cout << res << '\n';
}