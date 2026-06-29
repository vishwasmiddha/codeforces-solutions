// Problem: D. Skibidi Table
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/D
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
 
ll what(ll x,ll y,int n){
	ll ini = 1<<(n-1);
	ll num=0;
	while (x+y>2){
		//print(ini,x,y,num);
		vector<int> v={0,0};
		if(x>ini){
			v[0]++;
			x-=ini;
		}
		if (y>ini){
			v[1]++;
			y-=ini;
		}
		//print(ini,num,v[0]*10+v[1]);
		switch (v[0]*10+v[1]){
			case 11:
				num+=ini*ini;
				break;
			case 1:
				num+=3*ini*ini;
				break;
			case 10:
				num+=2*ini*ini;
				break;
			case 0:
				break;
		//print("num",num,v[0]*10+v[1]);
		}
		ini=ini>>1;
	}
	return num+1;
}
 
void where(ll d,int n){
	ll ini = 1<<(n-1);
	vector<ll> pos = {1,1};
	while(ini){
		//print(d,ini);
		switch((d-1)/(ini*ini)){
			case 1:
				pos[0]+=ini;
				pos[1]+=ini;
				break;
			case 2:
				pos[0]+=ini;
				break;
			case 3:
				pos[1]+=ini;
				break;
			case 0:
				break;
		}
		
		d-=((d-1)/(ini*ini))*ini*ini;
		ini = ini >>1;
	}
	cout << pos[0] << " " << pos[1] << "
";
}
 
int main(){
    speed();
    TESTCASE{
    	int n,q;
    	cin >> n >> q;
    	REP(q){
    		string s;
    		cin >> s;
    		//cout << s<< "
";
    		if(s=="->"){
    			ll x,y;
    			cin >> x >> y;
    			print(what(x,y,n));
    		} else {
    			ll d;
    			cin >> d;
    			//cout << "Calculating " << d << "
";
    			where(d,n);
    		}
    	}
    }
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 