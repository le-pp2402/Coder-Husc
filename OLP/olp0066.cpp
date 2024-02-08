// #pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int N = 3165;
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  bitset<N> isPr;
  for (int i = 0; i < N; i++)
    isPr[i] = 1;
  isPr[0] = isPr[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isPr[i]) {
      for (int j = i * i; j < N; j += i) {
        isPr[j] = 0;
      }
    }
  }
  vector<i64> a = {2};
  for (int i = 3; i < N; i += 2)
    if (isPr[i])
      a.push_back(i);
  int sz = a.size();
  i64 n;
  cin >> n;
  bitset<10000001> ok;
  for (int i = 0; i < sz && a[i] * a[i] <= n; i++) {
    for (int j = 0; j < sz && a[i] * a[i] + a[j] * a[j] * a[j] <= n; j++) {
      for (int z = 0; z < sz && a[i] * a[i] + a[j] * a[j] * a[j] + a[z] * a[z] * a[z] * a[z] <= n; z++) {
        ok[a[i] * a[i] + a[j] * a[j] * a[j] + a[z] * a[z] * a[z] * a[z]] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 28; i <= n; i++) {
    ans += (ok[i] == 1);
  }
  cout << ans << '\n';
}