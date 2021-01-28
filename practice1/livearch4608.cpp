// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2609
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define ll long long
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------
const int MOD = 1e6;

ll N, M, dp[10][500][1 << 11];

void add(ll &ans, ll y) {
    ans -= (MOD * (ans + y >= MOD));
    ans += y;
}

int apply_mask(int piece, int row, int col, int mask) {
    bool cur, fill, applied = false;
    fill = cur = mask & 1;
    bool down = (mask & (1 << 1)) || (row >= (N - 1));
    bool right = (mask & (1 << N)) || (col >= (M - 1));

    mask = mask >> 1;

    switch (piece) {
        case 0:
            if (!cur && !down && !right) {
                mask = mask | 1;               // turn on the one below
                mask = mask | (1 << N);        // turn on right of below
                mask = mask | (1 << (N - 1));  // turn on right of current
                fill = true;
                applied = true;
            }
            break;
        case 1:
            if (!cur && !down) {
                mask = mask | 1;         // turn on the one below
                mask = mask | (1 << N);  // turn on right of below
                fill = true;
                applied = true;
            }
            break;
        case 2:
            if (!cur && !down && !right) {
                mask = mask | 1;               // turn on the one below
                mask = mask | (1 << (N - 1));  // turn on right of current
                fill = true;
                applied = true;
            }
            break;
        case 3:
            if (!cur && !right & row < (N - 1)) {
                mask = mask | (1 << N);        // turn on right of below
                mask = mask | (1 << (N - 1));  // turn on right of current
                fill = true;
                applied = true;
            }
            break;
        case 4:
            if (cur && !right && !down) {
                mask = mask | 1;
                mask = mask | (1 << N);        // turn on right of below
                mask = mask | (1 << (N - 1));  // turn on right of current
                fill = true;
                applied = true;
            }
            break;
    }

    return (fill && applied) ? mask : -1;
}

ll gay_dp(ll row, ll col, ll mask) {
    if (col == M - 1) return mask == (1 << N) - 1;
    if (row == N) return gay_dp(0, col + 1, mask);

    ll &v = dp[row][col][mask];
    if (v != -1) return v;

    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        ll mask_new = apply_mask(i, row, col, mask);
        if (mask_new != -1) {
            add(ans, gay_dp(row + 1, col, mask_new));
        }
    }
    if (mask & 1) add(ans, gay_dp(row + 1, col, (mask >> 1)));

    return v = ans;
}

int main() {
    while ((cin >> N >> M) && N && M) {
        memset(dp, -1, sizeof dp);
        cout << gay_dp(0, 0, 0) % MOD << endl;
    }
}
