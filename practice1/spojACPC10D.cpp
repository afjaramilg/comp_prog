// https://www.spoj.com/problems/ACPC10D/
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
// const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;

// Problem start------------------------

const ll INF = 1e18;
int N, costs[int(1e6)][3];
ll dp[int(1e6)][3];

ll gay_dp(int row, int col) {
    if (col == 1 && row == N - 1) return costs[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    ll ans = INF;
    bool l_lim = col > 0;        // can move left
    bool r_lim = col < 2;        // can move right
    bool d_lim = row < (N - 1);  // can move down

    if (d_lim) {
        // straight down
        ans = gay_dp(row + 1, col);
        // left diagonal down
        if (l_lim) ans = min(ans, gay_dp(row + 1, col - 1));
        // right diagonal down
        if (r_lim) ans = min(ans, gay_dp(row + 1, col + 1));
    }
    // move right
    if (r_lim) ans = min(ans, gay_dp(row, col + 1));
    return dp[row][col] = ans + costs[row][col];
}

int main() {
    int ncase = 1;
    while (cin >> N && N) {
        forn(i, N) { forn(j, 3) cin >> costs[i][j]; }
        memset(dp, -1, sizeof dp);
        cout << ncase << ". " << gay_dp(0, 1) << endl;
        ++ncase;
    }
}
