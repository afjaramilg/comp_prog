// https://vjudge.net/problem/UVA-534
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
typedef pair<double, int> pdi;
typedef tuple<double, int, int> tdii;

vec<pdi> tree[2000];
vec<ii> stones;
bool markd[2000];
priority_queue<tdii, vec<tdii>, greater<tdii>> q;

double get_minimax(int u, double max_e) {
  markd[u] = true;
  double ret_val = 0;
  for (pdi v : tree[u]) {
    if (v.se == 1)
      return max(max_e, v.fi);
    if (!markd[v.se])
      ret_val = max(get_minimax(v.se, max(max_e, v.fi)), ret_val);
  }

  return ret_val;
}

double norm2(int x1, int x2, int y1, int y2) {
  return sqrt((double)pow(x1 - x2, 2) + (double)pow(y1 - y2, 2));
}

void process(int i) {
  ii s1 = stones[i];
  forn(j, stones.size()) {
    if (i != j && !markd[j]) {
      ii s2 = stones[j];
      double w = norm2(s1.fi, s2.fi, s1.se, s2.se);
      q.push(tdii(w, i, j));
    }
  }
  markd[i] = true;
}

void prim(int root) {
  process(root);
  while (!q.empty()) {
    int src = get<1>(q.top()), dst = get<2>(q.top());
    double w = get<0>(q.top());
    q.pop();
    if (!markd[dst]) {
      process(dst);
      tree[src].pb(pdi(w, dst));
      tree[dst].pb(pdi(w, src));
    }
  }
}

int main() {
  int cases = 1;
  int n;
  cin >> n;
  while (n) {
    stones.clear();
    forn(i, n) tree[i].clear();
    memset(markd, false, sizeof markd);
    ii fred, fiona;
    cin >> fred.fi >> fred.se;
    cin >> fiona.fi >> fiona.se;
    stones.pb(fred), stones.pb(fiona);
    forn(i, n - 2) {
      int x, y;
      cin >> x >> y;
      stones.pb(ii(x, y));
    }
    prim(0);
    memset(markd, false, sizeof markd);
    printf("Scenario #%i\n", cases);
    printf("Frog Distance = %.3f\n", get_minimax(0, 0));
    cout << el;
    ++cases;
    cin >> n;
  }
}
