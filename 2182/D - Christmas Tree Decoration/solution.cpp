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
const long long MOD = 998244353;
 
 
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
 
LL mod_inverse(LL a, LL m = MOD) {
    return power(a, m - 2);
}
 
 
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
 
void calculate(vector<ll> &fact, vector<ll> &invfact, int maxn = 52){
    ll one=1;
    ll mod=MOD;
    fact[0]=1;
    for(ll i=1;i<=maxn;i++){
        one = (one*i)%mod;
        fact[i]=one;
    }
    invfact[maxn] = mod_inverse(fact[maxn]);
    for(ll i=maxn-1;i>=0;i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }
}
 
ll nCr(int n, int r, vector<ll> &fact, vector<ll> &invfact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}
 
template <typename T>
vector<T> prefixmax(vector<T> &v){
    if(v.size()==0)return {};
    T temp = 0;
    vector<T> ans;
    for(int i=0;i<v.size();i++){
        temp = (v[i]+temp);
        ans.push_back(temp);
    }
    return ans;
}
 
template <typename T>
vector<T> suffixmax(vector<T> &v){
    if(v.size()==0)return {};
    T temp = 0;
    vector<T> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        temp = (v[i]+temp);
        ans[i]=temp;
    }
    return ans;
}
 
 
int main(){
    speed();
    vector<ll> fact(53,0), invfact(53,0);
    calculate(fact, invfact);
    TESTCASE{
        ll n;cin>>n;
        vector<ll> v;
        readvector(v,n+1);
        ll zero=v[0];
        vector<ll> v2;
        for(int i=1;i<=n;i++){
            v2.pb(v[i]);
        }
        SORT(v2);
        ll tocompare=v2[n-1];
        v2.pop_back();
        if(n==1){
            cout << "1
";
            continue;
        }
        int p1=0;
        ll count=0;
        int largestcount=1;
        while(v2.size()!=0 && v2[v2.size()-1]==tocompare){
            largestcount++;
            v2.pop_back();
        }
        if(largestcount==n){
            cout << fact[n]<<"
";
            continue;
        }
        REVERSE(v2);
        vector<ll> pref=prefixmax(v2),suff=suffixmax(v2);
 
        ll tolerate=((n-largestcount)*(tocompare-1)-suff[0]);
        if(tolerate>zero){
            cout << "0
";
            continue;
        }
        zero-=tolerate;
        count+=(fact[largestcount]*fact[n-largestcount])%MOD;
        ll n2=v2.size();
       // print(p1,n2);
    //    print("zeroleft",zero);
    //  print("largest",largestcount);
        while(p1<n2){
            tolerate=0;
            //tolerate += tocompare-v2[p1];
            if(zero>=1){
        //        print("zerook");
                zero-=1;
                count=(count+(((fact[n2]*fact[largestcount])%MOD)*nCr(p1+largestcount,largestcount-1,fact,invfact))%MOD)%MOD;
             //   print(v2[p1],"ok",count,"newcount");
                p1++;
                
            } else break;
        }
        cout << count << "
";
 
    }    
}