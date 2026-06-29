// Problem: C. Product of Three Numbers
// Contest: Codeforces - Codeforces Round 615 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1294/C
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
 
int main(){
    speed();
	TESTCASE{
		map<ll,int> m;
		ll n;
		cin>>n;
		ll n2=n;
		for(int i=2;i<=pow(n,0.5)+1;i++){
			while(n%i==0){
				n=n/i;
				m[i]+=1;
			}
		}
		if(n!=1){
			m[n]+=1;
		}
		bool pos = false;
		vector<ll> arr;
		if (m.size()>=3){
			pos = true;
			map<ll,int>::iterator it=m.begin();
			for(int i =0;i<=1;i++,++it){
				arr.pb(power((it)->first,(it)->second));
			}
			arr.pb(n2/(arr[0]*arr[1]));
		} else if (m.size()==2){
			vector<pair<ll,int>> v;
			for (auto c:m){
				v.pb(c);
			}
			if(v[0].second+v[1].second>=4){
				pos = true;
			}
			if ((v[0].second==1)&(pos)){
				arr.pb(v[0].first);
				arr.pb(v[1].first);
				arr.pb(pow(v[1].first,v[1].second-1));
			} else if ((v[1].second==1)&(pos)){
				arr.pb(v[0].first);
				arr.pb(v[1].first);
				arr.pb(pow(v[0].first,v[0].second-1));
			} else if (pos){
				arr.pb(v[0].first);
				arr.pb(v[1].first);
				arr.pb(pow(v[1].first,v[1].second-1)*pow(v[0].first,v[0].second-1));
			}
		} else if (m.size()==1){
			for (auto c:m){
				if (c.second>=6){
					pos = true;
					arr.pb(c.first);
					arr.pb(c.first*c.first);
					arr.pb(pow(c.first,c.second-3));
				}
			}
			
		}
		if(pos){
			print("YES");
			for (auto c:arr){
				cout << c << " ";
			}
			cout << "
";
		} else {
			cout << "NO
";
		}
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 