#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 10000001;
i64 pr[N];
i64 phi[N];
void sieve() {
  pr[1] = 1;
  for (int i = 2; i < N; i++) pr[i] = i;
  for (int i = 2; i < N; i++) {
    if (pr[i] == i) {
      for (i64 j = (i64)i * i; j < N; j += i) {
        pr[j] = i;
      }
    }
  }
}
static bool ok(i64 i) {
  string l = to_string(i);
  string r = to_string(phi[i]);
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  return (l == r);
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  sieve();
  phi[0] = 0;
  phi[1] = 1;
  for (i64 i = 2; i < N; i++) {
    if (phi[i] != 0) {
      continue;
    }
    else if (pr[i] == i) {
      phi[i] = i - 1;
      for (i64 j = i * i; j < N; j *= i) {
        phi[j] = j - j / i;
      }
    }
    else {
      i64 cur = 1, j = i;
      while (j % pr[i] == 0) {
        j /= pr[i];
        cur *= pr[i];
      }
      phi[i] = phi[cur] * phi[i / cur];
    }
  }
  i64 n;
  cin >> n;
  i64 x = 21, px = phi[21];
  for (i64 i = 2; i <= n; i++) {
    if (i * px < x * phi[i] && ok(i)) {
      x = i;
      px = phi[i];
    }
  }
  cout << x << '\n';
}
