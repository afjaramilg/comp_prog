// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (50000)

typedef long long ll;
using namespace std;
// problem start----------------------

int n, k, dp[MAXN][501];
vector<int> tree[MAXN];

ll gay_dp(ll u, ll p) {
    ll total = dp[u][k];
    dp[u][0] = 1;

    for (int v : tree[u]) {
        if (v == p) continue;
        dp[v][1] += 1;

        for (int i = 2; i <= k; ++i) {
            dp[v][i] = dp[u][i - 1];
        }

        total += gay_dp(v, u);

        for (int i = k; i >= 2; --i) {
            dp[u][i] += (dp[v][i - 1] - dp[u][i - 2]);
        }

        dp[u][1] += 1;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    memset(dp, 0, sizeof dp);

    cin >> n >> k;
    for (int _ = 0; _ < n - 1; ++_) {
        int src, dst;
        cin >> src >> dst;

        tree[src - 1].push_back(dst - 1);
        tree[dst - 1].push_back(src - 1);
    }

    cout << gay_dp(0, -1) << el;
}

