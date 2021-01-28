// https://codeforces.com/gym/101173/attachments
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (int(1e5) + 1)

typedef long long ll;
using namespace std;
// problem start----------------------

typedef array<int, 2> ii;

struct dsu {
    vector<int> p, set_size;
    int size, sets;
    dsu(int size) {
        this->size = (this->sets = size);
        this->p.reserve(size);
        for (int i = 0; i < size; ++i) this->p.push_back(i);
        this->set_size.resize(size, 1);
    }
    int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
    bool same_set(int i, int j) { return find_set(i) == find_set(j); }
    void union_set(int i, int j) {
        int s1 = find_set(i), s2 = find_set(j);
        if (set_size[s1] < set_size[s2]) {
            p[i] = p[j];
            set_size[s2] += set_size[s1];
            set_size[s1] = 0;
        } else {
            p[j] = p[i];
            set_size[s1] += set_size[s2];
            set_size[s2] = 0;
        }
        sets--;
    }
    void reset() {
        this->p.clear();
        this->set_size.clear();
        this->size = (this->sets = 0);
    }
};

int n, m;
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
