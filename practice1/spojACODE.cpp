// https://www.spoj.com/problems/ACODE/
// typedefs and such/-----------------
#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define vec vector
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------


string a;
ll dp[5001];

ll go(int in) {
  if(in == a.size()-1){
    if(a[a.size()-1]=='0') return 0;
    else return 1;
  }
  
  if(in == a.size())
    return 1;
  
  if(a[in]=='0')
    return 0;

  ll &r = dp[in];
  int sub = stoi(a.substr(in, 2));
  if(r!=-1)
    return r;
  
  if(sub>26)
    return r = go(in+1);
  
  return r = go(in+1) + go(in+2);
  
}



int main() {
  
  while(cin >> a && a!="0") {
    memset(dp, -1, sizeof dp);

    cout << go(0) << el;

  }

}


