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
  i64 n, x;
  cin >> n >> x;
  map<i64, i64> mp;
  vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans += mp[x - a[i]];
    mp[a[i]]++;
  }
  cout << ans;
}