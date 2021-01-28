// https://vjudge.net/problem/UVA-10154
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 200;
const int INF = std::numeric_limits<int>::max();

using namespace std;
// problem start----------------------

typedef pair<int, int> ii;

vec<ii> turts;
int turt_no = 0, dp[5067];

int main() {
    int w, s, ans = 0;

    while (cin >> w >> s) {
        turts.push_back({w, s});
    }

    int turt_no = turts.size();

    sort(turts.begin(), turts.end(),
         [](ii a, ii b) { return a.second < b.second; });

    fill(dp, dp + 5067, INF);
    dp[0] = 0;

    for (int i = 0; i < turt_no; ++i) {
        for (int j = ans; j >= 0; --j) {
            int tw = turts[i].first, ts = turts[i].second;

            if ((ts >= dp[j] + tw) && (dp[j] + tw < dp[j + 1])) {
                dp[j + 1] = dp[j] + tw;
                ans = max(ans, j + 1);
            }
        }
    }

    cout << ans << el;
}
