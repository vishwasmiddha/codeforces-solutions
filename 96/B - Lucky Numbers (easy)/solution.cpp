#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> v;
    for(int max=1;max<11;max++){
    for (long long i=0;i<1<<max;i++){
        int fo=0;
        int se=0;
        long long num = 0;
        for (long long j=0;j<max;j++){
            if ((1<<j)&i){
                num+=7*pow(10,j);se++;
            } else {
                num+=4*pow(10,j);fo++;
            }
        }
        //cout << num << " "<<fo <<" "<< se<<"
";
        if(fo==se){//cout<<num<<"
";
        v.push_back(num);}
    }
    }
    sort(v.begin(),v.end());
    int length = v.size();
    for (auto c:v){
        //cout <<c<<"
";
        if (c>=n){
            cout << c;
            break;
        }
    }
}