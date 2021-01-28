// https://vjudge.net/problem/UVA-10147
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
    num_sets = size;
    r.assign(size, 1), p.resize(size);
    forn(i, size) p[i] = i;
  }
  int find_set(int i) { return (p[i] == i) ?  i : (p[i] = find_set(p[i])); }
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

#define tin(ind, t) get<ind>(t)
typedef tuple<double, int, int> dii;
typedef pair<double, int> di;

vec<ii> towns;
vec<dii> edges;
set<ii> curr;
vec<ii> ans;
dsu mst;

double dist(int i, int j) {
  ii u = towns[i], v = towns[j];
  return sqrt(pow(u.fi - v.fi, 2) + pow(u.se - v.se, 2));
}

void kruskal() {
  sort(edges.begin(), edges.end());
  for (dii e : edges) {
    if (!mst.same_set(tin(1, e), tin(2, e))) {
      mst.union_set(tin(1, e), tin(2, e));
      ans.pb(ii(tin(1, e)+1, tin(2, e)+1));
    }
  }

  sort(ans.begin(), ans.end());
  
  for(ii a: ans) 
    printf("%i %i\n", a.fi , a.se);
}

int main() {
  int cases;
  cin >> cases;

  forn(c, cases) {
    if(c>0)
      cout << el;
    towns.clear(), edges.clear(), curr.clear();

    int n;
    cin >> n;
    mst.init(n);
    
    forn(i, n) {
      int x, y;
      cin >> x >> y;
      towns.pb(ii(x, y));
    }
    int m;
    cin >> m;
    
    // if(m>=n) {
      // cout << "No new highways need" << el;
      // continue;
    // }
      
    
    forn(i, m) {
      int t1, t2;
      cin >> t1 >> t2;
      mst.union_set(t1-1, t2-1);
    }
    forn(i, n - 1) {
      fore(j, i + 1, n - 1) {
        if (!mst.same_set(i,j))
          edges.pb(dii(dist(i, j), i, j));
      }
    }
    if(mst.num_sets > 1)
      kruskal();
    else
      cout << "No new highways need" << el;

  }
}
