#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
 
int main() {
	// your code goes here
    int n;cin>>n;
    ll v[n];
    for(int i=0;i<n;i++)cin >> v[i];
    ll prefix[n];
    ll suffix[n];
    ll temp = v[0];
    for(int i=0;i<n;i++){
        temp = gcd(temp,v[i]);
        prefix[i] = temp;
    }
    temp = v[n-1];
    for(int i=n-1;i>=0;i--){
        temp = gcd(temp,v[i]);
        suffix[i]=temp;
    }
    ll cost = 0;
    cost += prefix[n-1];
    for(int i=1;i<n-1;i++){
        cost += min(suffix[i],prefix[i]);
    }
    cout << cost ;
}