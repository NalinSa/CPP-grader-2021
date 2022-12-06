#include<iostream>
#include<vector>

using namespace std;
void findIdx(long long int& begin,long long int start,long long int stop,vector<long long int>& v,long long int& k,long long int& total){
    long long int m = (start+stop)/2;
    long long int count = 0;
    for(long long int i = begin;i<=m;i++){
        count += v[i];
    }
    long long int rang = count*k;
    count += rang;
    if(start==stop){
        cout << count << " ";
        if(count>total){
            count -= v[start];
        }
        count -= rang;
        cout << count << "\n";
        return;
    }
    if(count>=total){
        findIdx(begin,start,m,v,k,total);
    }
    else{
        findIdx(begin,m+1,stop,v,k,total);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long int n,m,k,x,idx;
    long long int total;
    cin >> n >> m >>k;
    vector<long long int> vec(n);
    for(long long int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
    }
    for(long long int i = 0;i<m;i++){
        cin >> idx >> total;
        findIdx(idx,idx,vec.size()-1,vec,k,total);
    }
}