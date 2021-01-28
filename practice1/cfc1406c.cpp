// https://codeforces.com/contest/1406/problem/C
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

typedef long long ll;
const int INF = 1 << 30;
const int MAXN = int(1e5) + 1;
using namespace std;
// problem start----------------------

vector<int> g[MAXN];
int t, n, max_c[MAXN];

int dfs(int u, int p) {
    int branch, total = 0;

    for (int v : g[u]) {
        if (v != p) {
            total += (branch = dfs(v, u));
            max_c[u] = max(max_c[u], branch);
        }
    }
    max_c[u] = max(max_c[u], n - total - 1);
    return total + 1;
}

int get_leaf(int u, int p) {
    if (g[u].size() == 1) return u;
    return get_leaf(g[u][g[u][0] == p], u);
}

int main() {
    int src, dst;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(max_c, 0, sizeof max_c);
        for (int i = 0; i <= n; ++i) g[i].clear();

        for (int i = 0; i < n - 1; ++i) {
            cin >> src >> dst;
            g[src].push_back(dst), g[dst].push_back(src);
        }
        dfs(1, -1);
        int cev[2] = {INF, INF}, cen[2];
        for (int i = 1; i <= n; ++i) {
            if (cev[0] == max_c[i]) cev[1] = max_c[i], cen[1] = i;
            if (cev[0] > max_c[i]) cev[0] = max_c[i], cen[0] = i, cev[1] = INF;
        }

        if (cev[1] < INF) {
            int leaf = get_leaf(cen[0], cen[1]);
            cout << leaf << ' ' << g[leaf][0] << el;
            cout << leaf << ' ' << cen[1] << el;
        } else {
            cout << 1 << ' ' << g[1][0] << el;
            cout << 1 << ' ' << g[1][0] << el;
        }
    }
}
