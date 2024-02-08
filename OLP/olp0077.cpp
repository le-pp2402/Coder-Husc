#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
	cin.tie(0) -> ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int prefix = 0, ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(') prefix++;
		if (s[i] == ')') prefix--;
		if (prefix < 0) {
			ans++;
			prefix += 2;
		}
	}
	if (prefix > 0) {
		ans += (prefix / 2);
	}
	cout << ans << '\n';
}