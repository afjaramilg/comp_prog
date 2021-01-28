// https://vjudge.net/problem/UVA-1234
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

vec<ii> g[MAXN];
bool markd[MAXN];
priority_queue<ii, vec<ii>> q;



void process(int u) {
  for(ii e: g[u]) {
    if(!markd[e.se])
      q.push(e);
  }
  markd[u] = true;
}



void prim(int root) {
  process(root);
  int res = 0;
  while(!q.empty()) {
    ii e = q.top();
    q.pop();
    if(!markd[e.se]) 
      process(e.se);
    else
      res+=e.fi;
  }

  cout << res << el;

}


int main() {
  int cases;
  cin >> cases;
  forn(c, cases) {
    memset(markd, false, sizeof markd);
    int n, m;
    cin >> n >> m;
    forn(j, m) {
      int src, dst, w;
      cin >> src >> dst >>w;
      g[src].pb(ii(w,dst));
      g[dst].pb(ii(w,src));
    }
    prim(1);
    forn(i, n+1) g[i].clear();
    
  }


}
