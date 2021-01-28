// https://vjudge.net/problem/UVA-10465
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

int m, n, t;
ii dp[10002];

ii gay_dp(int step) {
    if (step == t) return {0, 0};
    if (dp[step] != ii(-1, -1)) return dp[step];

    bool nend = (step + n) > t, mend = (step + m) > t;

    ii nstep = (nend) ? ii(t - step, 0) : gay_dp(step + n);
    ii mstep = (mend) ? ii(t - step, 0) : gay_dp(step + m);

    // if we are at an "end" and cant eat anymore,
    // then we shouldnt count it as a burger
    nstep.se += !nend, mstep.se += !mend;

    // if the amount of beer to be drunk is different
    // then pick the one with the smallest if the amount
    // is the same, then pick the onw with the most burgers.
    dp[step] = (nstep.fi == mstep.fi) ? max(nstep, mstep) : min(nstep, mstep);
    return dp[step];
}

int main() {
    while (cin >> m) {
        cin >> n >> t;
        forn(i, t + 1) dp[i] = {-1, -1};

        ii ans = gay_dp(0);
        cout << ans.se;
        if (ans.fi) cout << " " << ans.fi;
        cout << endl;
    }
}
