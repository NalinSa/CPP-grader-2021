#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> table;
int inf = 2000000;
int N,D;
void findDis(){
    for(int k = 0 ;k< N;k++){
        //cout << "k=========  " << k << endl;
        for(int i = 0 ; i<N;i++){
            //cout << "i =========  " << i << endl;
            if(table[i][k]==-1) continue;
            for(int j = 0; j <N ;j++){
                //cout << table[i][k] << " and " << table[k][j] << endl;
                if(table[k][j]==-1) continue;
                    //cout << "    Yes  "; 
                    if(table[i][j]==-1||table[i][j]>table[i][k]+table[k][j]){
                        table[i][j] = table[i][k]+table[k][j];
                    }
            }
        }
    }
}
int main(){
    cin >> N;
    table = vector<vector<int>>(N,vector<int>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin >> D;
            table[i][j] = D;
        }
    }
    findDis();
    int maxx = -1;
    for(int i = 0 ; i < N ; i++){
        if(table[0][i]>maxx){
            maxx = table[0][i];
        }
        if(table[0][i]==-1){
            maxx = -1;            
            break;
        }
    }
    if(maxx==-1){
        cout << -1;
    }
    else{
        cout << maxx;
    }
}