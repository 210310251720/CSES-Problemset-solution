#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo for(int i=0;i<n;++i)
#define vect(type1,name) vector<type1> name
#define pb push_back
#define full(x) x.begin(),x.end()
#define Pi 3.1415926535897932382626

void solve()
{
  ll n;
  cin>>n;
  vector<ll> v(n);
  ll ans = 0;
  fo
  {
    cin>>v[i];
  }
  for(int i=0;i<n-1;i++)
  {
    if(v[i]>v[i+1])
    {
      ans += (v[i]-v[i+1]);
      v[i+1]=v[i];
    }
  }
  cout<<ans<<"\n";

  
}
int main(){
  ll t;
  t=1;
  //cin>>t;
  while(t--)
  {
    solve();
 }

}