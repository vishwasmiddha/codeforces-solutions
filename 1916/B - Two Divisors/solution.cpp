#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main()
{
	long long a,b;
	int loops;
	cin >> loops;
	for(int i=0;i<loops;i++){
		cin >> a >> b;
		if(max(a,b)%min(a,b)!=0){
			cout << a*b/gcd(a,b) << endl;
		} else {
			cout << max(a,b)*max(a,b)/min(a,b) << endl;
		}
	}
}