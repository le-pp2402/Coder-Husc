#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

void p(int n) {
  for (int i = 1, even = 2, odd = 1; i <= n; i++) {
    if (i % 2 == 1) {
      cout << odd << ' ';
      odd += 2;
    }
    else {
      cout << even << ' ';
      even += 2;
    }
  }
  cout << 1 << '\n';
}
void solve() {
  int n;
  cin >> n;
  vector<int> k;
  vector<int> pos(n);
  for (int i = 3; i <= n; i += 2)
    k.push_back(i);
  for (int i = n / 2 * 2; i >= 2; i -= 2)
    k.push_back(i);
  for (int i = 0; i < n - 1; i++) {
    pos[k[i]] = i;
  }
  // 2 - 3
  // 3 - 5
  // 5 - 7
  // 7 - 9
  // ....
  for (int i = 0;  i < n / 2; i++) {
    int l = (pos[2] + i) % (n - 1), r = (l + 1) % (n - 1);
    cout << 1 << ' ';
    for (int j = 1; j < n; j++) {
      if (j % 2 == 1) {
        cout << k[l] << ' ';
        l = (l - 1 + n - 1) % (n - 1);
      }
      else {
        cout << k[r] << ' ';
        r = (r + 1 + (n - 1)) % (n - 1);
      }
    }
    cout << "1\n";
  }
  cout << '\n';
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}