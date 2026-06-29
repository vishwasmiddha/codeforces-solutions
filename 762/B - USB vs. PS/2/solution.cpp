// Problem: B. USB vs. PS/2
// Contest: Codeforces - Educational Codeforces Round 17
// URL: https://codeforces.com/contest/762/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
// Problem: B. Pashmak and Flowers
// Contest: Codeforces - Codeforces Round 261 (Div. 2)
// URL: https://codeforces.com/problemset/problem/459/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <algorithm>
#include <cmath>
#include <numeric>
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
	int a,b,c;
	cin >> a>>b>>c;
	ll cost2;
	string type;
	vector<ll> usb;
	vector<ll> ps2;
	TESTCASE{
		cin >> cost2 >> type;
		if(type=="USB"){
			usb.pb(cost2);
		} else {
			ps2.pb(cost2);
		}
		
	}
	SORT(usb)
	SORT(ps2)
	ll cost = 0;
	int cusb = usb.size();
	int cps2 = ps2.size();
	if(a>cusb){
		cusb=0;
		cost+=accumulate(usb.begin(),usb.end(),0LL);
	} else {
		cusb-=a;
		for(int i=0;i<a;i++){
			cost+=usb[i];
		}
	}
	if (b>cps2){
		cps2=0;
		cost+=accumulate(ps2.begin(),ps2.end(),0LL);
	} else {
		cps2 -= b;
		for(int i=0;i<b;i++){
			cost+=ps2[i];
		}
	}
	int p1=a;
	int p2=b;
	while ((c!=0) & (cusb + cps2!=0)){
		if(cusb*cps2!=0){
			if(usb[p1]<ps2[p2]){
				p1++;
				cusb--;
				cost+=usb[p1-1];
				c--;
			} else {
				p2++;
				cps2--;
				cost+=ps2[p2-1];
				c--;
			}
		} else if (cusb){
			p1++;
				cusb--;
				cost+=usb[p1-1];
				c--;
		} else {
			p2++;
				cps2--;
				cost+=ps2[p2-1];
				//print(ps2[p2-1]);
				c--;
		}
	}
	print(usb.size()+ps2.size()-cusb-cps2,cost);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 