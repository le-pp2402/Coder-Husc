/**
 * author:  Le Phi Phat
 * created: 2023
**/
#pragma once
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair<i64, int>;

const int N = 200001;
const i64 INF = LLONG_MAX;

struct TEdge {
  int u, v;
  i64 w;
};
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<TEdge> edge(m);
  for (TEdge& e : edge) {
    cin >> e.u >> e.v >> e.w;
  }
  i64 ans = 0;
  static vector<bool> processed(n + 1);
  static vector<i64> d(n + 1);

  for (int i = 0; i < m; i++) {
    vector<pair<i64, int>> a[n + 1];
    for (int j = 0; j <= n; j++) {
      d[j] = INF;
      processed[j] = false;
    }
    edge[i].w *= 2;
    for (int j = 0; j < m; j++) {
      a[edge[j].u].push_back({ edge[j].w, edge[j].v });
      a[edge[j].v].push_back({ edge[j].w, edge[j].u });
    }
    d[1] = 0;
    for (int z = 0; z < n; ++z) {
      int u;
      i64 Max = INF;
      for (int j = 1; j <= n; ++j) {
        if (d[j] < Max && processed[j] == false) {
          Max = d[j];
          u = j;
        }
      }
      processed[u] = true;
      for (auto& [uv, v] : a[u]) {
        if (d[v] > uv + d[u]) {
          d[v] = uv + d[u];
        }
      }
    }
    ans = max(ans, d[n]);
    edge[i].w /= 2;
  }
  vector<pair<i64, int>> a[n + 1];
  for (int i = 0; i <= n; i++) {
    processed[i] = false;
    d[i] = INF;
  }
  for (int j = 0; j < m; j++) {
    a[edge[j].u].push_back({ edge[j].w, edge[j].v });
    a[edge[j].v].push_back({ edge[j].w, edge[j].u });
  }
  d[1] = 0;
  for (int z = 0; z < n; z++) {
    int u;
    i64 Max = INF;
    for (int j = 1; j <= n; j++) {
      if (d[j] < Max && processed[j] == false) {
        Max = d[j];
        u = j;
      }
    }
    processed[u] = true;
    for (auto& [uv, v] : a[u]) {
      if (d[v] > uv + d[u]) {
        d[v] = uv + d[u];
      }
    }
  }
  cout << ans - d[n] << '\n';
}