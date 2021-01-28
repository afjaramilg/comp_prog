#include <iostream>
#include <string>
using namespace std;
struct shot {
    string data;
    shot(string data);
    ~shot();
};

shot::shot(string data) : data(data) {}
shot::~shot() {
    // cout << "oi shot: " << data << " die!" << endl;
}

struct node {
    shot a;
    node* next = nullptr;
    node(shot a);
    ~node();
};

node::node(shot a) : a(a) {}
node::~node() {
    // puts("oi node die");
}

struct linked_list {
    int size = 0;
    ~linked_list();
    node* head = nullptr;
    void push(shot d);
    void pop();
};

void linked_list::push(shot d) {
    // puts("the node d copied will die soon");
    //cout << size << endl;
    if (!size) {
        head = new node(d);
    } else {
        node* nhead = new node(d);
        nhead->next = head;
        head = nhead;
    }
    d.data = "copy of " + d.data;
    size++;
    // puts("pushed node");
}

void linked_list::pop() {
    node* old = head;
    head = head->next;
    size--;
    delete head;
}

linked_list::~linked_list() {
    // if this were empty the program in main would
    // start filling up memory
    //puts("now list dies");

    node* cur = head;
    while (size && cur->next) {
        node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }

    puts("oi list die");
}

int main() {
    for (int i = 1; i < 10000000; ++i) {
        linked_list a;
        for (int j = 0; j < 10000; ++j) {
            a.push(shot("huhuuhuhuhu"));
        }
        //cout << ((a.head)->a).data << endl;

        // cout << "passed " << i << endl;
    }
    cout << "exited successfully" << endl;
}



//------------------------------------------------------------
// http://codeforces.com/contest/682/problem/C
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

typedef long long ll;
const int INF = 1 << 30;
const int MAXN = int(1e5) + 1;
using namespace std;
// problem start----------------------

#define fi first
#define se second
typedef pair<int, int> ii;

vector<ii> tree[MAXN];

ll n, change = 0, cap[MAXN], sum[MAXN];
vector<ll> suf;

void init_suf(int u, int p, int w) {
    if (tree[u].size() == 1 && u != 1) {
        suf.push_back(u), sum[u] = w;
    } else {
        bool v = tree[u][0].fi == p;
        init_suf(tree[u][v].fi, u, tree[u][v].se);
        if (u != 1) {
            sum[u] = sum[suf.back()] + w;
            suf.push_back(u);
        }
    }
}

bool catch_up = true;
ll dfs(int u, int p, int w) {
    if (tree[u].size() == 1 && u != 1) {
        catch_up = false, change -= w;
        return (sum[suf.back()] > cap[u]);
    }

    ll tot_sad = 0;
    for (ii vw : tree[u]) {
        if (vw.fi != p) {
            
            tot_sad += dfs(vw.fi, u, vw.se);
        }
    }
    tot_sad += (sum[suf.back()] + changes) > cap[u];
    changes -= w;
    return tot_sad;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> cap[i];

    int dst, w;
    for (int src = 1; src <= n - 1; ++src) {
        cin >> dst >> w;
        tree[src + 1].push_back({dst, w});
        tree[dst].push_back({src + 1, w});
    }
    init_suf(1, -1, 0);
    reverse(suf.begin(), suf.end());

    ll max_s = suf[0];
    for (int i = 1; i < suf.size(); ++i) {
        if (sum[max_s] < sum[suf[i]]) max_s = suf[i];
        suf[i] = max_s;
    }

    for (int i = 1; i <= n; ++i) cout << sum[i] << ' ';
    cout << el;

    for (ll s : suf) cout << s << ' ';
    cout << el;
}


