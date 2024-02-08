#include <iostream>
using namespace std;

const int N = 50;
int a[N + 1][N + 1] = {};
int f(int x, int y, int x1, int y1) {
  return a[x][y] - a[x1][y] - a[x][y1] + a[x1][y1];
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
    }
  }
  int ans = 0;
  for (int x = 0; x <= n; x++) {
    for (int y = 0; y <= n; y++) {
      for (int x1 = x + 1; x1 <= n; x1++) {
        for (int y1 = y + 1; y1 <= n; y1++) {
          for (int x2 = x1 + 1; x2 <= n; x2++) {
            for (int y2 = y1 + 1; y2 <= n; y2++) {
              if (f(x1, y1, x, y) == f(x2, y2, x1, y1)) ans++;
              if (f(x1, y2, x, y1) == f(x2, y1, x1, y)) ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
}