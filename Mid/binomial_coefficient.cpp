#include <iostream>
using namespace std;
int num[30][30];
int calculate(int n,int k){
    if(n==k||k==0){
        return 1;
    }
    if(num[n][k]>0){
        return num[n][k];
    }
    else{
        num[n][k]=calculate(n-1,k-1)+calculate(n-1,k);
        return num[n][k];
    }

}
int main(){
    int n,k;
    cin >> n >> k;
    cout << calculate(n,k);
}