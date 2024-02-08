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

i64 len(int N) {
	if (N == 2) return 1;
	for (int i = 2; i <= N; i++) {
		if (N % i != 0) return 1 + len(i);
	}
	return 0;
}
int main() {
	cin.tie(0) -> ios::sync_with_stdio(0);
	i64 l, r;
	cin >> l >> r;
	i64 cur = 1;
	i64 ans = 0;
	for (i64 i = 2; i <= 50 && cur <= 1e17; i++) {
		i64 L = (l + cur - 1LL) / cur * cur;
		i64 R = r / cur * cur;
		i64 ans1 = (R - L) / cur + 1;
		cur = i * cur / __gcd(i, cur);
		L = (l + cur - 1LL) / cur * cur;
		R = r / cur * cur;
		i64 ans2 = (R - L) / cur + 1LL;
		ans += (ans1 - ans2) * (1LL + len(i));
	}
	cout << ans << '\n';	
}