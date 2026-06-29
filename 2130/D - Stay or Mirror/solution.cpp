// Problem: D. Stay or Mirror
// Contest: Codeforces - Codeforces Round 1040 (Div. 2)
// URL: https://codeforces.com/contest/2130/problem/D
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
 
int main(){
    //speed();
	TESTCASE{
		int n;cin>>n;//print("n: ",n);
		//vector<int> flip(n+1,0);
		//vector<int> noflip(n+1,0);
		vector<int> indices(n+1,0);
		vector<int> v;
		readvector(v,n);
		for(int i=0;i<n;i++){
			indices[v[i]]=i;
		}
		int temp1=0,temp2=0;
		int sub=0;int index;
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				if(j!=indices[i]){
					//print("i ",i);
					index=indices[i];
					if(((v[j]>i)&&(j<indices[i]))||((v[j]<i)&&(j>indices[i])))temp1++;
					i=2*n-i;//print("i2 ",i);
					if(((v[j]>i)&&(j<index))||((v[j]<i)&&(j>index)))temp2++;
					i=2*n-i;
				}
			}
				//print("temps",i,temp1,temp2);
				if(temp2<temp1){
					v[indices[i]]=2*n-i;
					sub+=temp2;
				} else sub+=temp1;
				temp1=0;temp2=0;
			
		}
		sub=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[j]<v[i])sub++;
			}
		}
		// for(auto c:v) cout << c << " ";
		// cout << "
";
		cout << sub  << "
";
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 