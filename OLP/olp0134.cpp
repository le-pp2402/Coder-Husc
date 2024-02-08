#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;   
using vvi = vector<vi>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define isz(x) (int)(x).size()
#define rall (x).rbegin(), (x).rend()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair

const int N = 200001;
static int fen[N];
int n;
void upd(int id, int val) {
    while (id <= n) {
        fen[id] += val;
        id += id & (-id);
    }  
}
int get(int id) {
    int ans = 0;
    while (id) {
        ans += fen[id];
        id -= id & (-id);
    } 
    return ans;
}
int getRange(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}

void solve() {
    cin >> n;
    vector<pair<ii, int>> allEdege;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int j = (i == n ? 1 : i + 1);
        allEdege.pb(mp(mp(min(i, j), max(j, i)), c - '0'));
    }
    
    vector<array<int, 3>> e;
    for (int i = 0; i < n - 3; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        if (x > y) swap(x, y);
        e.pb({x, -y, v});
        allEdege.pb(mp(mp(x, y), v));
    }

    sort(all(e));
    for (auto &[x, y, v]: e) y = -y;

    for (int i = 0; i < isz(e); i++) {
        if (e[i][0] + 1 <= e[i][1] - 1) {
            if (getRange(e[i][0] + 1, e[i][1] - 1)) {
                cout << "invalid triangulation\n";
                return;
            }
        }
        upd(e[i][0], 1);
        upd(e[i][1], 1);
    }

    for (int i = 1; i <= n; i++) {
        fen[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        upd(i, 1);
    }
    sort(all(e), [] (array<int, 3> &ar1, array<int, 3> &ar2) {
        auto &[i1, i2, i3] = ar1;
        auto &[j1, j2, j3] = ar2;
        int v1 = min(getRange(i1 + 1, i2 - 1), getRange(1, i1 - 1) + getRange(i2 + 1, n));
        int v2 = min(getRange(j1 + 1, j2 - 1), getRange(1, j1 - 1) + getRange(j2 + 1, n));
        return (v1 < v2);
    });

    sort(all(allEdege));
    auto cnp = [&] (int L, int R) {
        if (L > R) return -1;
        int lo = L, hi = R;
        if (getRange(L,L)) {
            return L;
        }
        while (lo + 1 < hi) {
            int mi = (lo + hi) / 2;
            if (getRange(L, mi) == 0) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        return (hi == R ? -1 : hi);
    };
    for (auto &[x, y, v]: e) {
        int i = cnp(x + 1, y);
        if (i != -1 && getRange(x + 1, y - 1) == 1) {
            upd(i, -1);
            auto c1 = lb(all(allEdege), mp(mp(min(x, i), max(i, x)), 0));
            auto c2 = lb(all(allEdege), mp(mp(min(x, y), max(x, y)), 0));
            auto c3 = lb(all(allEdege), mp(mp(min(y, i), max(y, i)), 0));
            if (!(c1 -> se != c2 -> se && c2 -> se != c3 -> se && c3 -> se != c1 -> se)) {
                cout << "invalid coloring\n";
                return;
            }
        } else {
            if (getRange(1, x - 1) == 1) {
                i = cnp(1, x);
            }
            if (i == -1 || getRange(1, x - 1) != 1) {
                i = cnp(y + 1, n + 1);
            }
            if (i != -1) {
                upd(i, -1);
                auto c1 = lb(all(allEdege), mp(mp(min(x, i), max(i, x)), 0));
                auto c2 = lb(all(allEdege), mp(mp(min(x, y), max(x, y)), 0));
                auto c3 = lb(all(allEdege), mp(mp(min(y, i), max(y, i)), 0));
                if (!(c1 -> se != c2 -> se && c2 -> se != c3 -> se && c3 -> se != c1 -> se)) {
                    cout << "invalid coloring\n";
                    return;
                }
            }
        }
    }
    vi rem;
    for (int i = 1; i <= n; i++) {
        if (getRange(i, i) == 1) {
            rem.pb(i);
        }
    }

    if (rem.size() == 3) {
        int x = rem[0];
        int y = rem[1];
        int i = rem[2];
        auto c1 = lb(all(allEdege), mp(mp(min(x, i), max(i, x)), 0));
        auto c2 = lb(all(allEdege), mp(mp(min(x, y), max(x, y)), 0));
        auto c3 = lb(all(allEdege), mp(mp(min(y, i), max(y, i)), 0));
        if (!(c1 -> se != c2 -> se && c2 -> se != c3 -> se && c3 -> se != c1 -> se)) {
            cout << "invalid coloring\n";
            return;
        }
    }
    cout << "correct\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t;
    cin >> t;
    solve();  
}