#include <iostream>
using namespace std;
int store[200001][2];
int vec[200001][2];
int billboard(int& plus,int idx,int choose,int total){
    //cout << " idx =" << idx << "  ";
    if(idx<=-1||total<=0) {
        return 0;
    }
    if(store[idx][choose]>-1){
        return store[idx][choose];
    }
    store[idx][choose] = max(vec[idx][choose]+billboard(plus,idx-1-plus,(choose==1)? 0:1,total-1),billboard(plus,idx-1,choose,total));
        //cout << " return1:" << i << endl;
    return store[idx][choose];


}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w,k,x;
    cin >> n >> w >> k;
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i][0] = x;
        store[i][0] = -1;
    }
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i][1] = x;
        store[i][1] = -1;

    
    }
    int maxx = max(billboard(w,n-1,0,k),billboard(w,n-1,1,k));
    cout<< maxx;
}