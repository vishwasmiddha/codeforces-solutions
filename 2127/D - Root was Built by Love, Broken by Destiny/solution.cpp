// Problem: D. Root was Built by Love, Broken by Destiny
// Contest: Codeforces - Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2127/problem/D
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
 
#include <queue>
 
int main(){
    speed();
	TESTCASE{
		int n,m;cin >> n >> m;int a,b;
		vector<vector<int>> edges(n+1,vector<int>());
		for(int i=0;i<m;i++){
			cin >> a >> b;
			edges[a].pb(b);edges[b].pb(a);
		}
		vector<int> colours(n+1,0);
		queue<int> q;
		int process;
		q.push(1);
		colours[1]=1;
		bool poss=true;
		while(!q.empty()&&poss){
			process=q.front();
			q.pop();
			for(auto c:edges[process]){
				if(colours[c]==0){
					colours[c]=-colours[process];
					q.push(c);
				}
				else if(colours[c]==colours[process]){
					poss=false;
					break;
				}
			}
		}
		ll cases=2;
		int check=0;
		if(!poss)cout << "0
";
		
		else{
			int overall=0;
			for(int i=1;i<=n;i++){
				for(auto c:edges[i]){
					check+=(edges[c].size()>1?1:0);
				}
				if(check>2){
					//impossible
					cases=0;
					break;
				} else if ((check==1)&&edges[i].size()>1){
					overall++;
					//print("over",i);
					for(ll j=2;j<=edges[i].size()-check;j++){
						cases=(cases*j)%MOD;
					}
				}
				
				else {
					//print(i,"check");
					for(ll j=2;j<=edges[i].size()-check;j++){
						cases=(cases*j)%MOD;
					}
				}
				//print(i,check,edges[i].size());
				check=0;
			}
			
			int red=0;int blue=0;
			for(int i=1;i<=n;i++){
				if(red>1&&blue>1)break;
				else{
					if(colours[i]==1)red++;
					else blue++;
				}
			}
			if((overall!=2)&&min(red,blue)>1)cases=0;
			//print(blue,red);
			if(min(blue,red)==1){
				cout << cases << "
";
			} else {
				cout << (cases*2LL)%MOD << "
";
			}
			//print("overall",overall);
			
			
			
			
			
			
			
		}
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 