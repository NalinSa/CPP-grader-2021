#include<iostream>
#include<vector>
using namespace std;
void mergeCount(vector<int> &v,int& num,int start,int stop){
    if(num==0){
        return;
    }
    if(num<0){
        return;
    }
    if(start<stop-1){
        int m = (start+stop)/2;
         //cout<<m-1<<" "<<m<<endl;
        //cout<<v[m-1]<<" "<<v[m]<<endl;
        swap(v[m-1],v[m]);
        num -=  2;
        mergeCount(v,num,start,m);
        mergeCount(v,num,m,stop);
    }

}
int main(){
    int x,y;
    cin>>x>>y;
    vector<int> vec(x);

    for(int i=1;i<=x;i++){
        vec[i-1] = i;
    }
    mergeCount(vec,--y,0,vec.size());
    cout<< "\n";
    if(y==0){
        for(auto &x:vec){
            cout<<x<<" ";
        }
    }
    else cout<< -1;


}