// https://www.spoj.com/problems/PT07X/
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
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

vec<int> tree[MAXN];
int dp[MAXN][2]={0};

void dp_dfs(int node, int par) {
  dp[node][1] = 1;
  dp[node][0] = 0;
  for(int i: tree[node])
    if(i!=par) {
      dp_dfs(i, node);
      dp[node][0] += dp[i][1];
      dp[node][1] += min(dp[i][0], dp[i][1]);
    }
 
}


int main() {
  int n;
  cin >> n;
  int src, dst;
  forn(i, n-1) {
    cin >> src >> dst;
    tree[src-1].pb(dst-1);
    tree[dst-1].pb(src-1);
  }

  dp_dfs(0, -1);
  cout << min(dp[0][1], dp[0][0])<<el;
}
