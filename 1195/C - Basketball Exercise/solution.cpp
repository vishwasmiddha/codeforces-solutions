#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    long long h;
    vector<long long> v1;
    vector<long long> v2;
    for(int i=0;i<n;i++){
        cin >> h;
        v1.push_back(h);
    }
    for(int i=0;i<n;i++){
        cin >> h;
        v2.push_back(h);
    }
    if (n>2){
        vector<long long> s1={v1[0],v1[1]+v2[0]};
        vector<long long> s2={v2[0],v2[1]+v1[0]};
        for(int i=2;i<n;i++){
            s1.push_back(max(s2[i-1],s2[i-2])+v1[i]);
            s2.push_back(max(s1[i-1],s1[i-2])+v2[i]);
        }
        cout << max(s1[s1.size()-1],s2[s2.size()-1])<<"
";
    } else if (n==1) {
        cout << max(v1[0],v2[0]) << "
";
    } else {
        cout << max(v1[0]+v2[1],v1[1]+v2[0]) << "
";
    }
}