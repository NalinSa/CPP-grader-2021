#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
bool virus_scan(vector<int>&v,int start,int stop){
    if(stop-start==1){
        if(v[start]==0&&v[stop]==1){
            return true;
        }
        else if(v[start]==1&&v[stop]==0){
            return false;
        }
        else if(v[start]==1&&v[stop]==1){
            return false;
        }        
        else {
            return false;
        }
    }
    
    int m = (start+stop)>>1;
    
    bool left = virus_scan(v,start,m);
    bool right = virus_scan(v,m+1,stop);
    vector<int> tmp(v);
    
    for(int i = m, j = start;i>=start;i--,j++){
        tmp[j] = v[i];
    }
    bool left_reverse = virus_scan(tmp,start,m);
    return (left&&right)||(left_reverse&&right);


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,xx;
    cin>>n>>k;
    int power = 1;
    while(k--){
        power*=2;
    }
    vector<int> vec(power);
    while(n--){
        for(int i = 0;i<power;i++){
            cin>>xx;
            vec[i]=xx;
        }
        bool ans = virus_scan(vec,0,vec.size()-1);
        if(ans){
            cout<< "yes\n";
        }
        else cout<< "no\n";
    }
}