#include <bits/stdc++.h>
#include <cctype>
using namespace std;
 
long long fetch(int a, unordered_map<int,long long> &mappie) {
    if (mappie.count(a)){
        return mappie[a];
    } else {
        return 0;
    }
}
 
long long fetch(int a, map<int,long long> &mappie) {
    if (mappie.count(a)){
        return mappie[a];
    } else {
        return 0;
    }
}
 
long long value(int a, map<int,long long> &mappie, long long swap1, long long swap2){
    //cout << a << " dekh rhe
";
    return max(swap1,swap2) + (mappie[a]*(long long)a);
}
 
int main(){
    int n,in,bigga;
    long long swap1, swap2, swap3;
    //pair<int,long long> a;
    //pair<int,long long> b;
    //int alternate=0;
    long long store;
    cin >> n;
    map<int,long long> m;
    //unordered_map<int,long long> m2;
    for (int i=0;i<n;i++){
        cin >> in;
        if (in>bigga) bigga=in;
        if (m.count(in)){
            m[in] = m[in] + 1;
        } else {
            m[in] = 1;
        }
    }
    //chhap(m);
    swap1 = fetch(1,m);
    swap2 = 2*fetch(2,m);
    swap3 = 3*fetch(3,m) + swap1;
    
    for (int i=4;i<=bigga;i++){
        //cout<< c.first << " dekhte hain
";
        store = value(i,m,swap1,swap2);
        //alternate++;
        swap1 = swap2;
        swap2 = swap3;
        swap3 = store;
        //if (alternate%2==1){
        //    a = make_pair(c.first,store);
        //} else {
        //    b = make_pair(c.first,store);
        //}
        //chhap(m2);
    }
    cout << max(swap2,swap3);
}