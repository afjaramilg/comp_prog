// http://codeforces.com/contest/275/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  map<long long, int> elems;
  long long arr[n];

  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
    elems[arr[i]]++;
  }

  sort(arr, arr + n);
  vector<long long> fin;
  fin.reserve(n);

  for (long long i = 0; i < n; ++i) {
    if (elems[arr[i]] > 0) {
      if (elems[arr[i] * k] > 0) {
        elems[arr[i] * k] = 0;
        fin.push_back(arr[i] * k);
      }
    }
  }
  cout << n - fin.size() << endl;
}
