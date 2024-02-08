#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1000000007;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x: a) cin >> x;
  for (int i = 0; k && i < 100; i++, k--) {
    vector<int> cnt(n + 1);
    for (int j = 0; j < n; j++) cnt[a[j]]++;
    for (int j = 0; j < n; j++) a[j] = cnt[j + 1];
  }
  for (int& x : a) cout << x << ' ';
  return 0;
}