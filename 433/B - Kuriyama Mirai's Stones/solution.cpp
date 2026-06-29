#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,in,m;
    cin >> n;
    vector<long long> sigma;
    long long sigmaboi = 0;
    vector<int> v;
    for (int i=0;i<n;i++) {
        cin >> in;
        v.push_back(in);
        sigmaboi += (long long)in;
        sigma.push_back(sigmaboi);
    }
    vector<int> chotu = v;
    sort(chotu.begin(),chotu.end());
    vector<long long> chotusigma;
    long long chotuboi = 0;
    for (int i=0;i<n;i++){
        chotuboi += (long long)chotu[i];
        chotusigma.push_back(chotuboi);
    }
    cin >> m;
    int a,l,r;
    for (int i=0;i<m;i++){
        cin >> a >> l >> r;
        if (a==1){
            cout << (l!=1?sigma[r-1]-sigma[l-2]:sigma[r-1]) << "
";
        } else {
            cout << (l!=1?chotusigma[r-1]-chotusigma[l-2]:chotusigma[r-1]) << "
";
        }
    }
}