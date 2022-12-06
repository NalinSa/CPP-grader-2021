#include <iomanip> 
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> member(n);
    vector<int> vec(m);
    for(int i = 0;i<m;i++){
        cin >> x;
        vec[i] = x;
    }
    sort(vec.begin(),vec.end());
     
    float d = 0;
    int idx = 0;
    for(auto &time:vec){
        member[idx] += time;
        d += member[idx];
        idx = (idx+1)%n;
    }
    d = (d/m);
    std::cout<<std::setprecision(3)<<d;
} 