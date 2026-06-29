#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    string a;
    for (int i=0;i<n;i++){
        cin >> a;
        cout << a.substr(0,a.size()-2) << "i
"; 
    }
}