// v=0b-Q-uO2oYk
// #include "debug.h"
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int INF = 1e6;

int ans = 100;
int n;

int zero(vector<vector<int>> a) {
  int ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 1) {
        for (int i_ = 0; i_ <= i; i_++) {
          for (int j_ = 0; j_ <= j; j_++) {
            a[i_][j_] = 1 - a[i_][j_];
          }
        }
        ret++;
      }
    }
  }
  return ret;
}
int one(vector<vector<int>> a) {
  int ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 0) {
        for (int i_ = 0; i_ <= i; i_++) {
          for (int j_ = 0; j_ <= j; j_++) {
            a[i_][j_] = 1 - a[i_][j_];
          }
        }
        ret++;
      }
    }
  }
  return ret;
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  cout << min(zero(a), one(a) + 1);
  // cout << ans << '\n';
}