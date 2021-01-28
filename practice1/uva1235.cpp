// https://vjudge.net/problem/UVA-1235
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

const int MAXN = 1e6 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------
int n, t;
bool markd[MAXN];
vec<ii> g[MAXN];
string keys[MAXN];
priority_queue<tiii, vec<tiii>, greater<tiii>> q;

int cturn(string a, string b) {
  int cost = 0;
  forn(i, 4) {
    int direct = abs((a[i] - '0') - (b[i] - '0'));
    cost += min(direct, 10 - direct);
  }
  return cost;
}

void process(int u) {
  for (ii t : g[u])
    if (!markd[t.se]) {
      q.push(tiii(t.fi, u, t.se));
    }
  markd[u] = true;
}

int prim(int root) {
  int new_w = 0, mst_v = 1;
  process(root);

  while (!q.empty()) {
    int src = q.top()[1], dst = q.top()[2], w = q.top()[0];
    q.pop();
    if (!markd[dst]) {
      // printf("%i %i\n", src, dst);
      process(dst), new_w += w, mst_v++;
    }
  }
  return new_w;
}

int main() {
  cin >> n;
  forn(c, n) {
    cin >> t;
    memset(markd, false, sizeof markd);
    forn(i, t + 1) g[i].clear();

    keys[0] = "5555";
    int r = 0;
    for1(i, t) {
      cin >> keys[i];
      r = (cturn("0000", keys[i]) <= cturn("0000", keys[r])) ? i : r;
    }

    for1(i, t - 1) fore(j, i + 1, t) {
      g[i].pb(ii(cturn(keys[i], keys[j]), j));
      g[j].pb(ii(cturn(keys[i], keys[j]), i));
    }

    cout << prim(r) + cturn("0000", keys[r]) << el;
  }
}
