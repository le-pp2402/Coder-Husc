#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
i64 frac[10];
int main() {
  string s;
  while(getline(cin, s)) {
    string str = "";
    for (char &c: s) {
      if (isalpha(c)) {
        str += tolower(c);
      }
    }
    // cout << "str = " << str << '\n';
    string t = str;
    reverse(t.begin(), t.end());
    if (t == str) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}