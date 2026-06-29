// Problem: B. Cubes for Masha
// Contest: Codeforces - Codeforces Round 444 (Div. 2)
// URL: https://codeforces.com/contest/887/problem/B
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
 
 
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    speed();
	int n;
	cin>>n;
	if(n==3){
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<bool> v(pow(10,n),false);
	readvector(v1,6);
	readvector(v2,6);
	readvector(v3,6);
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				v[100*v1[i]+10*v2[j]+v3[k]]=true;
				v[100*v1[i]+10*v3[k]+v2[j]]=true;
				v[100*v2[j]+10*v1[i]+v3[k]]=true;
				v[100*v2[j]+10*v3[k]+v1[i]]=true;
				v[100*v3[k]+10*v1[i]+v2[j]]=true;
				v[100*v3[k]+10*v2[j]+v1[i]]=true;
				v[10*v1[i]+v2[j]]=true;
				v[10*v1[i]+v3[k]]=true;
				v[10*v2[j]+v3[k]]=true;
				v[10*v2[j]+v1[i]]=true;
				v[10*v3[k]+v1[i]]=true;
				v[10*v3[k]+v2[j]]=true;
				v[v1[i]]=true;
				v[v2[j]]=true;
				v[v3[k]]=true;
			}
		}
	}
	for(int i=1;i<v.size();i++){
		if (v[i]==false){
			cout << i-1<<"
";
			break;
		}
	}
	//for(auto c:v) cout << c << "
";
	} else if (n==2){
	vector<int> v1;
	vector<int> v2;
	vector<bool> v(pow(10,n),false);
	readvector(v1,6);
	readvector(v2,6);
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
				v[10*v1[i]+v2[j]]=true;
				//v[100*v1[i]+10*v3[k]+v2[k]]=true;
				v[10*v2[j]+v1[i]]=true;
				//v[100*v2[j]+10*v3[k]+v1[i]]=true;
				//v[100*v3[k]+10*v1[i]+v2[j]]=true;
				//v[100*v3[k]+10*v2[j]+v1[i]]=true;
				v[v1[i]]=true;
				v[v2[j]]=true;
		}
	}
	
	for(int i=1;i<v.size();i++){
		if (v[i]==false){
			cout << i-1<<"
";
			break;
		}
	}
	} else {
		
		
		
		
		
vector<int> v1;
	vector<bool> v(pow(10,n),false);
	readvector(v1,6);
	for(int i=0;i<6;i++){
 
				//v[100*v1[i]+10*v3[k]+v2[k]]=true;
				v[v1[i]]=true;
				//v[100*v2[j]+10*v3[k]+v1[i]]=true;
				//v[100*v3[k]+10*v1[i]+v2[j]]=true;
				//v[100*v3[k]+10*v2[j]+v1[i]]=true;
	}
	for(int i=1;i<v.size();i++){
		if (v[i]==false){
			cout << i-1<<"
";
			break;
		}
	}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}	
		
		
		
		
	
	}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 