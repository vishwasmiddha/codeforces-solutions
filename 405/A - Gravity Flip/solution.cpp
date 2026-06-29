#include <bits/stdc++.h>
#include <cctype>
using namespace std;
 
int main(){
    int n;
    int in;
    cin >> n;
    vector<int> v;
    for (int i=0;i<n;i++){
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(),v.end());
    for (auto c:v){
        cout << c << " ";
    }
}