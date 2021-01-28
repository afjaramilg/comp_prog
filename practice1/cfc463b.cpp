//http://codeforces.com/contest/463/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector < int > list;
  list.push_back(0);
  int val1;
  while(cin>>val1){
    list.push_back( val1);
  }
  int energy = 0;
  int munny = 0;
  int hip = 0;
  for( int i = 0; i < list.size()-1; i++){
    hip = energy + (list[i]-list[i+1]);
    // cout << list[i]-list[i+1] << endl;
    if(hip < 0){
      munny+=-(hip);

      energy = 0;
    }else{
      energy = energy + (list[i]-list[i+1]);
    }

  }
  cout<<munny<<endl;

}
