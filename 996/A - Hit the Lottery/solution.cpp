#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {100,20,10,5,1};
    int money;
    int count = 0;
    cin >> money;
    for (auto c:v){
        while(c<=money){
            money = money - c;
            count++;
        }
    }
    cout << count;
}