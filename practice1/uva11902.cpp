// https://vjudge.net/problem/UVA-11902
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
bool g[101][101], mdom[101][101], visited[101];

bool dom_dfs(int n, int dom, int sub, bool fdom) {
  visited[n] = true;
  if (n == sub && !fdom) 
    return false || dom == sub;
  

  forn(i,101) 
    if (g[n][i]==true && i != dom && !visited[i])
      if (!dom_dfs(i, dom, sub, i == dom || fdom))
        return false;
    
  
  return true;
}

int main() {
  int cases, n;
  cin >> cases;
  for1(c, cases) {
    cin >> n;
    printf("Case %i:\n", c);
    forn(i, n) forn(j, n) cin >> g[i][j];

    bool reach[101]={0};
    dom_dfs(0, -1,-2,true);
    forn(i, n)
      reach[i] = visited[i];
        
    forn(dom, n) forn(sub, n) {
      memset(visited, 0, sizeof visited);
      mdom[dom][sub] = reach[sub]&&(dom_dfs(0, dom, sub, dom == 0));
    }

    string del = "+";
    forn(i, 2 * n - 1) del += "-";
    del += "+";

    forn(i, n) {
      cout << del << "\n|";
      forn(j, n) cout << (mdom[i][j] ? 'Y' : 'N') << "|";
      cout << el;
    }
    cout << del << el;
    memset(g, 0, sizeof g);
    memset(visited, 0, sizeof visited);
    memset(mdom, 0, sizeof mdom);
  }
}
