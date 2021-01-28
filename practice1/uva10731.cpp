// https://vjudge.net/problem/UVA-10731
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

int n, timer, num[MAXN], low[MAXN], ctoind[300];
char indtoc[30];
bool seen[MAXN];
vi s, g[MAXN];
vec<vi> ans;

void tarjan_scc(int u) {
  num[u] = low[u] = ++timer;
  seen[u] = true;
  s.pb(u);
  for (int v : g[u]) {
    if (num[v] == -1)
      tarjan_scc(v);
    if (seen[v])
      low[u] = min(low[u], low[v]);
  }

  if (low[u] == num[u]) {
    vi temp;
    for (;;) {
      int v = s.back();
      s.pop_back();
      seen[v] = false;
      temp.pb(v);
      if (u == v)
        break;
    }
    ans.pb(temp);
  }
}

int main() {
  cin >> n;
  while (n) {
    timer = 0;
    memset(num, -1, sizeof num);
    memset(low, MAXN, sizeof low);
    memset(ctoind, -1, sizeof ctoind);
    memset(seen, false, sizeof seen);
    memset(seen, false, sizeof seen);
    forn(i, 30) g[i].clear();
    s.clear();
    ans.clear();

    int ncount = 0;
    char a;
    forn(i, n) {
      char bank[5];
      forn(j, 5) {
        cin >> bank[j];
        if (ctoind[(int)bank[j]] == -1) {
          indtoc[ncount] = bank[j];
          ctoind[(int)bank[j]] = ncount;
          ncount++;
        }
      }
      cin >> a;
      if (ctoind[(int)a] == -1) {
        indtoc[ncount] = a;
        ctoind[(int)a] = ncount;
        ncount++;
      }

      forn(i, 5) if (bank[i] != a) g[ctoind[a]].pb(ctoind[bank[i]]);
    }

    // forn(i, ncount) {
    //   cout << indtoc[i] << ": ";
    //   for (int j : g[i])
    //     printf("%c ", indtoc[j]);
    //   cout << el;
    // }

    forn(i, ncount) if (num[i] == -1) tarjan_scc(i);

    for (vi &t : ans)
      sort(t.begin(), t.end(),
           [](int a, int b) { return indtoc[a] < indtoc[b]; });

    sort(ans.begin(), ans.end(),
         [](vi a, vi b) { return indtoc[a[0]] < indtoc[b[0]]; });

    for (vi t : ans) {
      printf("%c", indtoc[t[0]]);
      fore(i, 1, t.size() - 1) printf(" %c", indtoc[t[i]]);

      cout << el;
    }
    cin >> n;
    if(n)
        cout << el;
  }
}
