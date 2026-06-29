#include <iostream>    // cin, cout, cerr
#include <vector>      // vector
#include <array>       // array
#include <deque>       // deque
#include <list>        // list
#include <forward_list>// forward_list
#include <stack>       // stack
#include <queue>       // queue, priority_queue
#include <set>         // set, multiset
#include <map>         // map, multimap
#include <unordered_set> // unordered_set, unordered_multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <string>      // string, stoi, to_string
#include <cstring>     // memset, strcpy (C-style strings)
#include <sstream>     // stringstream
#include <algorithm>   // sort, min, max, reverse, lower_bound, upper_bound
#include <numeric>     // accumulate, gcd, lcm
#include <functional>  // greater, less, function
#include <utility>     // pair, swap, move
#include <tuple>       // tuple, tie
#include <cmath>       // sqrt, pow, abs, sin, cos, etc.
#include <bitset>      // bitset
 
 
using namespace std;
const long long INF = 9223372036854775807;
const long long MOD = 1e9 + 7;
 
 
template<typename T>
void readvector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}
 
template<typename T>
pair<int,vector<T>> makevec(){
    int n;cin>>n;
    vector<T> temp(n);
    for(int i=0;i<n;i++){
        cin >> temp[i];
    }
    return {n,temp};
}
 
template <typename T>
auto SUM(const T& A) {
    using Elem = typename T::value_type;
    return std::accumulate(A.begin(), A.end(), Elem(0));
}
 
