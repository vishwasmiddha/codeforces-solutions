#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main(){
    int n;
    cin >> n;
    int d;
    long long count0 = 0;
    unordered_map<int,pair<long long,long long>> map;
    for (int i=0;i<n;i++){
        cin >> d;
        if (map.count(abs(d)) && d!=0){
            pair<long long, long long> p = map[abs(d)];
            if (d>0){ p = {p.first+1,p.second}; } else { p = {p.first,p.second+1}; }
            map[abs(d)] = p;
            
        }  else if (d!=0){
            pair <long long, long long> p;
            if (d>0){ p = {1,0}; } else { p = {0,1}; }
            map[abs(d)] = p;
        } else {
            count0++;
        }
    }
    long long value = (long long)(count0>=2 ? (count0*(count0-1))/2 : 0);
    for (auto x:map){
        value += (long long)(x.second.first * x.second.second);
    }
    cout << value;
}