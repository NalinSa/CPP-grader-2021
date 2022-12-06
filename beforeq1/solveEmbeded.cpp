#include<iostream>
#include<vector>
using namespace std;
int main(){
    string x;
    cin >> x;
    string y = "";
    int count = 0;
    int i = 0;
    while(i<x.size()){
        //cout<< i;
        if(count==0){
            //cout<< "start";
            y+= 's';
            count++;
        }
        else if(count>0&&count<9){
            //cout<< count;
            y += x[i];
            count++;
        }
        else{
            //cout<< "stop";
            y += 't';
            while(x[i]=='1'){
                i++;
            }
            i-=8;
            count = 0;
        }
        i+=8;
    }
    cout<<endl<< "    is   ";
    cout << y;
}