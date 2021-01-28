// https://www.spoj.com/problems/TRT/
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
const int MAXT =  2501;
int n, treats[MAXT], dp[MAXT][MAXT];
void gay_dp() {
  forn(i, n) {
    dp[i][i] = n*treats[i];
  }

  int l, r;
  forn(i, n) {
    l = 0, r = i+1;
    while(r < n) {
      int lo = ((n-1-i) * treats[l]) + dp[l+1][r];
      int ro = ((n-1-i)*treats[r]) + dp[l][r-1];
      dp[l][r] = max(lo, ro);
      r++, l++;
    }

  }

  cout << dp[0][n-1]<<el;
}



int main() {
  cin >> n;
  forn(c, n) {cin >> treats[c];}
  gay_dp();

}
