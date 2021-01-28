#include <bits/stdc++.h>
#define vec vector
#define d(x) std::cout << #x << ' ' << x << std::endl;
using namespace std;

typedef pair<int, int> ii;

const int MAXN = int(1e5);

bool seen[2 * MAXN + 1];
int n, m, dfs_num, low[2 * MAXN + 1], num[2 * MAXN + 1];
vec<ii> g[2 * MAXN + 1], s;
vec<vec<int>> sccs;

void tarjan_scc(int u) {
    low[u] = num[u] = dfs_num++;
    s.push_back(u);
    seen[u] = true;

    for (ii vp : g[u]) {
        int v = vp.second;
        if (num[v] == -1) tarjan_scc(v);
        if (seen[v]) low[u] = min(low[u], low[v]);
    }

    if (low[u] == num[u]) {
        vec<int> cur_scc;
        while (true) {
            int v = s.back();
            s.pop_back();
            seen[v] = false;

            cur_scc.push_back(v);
            if (u == v) break;
        }
        sccs.push_back(cur_scc);  // inefficient fuck you
    }
}

int main() {
    int t;
    cin >> t;
    while (t) {
        cin >> n >> m;
        dfs_num = 0;
        memset(seen, false, sizeof seen);
        memset(low, -1, sizeof low);
        memset(num, -1, sizeof num);
        s.clear();

        for (int i = 0; i < m; ++i) {
            int type, src, dst;
            cin >> type >> src >> dst;
            g[src].push_back(ii(type, dst));
            if (type == 0) g[dst].push_back(ii(type, src));
        }
        for (int i = 1; i <= n; ++i)
            if (num[i] == -1) tarjan_scc(i);

        puts("DONE");
        for (vec<int> v : sccs) {
            for (int a : v) cout << a << ' ';
            cout << endl;
        }

        t--;
    }
}
