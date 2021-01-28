// http://codeforces.com/contest/71/problem/B
#include <bits/stdc++.h>

using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout<<endl; 
}

int main() {
  double n, k, t;
  cin >> n >> k >> t;

  double num = (t * n) / 100;
  int barritas = (int)num;
  double i = num - barritas;
  int sat_i = i * k;

  vector<int> arr;
  for (int j = 0; j < n; ++j) {
    if (j < barritas)
      arr.push_back(k);
    else if (j == barritas)
      arr.push_back(sat_i);
    else
      arr.push_back(0);
  }
  // cout<<barritas<<" "<<num<<" "<<" "<<i<<" "<<sat_i<<endl;
  print_vec(arr);
}
