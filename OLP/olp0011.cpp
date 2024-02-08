#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int M = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int n;
  cin >> n >> s;
  int cnt = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ans++;
      cnt = 2;
    }
    else {
      if (cnt) {
        ans++;
        cnt--;
      }
    }
  }
  cout << ans;
}