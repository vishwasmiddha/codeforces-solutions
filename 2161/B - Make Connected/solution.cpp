// Problem: B. Make Connected
// Contest: Codeforces - Pinely Round 5 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2161/problem/B
// Memory Limit: 512 MB
// Time Limit: 1500 ms
 
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
 
bool dfs(vector<string> &v, vector<vector<bool>> &visited, int i, int j){
    visited[i][j]=true;
    int n=v.size();
    if(v[i][j]=='#'){
        //print("hash caught",i,j);
        // true
        if(i+1<n){
            if(!visited[i+1][j]){
                //print("Case1",i,j);
                dfs(v,visited,i+1,j);
            }
        }
        if(i-1>=0){
            if(!visited[i-1][j]){
                //print("case2",i,j);
                dfs(v,visited,i-1,j);
            }
        }
        if(j+1<n){
            if(!visited[i][j+1]){
                //print("case3",i,j);
                dfs(v,visited,i,j+1);
            }
        }
        if(j-1>=0){
            if(!visited[i][j-1]){
                //print("case4",i,j);
                dfs(v,visited,i,j-1);
            }
        }
        return true;
    } else {
        //print("hashfail",i,j);
        return false;}
}
 
bool allconnected(vector<string> &v){
    int cnt=0;
    int n=v.size();
    for(auto c:v){
        for(auto d:c){
            if(d=='#')cnt++;
        }
    }
    if(cnt==0)return true;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int i=0;
    int j=0;
    while(!dfs(v,visited,i,j)){
        //print("start dfs",i,j);
        if(j==n-1){
            j=0;
            i++;
        } else j++;
    }
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<n;j1++){
            if(v[i1][j1]=='#' && !visited[i1][j1])return false;
        }
    }
    return true;
}
 
bool nothree(vector<string> &v){
    int cnt=0;
    int n=v.size();
    for(auto c:v){
        cnt=0;
        for(auto d:c){
            if(d=='#'){
                cnt++;
                if(cnt==3)return false;
                
            } else cnt=0;
        }
    }
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<n;j++){
            if(v[j][i]=='#'){
                cnt++;
                if(cnt==3)return false;
            } else cnt=0;
        }
    }
    return true;
}
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void printstring(vector<string> &v, string s){
    print(s);
    for(auto c:v){
        print(c);
    }
}
 
bool four(vector<string> &v){
    int i=-1;
    int j=-1;
    int n=v.size();
    int cnt = 0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(v[x][y]=='#'){
                cnt ++;
                if(i!=-1)continue;
                i=x;
                j=y;
            }
        }
    }
    if(cnt<=1)return true;
    if(cnt==4){
        if(i+1<n && j+1<n){
            if(v[i][j+1]=='#' && v[i+1][j]=='#' && v[i+1][j+1]=='#')return true;
        }
    }
    return false;
}
 
int main(){
    speed();
    TESTCASE{
        int n;cin>>n;
        vector<string> v;
        string s;
        
        REP(n){
            cin >> s;
            v.pb(s);
        }
        if(four(v)){
            cout << "YES
";
            continue;
        }
        set<int> sum;
        set<int> diff;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='#'){
                    sum.insert(i+j);
                    diff.insert(i-j);
                }
            }
        }
        bool possible = false;
        if(sum.size()<2 || diff.size()<2)possible=true;
        if (sum.size()==2){
            int first = *sum.begin();
            int second = *(next(sum.begin()));
            if(abs(first-second)==1)possible = true;
        }
        if (diff.size()==2){
            int first = *diff.begin();
            int second = *(next(diff.begin()));
            if(abs(first-second)==1)possible = true;
        }
        if(possible)cout << "YES
";
        else cout << "NO
";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 