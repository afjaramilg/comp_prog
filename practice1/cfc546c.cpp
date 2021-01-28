// http://codeforces.com/contest/546/problem/C
#include <bits/stdc++.h>
using namespace std;




int main() {
  int n, n1, n2,temp;
  queue<int> p1,p2;
  cin>>n>>n1;
  for (int i=0; i<n1; i++){
    cin>>temp;
    p1.push(temp);
  }
  cin>>n2;
    for (int i=0; i<n2; i++){
    cin>>temp;
    p2.push(temp);
  }
    long long it=0;
    while(!p1.empty()||!p2.empty()){
      it++;
      if(p1.front()>p2.front()){
	p1.push(p2.pop());
	p1.push(p1.pop());
      } else {
	p2.push(p1.pop());
	p2.push(p2.pop());
      }
      if(it>){

      }
    }
    if(p1.empty()) cout<<it<<" "<<"1";
    if(p2.empty()) cout<<it<<" "<<"2";
    
}
 
