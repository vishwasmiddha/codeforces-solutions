// Problem: D. Catshock
// Contest: Codeforces - Codeforces Round 1060 (Div. 2)
// URL: https://codeforces.com/contest/2154/problem/D
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
 
void dfs(int node, int pathlength, vector<pair<int,int>>&blacks, vector<bool>&visited,vector<vector<int>> &edges,const int n, vector<bool>&onway){
    visited[node]=true;
    for(auto c:edges[node]){
        if(!visited[c]){
            dfs(c,pathlength+1,blacks,visited,edges,n,onway);
        }
    }
    if(node==n)return;
    if(onway[node])return;
    if(pathlength%2==1){
        blacks.pb({node,1});
    } else {
        blacks.pb({node,2});
    }
}
 
void dfs2(int node, vector<int> &path, bool &reached,int n, vector<vector<int>> &edges, vector<bool> &visited){
    path.pb(node);
    visited[node]=true;
    if(node==n){
        reached = true;
        return;
    }
    for(auto c:edges[node]){
        if(visited[c])continue;
        dfs2(c,path,reached,n,edges,visited);
        if(reached)break;
    }
    if(!reached)path.pop_back();
 
}
 
int main(){
    speed();
    TESTCASE{
        int n;cin>>n;
        vector<vector<int>> edges(n+1,vector<int>());
        int a,b;
        REP(n-1){
            cin >> a >> b;
            edges[a].pb(b);
            edges[b].pb(a);
        }
        vector<int> path;
        vector<bool> visited2(n+1,false);
        bool reached=false;
        dfs2(1,path,reached,n,edges,visited2);
        vector<bool> onway(n+1,false);
        for(auto c:path)onway[c]=true;
        vector<bool> visited(n+1,false);
        vector<pair<int,int>> blacks;
        dfs(1,0,blacks,visited,edges,n,onway);
        int blacknow = 1;
        vector<string> inst;
        for(auto c:blacks){
            if(c.second==blacknow){
                blacknow = 3-blacknow;
                inst.pb("2 "+to_string(c.first)+"
");
                inst.pb("1
");
            } else {
                inst.pb("1
");
                inst.pb("2 "+to_string(c.first)+"
");
                inst.pb("1
");
            }
        }
        int pathlength = 0;
        if(blacknow==1){
            inst.pb("1
");
        }
        for(auto c:path){
            if(c==n)break;
            inst.pb("2 "+to_string(c)+"
");
            inst.pb("1
");
            pathlength++;
        }
        //inst.pop_back();
        cout << inst.size()<<"
";
        for(auto c:inst)cout << c;
        cout<<"
";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 