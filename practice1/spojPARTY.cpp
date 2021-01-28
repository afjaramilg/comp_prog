// http://www.spoj.com/problems/PARTY/
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
#define vec vector
#define iii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------

int b, n, parts[102][2], dp[102][502];

void gay_dp() {

  for1(i, n) {
    for1(j, b) {
      dp[i][j] = dp[i - 1][j];
      if (parts[i][0] <= j)
        dp[i][j] = max(dp[i][j], parts[i][1] + dp[i - 1][j - parts[i][0]]);
    }
  }
  int max_i = 0;
  forn(i, b+1) {
    if(dp[n][i] > dp[n][max_i])
      max_i = i;
  }

  cout << max_i << ' ' << dp[n][max_i] << el;
}

int main() {
  cin >> b >> n;
  while(b || n) {
    memset(dp, 0, sizeof dp);
    memset(parts, 0, sizeof parts);      
    for1(p, n) cin >> parts[p][0] >> parts[p][1];
    gay_dp();        
    cin >> b >> n;
  }

}
