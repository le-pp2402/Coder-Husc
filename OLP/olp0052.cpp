#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 INF = LLONG_MAX; 
const int N = 100001;
vector<int> a[N];
vector<int> num(N), low(N);
vector<pair<int, int>> bridge;
int dfsTimer = 0;
void dfs(int u, int v) {
	num[u] = low[u] = ++dfsTimer;
	int cnt = 0;
	for (int &x: a[u]) {
		if (x == v) continue;
		if (num[x]) {
			low[u] = min(low[u], num[x]);
			continue;
		} else {
			dfs(x, u);
			low[u] = min(low[u], low[x]);
		}
		if (low[x] == num[x]) {
			bridge.push_back({u, x});
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<i64, int>> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		a[u].push_back(v);
		a[v].push_back(u);
		g[u].push_back({d, v});
		g[v].push_back({d, u});
	}
	int r1, r2;
	cin >> r1 >> r2;
	dfs(1, 1);
	// r1
	i64 d1[n + 1] = {};
	for (int i = 0; i <= n; i++) d1[i] = INF;
	priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
	vector<bool> processed(n + 1, false);
	pq.push({0, r1});
	d1[r1] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (processed[u]) continue;
		processed[u] = true;
		for (auto &x: g[u]) {
			i64 uv = x.first;
			int v = x.second;
			if (d1[v] > uv + d1[u]) {
				d1[v] = uv + d1[u];
				pq.push({d1[v], v});
			}
		}
	}
	
	i64 d2[n + 1] = {};
	for (int i = 0; i <= n; i++) d2[i] = INF;
	processed.assign(n + 1, false);
	pq.push({0, r2});
	d2[r2] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (processed[u]) continue;
		processed[u] = true;
		for (auto &x: g[u]) {
			i64 uv = x.first;
			int v = x.second;
			if (d2[v] > uv + d2[u]) {
				d2[v] = uv + d2[u];
				pq.push({d2[v], v});
			}
		}
	}
	i64 ans = LLONG_MAX;
	for (auto &x: bridge) {
		int x1 = x.first, x2 = x.second;
		ans = min({ans, max(d1[x1], d2[x2]), max(d1[x2], d2[x1])});	
	}
	cout << ans << '\n';
}