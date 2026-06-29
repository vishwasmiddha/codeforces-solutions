#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
int main(){
    int n,k;
    cin >> n >> k;
    int a;
    int ppl=0;
    int min;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    min = vec[k-1];
    for(int num:vec){
        if(num>=min&&num>0){
            ppl++;
        }
    }
    cout << ppl;
}