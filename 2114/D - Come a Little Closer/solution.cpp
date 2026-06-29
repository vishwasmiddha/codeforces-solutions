// Problem: E. Bus Routes
// Contest: Codeforces - Codeforces Round 873 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1827/E
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
 
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
 
ll coinscost(vector<pair<ll,ll>> &v,ll x, ll y){
    if(v.size()==1)return 1;
    ll minx = pow(10LL,9LL)+1;
    ll miny = pow(10LL,9LL)+1;
    ll maxx = -1;
    ll maxy = -1;
    for(auto c:v){
        if(c.first==x && c.second==y)continue;
        else {
            minx=min(minx,c.first);
            miny = min(miny,c.second);
            maxx = max(maxx,c.first);
            maxy = max(maxy,c.second);
        }
    }
    ll temp = (maxx-minx+1)*(maxy-miny+1);
    if(temp == v.size()-1){
        return min((maxx-minx+2)*(maxy-miny+1),(maxx-minx+1)*(maxy-miny+2));
    } else return temp;
}
 
int main(){
    speed();
    TESTCASE{
        int n;cin>>n;
        vector<pair<ll,ll>> v;
        vector<pair<ll,ll>> v2;
        map<ll,vector<ll>> mx;
        map<ll,vector<ll>> my;
        ll x,y;
        REP(n){
            cin >> x>> y;
            v.pb({x,y});
            v2.pb({y,x});
            mx[x].pb(y);
            my[y].pb(x);
        }   
        vector<pair<ll,ll>> points;
        SORT(v);
        SORT(v2);
        points.pb({v[0].first,MIN_IN(mx[v[0].first])});
        points.pb({v[0].first,MAX_IN(mx[v[0].first])});
        points.pb({v[n-1].first,MIN_IN(mx[v[n-1].first])});
        points.pb({v[n-1].first,MAX_IN(mx[v[n-1].first])});
        points.pb({MIN_IN(my[v2[0].first]),v2[0].first});
        points.pb({MAX_IN(my[v2[0].first]),v2[0].first});
        points.pb({MIN_IN(my[v2[n-1].first]),v2[n-1].first});
        points.pb({MAX_IN(my[v2[n-1].first]),v2[n-1].first});
        vector<ll> values;
        for(auto c:points)values.pb(coinscost(v,c.first,c.second));
        //cout << 1;
        cout << MIN_IN(values) << "
";
    }    
}