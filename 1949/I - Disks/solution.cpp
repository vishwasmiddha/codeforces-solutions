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
 
void dfs(int node, vector<vector<ll>> &adj, vector<int> &visited, int colorindex, int &cnt1, int &cnt2, int color, bool &bp ){
    visited[node]=2*colorindex+color;
    if(color==1)cnt1++;
    else cnt2++;
    for(auto c:adj[node]){
        if(visited[c]==0){
            dfs(c,adj,visited,colorindex,cnt1,cnt2,3-color,bp);
        } else if(visited[c]==visited[node]){
            bp=false;
        }
    }
}
 
int main(){
    speed();
    ll n;cin>>n;
    vector<vector<ll>> v;
    REP(n){
        ll a,b,c;cin>>a>>b>>c;
        v.pb({a,b,c});
    }
    vector<vector<ll>> adj(n,vector<ll>());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pow(v[i][0]-v[j][0],2LL)+pow(v[i][1]-v[j][1],2LL)==pow(v[i][2]+v[j][2],2LL)){
                //tangent
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    //bool nocyclefound=false;
    bool componentfound=false;
    vector<int> color(n,0);
    int clr=1;
    for(int i=0;i<n;i++){
        if(color[i])continue;
        //bool cyclic=false;
        // for(auto c:adj[i]){
        //     visited[i]=1;
        //     if(cyclic)break;
        //     dfs(c,cyclic,adj,visited,c+1);
        // }
        // if(!cyclic)nocyclefound=true;
        int cnt1=0,cnt2=0;
        bool bp=true;
        dfs(i,adj,color,clr,cnt1,cnt2,1,bp);
        clr++;
        if(bp){
            if(cnt1!=cnt2){
                componentfound=true;break;
            }
        }
    }
    boolprint(componentfound);
}