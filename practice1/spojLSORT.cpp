// https://www.spoj.com/problems/LSORT/
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------

int dp[1001][1001], xback[1001][1001], xfront[1001][1001], arr[1001], ind[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T, N;

    cin >> T;

    while (T--) {
        cin >> N;
        memset(dp, -1, sizeof dp);
        memset(xback, 0, sizeof xback);
        memset(xfront, 0, sizeof xfront);

        for (int i = 1; i <= N; ++i) {
            cin >> arr[i];
            ind[arr[i]] = i;
            dp[arr[i]][arr[i]] = i;
        }

        for (int t = 2; t <= N; ++t) {
            for (int n = 1; n <= (N - t + 1); ++n) {
                xback[t][n] = xback[t - 1][n] - (ind[n] > ind[n + t - 1]);
            }

            for (int n = t; n <= N; ++n) {
                xfront[t][n] = xfront[t - 1][n] - (ind[n] > ind[n - t + 1]);
            }
        }

        for (int i = N; i >= 1; --i) {
            for (int j = i + 1; j <= N; ++j) {
                int turn = j - i + 1;
                int bcost = (ind[i] + xback[turn][i]) * turn;
                int fcost = (ind[j] + xfront[turn][j]) * turn;

                dp[i][j] = min(dp[i + 1][j] + bcost, dp[i][j - 1] + fcost);
            }
        }

        cout << dp[1][N] << el;
    }
}
