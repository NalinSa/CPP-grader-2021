#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int scanVirus(int start,int stop,vector<int>& v,int& num){
    //cout<< stop-start;
    if(stop-start==1){
        int count = 0;
        for(int j = start;j<=stop;j++){
            if(v[j]==1){
                count++;
            }
        }
        return count;
    }
    int m = (start+stop)>>1;
    int left = scanVirus(start,m,v,num);
    int right = scanVirus(m+1,stop,v,num);
    if(abs(left-right)>1) num++;
    return left + right;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,x,num;
    num = 0;
    cin>>n>>k;
    int sum = 1;
    while(k--){
        sum*=2;
    }
    vector<int> vec(sum);
    while(n--){
        for(int i = 0;i<sum;i++){
            cin>>x;
            vec[i] = x;
        }
        scanVirus(0,vec.size()-1,vec,num);
        if(num>0){
            cout<< "no\n";
        }
        else{
            cout<< "yes\n";
        }
        num = 0;
    }
}