// http://codeforces.com/contest/1417/problem/C
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 2;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------

int a[3 * MAXN], head[3 * MAXN], last[3 * MAXN], ans[3 * MAXN], dist[3 * MAXN];

int main() {
    int t, n;
    cin >> t;

    vector<int> nums;
    nums.reserve(3 * MAXN);

    while (t--) {
        cin >> n;
        // cout << "---" <<el;

        nums.clear();
        memset(head, -1, 4 * n);
        memset(last, -1, 4 * n);
        memset(dist, -1, 4 * n);
        memset(ans, -1, 4 * n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (head[a[i]] == -1) {
                nums.push_back(a[i]);
                head[a[i]] = i;
            } else {
                dist[a[i]] = max(dist[a[i]], i - last[a[i]]);
            }

            last[a[i]] = i;
        }

        for (int k : nums) {
            int tail = n - 1 - last[k];
            int best = max(head[k], tail);
            best = (dist[k] > best) ? dist[k] - 1 : best;

            // cout << k <<  ' ' << head[k] <<  ' '  << tail << ' ' << best <<
            // el;
            ans[best] = (ans[best] == -1 || ans[best] > k) ? k : ans[best];
        }

        int minst = -1;

        for (int i = 0; i < n; ++i) {
            if (ans[i] != -1 && (minst == -1 || ans[i] < minst)) {
                minst = ans[i];
            }
            ans[i] = minst;
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << el;
    }
}
