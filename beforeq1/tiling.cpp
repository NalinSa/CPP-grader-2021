#include<iostream>
#include <bits/stdc++.h>
#include<vector> 
using namespace std;
void tile(int size,int x,int y,int compx,int compy,vector<int>& count,int& c){
    //missing in 1st part
    if(size<=1) return;
    int xx = x-compx;
    int yy = y-compy;
    int oldx = x;
    int oldy = y;
    x = size/2-1+compx;
    y = size/2-1+compy;
    if(xx<size/2&&yy<size/2){
        count[c++] = 0;
        count[c++] = x;
        count[c++] = y;
        tile(size/2,oldx,oldy,compx,compy,count,c);
        tile(size/2,x+1,y,compx+size/2,compy,count,c);
        tile(size/2,x,y+1,compx,compy+size/2, count,c);
        tile(size/2,x+1,y+1,compx+size/2,compy+size/2,count,c);
    }
    //missing in 2nd part
    else if(xx>=size/2&&yy<size/2){
        count[c++] = 0;
        count[c++] = x;
        count[c++] = y;
        tile(size/2,x,y,compx,compy,count,c);
        tile(size/2,oldx,oldy,compx+size/2,compy,count,c);
        tile(size/2,x,y+1,compx,compy+size/2,count,c);
        tile(size/2,x+1,y+1,compx+size/2,compy+size/2,count,c);
    }
 //missing in 3rd part
    else if(xx<size/2&&yy>=size/2){
        count[c++] = 0;
        count[c++] = x;
        count[c++] = y;
        tile(size/2,x,y,compx,compy,count,c);
        tile(size/2,x+1,y,compx+size/2,compy,count,c);
        tile(size/2,oldx,oldy,compx,compy+size/2,count,c);
        tile(size/2,x+1,y+1,compx+size/2,compy+size/2,count,c);
    }
     //missing in 4th part
    else {
        count[c++] = 3;
        count[c++] = x;
        count[c++] = y;
        tile(size/2,x,y,compx,compy,count,c);
        tile(size/2,x+1,y,compx+size/2,compy,count,c);
        tile(size/2,x,y+1,compx,compy+size/2,count,c);
        tile(size/2,oldx,oldy,compx+size/2,compy+size/2,count,c);
    }
    
}
int main(){
    int l,x,y;
    vector<int> vec((l*l-1));
    cin >> l >> x >> y;
    int c = 0;
    tile(l,x,y,0,0,vec,c);

}