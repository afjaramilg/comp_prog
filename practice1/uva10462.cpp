// https://vjudge.net/problem/UVA-10462
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
#define ri(n) scanf("%d", &n)
#define vec vector
#define iii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------

struct dsu {
  int num_sets;
  vi p, r;
  void init(int size) {
    num_sets = size;
    r.assign(size, 1), p.resize(size);
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

vec<ii> tree[200];
vec<iii> edges;
int v, m, l, timer, first[200], last[200], up[200][200], max_e[200][200];
dsu mst;

void dfs(int u, int p) {
  first[u] = timer++, up[u][0] = p;

  for (int i = 1; i <= l; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
    max_e[u][i] = max(max_e[up[u][i - 1]][i - 1], max_e[u][i - 1]);
  }

  for (ii e : tree[u])
    if (e.se != p)
      max_e[e.se][0] = e.fi, dfs(e.se, u);

  last[u] = timer++;
}

bool is_ancestor(int u, int v) {
  return first[u] <= first[v] && last[u] >= last[v];
}

int lca(int u, int v) {
  int og_u = u, og_v = v, cur_max = -1;
  ford(i, l + 1) {
    if (!is_ancestor(up[u][i], v)) 
      cur_max = max(cur_max, max_e[u][i]), u = up[u][i]; 
  }
  
  if (!is_ancestor(og_u, og_v))  
    cur_max = max(max_e[u][0], cur_max);

  ford(i, l + 1) {
    if (!is_ancestor(up[v][i], og_u)) 
      cur_max = max(cur_max, max_e[v][i]), v = up[v][i]; 
  }
  
  if (!is_ancestor(og_v, og_u))
    cur_max = max(max_e[v][0], cur_max);
  
  // d(up[u][0]);
  return cur_max;
  // return up[u][0];
}

void kruskal() {
  sort(edges.begin(), edges.end());
  vec<iii> not_mst;
  int mst_w = 0;
  for (iii e : edges) {
    if (!mst.same_set(e[1], e[2])) {
      mst.union_set(e[1], e[2]);
      tree[e[1]].pb(ii(e[0], e[2]));
      tree[e[2]].pb(ii(e[0], e[1]));
      mst_w += e[0];
    } else
      not_mst.pb(e);
  }

  dfs(0, 0);
  if (mst.num_sets > 1)
    cout << "No way" << el;
  else {
    int second = INF;
    for (iii e : not_mst) {
      int k = lca(e[1], e[2]);
      second = min(second, mst_w - k + e[0]);
    }
    if (second != INF)
      cout << second << el;
    else
      cout << "No second way" << el;
  }
}

int main() {
  int t;
  cin >> t;
  forn(c, t) {
    cin >> v >> m;
    l = ceil(log2(v));
    timer = 0;
    memset(first, -1, sizeof first);
    memset(last, -1, sizeof last);
    memset(up, -1, sizeof up);
    memset(max_e, -1, sizeof max_e);
    mst.init(v), edges.clear();
    forn(i, v) tree[i].clear();

    forn(i, m) {
      int src, dst, w;
      cin >> src >> dst >> w;
      edges.pb(iii(w, src - 1, dst - 1));
    }
    printf("Case #%i : ", c+1);
    kruskal();
  }
}

