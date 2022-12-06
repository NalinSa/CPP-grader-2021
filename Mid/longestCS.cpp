#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool bo[1000][1000];
int store[1000][1000];
int cal(vector<set<int>>& v,int compare,int idx){
    if(bo[idx][compare]){
        return store[idx][compare];
    }
    if(idx==v.size()){
        //cout<< "turn 0  ";
        return 0;
    }
    int maxx = 0;
    for(auto& x :v[idx]){
        if(x>compare){
            maxx = max(1+cal(v,x,idx+1),maxx);
            break;
        }
    }
    maxx = max(cal(v,compare,idx+1),maxx);
    store[idx][compare] = maxx;
    bo[idx][compare] = true;
    return maxx;
}
int main(){
    string a,b;
    cin >> a >> b;
    vector<set<int>> eachIdx(b.length());
    for(int i = 0;i<b.length();i++){
        for(int j = 0;j<a.length();j++){
            if(a[j]==b[i]){
                eachIdx[i].insert(j);
            }
        }
    }
    int ans = cal(eachIdx,-1,0);
    cout << ans;
}