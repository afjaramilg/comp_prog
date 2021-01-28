// https://www.spoj.com/problems/IOIPALIN/
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
string s;
int n, dp[5001][5001];

void gay_dp() {
  forn(i, n+1) dp[0][i] = dp[i][0] = 0;
  
  string r = s;
  reverse(r.begin(), r.end());

  for1(i, n) {
    for1(j, n) {
      if (r[i-1] == s[j-1]) 
	dp[i][j] = 1 + dp[i-1][j-1]; 
      else 
	dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
    }
  }

  cout << n - dp[n][n] << el;
}


int main() {
  cin >> n >> s;
  gay_dp();

}
