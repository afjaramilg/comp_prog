//http://codeforces.com/contest/402/problem/C
#include <bits/stdc++.h>
using namespace std;




void print_shit() {
  int n, p;
  cin >> n>>p;  
  int vertex = 0; 
  for(int i = 1; i <= n ; ++i) {
    for(int j = i+1; j <= n; ++j) {
      if(vertex >= 2*n+p) return; 
      cout <<i << " "<<j<<endl;
      vertex++; 
    }
  }
}

int main() {
  int cases;
  cin >> cases;
  for(int i  = 0; i<cases; ++i)
    print_shit(); 
  
  
}
