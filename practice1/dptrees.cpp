//typedefs and such/-----------------
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
//Problem start------------------------


int w[MAXN], dp[MAXN][2];
vec<int> tree[MAXN];

void rec_dfs(int node, int par) {
  dp[node][1]=w[node];
  dp[node][0]=0;
  for(int i: tree[node]) 
    if(i!=par) {
      rec_dfs(i, node);      
      dp[node][1]+= dp[i][0];
      dp[node][0]+=max(dp[i][1], dp[i][0]);
    }
  
}

int main() {
  int n;
  cin >> n;

  forn(i, n)
    cin >> w[i];

  int node, dest;
  forn(i, n-1) {
    cin >> node >> dest;
    tree[node].pb(dest);
    tree[dest].pb(node);
  }
     
  rec_dfs(0, -1);
  cout << max(dp[0][1], dp[0][0])<<el;
}
