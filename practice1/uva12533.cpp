// https://vjudge.net/problem/UVA-12533
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
#define tiii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 10;
const int INF = 1e8;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------

vi topo, euler, g[MAXN], inv[MAXN];
bool seen[MAXN];
// bool parent[MAXN];
map<int, int> scc[MAXN];
int n, q, loopc, first[MAXN], h[MAXN], last_k[MAXN], tree[5 * MAXN],
    nloop[MAXN];

bool in_loop(int u) { return (scc[nloop[u]].size() > 1 || g[u][0] == u); }

void euler_proc(int u, int depth, bool mode) {
  if (!mode) { // first time we see the node
    first[u] = (first[nloop[u]] == -1) ? first[nloop[u]] = euler.size()
                                       : first[nloop[u]];

    if (in_loop(u))
      h[u] = 0;
    else
      h[u] = depth;
  }

  if (in_loop(u)) {
    if (euler.size() == 0 || euler[euler.size() - 1] != nloop[u])
      euler.pb(nloop[u]);

    last_k[euler.size()] = u;

  } else {
    euler.pb(nloop[u]);
    last_k[euler.size()] = last_k[euler.size() - 1];
  }
}

// fuck you nigga i aint doing more than 1 dfs
void toposort(vi *gr, int u, int mode = 0, int depth = 0) {

  if (mode != 1)
    seen[u] = true;

  if (mode == 1) {
    nloop[u] = loopc;
    // if(!scc[loopc].count(u))
    scc[loopc][u] = scc[loopc].size();
  }
  if (mode == 2)
    euler_proc(u, depth, 0);

  for (int v : gr[u])
    if ((mode != 1 && !seen[v]) || (mode == 1 && nloop[v] == -1)) {
      toposort(gr, v, mode, h[u] + 1);
      if (mode == 2) {
        euler_proc(u, depth, 1);
      }
    }

  if (mode == 0)
    topo.pb(u);
}

/*
first step is to indenfiy the loops in all the _regular_
trees. to do this we do kosaraju for each tree. The total complexity
_should_ add up to O(c*n)
 */
void kosaraju() {
  for1(u, n) if (!seen[u]) toposort(g, u);
  ford(u, topo.size()) {
    if (nloop[topo[u]] == -1) {
      loopc = topo[u];
      toposort(inv, topo[u], 1);
    }
  }

  // for1(i, n) {
  // cout << i << ' ';
  // if (scc[i].size() > 0)
  // for (ii k : scc[i])
  // printf("%i %i --", k.fi, k.se);
  // cout << " Done" << el;
  // }

  // cout << "nloop: ";
  // for1(i, n) printf("%i ", nloop[i]);
  // cout << el;
}

void build_lca() {
  memset(seen, false, sizeof seen);

  for1(u, n) if (in_loop(u)) { toposort(inv, u, 2); }

  // cout << "DIDNT CRASH!!" << el;

  // cout << "first: ";
  // for1(i, n) printf("%i ", first[i]);
  // cout << el;

  // cout << "h: ";
  // for1(i, n) printf("%i ", h[i]);
  // cout << el;

  // cout << "last_k: ";
  // forn(i, euler.size()) printf("%i ", last_k[i]);
  // cout << el;

  // cout << "euler: ";
  // forn(i, euler.size()) printf("%i ", euler[i]);
  // cout << el;
}

int build_tree(int v, int lt, int rt) {
  if (lt == rt)
    return tree[v] = euler[lt];
  else {
    int lm = (lt + rt) / 2;
    int l = build_tree(2 * v, lt, lm);
    int r = build_tree(2 * v + 1, lm + 1, rt);
    return tree[v] = (h[l] < h[r]) ? tree[2 * v] : tree[2 * v + 1];
  }
}

int query_tree(int v, int lt, int rt, int l, int r) {
  // d(v), d(lt), d(rt), d(l), d(r);
  if (l <= lt && rt <= r) {
    // cout << "done\n----\n" << el;
    return tree[v];
  } else if (l <= r) {
    // cout << "keep diggin" << el;
    int lm = (lt + rt) / 2;
    // d(lm);
    // printf("-----\n");
    int roo = query_tree(2 * v, lt, lm, l, min(r, lm));
    int ree = query_tree(2 * v + 1, lm + 1, rt, max(l, lm + 1), r);
    return (h[roo] < h[ree]) ? roo : ree;
  }
  // printf("-----\n");
  return n + 1;
}

