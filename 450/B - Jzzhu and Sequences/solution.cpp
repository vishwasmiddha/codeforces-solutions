#include <bits/stdc++.h>
#include <cctype>
using namespace std;
 
int main(){
    long long x,y,n;
    cin >> x >> y >> n;
    int m = (int)n%6;
    vector<long long> v={x-y,x,y,y-x,-x,-y};
    long long d = v[m]%((long long)pow(10,9)+7);
    cout << (d>=0 ? d : d+(long long)pow(10,9)+7);
}