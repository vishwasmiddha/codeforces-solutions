#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define range(i,a,b) for (long long i=a;i<b;i++)
 
 
int main(){
    int l,r,L,R,t,ll,rr;
    cin >> t;
    range(some,0,t){
        cin >> l >> r >> L >> R;
        if (R<l){
            cout << 1 << "
";
        } else if (L>r) {
            cout << 1 << "
";
        } else {
            int common = 0;
            ll = max(l,L);
            rr = min(R,r);
            common += (rr>ll) ? rr-ll:0;
            common += (r==R) ? 0:1;
            common+= (l==L) ? 0:1;
            cout << common << "
";
            
        }
        
    }
    
}