#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
 
long long answer(long long n,long long some, vector<long long> x, vector<long long> r){
    map<long long,long long> m;
    for (long long i=0;i<n;i++){
        long long loc = x[i];
        long long rad = r[i];
        for (long long j=loc-rad;j<=loc+rad;j++){
            
            long long height=floor(pow(rad*rad-(loc-j)*(loc-j),0.5));
            if (height>=0){
                long long num  = 2*height+1;
                if ((m.find(j)!=m.end()) && (num>m[j])){
                    m[j]=num;
                } else if(m.find(j)==m.end()){
                    m[j]=num;
                }
            }
        }
    }
    long long sum = 0;
    for (auto c:m){
        sum += c.second;
    }
    return sum;
}
 
int main(){
    long long t;
    cin >> t;
    for(long long heh=0;heh<t;heh++){
    long long n,m;
    cin >> n >> m;
    vector<long long> x;
    vector<long long> r;
    long long in;
    for(long long i =0;i<n;i++){
        cin >> in;
        x.push_back(in);
    }
    for(long long i =0;i<n;i++){
        cin >> in;
        r.push_back(in);
    }
    cout << answer(n,m,x,r) << "
";
    }
}
 