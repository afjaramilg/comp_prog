// http://codeforces.com/contest/604/problem/C
#include <bits/stdc++.h>
using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << endl;
  }
}

int main() {
  int n, res = 1;
  cin >> n;
  string num;
  cin>>num;
  char old, k;
  int  l;
  vector<int> ranges;
  bool first = true;
   old=num[0];
  for (int i = 1; i < n; ++i) {
    k=num[i];
    if (k != old && first) {
      ++res;
    } else if (first) {
      l = i - 1;
      first = false;
    } else if (k != old) {
      ranges.push_back(i - l);
      first = true;
      res++;
    }
    old = k;
  }
  
  if (ranges.size() == 0) {
    cout << res << endl;
  } else if (ranges.size() == 1) {
    if (ranges[0] == 2)
      cout << res + 1 << endl;
    else if(ranges.size() == num
    else cout<<res+2<<endl;
  } else {
    cout << res + 2 << endl;
  }
  
}
