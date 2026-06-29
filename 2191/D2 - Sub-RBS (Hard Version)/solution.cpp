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
        int n;cin>>n;
        ll bigmod=998244353;
        string s;cin>>s;
        map<vector<ll>,pair<ll,ll>> dp;
        // i, points, after '(' = {sequences, sum of scores}
 
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                dp[{i,1,0}]={1,1};
                for(int j=0;j<i;j++){
                    // j = index
                    for(ll points=1;points<=n;points++){
                        if(s[j]=='('){
                            pair<ll,ll> temp = dp[{j,points-1,0}];
                            dp[{i,points,0}] = {(dp[{i,points,0}].first+temp.first)%bigmod,((temp.first+temp.second)%bigmod+dp[{i,points,0}].second)%bigmod};
                            temp = dp[{j,points-1,1}];
                            dp[{i,points,2}] = {(dp[{i,points,2}].first+temp.first)%bigmod,((temp.first+temp.second)%bigmod+dp[{i,points,2}].second)%bigmod};
                            temp = dp[{j,points-1,2}];
                            dp[{i,points,2}] = {(dp[{i,points,2}].first+temp.first)%bigmod,((temp.first+temp.second)%bigmod+dp[{i,points,2}].second)%bigmod};
                        }
 
                        else {
                            for(ll after=1;after<=2;after++){
                                pair<ll,ll> temp = dp[{j,points-1,after-1}];
                                dp[{i,points,after}] = {(dp[{i,points,after}].first+temp.first)%bigmod,((temp.first+temp.second)%bigmod+dp[{i,points,after}].second)%bigmod};
                                if(after==2){
                                temp = dp[{j,points-1,2}];
                               // ll after=2;
                                dp[{i,points,after}] = {(dp[{i,points,after}].first+temp.first)%bigmod,((temp.first+temp.second)%bigmod+dp[{i,points,after}].second)%bigmod};
                                }
                            }
                        }
                    }
                } 
            } else {
                //dp[{i,-1,0}]={1,1};
                for(int j=0;j<i;j++){
                    // j = index
                    for(ll points=0;points<=n;points++){
                        for(ll after=0;after<=2;after++){
                                dp[{i,points,after}] = {(dp[{i,points,after}].first+dp[{j,points+1,after}].first)%bigmod,((dp[{j,points+1,after}].first+dp[{j,points+1,after}].second)%bigmod+dp[{i,points,after}].second)%bigmod};
                            }
                    }
                } 
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){ans = (ans+(dp[{i,0,2}].second-2*dp[{i,0,2}].first+bigmod)%bigmod+bigmod)%bigmod;}
        cout << ans<<"
";
        //print(dp[{n-1,0,2}].first,dp[{n-1,0,2}].second);
    }    
}