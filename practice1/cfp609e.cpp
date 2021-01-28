// https://codeforces.com/problemset/problem/609/E
// typedefs and such/-----------------
#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define vec vector
#define iii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;

// Problem start------------------------

struct dsu {
  int num_sets;
  vi p, r;
  void init(int size) {
    num_sets = size;
    p.resize(size), r.assign(size, 1);
    forn(i, size) p[i] = i;
  }
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    if (!same_set(i, j)) {
      if (r[p[i]] > r[p[j]])
        p[p[j]] = p[i], r[p[i]] += r[p[j]], r[p[j]] = 0;
      else
        p[p[i]] = p[j], r[p[j]] += r[p[i]], r[p[i]] = 0;
      num_sets--;
    }
  }
};

const int logMAXN = ceil(log2(2 * MAXN));
vec<iii> edges;
vec<ii> tree[2 * MAXN];
int n, m, l, lvl[2 * MAXN], up[2 * MAXN][logMAXN + 1],
    max_e[2 * MAXN][logMAXN + 1];
bool in_mst[2 * MAXN];
dsu mst;

void dfs(int u, int p = -1, int h = 0) {
  lvl[u] = h, up[u][0] = p;
  fore(i, 1, l) {
    if (up[u][i - 1] != -1) {
      up[u][i] = up[up[u][i - 1]][i - 1];
      max_e[u][i] = max(max_e[up[u][i - 1]][i - 1], max_e[u][i - 1]);
    }
  }
  for (ii e : tree[u])
    if (e.se != p)
      max_e[e.se][0] = e.fi, dfs(e.se, u, h + 1);
}

int max_wlca(int p, int q) {
  if (lvl[p] < lvl[q])
    swap(p, q);

  int cur_max = -1;
  ford(i, l + 1) {
    if (lvl[p] - (1 << i) >= lvl[q])
      cur_max = max(cur_max, max_e[p][i]), p = up[p][i];
  }

  if (p == q)
    return cur_max;

  ford(i, l + 1) {
    if (up[p][i] != -1 && up[p][i] != up[q][i]) {
      cur_max = max(max_e[p][i], max(max_e[q][i], cur_max));
      p = up[p][i], q = up[q][i];
    }
  }
  return max(max_e[q][0], max(max_e[p][0], cur_max));
}

void kruskal() {
  vec<pair<iii, int>> sortd;
  forn(i, edges.size()) sortd.pb(make_pair(edges[i], i));
  sort(sortd.begin(), sortd.end());

  ll mst_w = 0;
  for (pair<iii, int> pe : sortd) {
    iii e = pe.fi;
    if (!mst.same_set(e[1], e[2])) {
      mst.union_set(e[1], e[2]), mst_w += e[0], in_mst[pe.se] = true;
      tree[e[1]].pb(ii(e[0], e[2]));
      tree[e[2]].pb(ii(e[0], e[1]));
    }
  }

  dfs(0);
  forn(i, edges.size()) {
    if (in_mst[i])
      cout << mst_w << el;
    else
      cout << mst_w + edges[i][0] - max_wlca(edges[i][2], edges[i][1]) << el;
  }
}

int main() {
  cin >> n >> m;
  l = ceil(log2(n));
  memset(lvl, -1, sizeof lvl);
  memset(up, -1, sizeof up);
  memset(max_e, -1, sizeof max_e);
  memset(in_mst, false, sizeof in_mst);
  mst.init(n), edges.clear();
  forn(i, n) tree[i].clear();

  forn(i, m) {
    int src, dst, w;
    cin >> src >> dst >> w;
    edges.pb(iii(w, src - 1, dst - 1));
  }
  kruskal();
  /*  
  forn(i, n) {
    cout << i << ' ';
    forn(j, l + 1) cout << up[i][j] << " ";
    cout << el;
  }
  cout << "------------" << el;
  forn(i, n) {
    cout << i << ' ';
    forn(j, l + 1) cout << max_e[i][j] << " ";
    cout << el;
  }
  */
}
