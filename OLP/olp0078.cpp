#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
//#include "debuge.cpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, \
										less<T>, rb_tree_tag, \
										tree_order_statistics_node_update>;  

using i64 = long long;

int main() {
	cin.tie(0) -> ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<i64> a(k);
	i64 l = 0, r = 0;
	for (i64 &x: a) {
		cin >> x;
		r = max(r, x); 
	}
	while (l + 1 < r) {
		i64 m = (l + r) / 2;
		i64 total = 0;
		for (int i = 0; i < k; i++) {
			total += a[i] / m;
			if (a[i] % m != 0) total++;
		}
		if (total <= n) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << r << '\n';
	// moi nhom co it nhat m
	return 0;
}