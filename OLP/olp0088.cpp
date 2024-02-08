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
  int n;
  cin >> n;
  vi a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  map<int, int> mp;
  for (int j = 1; j <= n; j++) {
    mp[b[c[j]]]++;
  }
  i64 ans = 0;
  for (int j = 1; j <= n; j++) {
    ans += mp[a[j]];
  }
  cout << ans << '\n';
  return 0;
}