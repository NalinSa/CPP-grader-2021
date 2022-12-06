#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,m,k,x,y,a,b;
int A[1001][1001];
int p[1001][1001];

int findP(int row1,int colum1){
    if(row1<0||colum1<0) return 0;
    return p[row1][colum1];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> x;
            A[i][j] = x;
        }
    }
    p[0][0] = A[0][0];
    for(int j = 1;j<m;j++){
        p[0][j] = p[0][j-1] + A[0][j];
    }
    for(int i = 1;i<n;i++){
        p[i][0] = p[i-1][0] + A[i][0];
        for(int j =1;j<m;j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }
    while(k--){
        cin >> x >> y >> a >> b;
        int ans = findP(a,b) - findP(x-1,b) - findP(a,y-1) + findP(x-1,y-1);
        cout << ans << "\n";
    }
}