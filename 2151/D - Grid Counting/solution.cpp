// Problem: D. Grid Counting
// Contest: Codeforces - Codeforces Round 1053 (Div. 2)
// URL: https://codeforces.com/contest/2151/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
// Problem: B. Pashmak and Flowers
// Contest: Codeforces - Codeforces Round 261 (Div. 2)
// URL: https://codeforces.com/problemset/problem/459/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <iostream>    // cin, cout, cerr
#include <vector>      // vector
#include <array>       // array
#include <deque>       // deque
#include <list>        // list
#include <forward_list>// forward_list
#include <stack>       // stack
#include <queue>       // queue, priority_queue
#include <set>         // set, multiset
#include <map>         // map, multimap
#include <unordered_set> // unordered_set, unordered_multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <string>      // string, stoi, to_string
#include <cstring>     // memset, strcpy (C-style strings)
#include <sstream>     // stringstream
#include <algorithm>   // sort, min, max, reverse, lower_bound, upper_bound
#include <numeric>     // accumulate, gcd, lcm
#include <functional>  // greater, less, function
#include <utility>     // pair, swap, move
#include <tuple>       // tuple, tie
#include <cmath>       // sqrt, pow, abs, sin, cos, etc.
#include <bitset>      // bitset
 
 
using namespace std;
const long long INF = 9223372036854775807;
const long long MOD = 1e9 + 7;
 
 
template<typename T>
void readvector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}
 
 
 
template <typename T>
auto SUM(const T& A) {
    using Elem = typename T::value_type;
    return std::accumulate(A.begin(), A.end(), Elem(0));
}
 
void boolprint(bool a){
    cout << (a?"YES
":"NO
");
}
 
template <typename T>
void printvec(vector<T> &v){
    cout << "Vector: {";
    for(auto c:v)cout << c << ", ";
    cout << "}
";
}
#define REP(n) for(int t=0; t<n; t++)
#define FOR(i, n) for (i = 0; i < n; i++)
#define FFOR(i, j, n) for(i = j; j < n; j++)
#define FOR_S(i, n, k) for (i = 0; i < n; i += k)
#define RFOR(i, n) for (i = n - 1; i >= 0; i--)
#define RFOR_S(i, n, k) for (i = n - 1; i >= 0; i -= k)
#define MAX_OF(x, y) ((x > y) ? x : y)
#define MIN_OF(x, y) ((x > y) ? y : x)
#define MIN_IN(A) *(std::min_element(A.begin(), A.end()))
#define MAX_IN(A) *(std::max_element(A.begin(), A.end()))
#define MAX_AT(A) (std::max_element(A.begin(), A.end()) - A.begin())
#define MIN_AT(A) (std::min_element(A.begin(), A.end()) - A.begin())
#define COUNT(V,A) count(V.begin(), V.end(), A);
#define makevec(v,n) \
vector<int> v;               \
readvector(v,n);  
#define TESTCASE                                                              \
int testcase;                                                               \
std::cin>>testcase;                                                         \
while(testcase--)
#define GCD(a,b) std::__gcd(a,b);
#define LCM(a, b) ((a) / std::__gcd((a), (b)) * (b))
#define SORT(A) std::sort(A.begin(), A.end());
#define RSORT(A) std::sort(A.rbegin(), A.rend());
#define REVERSE(A) std::reverse(A.begin(), A.end());
#define ANY(container, result, condition)                                      \
result = false;                                                              \
for (const auto &e : container)                                              \
    if (condition(e)) {                                                        \
    result = true;                                                           \
    break;                                                                   \
    }
#define ALL(container, result, condition)                                      \
result = true;                                                               \
for (const auto &e : container)                                              \
    if (!condition(e)) {                                                       \
    result = false;                                                          \
    break;                                                                   \
    }
template<typename... Args>
void print(Args... args) {
    ((cout << args << " "), ...);
    cout << "
";
}
 
#define ll long long
#define LL long long
#define vec vector
#define pb push_back
#define popb pop_back
 
LL power(LL x, unsigned long long y) {
    // returns  x^y % p
    LL res = 1;
    x = x % MOD; 
    while (y > 0) {  
        if (y & 1) 
            res = (res*x) % MOD;  
        y = y>>1;
        x = (x*x) % MOD;   
    } 
    return res; 
 }
 
 
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
//include tuple
ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
 
 
 
ll modinv(ll a, ll m){
    ll x, y;
    ll g = gcd(a, m, x, y);
    if(g != 1) {
        return -1; // no solution
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}
 
 
 
ll ncr(ll n, ll r,vector<ll> &ft){
	ll i=1;
	if(n==r)return 1;
	if(r>n)return 0;
	i=(i*ft[n])%998244353;
	i=(i*modinv(ft[n-r],998244353))%998244353;
	i=(i*modinv(ft[r],998244353))%998244353;
	return i;
}
 
int main(){
    speed();
    ll mod=998244353;
    vector<ll> ft(2000002,0);
    ft[0]=1;
    ll x=1;
    for(ll i=1;i<2000002;i++){
    	x=(x*i)%mod;
    	ft[i]=x;
    }
	TESTCASE{
		ll n;
		cin >> n;
		vector<ll> a;
		readvector(a,n);
		if(SUM(a)!=n){
			cout << "0
";
			continue;
		}
		ll available=0;
		ll emptyspaces=0;
		ll ways=1;
		ll ncrboy=1;
		// if(n%2==1){
			// emptyspaces+=2;
			// if(available+a[(n+1)/2-1]<emptyspaces){ways=0;}
			// else {for(ll i=available+1;i<available+1+a[(n+1)/2-1];i++){
				// ncrboy = (ncrboy*i)%mod;
				// ncrboy = (ncrboy*modinv(i-emptyspaces-2,mod))%mod;
			// }
			// available+=a[(n+1)/2-1];
// 			
// 			
			// if(available>emptyspaces)break;
			// ways=(ways*ncrboy)%mod;
			// emptyspaces-=available;}
		// }
		for(ll i=(n+1)/2-1;i>-1;i--){
			
			
			if(i!=(n+1)/2-1 || n%2==0)emptyspaces+=2;
			else emptyspaces+=1;
			// if(available+a[i]<emptyspaces){ways=0;print("bad");break;}
			// for(ll j=available+1;j<available+1+a[i];j++){
				// ncrboy = (ncrboy*j)%mod;
				// ncrboy = (ncrboy*modinv(j-emptyspaces+2,mod))%mod;
			// }
			// ncrboy=(ncrboy*modinv(emptyspaces,mod))%mod;
			// ncrboy=(ncrboy*modinv(emptyspaces-1,mod))%mod;
			// ncrboy=(ncrboy*modinv(available+a[i]-emptyspaces,mod))%mod;
			// ncrboy=(ncrboy*modinv(available+a[i]+1-emptyspaces,mod))%mod;
			available=a[i];
			if(available>emptyspaces){ways=0;break;}
			
			ncrboy=ncr(emptyspaces,available,ft);
			ways=(ways*ncrboy)%mod;
			//print("good",available,emptyspaces,i,ncrboy);
			//available-=2;
			if(ways==0)break;
			emptyspaces-=available;
		}
		if(emptyspaces!=0)ways=0;
		cout << ways << "
";
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 