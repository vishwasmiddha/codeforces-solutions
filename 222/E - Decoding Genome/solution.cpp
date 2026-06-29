#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define range(i,a,b) for (long long i=a;i<b;i++)
 
 
vector<vector<long long>> multi(vector<vector<long long>> &A,vector<vector<long long>> &B, long long m = 1000000007){
    long long rows = A.size();
    long long cols = B[0].size();
    vector<vector<long long>> answer;
    range(i,0,rows){
        vector<long long> empty;
        range(j,0,cols){
            long long sum = 0;
            range(k,0,A[0].size()){
                sum = (sum + A[i][k]*B[k][j])%m;
            }
            empty.push_back(sum);
            
        }
        answer.push_back(empty);
    }
    return answer;
}
 
vector<vector<long long>> expo(vector<vector<long long>> &A, long long n){
    long long length = A.size();
    vector<vector<long long>> ans(length,vector<long long>(length,0));
    range(i,0,length){
        ans[i][i]=1;
    }
    while (n!=0){
        if (n%2==1){
            ans = multi(ans,A);
        }
        n = n/2;
        A = multi(A,A);
    }
    return ans;
}
 
long long ascii(char &c){
    if (islower(c)){
        return c - 'a' + 1;
    } else {
        return c - 'A' + 27;
    }
}
 
int main(){
    long long n,m,k;
    cin >> n >> m >> k;
    //vector<long long> v(m,1);
    string s;
    vector<vector<long long>> matrix(m,vector<long long>(m,1));
    //cout << "SIZE: " << matrix.size() << " " << matrix[0].size()<<endl;
    for (long long i=0;i<k;i++){
        cin >> s;
        //cout << ascii(s[0]) << " " << ascii(s[1])<<endl;
        matrix[ascii(s[0])-1][ascii(s[1])-1]=0;
    }
    matrix = expo(matrix,n-1);
    long long sum = 0;
    for (auto v:matrix){
        for (auto i:v) sum += i;
    }
    cout << sum%1000000007;
}