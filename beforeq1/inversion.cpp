#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int start,int m,int stop,vector<int>& tmp,int& count){
    int bi = start;
    int ci = m+1;
    for(int i = start;i<=stop;i++){
        if(bi>m){tmp[i]=v[ci++];}
        else if(ci>stop){tmp[i]=v[bi++];}
        else if(v[ci]<v[bi]){
            //cout<< ci << " "<< bi<< endl;
           // cout<< v[ci] << " "<< v[bi]<< endl;
            count += (m-bi+1);
            //cout<< "count= " << count << endl;
            tmp[i]= v[ci++];
        }
        else{
            tmp[i]=v[bi++];
        }
    }
    for(int i =start;i<=stop;i++){v[i]=tmp[i];}
}
void merge_sort(vector<int> &v,int start,int stop,vector<int>& tmp,int& count){
    if(start<stop){
        int m = (start+stop)>>1;
        merge_sort(v,start,m,tmp,count);
        merge_sort(v,m+1,stop,tmp,count);
        merge(v,start,m,stop,tmp,count);
    }
}
int main(){
    int N,x;
    int count = 0;
    cin >> N;
    vector<int> vec(N);
    vector<int> v(N);
    for(int i = 0; i<N;i++){
        cin>>x;
        vec[i] = x; 
    }
    merge_sort(vec,0,vec.size()-1,v,count);
    cout << count;
}
