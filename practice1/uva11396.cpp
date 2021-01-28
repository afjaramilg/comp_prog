// https://vjudge.net/problem/UVA-11396
// typedefs and such/-----------------
#include <bits/stdc++.h>
#include <typeinfo>

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
vi g[330];
int n, color[330];
bool bipart, seen[330];

void solve(int root) {
  queue<int> q;
  q.push(root);
  color[root] = 0;

  while (!q.empty() && bipart) {
    int u = q.front();
    seen[u] = true;
    q.pop();
    for (int v : g[u]) {
      if (color[v] < 0) {
        color[v] = abs(1 - color[u]);
        q.push(v);
      } else if (color[v] == color[u]) {
        bipart = false;
        break;
      }
    }
  }
}

int main() {
  cin >> n;
  while (n) {
    forn(j, 330) g[j].clear();
    bipart = true;
    memset(color, -1, sizeof color);
    memset(seen, false, sizeof seen);

    int src, dst;
    cin >> src >> dst;
    while (src != 0 && dst != 0) {
      g[src].pb(dst);
      g[dst].pb(src);
      cin >> src >> dst;
    }

    forn(j, n) if (!seen[j]) solve(j);
    cout << (bipart ? "YES" : "NO") << el;

    cin >> n;
  }
}
