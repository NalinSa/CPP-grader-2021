#include <iostream>
#include <vector>
using namespace std;
int N,M,K;
int minVal = 2000000;
vector<int> setOfVal;

void sumSubSet(int idx,int vec,int totalChoose){
    if(totalChoose==M) {
        minVal = min(minVal,abs(K-vec));
    }
    else{
        //cout << "--------------------------idx is  " << idx << endl;
        if(idx==N) return;
        if(totalChoose<M){
            if(vec>K&&vec-K>minVal) {
                return;
            }
            else{
                sumSubSet(idx+1,vec+setOfVal[idx],totalChoose+1);
            }
        }
        if(N-idx>totalChoose){
          sumSubSet(idx+1,vec,totalChoose);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    int x;
    setOfVal = vector<int>(N);
    for(int i = 0;i<N;i++){
        cin >> x;
        setOfVal[i] = x;
    }
    sumSubSet(0,0,0);
    cout << minVal;
}