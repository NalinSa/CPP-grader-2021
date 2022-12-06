#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> table;
int N, E, minColor;

bool checkCorrect(vector<int> &color, int &idx)
{
    for (int i = 0; i < idx; i++)
    {
        if (table[idx][i] == 1)
        {
            if (color[i] == color[idx])
                return false;
        }
    }
    return true;
}
int max_element(vector<int> &vec)
{
    int maxEle = 0;
    for (auto &x : vec)
    {
        maxEle = max(maxEle, x);
    }
    return maxEle;
}
void colorDec(int idx, vector<int> vec)
{
    if (idx == N)
        minColor = min(max_element(vec), minColor);
    else
    {
        for (int i = 1; i < minColor; i++)
        {
            vec[idx] = i;
            if (checkCorrect(vec, idx))
            {
                colorDec(idx + 1, vec);
            }
        }
    }
}
int main()
{
    cin >> N >> E;
    minColor = N + 1;
    int x, y;
    table = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        table[x][y] = 1;
        table[y][x] = 1;
    }
    vector<int> vec(N, 0);
    colorDec(0, vec);
    cout << minColor;
}