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
 
template<typename T>
pair<int,vector<T>> makevec(){
    int n;cin>>n;
    vector<T> temp(n);
    for(int i=0;i<n;i++){
        cin >> temp[i];
    }
    return {n,temp};
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
 
bool run(){
    ll n,k;cin>>n>>k;
    vector<ll> a,b;
    readvector(a,n);
    readvector(b,n);
    if(k>1){
        
        
        // for(int i=k;i<n;i++){
        //     if(a[i]==a[i-k]){
        //         //same
        //         if(b[i-k]!=-1){
        //             if(b[i]==-1)b[i]=b[i-k];
        //             else if(b[i]!=b[i-k])return false;
        //         } else {
        //             if(b[i]!=-1)b[i-k]=b[i];
        //         }
        //     } else {
        //         // find this.
        //         if(index==-1)index=i;
        //     }
        // }
        
        // for ever 0 to k-1. find the defining element if any. if none then ok always. else works front and back from there.
        for(int i=0;i<k;i++){
            vector<ll> bs;
            if(b[i]!=-1)bs.pb(b[i]);
            bool allsame=true;
            for(int temp=i+k;temp<n;temp+=k){
                if(a[temp]!=a[temp-k]){
                    allsame=false;
                    break;
                }
                if(b[temp]!=-1)bs.pb(b[temp]);
            }
            if(allsame){
                if(bs.size()>0){
                    //allsame;
                    ll all = bs[0];
                    for(int temp=i;temp<n;temp+=k){
                        if(b[temp]!=-1 && b[temp]!=all)return false;
                        if(b[temp]==-1)b[temp]=bs[0];
                    }
                } else {
                    //nothing
                }
            } else {
                for(int temp=i;temp<n;temp+=k){
                    if(b[temp]!=-1 && b[temp]!=a[temp])return false;
                    b[temp]=a[temp];
                }
            }
        }
        multiset<ll> m;
        for(int i=0;i<k;i++){
            m.insert(a[i]);
        } 
        for(int i=0;i<k;i++){
            if(b[i]!=-1){
                if(m.count(b[i])){
                    auto it = m.find(b[i]);
                    m.erase(it);
                } else {
                    return false;
                }
            }
        }
 
 
 
 
 
        return true;
    } else {
        for(int i=0;i<n;i++){
            if(b[i]!=-1 && b[i]!=a[i])return false;
        }
        return true;
    }
 
 
 
 
}
 
int main(){
    speed();
    TESTCASE{
        boolprint(run());
    }    
}