int query_flights(int x, int y) {
  printf("%i %i\n", x, y);
  // printf("nloops: %i %i\n", nloop[x], nloop[y]);
  if (nloop[x] == nloop[y]) { // both are in the loop
    cout << "BOTH INSIDE LOOP" << el;
    int direct = abs(scc[nloop[x]][x] - scc[nloop[x]][y]);
    return min(direct, int(scc[nloop[x]].size()) - direct);

  } else if (in_loop(x) && !in_loop(y)) {
    cout << "X INSIDE, Y OUTSIDE" << el;
    int branch = last_k[first[y]];
    if (nloop[branch] == nloop[x]) { // x is a root of the tree y is in
      // since the heigh of x will be zero,
      // the min will be the height of y
      int base = h[y];
      int direct = abs(scc[nloop[x]][x] - scc[nloop[x]][branch]);
      return base += min(direct, int(scc[nloop[x]].size()) - direct);
    }

  } else if (!in_loop(x) && in_loop(y)) {
    cout << "Y INSIDE, X OUTSIDE" << el;
    int branch = last_k[first[x]];
    // d(branch);
    if (nloop[branch] == nloop[y]) { // y is a root of the tree x is in
      // since the heigh of y will be zero,
      // the min will be the height of x
      int base = h[x];

      int direct = abs(scc[nloop[y]][y] - scc[nloop[y]][branch]);
      // d(h[x]), d(direct);

      return base += min(direct, int(scc[nloop[y]].size()) - direct);
    }
  } else if (!in_loop(x) && !in_loop(y)) {
    cout << "BOTH OUTSIDE" << el;
    int branch_x = last_k[first[x]], branch_y = last_k[first[y]];
    d(branch_x), d(branch_y);
    d(first[x]), d(first[y]);
    d(nloop[last_k[first[x]-1]]), d(nloop[last_k[first[y]-1]]);
    d(nloop[last_k[first[x]]]), d(nloop[last_k[first[y]]]);
    d(scc[nloop[branch_x]].size()), d(scc[nloop[branch_y]].size());

    if (nloop[branch_x] == nloop[branch_y]) { // check theyre on the same tree
      // d(nloop[branch_x]), d(nloop[branch_y]);
      int left = first[x], right = first[y];
      if (left > right)
        swap(left, right);
      int lca = query_tree(1, 0, euler.size() - 1, left, right);
      // d(left), d(right);
      // d(lca), d(h[lca]);
      int base = (h[x] - h[lca]) + (h[y] - h[lca]);
      if (nloop[lca] == nloop[branch_x]) { // their lca is the root
        cout << "THEIR LCA IS THE ROOT" << el;
        int direct = abs(scc[nloop[lca]][branch_y] - scc[nloop[lca]][branch_x]);
        base += min(direct, int(scc[nloop[lca]].size()) - direct);
      }
      return base;
    }
  }
  return -1;
}

int main() {
  euler.reserve(MAXN);
  topo.reserve(MAXN);
  forn(i, MAXN) g[i].reserve(1);
  int quer = 1;
  while (cin >> n) {
    // d(n);
    h[n + 1] = INF;
    memset(seen, false, sizeof seen);
    // memset(parent, false, sizeof parent);
    memset(nloop, -1, sizeof nloop);
    memset(first, -1, sizeof first);
    // memset(h, -1, sizeof h);
    memset(last_k, -1, sizeof last_k);
    memset(tree, -1, sizeof tree);
    int city;
    for1(i, n) {
      cin >> city;
      // if(city != i){
      g[i].pb(city);
      inv[city].pb(i);
      // } else
      // parent[i] = true;
    }

    kosaraju();

    build_lca();

    build_tree(1, 0, euler.size() - 1);
    cout << "IT DIDNT CRASH HAHA " << el;
    // forn(k, 60) { printf("node: %i - val: %i -- ", k, tree[k]); }

    cin >> q;

    int c1, c2, incr = 0;
    for (incr; incr < q; ++incr) {
      cin >> c1 >> c2;
      printf("case #%i ", quer + incr);
      cout << query_flights(c1, c2) << el;
    }
    quer += incr;
    topo.clear();
    euler.clear();
    forn(j, n + 1) g[j].clear();
    forn(j, n + 1) inv[j].clear();
    forn(j, n + 1) scc[j].clear();
  }
}
