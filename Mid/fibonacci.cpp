#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    int num[2] = {0,1};
    while(x>1){
        int tmp = num[0];
        num[0] = num[1];
        num[1] = tmp+num[1];
        x--;
    }
    cout<<num[x];
    
}