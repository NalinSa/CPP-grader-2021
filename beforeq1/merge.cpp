#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int start, int m, int stop,vector<int> &tmp) {
int bi = start; //index of B
int ci = m+1; //index of C
for (int i = start; i<= stop;i++) {
if (ci > stop) { tmp[i] = v[bi++]; continue; }
if (bi > m) { tmp[i] = v[ci++]; continue; }
tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
}
for (int i = start; i<= stop;i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v,int start, int stop,vector<int> &tmp) {
if (start < stop) {
int m = (start + stop) >> 1;
merge_sort(v,start,m,tmp);
merge_sort(v,m+1,stop,tmp);
merge(v,start,m,stop,tmp);
    for(auto &x:v){
            cout << x;
        }
        cout << "\n";
}
}
int main(){
    vector<int> vec = {2,5,6,9,7,1,3};
    vector<int> tmp(vec.size());
    merge_sort(vec,0,6,tmp);
}