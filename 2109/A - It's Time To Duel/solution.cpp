// Problem: A. It's Time To Duel
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2109/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <iostream>
 
#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <map>
//#include <set>
#include <numeric>
 
using namespace std;
typedef long long ll;
 
bool ans(int n, vector<int> &v){
	//cout << "n: " << n << endl;
	int sum = accumulate(v.begin(),v.end(),0);
	//cout << sum << " " << n;
	if(sum==n) return false;
	if (n==2){
		//cout << "xor "<<v[0]<<" "<<v[1]<<"
";
		return v[0]^v[1];
	} else {
		for (int i=0;i<n-1;i++){
			if (v[i]==v[i+1] && v[i+1]==0){
				//cout << i;
				return false;
			}
		}
	}
	return true;
}
 
void speed(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    speed();
    int t;
    int n;
    int x;
    cin >> t;
    while(t--){
    	cin >> n;
    	vector<int> v;
    	while (n--){
    		cin >> x;
    		v.push_back(x);
    	}
    	cout << (!ans(v.size(),v)?"YES":"NO")<<"
";
    }
    
} 	