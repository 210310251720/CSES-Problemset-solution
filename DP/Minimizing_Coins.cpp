#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")

using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;

const double pi = 3.1415926535;
 
//#ifndef ONLINE_JUDGE
//#define dbg(x) cerr << #x<<" "; _print(x); cerr << endl;
//#else
//#define dbg(x);
//#endif
 
template<typename T> istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #_VA_ARGS_ << "):", dbg_out(_VA_ARGS_)
#else
#define dbg(...)
#endif

#define vll vector<long long>
#define endl "\n"   // Change for interactive problems.
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define inmap(mp)       map<ll,ll> mp
#define chmap(mp)       map<char,ll> mp
#define mod            1000000007
//#define max(a)   *max_element(a.begin(), a.end());
#define sort(a)   sort(a.begin(), a.end());

// PBDS :
//order_of_key(k): returns count of elements strictly smaller than k
//find_by_order(k): returns the iterator of the k-th element in a set (0-index)
//TC: O(log(n)) for both.
// Change int -> pair<int,int> if required. Change less to less_equal for multiset; less to greater for descending.
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

/*________________________________________________*/
 
vll sieve(ll n){vector<bool> prime(n+1, true); for (ll p = 2; p * p <= n; p++) if (prime[p] == true) for (ll i = p * p; i <= n; i += p) prime[i] = false; vll v;
for (ll p = 2; p <= n; p++){if (prime[p]) v.push_back(p);} return v;}
ll gcd(ll a, ll b){ if(b == 0){ return a;} return gcd(b, a%b);}
ll nCr(int n, int r){ll p = 1, k = 1;if (n - r < r) {r = n - r;} if (r != 0) {while (r) {p *= n;k *= r; ll m = gcd(p, k);p /= m;k /= m;n--;r--;}}else {p = 1;} return p;}
void precision(int x){cout << fixed << setprecision(x);}
ll fastexpo(ll x, ll y){ll res = 1; while (y) {if (y % 2 == 1)res = (res * x);y = y >> 1ll;x = (x * x);}return res;}
ll fastexpomod(ll x, ll y, ll p) { ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0) { if (y & 1ll) res = (res*x) % p; y = y>>1ll;x = (x*x) % p; } return res; } 
// ll nfactors(ll n){for(ll i = 2; i <= n; i++){for(ll j = i; j <= n; j += i)fact[j]++;}}
ll modpar(ll a){return ((a%mod) + mod) % mod; }
ll modadd(ll a,ll b){ return modpar(modpar(a)+modpar(b)); }
ll modmul(ll a,ll b){ return modpar(modpar(a)*modpar(b)); }
ll poww(ll n, ll r){ if(r == 0) return 1; if(r == 1) return n%mod; ll ans = 1; ll know=poww(n, r/2)%mod; if(r%2) ans = (ans * n)%mod; return (ans*((know*know)%mod))%mod;}

void solve() {
    ll n, x;
    cin>>n>>x;
    vll v(n);
    cin>>v;
    vll dp(x+1, 1e9);
    dp[0] = 0;
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i-v[j] >= 0)
                dp[i] = min(dp[i], dp[i-v[j]]+1);
        }
    }
    // cout<<dp<<endl;
    if(dp[x] == 1e9)
        cout<<-1;
    else
        cout<<dp[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
precision(10);
//#ifndef ONLINE_JUDGE
//freopen("inputf.txt", "r", stdin);
//freopen("outputf.txt", "w", stdout);
//freopen("errorf.txt", "w", stderr);
//#endif

    auto start = high_resolution_clock::now();
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout<<endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    #ifndef ONLINE_JUDGE
        cout <<endl << "Time: "<< (float)duration.count()/1000000 << " s" << endl;
    #endif
}
