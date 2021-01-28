//https://codeforces.com/contest/1420/problem/A
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

typedef long long ll;
const int INF = 1 << 30;
const int MAXN = int(1e5) + 1;
using namespace std;
// problem start----------------------


int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	    int k;
      	int mephisto=INF;
      	bool b = true;
          
	    for(int i = 0 ; i < n ; ++i){
	    	cin>>k;
          	if(k>=mephisto){
              	b = false;
            }
            mephisto=k;
        }
      	if(b) cout<<"NO\n";
      	else cout<<"YES\n";
	}
	return 0;
}
