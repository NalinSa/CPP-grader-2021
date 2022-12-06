#include<bits/stdc++.h>
using namespace std;
void insertion_dc(vector<int> &a,int l,int r) {

   if(l==r) return;
   for(int i=r-1;i>=l;--i){
       if(a[i]>a[i+1])swap(a[i],a[i+1]);
    }
    for(auto &x:a){
        cout << x <<",";
           
    }
    cout << endl;
    
   insertion_dc(a,l,r-1);
}

int main(){
    vector<int> vec = {5,4,7,0,8,6,3,2};
    insertion_dc(vec,0,7);
}