#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
 
string fun(int n,int t,vector<int> &a){
    int p=1;
    if (t==1){
        return "YES";}
    while(p!=n){
        p+=a[p-1];
        if (p==t){
            return "YES";
        }
    }
    return "NO";
}
 
int main(){
    int n,t,x;
    cin >> n >> t;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    cout << fun(n,t,a);
}
 