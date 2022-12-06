#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char>> mapPacman;
vector<pair<int,pair<int,int>>> time_position;
vector<vector<bool>> table;
vector<vector<int>> visited;
int total;
int R, C, n, T, r , c,ti, ri , ci ;
char ch;
void DijkstraPeople(int row, int column, int time){
    //table =  vector<vector<bool>>(R,vector<bool>(C,false));
    if(!table[row][column]){
    table[row][column] = true;
    total++;
    //cout << "People: Row = " << row << " Column = " << column << " Total = " << total << " Time= " << time << endl;
    }
    if(time>0&&time>visited[row][column]){
        visited[row][column]= time;
        if(row-1>=0&&mapPacman[row-1][column]!='#'){
            DijkstraPeople(row-1,column,time-1);
        }
        if(column-1>=0&&mapPacman[row][column-1]!='#'){
            DijkstraPeople(row,column-1,time-1);
        }
        if(row+1<R&&mapPacman[row+1][column]!='#'){
            DijkstraPeople(row+1,column,time-1);
        }
        if(column+1<C&&mapPacman[row][column+1]!='#'){
            DijkstraPeople(row,column+1,time-1);
        }
    }
}
void DijkstraGhost(int row, int column, int time){
    //table =  vector<vector<bool>>(R,vector<bool>(C,false));
    if(table[row][column]){
        table[row][column] = false;
        total--;
        //cout << "Ghost Row = " << row << " Column = " << column << " Total = " << total << " Time= " << time << endl;
    }
    if(time>0&&time>visited[row][column]){
        visited[row][column]= time;
        if(row-1>=0&&mapPacman[row-1][column]!='#'){
            DijkstraGhost(row-1,column,time-1);
        }
        if(column-1>=0&&mapPacman[row][column-1]!='#'){
            DijkstraGhost(row,column-1,time-1);
        }
        if(row+1<R&&mapPacman[row+1][column]!='#'){
            DijkstraGhost(row+1,column,time-1);
        }
        if(column+1<C&&mapPacman[row][column+1]!='#'){
            DijkstraGhost(row,column+1,time-1);
        }
    }
}
int main(){
    int e;
    //cout << "want e" ;
    cin >> e;
    while(e--){
        //cout << "for round = " << e;
        cin >> R >> C >> n >> T >> r >> c;
        total = 0;
        time_position = vector<pair<int,pair<int,int>>>();
        for(int i = 0;i<n;i++){
            //cout << "for i(n) = " << i;
            cin >> ti >> ri >> ci; 
            time_position.push_back(make_pair(ti,make_pair(ri,ci)));
        }
        mapPacman = vector<vector<char>>(R,vector<char>(C));
        for(int i = 0;i<R;i++){
            //cout << "for row = " << i;
            for(int j = 0;j<C;j++){
                //cout << "for column = " << j;
                cin >> ch;
                mapPacman[i][j] = ch;
            }
        }
        table =  vector<vector<bool>>(R,vector<bool>(C,false));
        visited = vector<vector<int>>(R,vector<int>(C,-1));
        DijkstraPeople(r,c,T);
        visited = vector<vector<int>>(R,vector<int>(C,-1));
        for(int i = 0;i<time_position.size();i++){
            pair<int,pair<int,int>> ghost = time_position[i];
            DijkstraGhost(ghost.second.first,ghost.second.second,T-ghost.first);
        }
        if(total>0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }
}