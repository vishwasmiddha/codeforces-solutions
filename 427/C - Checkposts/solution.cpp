// Problem: C. Checkposts
// Contest: Codeforces - Codeforces Round 244 (Div. 2)
// URL: https://codeforces.com/contest/427/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
// Problem: B. Pashmak and Flowers
// Contest: Codeforces - Codeforces Round 261 (Div. 2)
// URL: https://codeforces.com/problemset/problem/459/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <stack>
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
 
void dfs(int m,vector<int>&order,vector<int>&visited,vector<vector<int>> &adj){
		visited[m]=1;
		
		for(auto c:adj[m]){
			if(!visited[c]){
				dfs(c,order,visited,adj);
			}
		}
		order.pb(m);
	}
pair<ll,ll> dfs(int m,vector<int>&visited,vector<vector<int>> &adj, ll&mincost,vector<int>&cost,ll&count){
	visited[m]=1;
	if(cost[m]<mincost){
		count=1;
		mincost=cost[m];
	} else if (cost[m]==mincost){
		count++;
	}
	for(auto c:adj[m]){
		if(!visited[c]){
			dfs(c,visited,adj,mincost,cost,count);
		}
	}
	return {count,mincost};
}
int main(){
    speed();
	int n,m,u,v;
	cin >> n;
	vector<int> cost(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> cost[i];
	}
	cin >> m;
	vector<vector<int>> adj(n+1,vector<int>());
	vector<vector<int>> adjt(n+1,vector<int>());
	REP(m){
		cin >> u >> v;
		adj[u].pb(v);
		adjt[v].pb(u);
	}
	vector<int> order;
	vector<int> visited(n+1,0);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i,order,visited,adj);
		}
	}
	//dfs(1,order,visited,adj);
	REVERSE(order);
	ll ways=1;
	ll count=0;
	ll totalcost=0;
	ll mincost=LLONG_MAX;
	visited.assign(n+1,0);
	pair<ll,ll> p;
	for(auto c:order){
		if(!visited[c]){
			p=dfs(c,visited,adjt,mincost,cost,count);
			count=0;
			mincost=LLONG_MAX;
			totalcost+=p.second;
			ways=(ways*p.first)%MOD;
		}
	}
	print(totalcost,ways);
	
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 