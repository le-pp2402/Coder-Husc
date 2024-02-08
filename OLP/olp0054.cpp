#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ii = pair<int, int>; 

#ifdef LOCAL
#include "debuge.cpp"
#else
#define debug(...) 42
#endif

#define all(x)     (x).begin(), (x).end()

class DSU {
public:
  int n;
  vector<int> sz, par;
  DSU (int n) {
  	this -> n = n;
		sz.assign(n, 1);  
		par.assign(n, 0);
		for (int i = 1; i < n; i++) par[i] = i;
	}
  int find_set(int u) {
    return (u == par[u] ? u : (par[u] = find_set(par[u])));
  }
  void union_sets(int u, int v) {
    if ((u = find_set(u)) == (v = find_set(v))) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
  }
};

void file() {
    if (fopen("in", "r")) {
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    }
}

const int N = 200001;

vector<pair<ll, int>> g[N];
vector<pair<ll, ii>> edge;
vector<int> dep(N);
vector<vector<int>> up(N, vector<int> (20));
vector<vector<int>> dp(N, vector<int> (20));
vector<bool> con(N);

void dfs(int u, int p) {
    up[u][0] = p;
    for (auto &[w, v]: g[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dp[v][0] = w;
        dfs(v, u);                
    }
}

int jmp(int u, int k) {
    for (int i = 20; i >= 0; i--) {
        if ((1ll << i) & k) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = jmp(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

ll getMax(int u, int k) {
    ll ans = 0;
    for (int i = 20; i >= 0; i--) {
        if (k & (1ll << i)) {
            ans = max(ans, dp[u][i] * 1ll);
            u = up[u][i];
        }
    }
    return ans;
}

void lpp(int &test) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    vector<int> id(m);
    for (int i = 0; i < m; i++) id[i] = i;
    sort(all(id), [&] (const int l, const int r) {
        if (edge[l] < edge[r]) return true;
        return false;
    });
    sort(all(edge));
    DSU dsu(n + 1);
    int index = 0;
    ll ans = 0;

    for (auto &[w, uv]: edge) {
        index++;
        auto &[u, v] = uv;
        if (dsu.find_set(u) == dsu.find_set(v)) continue;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
        dsu.union_sets(u, v);
        con[index - 1] = true;
        ans += w;
    }
    
    dfs(1, 1);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= n; u++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
            dp[u][i] = max(dp[up[u][i - 1]][i - 1], dp[u][i - 1]);
        }        
    }

    vector<ll> ANS(m);
    for (int i = 0; i < m; i++) {
        if (con[i]) {
            ANS[id[i]] = ans;
        } else {
            auto &[w, p] = edge[i];
            auto &[u, v] = p;
            int LCA = lca(u, v);
            ANS[id[i]] = ans - max(getMax(u, dep[u] - dep[LCA]), getMax(v, dep[v] - dep[LCA])) + w;
        }
    }
    for (auto &x: ANS) cout << x << '\n';
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // file();
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) lpp(i);
    return 0;
}