void boolprint(bool a){
    cout << (a?"YES
":"NO
");
}
 
template <typename T>
void printvec(vector<T> &v){
    cout << "Vector: {";
    for(auto c:v)cout << c << ", ";
    cout << "}
";
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
#define makevec(v,n) \
vector<int> v;               \
readvector(v,n);  
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
 
template <typename T>
void sieve(T n, vector<T> &v){
    vector<bool> isnotprime(n+1,false);
    isnotprime[0]=true;
    isnotprime[1]=true;
    vector<T> primes;
    for (T i=2;i*i<=n;i++){
        if (!isnotprime[i]){
            for (T j=i*i;j<=n;j+=i){
                isnotprime[j]=true;
            }
 
        }
    }
    for (T i=2;i<=n;i++){
        if (!isnotprime[i]){
            v.push_back(i);
        }
    }
	return;
}
 
int main(){
    speed();
    vector<ll> primes;
    sieve(100000LL,primes);
    TESTCASE{
        ll n;cin>>n;
        vector<ll> a,b;
        readvector(a,n);
        readvector(b,n);
        ll moves=0;
        vector<int> mark(n,0);
        vector<vector<ll>> factors(n,vector<ll>());
        for(int i=0;i<n;i++){
            if(i==0){
                ll temp=gcd(a[i],a[i+1]);
                if(temp<a[i] && temp<=b[i]){
                    a[i]=temp;
                    moves++;
                    // if(temp*2LL<=b[i]){
                    //     mark[i]++;
                    // }
                    // if(temp*3LL<=b[i]){
                    //     mark[i]++;
                    // }
                } else if (temp==a[i]){
                    mark[i]=1;
                    
                    
 
                }
                
            } else if (i==n-1){
                ll temp=gcd(a[i],a[i-1]);
                if(temp<a[i] && temp<=b[i]){
                    a[i]=temp;
                    moves++;
                }else if (temp==a[i]){
                    mark[i]=1;
                    
                   
                }
            } else {
                ll temp=lcm(gcd(a[i],a[i+1]),gcd(a[i],a[i-1]));
                if(temp<a[i] && temp<=b[i]){
                    a[i]=temp;
                    moves++;
                }else if (temp==a[i]){
                    mark[i]=1;
                    
             
                }
            }
           
        }
        for(int i=0;i<n;i++){
            if(mark[i]){
                if(i==0){
ll temp2 = a[i+1]/a[i];
                    for(auto c:primes){
                        //print(c,"prime");
                        if(c*a[i]>b[i])break;
                        if(temp2%c!=0){
                            factors[i].pb(c);
                            if(factors[i].size()==3)break;
                        }
                    }
                } else if(i==n-1){
ll temp2 = a[i-1]/a[i];
                    for(auto c:primes){
                        if(c*a[i]>b[i])break;
                        if(temp2%c!=0){
                            factors[i].pb(c);
                            if(factors[i].size()==3)break;
                        }
                    }
                } else {
ll temp2 = lcm(a[i+1]/gcd(a[i],a[i+1]),a[i-1]/gcd(a[i],a[i-1]));
                    for(auto c:primes){
                        if(c*a[i]>b[i])break;
                        if(temp2%c!=0){
                            factors[i].pb(c);
                            if(factors[i].size()==3)break;
                        }
                    }
                }
             
            }
            while(factors[i].size()<3)factors[i].pb(0);
        }
        //printvec(a);
        vector<ll> dp1(n,0);
        vector<ll> dp2(n,0);
        vector<ll> dp3(n,0);
        vector<ll> dpnone(n,0);
        //printvec(mark);
        for(int i=0;i<n;i++){
            if(mark[i]<=0){
                // if(i>0){
                //     ll temp=max(dp2[i-1],dp3[i-1]);
                //     temp=max(temp,dpnone[i-1]);
                //     dpnone[i]=temp;
                //     dp2[i]=-1;
                //     dp3[i]=-1;
 
                // } else {
                //     dpnone[i]=0;
                //     dp2[i]=-1;
                //     dp3[i]=-1;
                // }
                if(i==0){
                    dp1[i]=-1;
                    dp2[i]=-1;
                    dp3[i]=-1;
                    dpnone[i]=0;
                } else {
                    dp1[i]=-1;
                    dp2[i]=-1;
                    dp3[i]=-1;
                    vector<ll> tempv = {dp1[i-1],dp2[i-1],dp3[i-1],dpnone[i-1]};
                    dpnone[i]=MAX_IN(tempv);
                }
            }
            else{
                for(int j=0;j<=3;j++){
                    if(j==3){
                        if(i==0)dpnone[i]=0;
                        else {
                            vector<ll> tempv = {dp1[i-1],dp2[i-1],dp3[i-1],dpnone[i-1]};
                            dpnone[i]=MAX_IN(tempv);
                        }
                    } else{
                        vector<ll> candidates={0};
                        for(int k=0;k<3;k++){
                            if(i>0){
                                if(factors[i-1][k]!=0 && factors[i-1][k]!=factors[i][j]){
                                    if(k==0)candidates.pb(dp1[i-1]);
                                    if(k==1)candidates.pb(dp2[i-1]);
                                    if(k==2)candidates.pb(dp3[i-1]);
                                }
                                
                            }
                        }
                        if(i>0)candidates.pb(dpnone[i-1]);
                        if(factors[i][j]!=0){
                            if(j==0)dp1[i]=MAX_IN(candidates)+1;
                            if(j==1)dp2[i]=MAX_IN(candidates)+1;
                            if(j==2)dp3[i]=MAX_IN(candidates)+1;
                        } else {
                            if(j==0)dp1[i]=-1;
                            if(j==1)dp2[i]=-1;
                            if(j==2)dp3[i]=-1;
                        }
                    }
                }
            }
        }
        // printvec(a);
        //     printvec(mark);
        //     for(int i=0;i<n;i++){
        //         if(mark[i]){
        //             print(i,a[i]);
        //             printvec(factors[i]);
        //         }
        //     }
        //     printvec(dp1);
        //     printvec(dp2);
        //     printvec(dp3);
        //     printvec(dpnone);
        //     print("done");
        cout << moves + max({dp1[n-1], dp2[n-1], dp3[n-1], dpnone[n-1]}) << "
";
    }    
}