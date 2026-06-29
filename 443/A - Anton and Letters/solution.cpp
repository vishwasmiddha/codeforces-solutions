#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    unordered_set<int> se;
    getline(cin,s);
    for(auto c:s){
        if (isalpha(c)) se.insert(c);
    }
    cout << se.size();
}