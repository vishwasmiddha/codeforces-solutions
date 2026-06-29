// Problem: B. Slice to Survive
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <iostream>
 
#include <vector>
//#include <cmath>
#include <algorithm>
//#include <map>
//#include <set>
 
using namespace std;
typedef long long ll;
 
int high(ll n){
	ll higher = 1;
	int power = 0;
	while (higher<n){
		higher = higher << 1;
		power++;
	}
	return power;
}
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    speed();
    int t;
    cin >> t;
    ll n,m,a,b;
    while(t--){
    	cin >> n >> m >> a >> b;
    	vector<pair<ll,ll>> v;
    	pair<ll,ll> p;
    	p.first=n-a+1;
    	p.second=m;
    	v.push_back(p);
    	p.first=a;
    	v.push_back(p);
    	p.first=n;
    	p.second=b;
    	v.push_back(p);
    	p.second = m-b+1;
    	v.push_back(p);
    	vector<int> v2;
    	for (auto c:v){
    		int some=0;
    		some += high(c.first)+high(c.second)+1;
    		//cout << "p: " << some << endl;
    		v2.push_back(some);
    	}
    	auto it = min_element(v2.begin(),v2.end());
    	cout << *it << "
";
    }
}