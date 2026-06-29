// Problem: Ultimate Value
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2140/problem/C
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
 
int main(){
    speed();
	TESTCASE{
		int n;
		vector<ll> a;
		cin >> n;
		readvector(a,n);
		if(n==1){
			cout << a[0] << "
";
			continue;
		} else if (n==2){
			cout << max(a[0]-a[1],a[1]-a[0]+1)<<"
";
			continue;
		}
		vector<ll> premin(n,100000000000000);
		vector<ll> postmin(n,100000000000000);
		ll least = 100000000000000;
		for(int i=0;i<n;i+=2){
			least = min(least, i + 2*a[i]);
			premin[i]=least;
			if(i+1<n)premin[i+1]=least;
		}
		least = 100000000000000;
		for(int i=n-1;i>=0;i-=2){
			if(i%2==1)i--;
			if(i==-1)break;
			least=min(least,2*a[i]-i);
			postmin[i]=least;
			if(i-1>=0)postmin[i-1]=least;
		}
		// print("vecbegin");
		// for(auto c:premin)cout <<c << " ";
		// cout << endl;
		// for(auto c:postmin)cout << c<< " ";
		// cout << endl;
		// print("vecend");
		ll big = -1;
		for(int i=1;i<n;i+=2){
			big=max(big,2*a[i]+i-premin[i]);
			big=max(big,2*a[i]-i-postmin[i]);
		}
		ll cost=0;
		for(int i=0;i<n;i++){
			if(i%2==0){
				cost+=a[i];
			} else cost -= a[i];
		}
		ll anyway = ((n%2==1)?n-1:n-2);
		// print("anyway",big,anyway);
		cout << max(anyway,big)+cost<<"
";
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 