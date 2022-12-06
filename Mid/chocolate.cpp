#include <iostream>
#include <vector>
using namespace std;
int store[10001];
int boo[10001];
int chocolate(vector<int>& vec,int idx){
    if(idx<=0) return 0;
    if(boo[idx]) {
        return store[idx];
    }
    int total = 0;
    for(auto&x : vec){
        if(idx==x){
             total = (total + 1 % 1000003) % 1000003;
        }
        total = (total+chocolate(vec,idx-x)% 1000003) % 1000003;
    }
    boo[idx] = true;
    store[idx] = total;
    return total;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,x;
    cin >> n>> k;
    vector<int> vec(k);
    for(int i = 0;i<k;i++){
        cin >> x;
        vec[i]= x;
    }
    cout << chocolate(vec,n);

}