/**
 * author:  Le Phi Phat
 * created: 2023
**/
#include <bits/stdc++.h>
// #include "algo/debug.h"
// #include <time.h>
using namespace std;
using i64 = long long;

//https://stackoverflow.com/questions/42701688/using-an-unordered-map-with-arrays-as-keys
struct ArrayHasher {
  std::size_t operator()(const std::array<int, 3>& a) const {
    std::size_t h = 0;

    for (auto e : a) {
      h ^= std::hash<int>{}(e)+0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
  }
};

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  unordered_map<array<int, 3>, bool, ArrayHasher> ump;
  int N;
  cin >> N;
  vector<array<int, 3>> base;
  for (int i = 1; i * i <= N; i++) {
    for (int j = i + 1; j * j <= N; j++) {
      if (__gcd(2 * j * j, __gcd(j * j - i * i, i * i + j * j)) == 1 && j * j * 2 + 2 * i * j <= N)
        base.push_back({ min(j * j - i * i, 2 * i * j), max(j * j - i * i, 2 * i * j), i * i + j * j });
    }
  }
  vector<int> cnt(N + 1);
  for (auto& x : base) {
    int j = x[0] + x[1] + x[2];
    for (int k = j; k <= N; k += j) {
      // debug(x[0], x[1], x[2], j, k);
      cnt[k]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += (cnt[i] == 1);
  }
  cout << ans << '\n';
  return 0;
}