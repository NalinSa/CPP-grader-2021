#include <iostream>
#include <vector>
using namespace std;
int iss(int max,int total){
    if(total==0) return 1;
    else{
        int sum = 0;
        for(int i = max;i<=total;i++){
            sum += iss(i,total-i);
        } 
        return sum;
    }
}
int main(){
    int N;
    cin >> N;
    cout << iss(1,N);
}