#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n,k;cin>>n>>k;    
    if(n%2==1){
        k--;
        int small = n;
        for(int i=2;i<n;i++){
            if(n%i==0){
                small=i;
                break;
            }
        }
        n+=small;
    }
    cout << n + 2*k << "
";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}