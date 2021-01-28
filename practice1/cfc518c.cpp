// http://codeforces.com/contest/518/problem/C
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  ll n, m, k, app;
  cin >> n >> m >> k;

  vector<int> app_index = {0};
  app_index.resize(n + 1);

  vector<int> index_app = {0};
  index_app.resize(n + 1);

  for (ll i = 0; i < n; ++i) {
    cin >> app;
    index_app.at(i) = app;
    app_index.at(app) = i;
  }

  ll total_moves = m;
  for (ll i = 0; i < m; ++i) {
    cin >> app;
    ll pos = app_index[app];
    total_moves+=pos/k;
    if (pos > 0) {
      ll prev_app = index_app[pos - 1];
      index_app[pos - 1] = app;
      index_app[pos] = prev_app;

      app_index[app]--;
      app_index[prev_app]++;
    }
  }


  cout << total_moves << endl; 
}
