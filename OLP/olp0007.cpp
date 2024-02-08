#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define db         42
#endif

using i64 = long long;
using pii = pair<int, int>;
using arr = array<int, 3>;

#define fi first;
#define se second;

const i64 M = 1000000007;
const int N = 500001;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  if (fopen("i", "r")) {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
  }
  int n;
  cin >> n;
  vector<int> a(n);
  i64 total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  set<int> s = { 0 };
  for (int i = 0; i < n; i++) {
    vector<int> rem;
    for (int x : s) rem.push_back(x + a[i]);
    for (int x : rem) s.insert(x);
  }
  cout << s.size() - 1 << '\n';
  for (int x : s) {
    if (x) cout << x << ' ';
  }
}