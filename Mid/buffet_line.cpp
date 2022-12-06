#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int f,w,n,x;
    cin >> f >> w >> n;
    vector<int> vec(f);
    for(int i = 0;i<vec.size();i++){
        cin >> x;
        vec[i] = x;
    }
    sort(vec.begin(),vec.end());
    int idx = 0;
    int total = 0;
    for(auto &x:vec){
        if(x>idx){
            idx = x+w*2;
            total += 1;
        }
    }
    cout << total;
}