// https://codeforces.com/problemset/problem/431/C
// typedefs and such/-----------------
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned int MOD = 1e9 + 7;
// Problem start------------------------

ll n, k, d, dp[102][2];

ll gay_dp(ll acum, bool has_val) {
    if (acum > n) return 0;
    if (acum == n && has_val) return 1;

    if (dp[acum][has_val] != -1) return dp[acum][has_val];

    ll ret_val = 0;
    for (int i = 1; i <= k; ++i) {
        ret_val += gay_dp(acum + i, has_val || (i >= d));
    }
    return dp[acum][has_val] = (ret_val % MOD);
}

int main() {
    cin >> n >> k >> d;
    memset(dp, -1, sizeof dp);
    cout << gay_dp(0, false) << endl;
}
