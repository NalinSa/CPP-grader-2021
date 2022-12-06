#include <iostream>
#include <vector>
using namespace std;
vector<vector<double>> exchangeTable;
int K,ss;
double price;
bool check(){
    for(int i = 0 ; i < ss ; i++){
        for(int j = 0 ; j < ss ; j++){
            for(int k = 0 ; k < ss ; k++){
                exchangeTable[i][j] = max(exchangeTable[i][j],exchangeTable[i][k]*exchangeTable[k][j]);
            }
        }
    }
    for(int i = 0 ; i < ss ; i++){
        if(exchangeTable[i][i]>1){
            return false;
        }
    }
    return true;
    
}
int main(){
    cin >> K;
    while(K--){
        cin >> ss;
        exchangeTable = vector<vector<double>>(ss,vector<double>(ss));
        for(int i = 0 ; i < ss ; i++){
            for(int j = 0 ; j < ss ; j++){
                cin >> price;
                exchangeTable[i][j] = price;
            }
        }
        if(check()){
            cout << "NO\n"; 
        }
        else{
            cout << "YES\n";
        }
    }
}