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
 
vector<int> dfs(int r, int c,int i,int j,pair<int,int> dir,vector<int> &temp,vector<vector<bool>> &visited,int cnt,vector<string> &v){
    //print(i,j,dir.first,dir.second,cnt);
    if(i==-1 || i==r || j==-1 || j==c){ return {temp[0],temp[1],dir.first,dir.second,cnt};}
    temp = {i,j,dir.first,dir.second,cnt};
    
 
    if(v[i][j]=='.'){
        vector<int> ans =  dfs(r,c,i+dir.first,j+dir.second,dir,temp,visited,cnt,v);
        visited[i][j]=false;
        return ans;
    }
    if(v[i][j]!='.'){
        if(!visited[i][j]){
            visited[i][j]=true;
            cnt++;
        }
        if(v[i][j]!='/'){
            vector<int> ans =  dfs(r,c,i+dir.second,j+dir.first,{dir.second,dir.first},temp,visited,cnt,v);
            visited[i][j]=false;
            return ans;
        }
        else {
            vector<int> ans =  dfs(r,c,i-dir.second,j-dir.first,{-dir.second,-dir.first},temp,visited,cnt,v);
            visited[i][j]=false;
            return ans;
        }
    }
    return {};
    
}
 
string direction(int i,int j){
    if(j==1)return "W";
    if(j==-1)return "E";
    if(i==1)return "N";
    if(i==-1)return "S";
}
 
int main(){
    speed();
    int r,c;cin>>r>>c;
    vector<string> v;
    readvector(v,r);
    int mirrorcnt = 0;
    for(auto c:v)for(auto d:c)if(d!='.')mirrorcnt++;
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    map<vector<int>,bool> started;
    vector<string> ans;
    vector<int> temp;
    for(int i=0;i<r;i++){
        if(!started[{i,0,0,1}]){
        temp = {i,0,0,1};
        temp = dfs(r,c,i,0,{0,1},temp,visited,0,v);
        started[{i,0,0,1}]=true;
        started[{temp[0],temp[1],-temp[2],-temp[3]}]=true;
        if(temp[4]==mirrorcnt){
            ans.pb("W"+to_string(i+1));
            if(temp[2]==0)ans.pb(direction(-temp[2],-temp[3])+to_string(temp[0]+1));
            else ans.pb(direction(-temp[2],-temp[3])+to_string(temp[1]+1));
        }
        }
        if(started[{i,c-1,0,-1}])continue;
        temp = {i,c-1,0,-1};
        temp = dfs(r,c,i,c-1,{0,-1},temp,visited,0,v);
        started[{i,c-1,0,-1}]=true;
        started[{temp[0],temp[1],-temp[2],-temp[3]}]=true;
        if(temp[4]==mirrorcnt){
            ans.pb("E"+to_string(i+1));
            if(temp[2]==0)ans.pb(direction(-temp[2],-temp[3])+to_string(temp[0]+1));
            else ans.pb(direction(-temp[2],-temp[3])+to_string(temp[1]+1));
        }
    }
    for(int i=0;i<c;i++){
        if(!started[{0,i,1,0}]){
        temp = {0,i,1,0};
        temp = dfs(r,c,0,i,{1,0},temp,visited,0,v);
        started[{0,i,1,0}]=true;
        started[{temp[0],temp[1],-temp[2],-temp[3]}]=true;
        if(temp[4]==mirrorcnt){
            ans.pb("N"+to_string(i+1));
            if(temp[2]==0)ans.pb(direction(-temp[2],-temp[3])+to_string(temp[0]+1));
            else ans.pb(direction(-temp[2],-temp[3])+to_string(temp[1]+1));
        }
        }
        if(started[{r-1,i,-1,0}])continue;
        temp = {r-1,i,-1,0};
        temp = dfs(r,c,r-1,i,{-1,0},temp,visited,0,v);
        started[{r-1,i,-1,0}]=true;
        started[{temp[0],temp[1],-temp[2],-temp[3]}]=true;
        if(temp[4]==mirrorcnt){
            ans.pb("S"+to_string(i+1));
            if(temp[2]==0)ans.pb(direction(-temp[2],-temp[3])+to_string(temp[0]+1));
            else ans.pb(direction(-temp[2],-temp[3])+to_string(temp[1]+1));
        }
    }    
    cout << ans.size() << "
";
    for(auto c:ans)cout << c << " ";
}