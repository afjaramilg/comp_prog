// https://codeforces.com/contest/1327/problem/A
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
#define tiii(a,b,c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------


int odds[int(1e7)+1], tree[5*int(1e7)];



int build(int v, int lt, int rt) {
  if(lt == rt)
    tree[v] =  odds[lt];
  else {
    int lm = (lt+rt)/2;
    int lc = build(2*v, lt, lm);
    int rc =  build(2*v+1, lm+1, rt);
    tree[v] =  lc + rt;
  }
}

int query(int v, int lt, int rt, int l, int r) {
  if(


}


int main() {
  odds[0] = 1;
  for1(i, n) {
    

  }
  
  
  cout << "hello" << el;

}




