#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    bool one = false;
    string a;
    for (int i=0;i<n;i++){
        cin >> a;
        for (int j=0;j<a.size()-1;j++){
            if (a[j]==a[j+1]){
                one = true;
                break;
            }
        }
        if (one){
            cout << "1
";
        } else {
            cout << a.size() << "
";
        }
        one = false;
    }
}