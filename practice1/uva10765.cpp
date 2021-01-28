// https://vjudge.net/problem/UVA-10765
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
int n, m, timer, rootc, artp[MAXN], num[MAXN], low[MAXN];
bool seen[MAXN];
vi g[MAXN];

void tarjan(int u, int p) {
  seen[u] = true;
  low[u] = num[u] = ++timer;
  for (int v : g[u]) {
    if (v != p) {
      if (!seen[v]) {
        if (u == 0)
          ++rootc;
        tarjan(v, u);
        if (low[v] >= num[u])
          artp[u]++;
        low[u] = min(low[u], low[v]);
      } else
        low[u] = min(low[u], num[v]);
    }
  }
}

int main() {
  cin >> n >> m;
  while (n != 0 && m != 0) {
    timer = rootc = 0;
    forn(i, n+1) g[i].clear();
    memset(num, MAXN, sizeof num);
    memset(low, MAXN, sizeof low);
    memset(seen, false, sizeof seen);
    memset(artp, 0, sizeof artp);

    int src, dst;
    cin >> src >> dst;

    while (src >= 0 && dst >= 0) {
      g[src].pb(dst);
      g[dst].pb(src);
      cin >> src >> dst;
    }
    tarjan(0, -1);
    artp[0] = (rootc > 1) ? rootc-1 : 0;

    vi ans(n, 0);
    forn(i, n) ans[i] = i;
    sort(ans.begin(), ans.end(),
         [](int a, int b) { return (artp[a] != artp[b]) ? artp[a] > artp[b] : a<b; });

    for(int i = 0; i < m; ++i)
      printf("%i %i\n", ans[i], artp[ans[i]] + 1);
    cout << el;
    cin >> n >> m;
  }
}
