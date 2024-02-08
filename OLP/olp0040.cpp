// v=0b-Q-uO2oYk
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int INF = 1e6;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  i64 a[n + 1][m + 1] = {};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) a[1][i] += a[1][i - 1];
  for (int j = 1; j <= n; j++) a[j][1] += a[j - 1][1];

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }

  for (int i = 0; i < q; i++) {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    cout << a[xx][yy] - a[xx][y - 1] - a[x - 1][yy] + a[x - 1][y - 1] << '\n';
  }
  return 0;
}