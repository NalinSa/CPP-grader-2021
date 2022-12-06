#include<iostream>
#include<vector>
using namespace std;

int b_search(vector<int>&v, int k,int start,int stop){
    if(start==stop) {
        if(v[start]==k){
            return start;

        } 
        else if(v[start]>k){
            cout<< "more";
            return --start;
        }
        else {
            return -99;
        }
    }
    int m = (start+stop)>>1;
    if(v[m]>=k) return b_search(v,k,start,m);
    else return b_search(v,k,m+1,stop);

} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,x,y;
    cin >> a >> b;
    vector<int> vec(a);
    for(int i = 0;i!=a;i++){
        cin>>x;
        vec[i] = x;
    }
    for(int i = 0;i!=b;i++){
        cin>>y;
        int ans = b_search(vec,y,0,vec.size()-1);
        if(ans<=-1) cout << ans << "\n";
        else cout << vec[ans] << "\n";
    }
}