// Problem: A. Permutation Warm-Up
// Contest: Codeforces - Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2108/A
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
    int t,n;
    cin >> t;
    while(t--){
    	cin >> n;
    	if (n&1){
    		cout << ((n*n)+3)/4<<"
";
    		//odd
    	} else {
    		cout << ((n*n)+4)/4<<"
";
    	}
    }
}