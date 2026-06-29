#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string poles = "";
    int inp;
    int group=1;
    for(int i=0;i<n;i++){
        cin >> inp;
        if(inp==10){
            poles+='N';
        } else {
            poles+='S';
        }
    }
    for(int i=0;i<n-1;i++){
        if(poles[i]!=poles[i+1]){
            group++;
        }
    }
    cout << group;
}