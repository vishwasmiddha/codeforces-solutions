#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,r;
    vector<int> a;
    cin >> n;
    bool possible = false;
    for (int i=0;i<n;i++){
        cin >> r;
        a.push_back(r);
    }
    for(int i=0;i<(1<<n);i++){
        int total = 0;
        for (int j=0;j<n;j++){
            if (i&(1<<j)){
                total += a[j];
            } else {
                total-= a[j];
            }
        }
        if (total%360==0){
            possible=true;
            break;
        }
    }
    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}