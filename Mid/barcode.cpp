#include<iostream>
#include<vector>
using namespace std;
int dat[30][30][30][30] = {};
bool boo[30][30][30][30];
int barcode(int total,int count,int& b,int c,int before){
    if(c<0) return 0;
    if(count>b) return 0;
        if(total==0){
        if(c!=0){
          return 0;
        }else{
          return 1;
        }
    }
    if(boo[total][count][c][before]){
        return dat[total][count][c][before];
    }
    boo[total][count][c][before] = true;
    if(before==0){
        dat[total][count][c][before] = barcode(total-1,count+1,b,c, 0)+ barcode(total-1,1,b,c-1,1);
        return dat[total][count][c][before];
    }
    else{
        dat[total][count][c][before] = barcode(total-1,1,b,c-1,0)+barcode(total-1,count+1,b,c,1);
        return dat[total][count][c][before];
    }  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    cout<< barcode(--a,1,b,c,0);
}
