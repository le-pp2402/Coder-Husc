#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

void solve() {

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  i64 a[n + 1][m + 1] = {};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) a[1][i] += a[1][i - 1];
  for (int i = 1; i <= n; i++) a[i][1] += a[i - 1][1];
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      a[i][j] = min(a[i - 1][j], a[i][j - 1]) + a[i][j];
    }
  }
  cout << a[n][m] << '\n';
}