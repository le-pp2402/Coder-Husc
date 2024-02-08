#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const i64 M = 1000000007;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, s, r;
  cin >> n >> s >> r;
  vector<int> a(n + 1, true);
  for (int i = 0; i < s; i++) {
    int num;
    cin >> num;
    a[num] = false;
  }

  for (int i = 0; i < r; i++) {
    int num;
    cin >> num;
    if (a[num] == false) {
      a[num] = true;
    }
    else {
      bool ok = true;
      if (a[num - 1] == false) {
        a[num - 1] = true;
        ok = false;
      }
      if (num + 1 <= n && a[num + 1] == false && ok == true) {
        a[num + 1] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == false) cnt++;
  }
  cout << cnt;
}
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const i64 M = 1000000007;

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, s, r;
  cin >> n >> s >> r;
  vector<int> a(n + 1, true);
  for (int i = 0; i < s; i++) {
    int num;
    cin >> num;
    a[num] = false;
  }

  for (int i = 0; i < r; i++) {
    int num;
    cin >> num;
    if (a[num] == false) {
      a[num] = true;
    }
    else {
      bool ok = true;
      if (a[num - 1] == false) {
        a[num - 1] = true;
        ok = false;
      }
      if (num + 1 <= n && a[num + 1] == false && ok == true) {
        a[num + 1] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == false) cnt++;
  }
  cout << cnt;
}
