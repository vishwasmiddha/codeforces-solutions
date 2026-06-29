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
 
void callcases(vector<ll> &distancesum, vector<ll> &odds, int numodds,vector<vector<ll>> &distances, int matched,int state){
    if(matched==numodds)return;
 
    vector<int> unmatchedindices;
    for(int i=0;i<numodds;i++){
        if((1<<i)&state)continue;
        unmatchedindices.pb(i);
    }
    // print("unmatched:");
    // printvec(unmatchedindices);
    int newstate;
    for(int i=1;i<unmatchedindices.size();i++){
      //  print(unmatchedindices[0],unmatchedindices[i]);
        newstate = state|(1<<unmatchedindices[0]);
        newstate = newstate|(1<<unmatchedindices[i]);
        distancesum[newstate]=min(distancesum[newstate],distancesum[state]+distances[odds[unmatchedindices[0]]][odds[unmatchedindices[i]]]);
        callcases(distancesum,odds,numodds,distances,matched+2,newstate);
    }
}
 
int main(){
    speed();
    int n,m;cin>>n>>m;
    vector<vector<ll>> adj(n+1,vector<ll>(n+1,1000000000000LL))    ;
    for(int i=1;i<=n;i++)adj[i][i]=0;
    ll a,b,c;
    vector<int> degrees(n+1,0);
    ll weightsum=0;
    vector<bool> looped(n+1,false);
    REP(m){
 
        cin >> a>> b >> c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=adj[a][b];
        degrees[a]++;
        degrees[b]++;
        weightsum+=c;
        if(a==b)looped[a]=true;
        //print(weightsum);
    }
    vector<ll>odds;
    for(ll i=1;i<=n;i++)if(degrees[i]%2)odds.pb(i);
    vector<vector<ll>> distances(n+1,vector<ll>(n+1,1000000000000LL));
    distances = adj;
    
 
    
 
 
 
 
 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);
            }
        }
    }
 
    bool alledgesreachable = true;
    for(int i=2;i<=n;i++){
        if(distances[i][1]==1000000000000LL){
            if(looped[i]){
                alledgesreachable=false;
                break;
            }
            for(int j=2;j<=n;j++){
                if(j==i)continue;
                if(distances[i][j]<1000000000000LL){
                    alledgesreachable=false;
                    break;
                }
            }
 
 
        }
        if(!alledgesreachable)break;
    }
    if(!alledgesreachable){
        cout << "-1";
    }
    else{
 
    int numodds = odds.size();
    vector<ll> distancesum((1<<(numodds)),100000000000000LL);
    distancesum[0]=0LL;
    if(numodds==0){
        cout << weightsum;
    }
    else{callcases(distancesum,odds,numodds,distances,0,0);
    print(weightsum+distancesum[(1<<numodds)-1]);}
 
    }
 
}