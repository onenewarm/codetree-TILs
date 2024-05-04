#include <iostream>

using namespace std;

int n;
int board[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visit[101][101];

int ansPangCnt = 0, ansMAXPang = 0;

void DFS(int num ,int row, int col, int* curBlockCnt)
{
    for(int iDir = 0 ; iDir < 4 ; ++iDir)
    {
        int nextRow = row + dy[iDir];
        int nextCol = col + dx[iDir];
        if(nextRow < 0 || nextCol < 0 || nextRow > n - 1 || nextCol > n - 1 
        || board[nextRow][nextCol] != num || visit[nextRow][nextCol] == 1) continue;

        visit[nextRow][nextCol] = 1;

        (*curBlockCnt)++;

        DFS(board[nextRow][nextCol] ,nextRow, nextCol, curBlockCnt);
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> board[iRow][iCol];
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(visit[iRow][iCol] != 0) continue;

            visit[iRow][iCol] = 1;
            
            int curBlockCnt = 1;
            DFS(board[iRow][iCol] ,iRow, iCol, &curBlockCnt);

            ansMAXPang = max(ansMAXPang, curBlockCnt);

            if(curBlockCnt >= 4)
            {
                ansPangCnt++;
            }
        }
    }

    cout << ansPangCnt << ' ' << ansMAXPang;

    return 0;
}