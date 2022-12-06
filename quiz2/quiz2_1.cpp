#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n;
int dp[10000001][3];
//true = 1 falses =0
long long int howmuch(int idx){
    if(idx==1) return 1;
    return 3*howmuch(idx-1)+2*howmuch(idx-1)+2*howmuch(idx-1);


}
int main(){
    cin >> n;
    cout << (howmuch(n))%100000007;
}