// Problem: C. Trip Shopping
// Contest: Codeforces - Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2127/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
// Problem: B. Pashmak and Flowers
// Contest: Codeforces - Codeforces Round 261 (Div. 2)
// URL: https://codeforces.com/problemset/problem/459/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;
 
 
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int prefix=0;
        int cost=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(prefix==0){
                    prefix++;
                    st.push(i);
                } else {
                    prefix--;
                    cost+=i-st.top();
                    st.pop();
                }
            } else {
                if(s[i]=='('){
                    prefix++;
                    st.push(i);
                } else {
                    prefix--;
                    cost+=i-st.top();
                    st.pop();
                }
            }
        }
        cout << cost << "
";
    }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 