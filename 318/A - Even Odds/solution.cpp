// Problem: A. Even Odds
// Contest: Codeforces - Codeforces Round 188 (Div. 2)
// URL: https://codeforces.com/problemset/problem/318/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <iostream>
 
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <map>
//#include <set>
 
using namespace std;
typedef long long ll;
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    speed();
    ll n,k;
    cin >> n >> k;
    if (!(n&1)){
    	if (k<=n/2){
    		cout << 2*k-1;
    	} else {
    		cout << 2*(k-n/2);
    	}
    } else {
    	if (k<=(n+1)/2){
    		cout << 2*k-1;
    	} else {
    		cout << 2*(k-(n+1)/2);
    	}
    }
}