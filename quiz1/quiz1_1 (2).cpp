#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
void permutation(vector<int>&v,int idx,vector<bool>&tmp,map<int,set<int>>& compare){
    if(idx==v.size()){
        for(auto &x:v){
            cout << x << " ";
        }
        cout<< "\n";
    }
    for(int i=0;i<tmp.size();i++){
        if(!tmp[i]){
            v[idx] = i;
            tmp[i] = true;
            int t = true;
            if(compare.find(i)!=compare.end()){
                for(auto &num:compare[i]){
                    //cout<< num<<"ha"<<endl;
                    if(tmp[num]==false){
                        t = false;
                        break;
                    }
                }
            }
            if(t) {permutation(v,idx+1,tmp,compare);}
            tmp[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x,y,one,two;
    cin>>x>>y;
    vector<int> vec(x);
    vector<bool> tmp(x,false);
    map<int,set<int>> compare;
    for(int i = 0;i<y;i++){
        cin >> one >> two;
        compare[two].insert(one);
    }
    permutation(vec,0,tmp,compare);

}