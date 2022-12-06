#include <iostream>
#include <map>
using namespace std;
int dpna[10001][1001];
int vec[10001];
int pressure(int& plus,int idx,int count){
    if(idx==-1)  return count>=plus? 0:10000000;
    if(dpna[idx][count]>0){
        return dpna[idx][count];
    }
    if(count<0){
        return 10000000;
    }
    dpna[idx][count] = min(vec[idx]+pressure(plus,idx-1,plus*2),pressure(plus,idx-1,count-1));
    return dpna[idx][count];

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w,x;
    cin >> n >> w;
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
    }
    cout << pressure(w,n-1,w);
}