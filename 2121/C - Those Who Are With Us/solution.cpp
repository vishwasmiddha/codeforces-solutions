// Problem: C. Those Who Are With Us
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2121/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
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
 
void printmap(map<int,int> &m){
	cout << "{";
	for (auto c:m){
		cout << c.first<<":"<<c.second<<",";
	}
	cout<<"}
";
}
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
bool poss(pair<int,int> c,vector<pair<int,int>> &pos){
	for (int i=0;i<pos.size();i++){
		if ((pos[i].first!=c.first)&&(pos[i].second!=c.second)) return false;
	}
	return true;
}
 
bool test(vector<pair<int,int>> &pos){
	if (pos.size()<=2) return true;
	vector<pair<int,int>> temp;
	int ind=-1;
	for (int i=1;i<pos.size();i++){
		if((pos[i].first!=pos[0].first)&&(pos[i].second!=pos[0].second)){
			ind = i;
			break;
		}
	}
	if (ind==-1) return true;
	temp.pb({pos[0].first,pos[ind].second});
	temp.pb({pos[ind].first,pos[0].second});
	for (auto c:temp){
		if (poss(c,pos)) return true;
	}
	return false;
}
 
int main(){
    speed();
	TESTCASE{
		int n,m;
		cin >> n >> m;
		vector<vector<int>> v;
		vector<int> te;
		REP(n){
			te.clear();
			readvector(te,m);
			v.pb(te);
		}
		vector<pair<int,int>> pos;
		int max=-1;
		for(int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (v[i][j]>max){
					max = v[i][j];
					pos.clear();
					pos.pb({i,j});
				} else if (v[i][j]==max){
					pos.pb({i,j});
				}
			}
		}
		if (test(pos)){
			cout << max-1<<"
";
		} else {
			cout << max << "
";
		}
		
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 