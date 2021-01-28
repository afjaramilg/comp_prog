//https://www.spoj.com/problems/SAMER08C/
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

const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------
const int MAXN = 1e5+1;
int mat[MAXN], best[MAXN], dp[MAXN];


int gay_dp(int i, int n, int* arr) {
  if(i>=n)
    return 0;
  if(dp[i])
    return dp[i];
  return dp[i] = max(gay_dp(i+1, n, arr), arr[i]+gay_dp(i+2, n, arr));
}

int main() {
  int m, n;
  while(scanf("%d%d", &m, &n) == 2 && (m || n)) {
    forn(r, m) {
      forn(c, n) {scanf("%d", &mat[c]);}
      fill(dp, dp+n, 0);
      best[r] = gay_dp(0, n, mat);
    }
    fill(dp, dp+m, 0);
    cout << gay_dp(0, m, best) << el;
  }
}
