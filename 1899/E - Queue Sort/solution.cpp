#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define range(i,a,b) for (long long i=a;i<b;i++)
 
 
int main(){
    int t,n,a;
    cin >> t;
    range(some,0,t){
        cin >> n;
        int small=-1;
        int index = -1;
        vector<int> v;
        //cout << "N: " << n << "
";
        range(i,0,n){
            cin >> a;
            if (small==-1 | small>a){
                small=a;
                index = i;
            } 
            v.push_back(a);
        }
        bool hojega = true;
        range(i,index+1,n){
            if (v[i]<v[i-1]){
                hojega = false;
                break;
            }
        }
        //cout << "esmall" << index << "
";
        if (hojega) {
            cout << index << "
"; 
        } else {
            cout << "-1
";
        }
    }
}