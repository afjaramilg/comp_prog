// http://codeforces.com/contest/304/problem/C
#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &vec) {
  for(int i: vec)
    cout<<i<<" ";
  cout<<endl; 
}


int main() {
  int n;
  cin >> n;
  vector<int> init;
  vector<int> res;
  vector<int> sum;

  if (n % 2 != 0) {
    for (int i = 0; i < n; ++i) {
      init.push_back(i);
      res.push_back((i + 2) % n);
      sum.push_back((i + ((i + 2) % n)) % n);
    }
    print_vec(init);
    print_vec(res);
    print_vec(sum);     
  } else {

    cout<<"-1"<<endl; 
  }

  
}


/*
  i have to have 3 different numbers in n positions
  if i take a set of them for n = 5 for example

  4 0 1 2 3  so if i add 2 to every one of them

  1 2 3 4 0 (when it hits 5 it starts over from 0)
            
  3 4 0 1 2 (and then again)

  0 1 2 3 4

  2 3 4 0 1 (and so on)
  




 */
