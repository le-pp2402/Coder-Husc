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
	vector<int> a[22];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int j = s.length();
		a[j].push_back(i);
	}
	i64 ans = 0;
	for (int i = 2; i <= 20; i++) {
		int l = 0;
		int sz = a[i].size();
		for (int r = 1; r < sz; r++) {
			while (l <= r && a[i][r] - a[i][l] > k) l++;
			ans += (r - 1 - l + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}