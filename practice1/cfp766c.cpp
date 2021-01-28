// https://codeforces.com/problemset/problem/766/C
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (int(1e3) + 1)
#define MOD (int(1e9) + 7)

typedef long long ll;
using namespace std;
// problem start----------------------

int n, s[MAXN], a[MAXN], mlen = 0;
ll dp[MAXN][MAXN];

ll gay_dp1(int pos, int len, int rem) {
    // printf("%i %i %i\n", pos, len, rem);
    mlen = max(mlen, len);
    if (pos == n) return 1;

    if (dp[pos][rem] != -1) return dp[pos][rem];

    ll ret = gay_dp1(pos + 1, 1, a[s[pos]] - 1) % MOD;
    // d(ret);

    int new_rem = a[s[pos]] - len;
    if (rem > 0 && new_rem > 0) {
        ll ret2 = gay_dp1(pos + 1, len + 1, min(new_rem, rem) - 1) % MOD;
        // d(ret2);
        ret = (ret + ret2) % MOD;
    }

    return dp[pos][rem] = ret;
}

ll gay_dp3(int pos, int len, int rem) {
    if (pos == n) return 0;
    if (dp[pos][rem] != -1) return dp[pos][rem];

    ll ret = (gay_dp3(pos + 1, 1, a[s[pos]] - 1) + 1) % MOD;

    int new_rem = a[s[pos]] - len;
    if (rem > 0 && new_rem > 0) {
        ll ret2 = gay_dp3(pos + 1, len + 1, min(new_rem, rem) - 1) % MOD;

        ret = min(ret, ret2);
    }

    return dp[pos][rem] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s[i] = int(c) - 97;
    }

    for (int i = 0; i < 26; ++i) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);
    ll ans = gay_dp1(1, 1, a[s[0]] - 1);
    cout << ans << el;
    cout << mlen << el;
    memset(dp, -1, sizeof dp);
    ans = gay_dp3(1, 1, a[s[0]] - 1) + 1;
    cout << ans << el;
}
