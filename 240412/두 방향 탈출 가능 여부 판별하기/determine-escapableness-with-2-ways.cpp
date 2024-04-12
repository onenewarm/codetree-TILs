#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> matrix;
vector<vector<int>> visit;

int dy[2] = {0, 1};
int dx[2] = {1, 0};

bool possibleFlag = false;

void DFS(int curRow, int curCol)
{
    if(curRow == n - 1 && curCol == m - 1)
    {
        possibleFlag = true;
        cout << 1;
        return;
    }

    for(int DCnt = 0 ; DCnt < 2 ; ++DCnt)
    {
        int nextY = curRow + dy[DCnt];
        int nextX = curCol + dx[DCnt];

        if(nextY < 0 || nextX < 0 || nextY > n - 1 
        || nextX > m - 1 || visit[nextY][nextX] == 1 || matrix[nextY][nextX] == 0) continue;

        visit[nextY][nextX] = 1;
        DFS(nextY, nextX);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    matrix.resize(n, vector<int>(m));
    visit.resize(n, vector<int>(m, 0));

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    visit[0][0] = 1;
    DFS(0,0);

    if(possibleFlag == false) cout << 0;

    return 0;
}