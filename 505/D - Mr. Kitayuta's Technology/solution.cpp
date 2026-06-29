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
void dfs(int m,vector<int>&visited,vector<vector<int>> &adjt,int groupno,vector<int>&groups,int&cyclecount,int&returnguy){
	cyclecount++;
	groups[m]=groupno;bool check=true;
	visited[m]=1;
	// if(cost[m]<mincost){
		// count=1;
		// mincost=cost[m];
	// } else if (cost[m]==mincost){
		// count++;
	// }
	for(auto c:adjt[m]){
		if(!visited[c]){
			check=false;
			//print("to visit: ",c,"group:",groupno,"from: ",m);
			dfs(c,visited,adjt,groupno,groups,cyclecount,returnguy);
		}
	}
	if(check)returnguy=m;
	//return {count,mincost};
}
 
void dfs3(int i,vector<set<int>> &finaledges,vector<int>&visited,int&keeptrack){
	visited[i]=1;
	keeptrack++;
	for(auto c:finaledges[i]){
		
		if(!visited[c]){
			dfs3(c,finaledges,visited,keeptrack);
		}
	}
	
}
 
void dfs4(int m,vector<int>&visited,vector<vector<int>>&adj,vector<vector<int>>&adjt,bool&flag,vector<int>&notcyclic,int&length){
	visited[m]=1;
	length++;
	//print(m,length);
	for(auto c:adj[m]){
		if(notcyclic[c]==0){
			flag=true;
		}
		else if(!visited[c]){
			//print(m,"to visit",c,length);
			dfs4(c,visited,adj,adjt,flag,notcyclic,length);
		}
	}
	for(auto c:adjt[m]){
		if(notcyclic[c]==0){
			flag=true;
		}
		else if(!visited[c]){
			//print(m,"to visit",c,length);
			dfs4(c,visited,adj,adjt,flag,notcyclic,length);
		}
	}
}
 
int main(){
    speed();
	int n,m,u,v;
	cin >> n;
	//vector<int> cost(n+1,0);
	// for(int i=1;i<=n;i++){
		// cin >> cost[i];
	// }
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
	// ll ways=1;
	// ll count=0;
	// ll totalcost=0;
	// ll mincost=LLONG_MAX;
	visited.assign(n+1,0);
	vector<int> groups(n+1,0);
	//pair<ll,ll> p;
	int roads=0;
	int groupno=1;
	int cyclecount=0;
	// for(auto c:order)cout << c << " ";
	// cout << "
";
	int returnguy =-1;
	vector<int> notcyclic(n+1,0);
	for(auto c:order){
		if(!visited[c]){
			//print("root",c);
			dfs(c,visited,adjt,groupno,groups,cyclecount,returnguy);
			if(returnguy==c)notcyclic[c]=1;
			groupno++;
			if(cyclecount>1)roads+=cyclecount;
			cyclecount=0;
			// count=0;
			// mincost=LLONG_MAX;
			// totalcost+=p.second;
			// ways=(ways*p.first)%MOD;
		}
	}
	// print("neighbours of 1");
	 // for(auto c:adj[1])cout << c << " ";
	 // cout << "
";
	 // for(auto c:groups)cout << c << " ";
	 // cout << "
";
	//cout << roads+groupno-2;
	//print(totalcost,ways);
	
	
	
	vector<int> notcyclicvisited(n+1,0);
	bool flag=false;
	int length=0;
	for(int i=1;i<=n;i++){
		if(notcyclic[i]){
			if(!notcyclicvisited[i]){
				dfs4(i,notcyclicvisited,adj,adjt,flag,notcyclic,length);
				if(flag)roads+=length;
				else roads+=length-1;
				length=0;
				flag=false;
				//print("dfsed",i,"made roads",roads);
			}
		}
	}
	
	print(roads);
	// for(auto c:notcyclic){
		// cout << c << " ";
	// }
	// cout << "
";
// 	
// 	
// 	
// 	
// 	
// 	
// 	
	// vector<set<int>> finaledges(groupno,set<int>());
// 
	// for(int i=1;i<=n;i++){
		// for(auto c:adj[i]){
			// if(groups[i]!=groups[c]){
				// finaledges[groups[i]].insert(groups[c]);
				// finaledges[groups[c]].insert(groups[i]);
			// }
		// }
	// }
	// vector<int> visitedgroups(groupno,0);
	// int keeptrack=0;
	// for(int i=1;i<groupno;i++){
		// if(!visitedgroups[i]){
			// dfs3(i,finaledges,visitedgroups,keeptrack);
			// roads+=keeptrack-1;
			// keeptrack=0;
		// }
	// }
	// cout << roads;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 