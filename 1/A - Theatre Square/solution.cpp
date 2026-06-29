#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    double n,m,a;
    cin >> n >> m >> a;
    long long x,y;
    x=ceil(double(n/a));
    y=ceil(double(m/a));
    cout << x*y;
}