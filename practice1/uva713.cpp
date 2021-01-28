// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=654
#include <bits/stdc++.h>
using namespace std;

int main() {
  // string num;
  // cin>>num;
  string stra;
  string strb;
  cin>>stra;
  cin>>strb;
  string out;

  string shortest = (stra.length() < strb.length()) ? stra:strb;
  string longest = (stra.length() > strb.length()) ? stra:strb;
  int slen = shortest.length();
  int llen = longest.length();
  for(int i = 0;  i <= llen - slen; i++) {
    shortest+="0";

  }

  
  for(int i = 0; i <llen-1; ++i) {
    int sum = (int) (shortest[i]-'0') + (int) (longest[i] -'0');
    if( sum%10!= 0 && i > slen) {
      out+=to_string((sum)%10);}
    shortest[i+1]+=sum/10;
  }


  int last_r = (int) (shortest[llen-1]-'0') + (int) (longest[llen-1]-'0');
  if (last_r > 9) {
    out+=to_string((last_r%10));
    out+="1";
  }
  
  char a ='1';

  int b =  a - '0';
  
  cout<<out<<endl;


  

}
