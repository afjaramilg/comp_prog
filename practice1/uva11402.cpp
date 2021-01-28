// https://vjudge.net/problem/UVA-11402
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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

int n;
int tree[8000000], lazy[8000000], child[8000000];
vi island;

void eval_lazy(int node) {
  if (lazy[node] == 2) {
    tree[node] = child[node] - tree[node];
    // printf("node %i %i tree[node]", node, tree[node]);
  } else if (lazy[node] != -1)
    tree[node] = lazy[node] * child[node];
}

void repet(int node) {
  if (lazy[node] == -1)
    lazy[node] = 2;
  else if (lazy[node] < 2)
    lazy[node] = abs(lazy[node] - 1);
  else 
    lazy[node] = -1;
}

void propagate(int v) {
  if (lazy[v] != -1) {
    if (lazy[v] < 2) {
      lazy[2 * v] = lazy[v];
      lazy[2 * v + 1] = lazy[v];
    } else {
      repet(2 * v);
      repet(2 * v + 1);
    }
    eval_lazy(v);
    lazy[v] = -1;
  }
}



int build(int v, int lt, int rt) {
  if (lt == rt) {
    child[v] = 1;
    return tree[v] = island[lt];
  }

  int lm = (lt + rt) / 2;
  tree[v] = build(2 * v, lt, lm) + build(2 * v + 1, lm + 1, rt);
  child[v] = child[2 * v] + child[2 * v + 1];
  return tree[v];
}

void update(int v, int lt, int rt, int l, int r, int inst) {
  propagate(v);
  if (l <= lt && rt <= r) {
    // printf("CCCCCCC l%i r%i lazy[v] %i v %i tree[v] %i\n", l, r, lazy[v], v,
    // tree[v]);
    if (inst < 2)
      lazy[v] = inst;
    else
      repet(v);

    propagate(v);
    // printf("BBBBBBBB l %i r %i inst %i v %i\n", l, r, inst, v);
  } else if (r >= l) {
    int lm = (lt + rt) / 2;
    update(2 * v, lt, lm, l, min(r, lm), inst);
    update(2 * v + 1, lm + 1, rt, max(l, lm + 1), r, inst);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  } 
}

int query(int v, int lt, int rt, int l, int r) {
    propagate(v);
  if (l <= lt && rt <= r) {
    return tree[v];
  } else if (r >= l) {
    int lm = (lt + rt) / 2;
    int lc = query(2 * v, lt, lm, l, min(r, lm));
    int rc = query(2 * v + 1, lm + 1, rt, max(l, lm + 1), r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    return lc + rc;
  }
    return 0;
}

int main() {
  island.reserve(2e6);
  int cases;
  cin >> cases;
  memset(lazy, -1, sizeof lazy);

  forn(i, cases) {
    printf("Case %i:\n", i + 1);
    int patterns;
    cin >> patterns;
    forn(j, patterns) {
      int times;
      string pat;
      cin >> times >> pat;

      forn(l, times) for (char k : pat) island.pb(k - '0');
    }

    // for (int a : island)
    // printf("%i", a);
    // cout << el;

    n = island.size();
    build(1, 0, n - 1);

    // forn(hoo, 50) printf("pos %i: %i,%i  -- ", hoo, tree[hoo], lazy[hoo]);
    // cout << el;

    int order, queries = 0;
   
    cin >> order;
    forn(haha, order) {
      char a;
      int l, r;
      cin >> a >> l >> r;
      // printf("ORDER %c %i %i\n", a, l, r);
      if (a == 'F')
        update(1, 0, n - 1, l, r, 1);
      if (a == 'E')
        update(1, 0, n - 1, l, r, 0);
      if (a == 'I')
        update(1, 0, n - 1, l, r, 2);
      if (a == 'S')
        printf("Q%i: %i\n", ++queries, query(1, 0, n - 1, l, r));

      // forn(hoo, 50) printf("pos %i: %i, lazy %i, child %i  -- ", hoo, tree[hoo],
                           // lazy[hoo], child[hoo]);
      // cout << el;
    }
    memset(lazy, -1, sizeof lazy);
    memset(tree, 0, sizeof tree);
    memset(child, 0, sizeof child);
    island.clear();
  }
}
