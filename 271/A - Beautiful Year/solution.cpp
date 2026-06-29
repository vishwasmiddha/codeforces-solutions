#include <iostream>
#include <string>
using namespace std;
 
bool same(int num){
    string nums = to_string(num);
    if(nums[0]==nums[1]||nums[0]==nums[2]||nums[0]==nums[3]||nums[1]==nums[2]||nums[1]==nums[3]||nums[2]==nums[3]){
        return true;
    } else {
        return false;
    }
}
 
int main(){
    int n;
    cin >> n;
    n++;
    while(same(n)){
        n++;
    }
    cout << n;
}