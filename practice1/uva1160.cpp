// https://vjudge.net/problem/UVA-1160
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
    p.assign(size, 0), r.assign(size, 1);
    forn(i, size) p[i] = i;
    num_sets = size;
  }
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    if (find_set(i) != find_set(j)) {
      if (r[p[i]] > r[p[j]])
        p[p[j]] = p[i], r[p[i]] += r[p[j]], r[p[j]] = 0;
      else
        p[p[i]] = p[j], r[p[j]] += r[p[i]], r[p[i]] = 0;
      num_sets--;
    }
  }
};

dsu mst;
vec<ii> edges;

int back_eds() {
  int back_eds = 0;
  reverse(edges.begin(), edges.end());
  for (ii e : edges) {
    if (!mst.same_set(e.fi, e.se))
      mst.union_set(e.fi, e.se);
    else
      ++back_eds;
  }
  return back_eds;
}

int main() {
  int src, dst;
  while (cin >> src) {
    int max_num = -1;
    while (src != -1) {
      cin >> dst;
      edges.pb(ii(src, dst));
      max_num = max(max_num, max(src, dst));
      cin >> src;
    }
    mst.init(max_num + 1);
    cout << back_eds() << el;
    edges.clear();
  }
}
