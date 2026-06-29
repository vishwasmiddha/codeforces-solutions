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
 
bool check(vector<ll> &v, int ind1, int ind2){
    ll temp = v[ind1];
    v[ind1]=v[ind2];
    v[ind2]=temp;
    //printvec(v);
    // check if v cont
    map<ll,bool> blocked;
    ll prev=-1;
    for(auto c:v){
        if(c!=prev){
            prev=c;
            if(blocked[c]){
                temp = v[ind1];
                v[ind1]=v[ind2];
                v[ind2]=temp;
                return false;}
            blocked[c]=true;
        }
    }
    swap(v[ind1],v[ind2]);
    return true;
}
 
int main(){
    speed();
    TESTCASE{
        ll n;cin>>n;
        vector<ll> v;
        readvector(v,n);
        map<ll,ll> blocks;
        ll prev=-1;
        vector<ll> breaks;
        for(int i=0;i<n;i++){
            if(prev!=v[i]){
                prev=v[i];
                blocks[v[i]]++;
            }
            if(blocks[v[i]]==2){
                breaks.pb(v[i]);
                blocks[v[i]]++;
            }
        }
        //printvec(breaks);
        if(breaks.size()==0)cout << "YES
";
        else if(breaks.size()>=3)cout << "NO
";
        else if(breaks.size()==2){
            map<ll,ll> first;
            map<ll,ll> last;
            bool foundone=false;
            bool foundtwo=false;
            for(int i=0;i<n;i++){
                if(!foundone && v[i]==breaks[0]){
                    first[v[i]]=i;
                    foundone=true;
                }
                if(!foundtwo && v[i]==breaks[1]){
                    first[v[i]]=i;
                    foundtwo=true;
                }
                if(foundone && foundtwo)break;
            }
            foundone=false;
            foundtwo=false;
            for(int i=n-1;i>=0;i--){
                if(!foundone && v[i]==breaks[0]){
                    last[v[i]]=i;
                    foundone=true;
                }
                if(!foundtwo && v[i]==breaks[1]){
                    last[v[i]]=i;
                    foundtwo=true;
                }
                if(foundone && foundtwo)break;
            }
            bool poss=false;
            if(check(v,first[breaks[0]],first[breaks[1]]))poss=true;
            if(check(v,first[breaks[0]],last[breaks[1]]))poss=true;
            if(check(v,last[breaks[0]],first[breaks[1]]))poss=true;
            if(check(v,last[breaks[0]],last[breaks[1]]))poss=true;
            if(poss)cout << "YES
";
            else cout << "NO
";
        } else {
            // one nasty element
            ll first;
            ll last;
            for(int i=0;i<n;i++){
                if(v[i]==breaks[0]){
                    first=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(v[i]==breaks[0]){
                    last=i;
                    break;
                }
            }
            // try to fill gaps
            // at max 2 gaps
            bool foundbreak=false;
            vector<pair<ll,ll>> breaksizes;
            ll prev=-1;
            ll breaksize=0;
            ll breakind=-1;
            for(int i=0;i<n;i++){
                ll c=v[i];
                if(c==breaks[0]){
                    if(!foundbreak){
                        foundbreak=true;
                        prev=c;
                        continue;
                    }
                    if(c==prev)continue;
                    // else break over
                    breaksizes.pb({breakind,breaksize});
                    breaksize=0;
                    //print(i,breakind,breaksize);
                } else {
                    if(foundbreak){
                        if(breaksize==0){
                            breakind=i;
                        }
                        breaksize++;
                    }
                }
                prev=c;
            }
            //print("sizes",breaksizes.size());
            //print(breaksizes[0].first,breaksizes[0].second);
            //print(breaksizes[1].first,breaksizes[1].second);
            if(breaksizes.size()>=3){
                cout << "NO
";
                continue;
            } else if(breaksizes.size()==1){
                bool poss=false;
                if(check(v,breaksizes[0].first,first))poss=true;
                if(check(v,breaksizes[0].first,last))poss=true;
                if(check(v,breaksizes[0].first+breaksizes[0].second-1,first))poss=true;
                if(check(v,breaksizes[0].first+breaksizes[0].second-1,last))poss=true;
                if(first>=1){
                    if(check(v,first-1,last))poss=true;
                }
                if(last<n-1){
                    if(check(v,first,last+1))poss=true;
                }
                if(poss)cout << "YES
";
                else cout << "NO
";
            } else {
            // 2 breaks
            // at least one must be size of 1
                vector<ll> indices;
                for(auto c:breaksizes){
                    if(c.second==1)indices.pb(c.first);
                }
                bool poss=false;
                for(auto c:indices){
                    if(check(v,c,first))poss=true;
                    if(check(v,c,last))poss=true;
                }
                if(poss)cout << "YES
";
                else cout << "NO
";
            }
        }
    }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 