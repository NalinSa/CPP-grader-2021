#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct puzzle
{
    /* data */
    vector<vector<int>> table = vector<vector<int>>(4, vector<int>(4));
    int row;
    int column;
};
puzzle puz;
set<vector<vector<int>>> vectorOfPuzzle;
auto cmp = [](const pair<int, pair<int, puzzle>> &lhs, const pair<int, pair<int, puzzle>> &rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second.first > rhs.second.first;
    else
        return lhs.first > rhs.first;
};
// pair<totalbest<time,puzzle>>
int howFar(puzzle &p)
{
    int far = 0;
    int value;
    int shoudbeROw;
    int shoudbeColumn;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (p.table[i][j] == 0)
                continue;
            else
            {
                value = p.table[i][j];
                shoudbeROw = (value - 1) / 4;
                shoudbeColumn = (value - 1) % 4;
                far += abs(i - shoudbeROw) + abs(j - shoudbeColumn);
            }
        }
    }
    // cout << "far = " << far << endl;
    return far;
}
bool isTheSame(puzzle &p)
{
    if (vectorOfPuzzle.find(p.table) != vectorOfPuzzle.end()) return true;
    vectorOfPuzzle.insert(p.table);
    return false;
}
int findWay()
{
    int bestway = 2000001;
    priority_queue<pair<int, pair<int, puzzle>>, vector<pair<int, pair<int, puzzle>>>, decltype(cmp)> pq(cmp);
    int far = howFar(puz);
    pq.push(make_pair(far, make_pair(0, puz)));
    int row = 0; int column = 0; int forcast; int time; 
    puzzle puzzForFind;
    while (!pq.empty())
    {
        forcast = pq.top().first;
        time = pq.top().second.first;
        puzzForFind = pq.top().second.second;
        row = puzzForFind.row;
        column = puzzForFind.column;
        pq.pop();
        // cout << "forcast = " << forcast << " bestway = " << bestway << endl;
        if (forcast > bestway)  break;
        if (isTheSame(puzzForFind)) continue;
        far = howFar(puzzForFind);
        if (far == 0)
        {
            if (time < bestway) bestway = time;
        }
        else
        {
            time++;
            if (row > 0)
            {
                swap(puzzForFind.table[row][column], puzzForFind.table[row - 1][column]);
                puzzForFind.row = row - 1;
                pq.push(make_pair(far + time, make_pair(time, puzzForFind)));
                swap(puzzForFind.table[row][column], puzzForFind.table[row - 1][column]);
                puzzForFind.row = row;
            }
            if (column > 0)
            {
                swap(puzzForFind.table[row][column], puzzForFind.table[row][column - 1]);
                puzzForFind.column = column - 1;
                pq.push(make_pair(far + time, make_pair(time, puzzForFind)));
                swap(puzzForFind.table[row][column], puzzForFind.table[row][column - 1]);
                puzzForFind.column = column;
            }
            if (row < 3)
            {
                swap(puzzForFind.table[row][column], puzzForFind.table[row + 1][column]);
                puzzForFind.row = row + 1;
                pq.push(make_pair(far + time, make_pair(time, puzzForFind)));
                swap(puzzForFind.table[row][column], puzzForFind.table[row + 1][column]);
                puzzForFind.row = row;
            }
            if (column < 3)
            {
                swap(puzzForFind.table[row][column], puzzForFind.table[row][column + 1]);
                puzzForFind.column = column + 1;
                pq.push(make_pair(far + time, make_pair(time, puzzForFind)));
            }
        }
    }
    return bestway;
}
int main()
{
    int x;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> x;
            if (x == 0)
            {
                puz.row = i;
                puz.column = j;
            }
            puz.table[i][j] = x;
        }
    }
    cout << findWay();
}