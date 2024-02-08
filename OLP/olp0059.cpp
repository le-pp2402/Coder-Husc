/**
 * author:  Le Phi Phat
 * created: 2023
**/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    a[i] = a[i] % m;
  }
  map<int, int> mp;
  for (int i = 0; i <= n; i++) {
    mp[a[i]]++;
  }
  i64 ans = 0;
  for (auto& [x, y] : mp) {
    ans += y * (y - 1) / 2;
  }
  cout << ans << '\n';
  return 0;
}