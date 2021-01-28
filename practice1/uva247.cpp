// https://vjudge.net/problem/UVA-247
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
int n, m, timer, num[MAXN], low[MAXN], casec(1);
bool seen[MAXN];
set<int> g[MAXN];
vec<vi> scc;
vi s;
string indtos[MAXN];
map<string, int> stoind;

// There can be no back edges between SCC's
// otherwise itd just be a bigger SCC (the low of
// the root wouldnt be itself
void find_scc(int u) {
  s.pb(u);
  seen[u] = true;
  num[u] = low[u] = ++timer;
  for (int v : g[u]) {
    if (num[v] < 0) // This implies i have never seen the node at all
      find_scc(v);
    if (seen[v])
      low[u] = min(low[u], low[v]);
    // this implies its still in the stack, so its not in any SCC,
    // but i've already seen it
  }

  if (num[u] == low[u]) {
    int comma = 0;
    for(;;) {
      int v = s.back();
      s.pop_back();
      seen[v] = false;
      if(comma++) printf(", ");
      cout << indtos[v];
      if(u==v) break;
    }
    cout << el;
  }
}

int main() {

  cin >> n >> m;
  while (n != 0 || m != 0) {
    printf("Calling circles for data set %i:\n", casec++);
    timer = 0;
    memset(seen, false, sizeof seen);
    memset(num, -1, sizeof num);
    memset(low, MAXN, sizeof low);
    forn(i, n + 1) g[i].clear();
    scc.clear();
    forn(i, n + 1) indtos[i] = "";
    stoind.clear();
    s.clear();

    int wcount = 0;
    string src, dst;
    forn(j, m) {
      cin >> src >> dst;
      if(!stoind.count(src)) {
	stoind[src] = wcount;
	indtos[wcount++] = src;
      }
      if(!stoind.count(dst)) {
	stoind[dst] = wcount;
	indtos[wcount++] = dst;
      }
      g[stoind[src]].insert(stoind[dst]);
    }
    forn(i, n) if (num[i] == -1) find_scc(i);

    cout << el;
    cin >> n >> m;
  }
}
