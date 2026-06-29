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
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> a,b,f;
        
        readvector(a,n);
        readvector(b,m);
        readvector(f,k);
        vector<ll> diff2;
        pair<ll,ll> temp2={a[0],a[1]};
        ll maxdiff=a[1]-a[0];
        int cnt=1;
        for(int i=2;i<n;i++){
            if(maxdiff<a[i]-a[i-1]){
                maxdiff=a[i]-a[i-1];
                temp2={a[i-1],a[i]};
                cnt=1;
            } else if (maxdiff==a[i]-a[i-1]){
                cnt++;
            }
        }
        for(int i=1;i<n;i++)diff2.pb(a[i]-a[i-1]);
        SORT(diff2);
        if(cnt>1){
            cout << maxdiff << "
";
            continue;
        }
        SORT(b);
        SORT(f);
        // vector<ll> prefixf;
        // ll temp=f[0];
        // for(int i=0;i<n;i++){
        //     temp=max(temp,f[i]);
        //     prefixf.pb(temp);
        // }
        //int left=0,right=k-1;
        int point=0;
        ll best = -1;
        vector<ll> candidates;
        //printvec(diff2);
        while(point<m){
            //print("start",point,b[point]);
            if(maxdiff%2==0){
                ll target=temp2.first+maxdiff/2;
                auto it = std::upper_bound(f.begin(), f.end(), target-b[point]);
                if(it!=f.end())candidates.pb(*it+b[point]);
                if(it!=f.begin()){
                    candidates.pb(*(--it)+b[point]);
                }
            } else {
                ll target=temp2.first+maxdiff/2;
                auto it = std::upper_bound(f.begin(), f.end(), target-b[point]);
                if(it!=f.end())candidates.pb(*it+b[point]);
                if(it!=f.begin()){
                    candidates.pb(*(--it)+b[point]);
                }
                target++;
                it = std::upper_bound(f.begin(), f.end(), target-b[point]);
                if(it!=f.end())candidates.pb(*it+b[point]);
                if(it!=f.begin()){
                    candidates.pb(*(--it)+b[point]);
                }
            }
            point++;
            //printvec(candidates);
            
        }
        
        vector<ll> ans;
        for(auto c:candidates){
            ans.pb(max(c-temp2.first,temp2.second-c));
        }
        if(n>2)cout << min(diff2[n-2],max(diff2[n-3],MIN_IN(ans)))<<"
";
        else cout << min(diff2[n-2],MIN_IN(ans))<<"
";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 