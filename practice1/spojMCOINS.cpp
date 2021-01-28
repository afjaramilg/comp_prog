// https://www.spoj.com/problems/MCOINS/
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
int k, l, m, dp[int(1e6 + 100)][2];



int gay_dp(int ind, bool turn) {
  if (ind < 0)
    return !turn;
  if (ind == 0 && turn) // if we are at 0 with B
    return dp[0][turn] = 1;
  if (ind == 0 && !turn) // if we are at 0 with A
    return dp[0][turn] = 0;

  if (dp[ind][turn] != -1) 
    return dp[ind][turn];

  
  int a = gay_dp(ind - k, !turn);
  int b = gay_dp(ind - l, !turn);
  int c = gay_dp(ind - 1, !turn);
  if (!turn)
    return dp[ind][turn] = a || b || c;
  else
    return dp[ind][turn] = a && b && c;
}

int main() {
  memset(dp, -1, sizeof dp);
  cin >> k >> l >> m;
  forn(n, m) {
    int ind;
    cin >> ind;
    
    if(gay_dp(ind, 0))
      cout << 'A';
    else
      cout << 'B';
  }


}
