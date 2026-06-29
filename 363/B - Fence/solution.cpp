#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define range(i,a,b) for (long long i=a;i<b;i++)
 
 
int main(){
    int n,k;
    cin >> n >> k;
    int place;
    int sum=0;
    int index,minisum,tempsum;
    //cout << sum << "
";
    vector<int> v;
    while (cin>>place) {
        sum+=place;
        //cout << "sum " << sum << endl;
        v.push_back(sum);
    }
    for (auto c:v) {
        //cout << "vector " << c <<endl; 
    }
    minisum = v[k-1];
    index = 0;
    range(i,1,v.size()-k+1){
        tempsum = v[k-1+i] - v[i-1];
        if (tempsum<minisum){
            index = i;
            //cout << i << " " << tempsum << " " << minisum << "
";
            minisum = tempsum; 
        }
    }
    cout << index+1;
}