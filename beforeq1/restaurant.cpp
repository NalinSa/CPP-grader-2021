#include<iostream>
#include<vector>
using namespace std;
long long int b_search(vector<long long int>&v, long long int k,long long int start,long long int stop){
    long long int m = (start+stop)>>1;
    long long int total = 0;
    //long long int trueNum = m*v[0];
    for(auto &x:v){
        total += m/x;
        total++;
    }
    if(start==stop) {
        cout<< total<< "ha"<< endl; 
        return m;
    }
    if(total>=k) return b_search(v,k,start,m);
    else return b_search(v,k,m+1,stop);

} 
int main(){
    long long int a,b,x,y;
    cin >> a >> b;
    vector<long long int> vec(a);
    for(long long int i = 0;i!=a;i++){
        cin>>x;
        vec[i] = x;
    }
    for(long long int i = 0;i!=b;i++){
        cin>>y;
        long long int ans = b_search(vec,y,0,y*vec[0]);
        cout<<ans<<endl;
    }
}