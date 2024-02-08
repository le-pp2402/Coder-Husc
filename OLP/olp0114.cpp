#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#ifdef DEBUG 
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

typedef            long long ll;
typedef       pair<int, int>  pii;
typedef         pair<ll, ll>  pll;
typedef pair<double, double> pdd;
typedef          vector<int>  vi;
typedef           vector<ll>  vll;
typedef          vector<pii>  vii;

#define                   fi  first
#define                   se  second
#define               all(v)  (v).begin(), (v).end()
#define                SZ(x)  ((int) (x).size())
#define                   pb  push_back
#define                   pf  push_front
#define                   lb  lower_bound
#define                   ub  upper_bound
 
#define         FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define         ROF(i, a, b) for (int i = (a); i > (b); --i)


ll mod = 1e9 + 7;

struct mat {
	ll a[2][2]{};
};

mat dv;

mat mul(mat &a, mat &b) {
	mat ret;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret.a[i][j] += (a.a[i][k] % mod) * (b.a[k][j] % mod) % mod;
				ret.a[i][j] %= mod;
			}
		}
	}
	return ret;
}

void pr(mat &m) {
	cout << m.a[0][0] << ' ' << m.a[0][1] << '\n';
	cout << m.a[1][0] << ' ' << m.a[1][1] << '\n';
}

mat power(mat &a, ll k) {
	if (k == 0) return dv;
	mat ret = power(a, k / 2);
	ret = mul(ret, ret);
	if (k % 2 != 0) ret = mul(ret, a);
	return ret;	
}

void LPP(int &test) {
	dv.a[0][0] = dv.a[1][1] = 1;
	ll n;
	cin >> n;
	if (n == 0) {
		return void (cout << 0);
	} else if (n == 1 || n == 2) {
		return void (cout << 1);
	}
	mat mt;
	mt.a[0][0] = mt.a[0][1] = mt.a[1][0] = 1;
	mt.a[1][1] = 0;
	mt = power(mt, n - 1);
	// pr(mt);
	cout << mt.a[0][0];
}

int32_t main() {
	cin.tie(0) -> ios::sync_with_stdio(0);
	int tc = 1;
	// cin >> tc;
	FOR(i, 1, tc + 1) LPP(i);
}


/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
*/