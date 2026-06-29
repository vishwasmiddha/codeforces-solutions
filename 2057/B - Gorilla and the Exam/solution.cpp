#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t,n,k;
    long long a;
    cin >> t;
    while(t--){
        cin >> n >> k;
        map<long long,int> m;
        while (n--){
            cin >> a;
            m[a] += 1;
        }
        vector<int> v;
        for (auto c:m){
            v.push_back(c.second);
            //cout << "check " << c.second<<"
";
        }
        sort(v.begin(),v.end());
        int l=0;
        while (k>= v[l] & l<v.size()-1){
            k-=v[l];
            l+=1;
        }
        cout << v.size()-l<<"
";
        
    }
}