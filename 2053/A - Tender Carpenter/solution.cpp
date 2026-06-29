#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define range(i,a,b) for (long long i=a;i<b;i++)
 
 
int main(){
    int t,n;
    float a,b;
    
    cin >> t;
    
    range(j,0,t){
        bool ans = false;
        cin >> n;
        cin >> a;
        range(i,0,n-1) {
            cin >>b;
            if(a/b>0.5 & a/b < 2) {
                ans = true;
                //cout << a << " " << b << " "<< i<< endl;
            }
            swap(a,b);
        }
        if (ans){
            cout << "YES
";
        } else {
            cout << "NO
";
        }
    }
}