#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {-1 ,1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, -1));

    int curX = 0;
    int curY = 0;
    int d = 3;

    int cnt = 1;
    int transCnt = 0;
    matrix[curY][curX] = cnt++;
    while(1)
    {
        int nextY = curY + dy[d];
        int nextX = curX + dx[d];

        if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > m-1 || matrix[nextY][nextX] != -1)
        {
            if(transCnt == 4) break;
            ++transCnt;
            if(d == 0)  d = 3;
            else if(d==1) d = 2;
            else if(d==2) d = 0;
            else if(d==3) d = 1;
        }
        else
        {
            transCnt = 0;

            curY += dy[d];
            curX += dx[d];

            matrix[curY][curX] = cnt++;
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0; iCol < m ;++iCol)
        {
            cout << matrix[iRow][iCol] <<' ';
        }
        cout << '\n';
    }

    return 0;
}