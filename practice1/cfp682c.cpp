// http://codeforces.com/contest/682/problem/C
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

typedef long long ll;
const int INF = 1 << 30;
const int MAXN = int(1e5) + 1;
using namespace std;
// problem start----------------------

#define fi first
#define se second
#define pb push_back
typedef pair<int, int> ii;

vector<ii> tree[MAXN];

ll n, cap[MAXN];
vector<ll> suf;

int dfs(int u, int p, ll w, bool p_cut) {
    int tot;

    (u == 1) ? (tot = p_cut) : ({
        ll best = (p != 1) ? max(w + suf.back(), w) : w;
        suf.pb(best);
        tot = p_cut = p_cut || (suf.back() > cap[u]);  // cut self later.
    });

    for (ii vw : tree[u]) {
        if (vw.fi != p) tot += dfs(vw.fi, u, vw.se, p_cut);
    }

    if (u != 1) suf.pop_back();

    return tot;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> cap[i];

    int dst, w;
    for (int src = 1; src <= n - 1; ++src) {
        cin >> dst >> w;
        tree[src + 1].push_back({dst, w});
        tree[dst].push_back({src + 1, w});
    }

    cout << dfs(1, -1, 0, cap[1] < 0) << endl;
}
