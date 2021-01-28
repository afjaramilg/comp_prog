// https://codeforces.com/contest/353/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a;
  a.resize(n);

  long ans = 0, sum = 0; // sum is gonna become my m, ans is my answer
  for (int i = 0; i < n; i++) {
    cin >> a[i]; // put all nums in the vector
    sum += a[i]; // sum them all up, its like if the binary was
    // entirely made up of 1's. this implicit binary will be called
    // sum binary
  }

  string x;
  cin >> x; // read the binary

  for (int i = n - 1; i >= 0; i--) {
    // if ypu find a 1 in the binary and
    // then check if removing said 1 from the sum binary
    // would increase the value of ans and if so, do it
    // more on why it goes backwrds later
    if (x[i] == '1' && ans < sum - a[i])
      ans = sum - a[i];
    else
      sum -= a[i]; // this turns sum into m eventually
  }

  //if you try going forward

  if (ans < sum)
    ans = sum;

  cout << ans;
}
