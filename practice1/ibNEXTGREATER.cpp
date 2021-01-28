// mr571z+5ktul22gtbye0@sharklasers.com
// stink_goblin69 bagoongos123
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (int(1e5) + 1)

typedef long long ll;
using namespace std;
// problem start----------------------

vector<int> nextGreater(vector<int> &A) {
    stack<int> s;
    vector<int> sol;
    sol.resize(A.size());

    for (int i = 0; i < A.size(); ++i) {
        sol[i] = -1;
    }

    for (int i = A.size() - 1; i >= 0; --i) {
        while(!s.empty() && s.top() <= A[i]) {
            s.pop();
        }

        if(!s.empty()) sol[i] = s.top();
        s.push(A[i]);
    }

    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
