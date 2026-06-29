#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    string s;
    cin >> n;
    map<string,int> m;
    for (int i=0;i<n;i++){
        cin >> s;
        m[s]++;
        if (m[s]>1){
            cout << s << m[s]-1 << "
";
        } else {
            cout << "OK
";
        }
    }
}