// Problem: C. Road Improvement
// Contest: Codeforces - VK Cup 2016 - Qualification Round 2
// URL: https://codeforces.com/contest/638/problem/C
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
#include <queue>
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
 
 
int main(){
    speed();
	int n;
	cin >> n;
	int a,b;
	vector<int> color(n,0);
	vector<int> incoming(n+1,0);
	vector<vector<vector<int>>> v(n+1,vector<vector<int>>());
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;
		v[a].pb({b,i});
		v[b].pb({a,i});
	}
	int maxsize = 0;
	for (auto c:v){
		maxsize=(c.size()>maxsize)?c.size():maxsize;
	}
	queue<int> q;
	// for(int i=1;i<=n;i++){
		// for(auto c:v[i]){
			// if(color[c[1]]!=0){
				// continue;
			// }
			// color[c[1]]=max(days[i],days[c[0]])+1;
			// days[i]++;
			// days[c[0]]++;
		// }
	// }
	vector<int> visited(n+1,0);
	visited[1]=1;
	int i;
	q.push(1);
	while(!q.empty()){
		i=q.front();q.pop();
		int colour=1;
		for(auto c:v[i]){
			if(!visited[c[0]]){
				visited[c[0]]=1;
				q.push(c[0]);
				if(incoming[i]==colour)colour++;
				color[c[1]]=colour;
				incoming[c[0]]=colour;
				colour++;
			}
		}
	}
	vector<vector<int>> coloured(maxsize+1,vector<int>());
	for(int i=1;i<=n-1;i++){
		coloured[color[i]].pb(i);
	}
	cout << maxsize<<"
";
	for(int i=1;i<=maxsize;i++){
		cout << coloured[i].size()<<" ";
		for(auto c:coloured[i]){
			cout << c <<" ";
		}
		cout << "
";
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 