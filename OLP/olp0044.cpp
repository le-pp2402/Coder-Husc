#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1000000007;

map<i64, i64> mp;

i64 mul(i64 a, i64 b) {
  return ((a % mod) * (b % mod)) % mod;
}
i64 MI(i64 a, i64 b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
i64 f(i64 n) {
  if (mp.count(n) != 0) return mp[n];
  if (n % 2 == 0) {
    i64 a = n / 2; a = f(a);
    i64 b = n / 2 + 1; b = f(b);
    mp[n] = mul(a, MI(mul(2, b), a));
    return mp[n];
  }
  else {
    i64 a = (n - 1) / 2;
    i64 b = (n - 1) / 2 + 1;
    a = f(a);
    b = f(b);
    mp[n] = (mul(a, a) + mul(b, b)) % mod;
    return mp[n];
  }
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  mp[0] = 0, mp[1] = 1, mp[2] = 1;
  i64 a1, n;
  cin >> a1 >> n;
  i64 fb = f(n + 2);
  fb = MI(fb, 1);
  fb = mul(fb, a1);
  cout << fb;
  return 0;
}
