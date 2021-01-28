// https://vjudge.net/problem/19206
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
ll n, dp[30001][5], coins[5] = {1, 5, 10, 25, 50};

ll gay_dp(ll remain, ll coin) {
    // cout << remain << endl;

    if (remain == 0) return 1;
    if (remain < 0) return 0;
    if (dp[remain][coin] != -1) return dp[remain][coin];
    ll ans = 0;
    for (int i = coin; i < 5; ++i) {
        if (coins[i] <= remain) {
            ans += gay_dp(remain - coins[i], i);
        }
    }
    return dp[remain][coin] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    while (cin >> n) {
        gay_dp(n, 0);
        if (dp[n][0] > 1)
            cout << "There are " << dp[n][0] << " ways to produce " << n
                 << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n
                 << " cents change.\n";
    }
}
