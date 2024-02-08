#include <bits/stdc++.h>
// #include "debug.h"

using namespace std;
using i64 = long long;
using pii = pair<int, pair<int, int>>;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
const int N = 111;
const int INF = 100 * 100 * 101;
int n, m;
int ans = 100 * 100 * 101;

bool ok(int x, int y) {
  return (x >= 1 && y >= 1 && x <= n && y <= m);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  int a[n + 1][m + 1] = {};

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];

  for (int so = 1; so <= n; so++) {
    int dis[n + 1][m + 1] = {};

    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        dis[i][j] = INF;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[so][1] = 0;
    pq.push({ 0, {so, 1} });
    while (!pq.empty()) {
      int du = pq.top().first;
      pair<int, int> u = pq.top().second;
      pq.pop();
      if (du != dis[u.first][u.second]) continue;

      for (int i = 0; i < 4; i++) {
        int nx = u.first + x[i], ny = u.second + y[i];
        if (ok(u.first + x[i], u.second + y[i]) && dis[u.first][u.second] + a[nx][ny] < dis[nx][ny]) {
          dis[nx][ny] = dis[u.first][u.second] + a[nx][ny];
          pq.push({ dis[nx][ny], {nx, ny} });
        }
      }
    }

    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= m; j++) {
    //     cout << dis[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    for (int i = 1; i <= n; i++) {
      ans = min(ans, dis[i][m] + a[so][1]);
    }
  }
  cout << ans << '\n';
  return 0;
}