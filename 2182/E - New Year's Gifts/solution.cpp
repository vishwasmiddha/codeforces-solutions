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
 
class SegmentTree {
public:
    vector<ll> tree;
    vector<int> indices;
    int n;
    
    SegmentTree(vector<ll>& boxes) {
        n = boxes.size();
        tree.assign(4 * n, LLONG_MIN / 2);
        indices.assign(4 * n, -1);
        build(1, 0, n - 1, boxes);
    }
    
    void build(int node, int start, int end, vector<ll>& boxes) {
        if (start == end) {
            tree[node] = boxes[start];
            indices[node] = start;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, boxes);
        build(2 * node + 1, mid + 1, end, boxes);
        if (tree[2 * node] >= tree[2 * node + 1]) {
            tree[node] = tree[2 * node];
            indices[node] = indices[2 * node];
        } else {
            tree[node] = tree[2 * node + 1];
            indices[node] = indices[2 * node + 1];
        }
    }
    
    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        if (tree[2 * node] >= tree[2 * node + 1]) {
            tree[node] = tree[2 * node];
            indices[node] = indices[2 * node];
        } else {
            tree[node] = tree[2 * node + 1];
            indices[node] = indices[2 * node + 1];
        }
    }
    
    int query(int node, int start, int end, ll val) {
        if (tree[node] < val) return -1;
        if (start == end) return indices[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, val);
        if (left != -1) return left;
        return query(2 * node + 1, mid + 1, end, val);
    }
    
    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int query(ll val) {
        return query(1, 0, n - 1, val);
    }
};
 
int main(){
    speed();
    TESTCASE{
        ll n,m,k;cin>>n>>m>>k;
        vector<pair<ll,ll>> friends;
        vector<ll> boxes;
        readvector(boxes,m);
        SORT(boxes);
        SegmentTree st(boxes);
        ll temp1,temp2,temp3;
        REP(n){
            cin >> temp1 >> temp2 >> temp3;
            friends.pb({temp3-temp2,-temp1});
            k-=temp2;
 
        }
 
        RSORT(friends);
        int cnt=0;
 
        
 
        vector<bool> friendhappy(n,false);
        for(int i=0;i<n;i++){
            int index = st.query(-friends[i].second);
            if(index == -1) continue;
            st.update(index, LLONG_MIN / 2);
            friendhappy[i]=true;
            cnt++;
        }
        for(int i=n-1;i>=0;i--){
           // print(k,"coins left",friends[i].first,"coins need");
            if(friends[i].first<=k){
                if(friendhappy[i])continue;
                k-=friends[i].first;
                cnt++;
                continue;
                
            }
            else break;
        }
        cout << cnt << "
";
 
        // pair is {last unused box, satisfied count, coinsleft}
        // vector<vector<ll>> boxsat(n);
        // vector<pair<ll,ll>> coinsat(n);
        // vector<pair<ll,ll>> unsat(n);
        // auto last = boxes.end();
        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         auto first = boxes.begin();
        //         auto find = lower_bound(first,last,friends[i].first);
        //         if(find==last){
        //             boxsat.pb({0,0,k});
        //         } else {
        //             boxsat.pb({1,boxsat})
        //         }
        //     }
        // }
 
    }
}