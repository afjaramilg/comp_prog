//http://codeforces.com/contest/515/problem/C
#include <bits/stdc++.h>
using namespace std;


bool myfunction (char i,char j) {  return (i>j); }

int main(){
  int len;
  string a;
  map < char, string > dict = {
    {'1', ""},
    {'2', "2"},
    {'3', "3"},
    {'4', "322"},
    {'5', "5"},
    {'6', "53"},
    {'7', "7"},
    {'8', "7222"},
    {'9',"7332"}
  };
  cin >> len >> a;

  string x = "";
  for(int i = 0; i < len; ++i){
   x += dict[a[i]];
   
  }
  int size = x.length();

  sort(x.begin(), x.end(), myfunction);
  
  cout << x << endl;


}
