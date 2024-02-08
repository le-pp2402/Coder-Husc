#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

i64 powf(i64 a, i64 b) {
  if (b == 0) return 1;
  i64 z = powf(a, b / 2);
  if (b % 2 == 0) return z * z % M;
  return z * z % M * a % M;
}
i64 f(i64 n) {
  return (n * (n + 1) % M * (n + 2) % M * powf(3LL, M - 2) % M - (n * (n + 1) / 2) % M + M) % M;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double A, B;
  cin >> A >> B;
  i64 a, b;
  a = ceil(A);
  b = (i64)B;
  cout << f(b) - f(a - 1);
}