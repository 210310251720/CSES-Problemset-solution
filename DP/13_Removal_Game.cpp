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

int main() {
    ll n;
    cin>>n;
    vll v(n);
    ll tot = 0;
    for(int i=0; i<n; i++){
        cin>>v[i]; 
        tot += v[i];
    }
    ll dp[n][n];
    for(int l=n-1; l>=0; l--) {
        for(int r=l; r<n; r++) {
            if(l == r)
                dp[l][r] = v[l];
            else 
                dp[l][r] = max(v[l] - dp[l+1][r], v[r] - dp[l][r-1]);
        }
    }
    
    cout<<(dp[0][n-1]+tot)/2;
}