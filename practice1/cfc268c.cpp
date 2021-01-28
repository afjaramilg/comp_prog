// http://codeforces.com/contest/268/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int min = (n < m) ? n : m;
  cout<<min+1<<endl; 
  for (int i = 0; i <= min; ++i) {
    cout << i << " " << min-i<<endl;
  }
}
