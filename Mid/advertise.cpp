#include <iostream>
#include <vector>
using namespace std;
int store[10000];
int billboard(vector<int>& left,int& plus,int idx){
    if(idx==left.size()){
        return 0;
    }
    if(idx == left.size()-1){
        return left[idx];
    }
    if(store[idx]>0){
        return store[idx];
    }
    int maxx = max(billboard(left,plus,idx+2)+left[idx],billboard(left,plus,idx+1));
    store[idx]=maxx;
    return store[idx];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,x;
    cin >> n;
    int w = 1;
    vector<int> left(n);
    for(int i = 0;i<n;i++){
        cin >> x;
        left[i] = x;
    }
    int maxx = billboard(left,w,0);
    cout<< maxx;
}