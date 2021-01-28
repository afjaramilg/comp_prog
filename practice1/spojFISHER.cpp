// https://www.spoj.com/problems/FISHER/
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
int n, t, state[52][52], toll[52][52], dp[52][1002];

void gay_dp() {
    dp[0][0] = 0;
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                int add = i - state[k][j];
                if (add >= 0) dp[j][i] = min(dp[j][i], toll[k][j] + dp[k][add]);
            }
        }
    }
    int* ans = min_element(dp[n - 1], dp[n - 1] + t + 1);
    cout << *ans << ' ' << ans - dp[n - 1] << el;
}

int main() {
    cin >> n >> t;
    while (n || t) {
        memset(toll, 0, sizeof dp);
        memset(state, 0, sizeof dp);
        forn(i, n + 2) forn(j, t + 2) dp[i][j] = INF;
        forn(i, n) { forn(j, n) cin >> state[i][j]; }
        forn(i, n) { forn(j, n) cin >> toll[i][j]; }

        gay_dp();
        cin >> n >> t;
    }
}
