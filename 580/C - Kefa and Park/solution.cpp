// Problem: C. Kefa and Park
// Contest: Codeforces - Codeforces Round 321 (Div. 2)
// URL: https://codeforces.com/problemset/problem/580/C
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
#define pb push_back
#define pop pop_back
 
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
 
void dfs(map<int,vector<int>> &adj,vector<int> &cat,vector<int> &consec,int root, int &possible,int parent,int m){
	//vector<int> neighbour;
	//cout << root << " root
";
	//int parent;
	if ((adj[root].size()==1) & (adj[root][0]==parent)){
		if (consec[root]!=-1){
			possible+=1;
		}
		return;
	}
	for(auto c:adj[root]){
		if (c!=parent){
			//cout << c<< " updation
";
		if (cat[c]==1){
			//cout << c << " cat
";
			int temp = consec[root]+1;
			if ((temp==0) | (temp==m+1)){
				consec[c]=-1;
			} else {
				consec[c]=temp;
			}
		} else {
			if (consec[root]==-1){
				consec[c]=-1;
			} else {
				consec[c]=0;
			}
		}
		dfs(adj,cat,consec,c,possible,root,m);
		}
	}
 
}
 
int main(){
    speed();
	int n,m,a,a1,a2;
	cin >> n >> m;
	vector<int> cat={0};
	REP(n){
		cin >> a;
		cat.pb(a);
	}
	map<int,vector<int>> adj;
	REP(n-1){
		cin >> a1 >> a2;
		adj[a1].pb(a2);
		adj[a2].pb(a1);
	}
	int possible = 0;
	vector<int> consec(n+1,-2); // -2 is unvisited -1 is impossible
	consec[1]=cat[1];
	dfs(adj,cat,consec,1,possible,0,m);
	cout << possible;
	/*for (int i=1;i<=n;i++){
		cout << i << " " << consec[i] << "
";
	}*/
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 