#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1000000007;

int n, m;

bool ok(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int x[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int y[] = { 0, 1, -1, 1, -1, 0, 1, -1 };

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '*');
    }
  }
  
  bool vis[n][m] = {};
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1 && vis[i][j] == false) {
        cnt++;
        deque<pair<int, int>> dq;
        dq.push_front({ i, j });
        while (!dq.empty()) {
          int xx = dq.back().first;
          int yy = dq.back().second;
          dq.pop_back();
          for (int d = 0; d < 8; d++) {
            if (ok(xx + x[d], yy + y[d]) && a[xx + x[d]][yy + y[d]] && vis[xx + x[d]][yy + y[d]] == false) {
              vis[xx + x[d]][yy + y[d]] = true;
              dq.push_front({ xx + x[d], yy + y[d] });
            }
          }
        }
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}