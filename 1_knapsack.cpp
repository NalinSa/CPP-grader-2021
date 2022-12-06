#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>  
using namespace std;
double setWeight;
int numOfItem;
vector<double> vecValue;
vector<double> vecWeight;
double sumOfValue(vector<int>& ch,int& total){
    double values = 0;
    for(int i = 0;i<=total;i++){
        values += vecValue[i]*ch[i];
    }
    return values;
}
double sumOfWeight(vector<int>& ch,int& total){
    double weight = 0;
    for(int i = 0;i<=total;i++){
        weight += vecWeight[i]*ch[i];
    }
    return weight;
}
double predictMaxValue(int idx,double remainWeight){
    priority_queue<pair<double,int>> ratio_idx;
    for(int i = idx+1;i<numOfItem;i++){
        ratio_idx.push(make_pair(vecValue[i]/vecWeight[i],i));
    }
    double predicted = 0;
    double ratio;
    int index;
    while(!ratio_idx.empty()){
        ratio = ratio_idx.top().first;
        index = ratio_idx.top().second;
        ratio_idx.pop();
        if(remainWeight==0) break;
        double minW = min(remainWeight,vecWeight[index]);
        predicted += ratio*minW;
        remainWeight -= minW;
    }
    return predicted;
}
int main(){
    cin >> setWeight >> numOfItem;
    double x;
    vecValue = vector<double>(numOfItem);
    vecWeight = vector<double>(numOfItem);
    for(int i = 0;i<numOfItem;i++){
        cin >> x;
        vecValue[i] = x;
    }
    for(int i = 0;i<numOfItem;i++){
        cin >> x;
        vecWeight[i] = x;
    }
    priority_queue<pair<double,pair<vector<int>,int>>> pq;
    vector<int> choose(numOfItem,0);
    pq.push(make_pair(predictMaxValue(-1,setWeight),make_pair(choose,-1)));
    double valueMax = -1;
    double predicted;
    
    int idxChosen;
    double sumValue;
    double sumWeight;
    while(!pq.empty()){
        predicted = pq.top().first;
        choose = pq.top().second.first;
        idxChosen = pq.top().second.second;
        pq.pop();
        if(predicted<=valueMax) break;
        sumValue = sumOfValue(choose,idxChosen);
        if(idxChosen==numOfItem-1){       
            if(sumValue>valueMax) valueMax = sumValue; 
        }
        else{
            sumWeight = sumOfWeight(choose,idxChosen);
            double tryPlus = sumWeight+vecWeight[idxChosen+1];
            if(tryPlus<=setWeight){
                choose[idxChosen+1] = 1;
                pq.push(make_pair(sumValue+vecValue[idxChosen+1]+predictMaxValue(idxChosen+1,setWeight-tryPlus),make_pair(choose,idxChosen+1)));
            }
            choose[idxChosen+1] = 0;
            pq.push(make_pair(sumValue+predictMaxValue(idxChosen+1,setWeight-sumWeight),make_pair(choose,idxChosen+1)));
        }

    }
    cout << fixed << setprecision(4) << valueMax;
}