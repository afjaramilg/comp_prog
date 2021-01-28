// http://codeforces.com/contest/462/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  long long suma = 0;
  if (n == 1) {
    cout << arr[0] << endl;
    return 0;
  }
  if (n == 2) {
    cout << (arr[0] + arr[1]) * 2 << endl;
    return 0;
  }
  for (long long i = 0; i < n; ++i) {
    suma += arr[i] * (i + 2);
  }
  suma -= arr[n - 1];

  cout << suma << endl;
}
