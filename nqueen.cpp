#include <iostream>
#include <vector>
using namespace std;
int n;
int invalid(vector<int> &column, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (abs(i - m) == abs(column[i] - column[m])) return false;
    }
    return true;
}
int queen(vector<int> column, int m)
{
    if (m == n) return 1;
    int total = 0;
    for (int i = m; i < n; i++)
    {
        swap(column[i], column[m]);
        if (invalid(column, m)) total += queen(column, m + 1);
        swap(column[i], column[m]);
    }
    return total;
}
int main()
{

    cin >> n;
    vector<int> columnEachQueen(n);
    for (int i = 0; i < n; i++)
    {
        columnEachQueen[i] = i;
    }
    cout << queen(columnEachQueen,0);
}