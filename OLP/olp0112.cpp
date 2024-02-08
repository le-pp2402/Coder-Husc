#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

// clang-format off
using ll  = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;

#define           fi first
#define           se second
#define       all(v) (v).begin(), (v).end()
#define        sz(x) ((int)(x).size())
#define           pb push_back
#define           pf push_front
#define           lb lower_bound
#define           ub upper_bound
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i > (b); --i)
// clang-format on

vector<ll> fi = {0, 1};

void LPP(int &test) {
	ll n;
	cin >> n;
	auto it = lb(all(fi), n);
	if (n == *it) return void (cout << "Yes\n");
	for (int i = 1; fi[i] * fi[i] <= n; i++) {
		if (n % fi[i] == 0) {
			auto ii = lb(all(fi), n / fi[i]);
			if (*ii == n / fi[i]) return void (cout << "Yes\n");
		}
	}
	cout << "No\n";
}
int32_t main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  
	for (int i = 2;; i++) {
    if (fi[i - 1] + fi[i - 2] > 1e9) {
      break;
		}
    fi.push_back(fi[i - 1] + fi[i - 2]);
  }
  
	int tc = 1;
  cin >> tc;
  rep(i, 1, tc + 1) { LPP(i); }
  return 0;
}

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/