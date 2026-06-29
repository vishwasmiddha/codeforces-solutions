// Problem: B. T-primes
// Contest: Codeforces - Codeforces Round 142 (Div. 2)
// URL: https://codeforces.com/problemset/problem/230/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
#include <iostream>
 
#include <vector>
#include <cmath>
#include <algorithm>
//#include <map>
//#include <set>
 
using namespace std;
typedef long long ll;
 
template <typename t>
void printvec(vector<t> &v){
	cout << "{";
	for (auto c:v){
		cout <<c<<", ";
	}
	cout << "}
";
}
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    speed();
    int n,n2;
    ll x;
    cin >> n;
    n2 = n;
    vector<ll> xx;
    while(n2--){
    	cin >> x;
    	xx.push_back(x);
    }
    ll big = *max_element(xx.begin(),xx.end());
    ll big2 = big;
    big = pow(big,0.5)+1;
    vector<bool> v(big+1,false);
 
 
    for (int i=2;i*i<=big;i++){
    	//cout << "i: " << i<<"
";
    	if(v[i]) continue;
    	for (int x=2*i;x<=big;x+=i){
    		//cout << i << " and " << x << "
";
    		v[x]=true;
    	}
    }
    //printvec(v);
    ll check;
    for (auto c:xx){
    	if (c<=3) {
    		cout << "NO
";
    	} else {
    	check = pow(c,0.5);
    	//cout << c << " " << check << "
";
    	if (check*check!=c) {
    		cout << "NO
";
    	} else {
    		if (v[check]) {
    			cout << "NO
";
    		} else {
    			cout << "YES
";
    		}
    	}
    	}
    }
}