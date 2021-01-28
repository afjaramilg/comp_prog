

// http://codeforces.com/contest/296/problem/C
#include <bits/stdc++.h>

using namespace std;
vector<long long> vec{0};
vector<tuple<long long, long long, long long>> ops{make_tuple(0,0,0)};



void apply_op(long long l, long long r, long long d, long long fact) {
  for(long long i = l; i <= r; ++i) {
    vec[i] += d*fact; 
  }
}

int main() {
  long long n, m, k;
  cin >> n >> m >> k;

  vec.reserve(n+1);
  ops.reserve(k+1); 

  vector<long long> mult;
  mult.resize(m + 1);

  for (int i = 0; i < n; ++i) {
    long long num;
    cin >> num;
    vec.push_back(num);
  }

  int l, d, r;

  for(int i = 0; i < m; ++i) {
    cin>>l>>d>>r;
    ops.push_back(make_tuple(l,d,r));
  }

  long long x,y; 
  for(int i = 0; i < k; ++i) {
    cin>>x>>y;
    for(long long j = x; j<=y ;++j){
      mult.at(j)+=1; 
    }
    
  }

  for(int i = 1; i < mult.size(); ++i) {
    int a = get<0>(ops.at(i));
    int b = get<1>(ops.at(i));
    int c = get<2>(ops.at(i));         

    apply_op(a,b,c, mult.at(i)); 


  }

  for(int i =  1; i < vec.size(); ++i)
    cout<<vec.at(i)<<" ";
  cout<<endl; 
  
  
}








/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[100005],temp1[100005],temp2[100005],l[100005],r[100005],d[100005],a[100005],b[100005];
int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    for(int i=0;i<m;i++){
        cin>>l[i+1]>>r[i+1]>>d[i+1];
    }
    for(int i=0;i<k;i++){
        cin>>a[i+1]>>b[i+1];
    }
    for(int i=0;i<k;i++){
        temp1[a[i+1]]++;
        temp1[b[i+1]+1]--;
    }
    for(int i=1;i<=m;i++){
        temp1[i]+=temp1[i-1];
    }
    for(int i=1;i<=m;i++){
        temp2[l[i]]+=temp1[i]*d[i];
        temp2[r[i]+1]-=temp1[i]*d[i];
    }
    for(int i=1;i<=n;i++){
        temp2[i]+=temp2[i-1];
    }
    for(int i=1;i<=n;i++)
    cout<<arr[i]+temp2[i]<<" ";
    
}

 */
