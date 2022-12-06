#include<iostream>
#include<vector>
using namespace std;
void generateBarcode(int& n,vector<int> vec,int idx,int& totalWant,int used){
    if(idx<n){
        if(used>=totalWant){
            vec[idx] = 0;
            generateBarcode(n,vec,idx+1,totalWant,used);
        }
        else if(n-idx>totalWant){
            vec[idx] = 0;
            generateBarcode(n,vec,idx+1,totalWant,0);
        }
        vec[idx] = 1;
        generateBarcode(n,vec,idx+1,totalWant,used+1);
    }
    else{
        for(auto &x:vec){
            cout << x;
        }
        cout << "\n";
    }
}
int main(){
    int a,b;
    cin >> b >> a;
    vector<int> vec(b);
    generateBarcode(b,vec,0,a,0);
}