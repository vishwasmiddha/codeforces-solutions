#include <iostream>
#include <string>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  double p =0;
  double vf;
  for(int i=0; i<n; i++){
    cin >> vf;
    p = p + vf/n;
  }
  cout << p;
}