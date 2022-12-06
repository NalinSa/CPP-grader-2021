#include <iostream>
#include <vector>
#include <map>
using namespace std;
int vec[200000];
int k;
int mss(int n){
    int suf = vec[0];
    int mss = vec[0];
    int count = 1;
    for(int i = 1;i<n;i++){
        if(count==k){
           suf = vec[i-k+1];
           count = 1;
            for(int j = i-k+2;j<si;j++){
               if(suf+vec[j]>vec[j]){
                count += 1;
                suf = suf + vec[j];
                }
                else{
                  count = 1;
                  suf = vec[j];
                }
            }
        }
        if(suf+vec[i]>vec[i]){
            count += 1;
            suf = suf + vec[i];
        }
        else{
            count = 1;
            suf = vec[i];
        }
        //cout << suf << endl;
        mss = max(mss,suf);
    } 
    return mss;
}
int main(){
    int n ,x;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
    }
    cout << mss(n);
}