#include <bits/stdc++.h>
using namespace std;

// clang-format off
template<typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for_each(vec.begin(), vec.end(), [&](auto &i) {is >> i; } );
    return is;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
    for_each(vec.begin(), vec.end(), [&](auto &i) {os << i << ' '; });
    return (os << '\n');
}

using ll = long long;
using ii = pair<int, int>;

#define           fi first
#define           se second
#define       all(v) (v).begin(), (v).end()
#define        sz(x) ((int)(x).size())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// clang-format on


#define FILENAME "a.in"

void solve(int &test) { 
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i * i <= (n + 1); i++) {
		if ((n + 1) % i == 0) {
			ans += 2;
			if ((n + 1) == i * i) ans--;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  // remove this if using debug or stress_test
  if (fopen(FILENAME, "r")) {
    freopen(FILENAME, "r", stdin);
  }
  int TC = 1;
  // cin >> TC;
  for (int i = 1; i <= TC; i++) {
    solve(i);
  }
  return 0;
}

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/