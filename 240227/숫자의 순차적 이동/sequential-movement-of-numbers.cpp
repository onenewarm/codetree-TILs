#include <iostream>

using namespace std;

int n,m;
int matrix[20][20];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void SearchPos(pair<int,int>* dest, int key)
{
    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(matrix[iRow][iCol] == key)
            {
                *dest = {iRow, iCol};
                return;
            }
        }
    }
}

void Solve()
{
    int curNum = 1;
    for(int iCnt = 0 ; iCnt < n * n ; ++iCnt)
    {
        pair<int,int> curPos;
        SearchPos(&curPos, curNum);

        int maxNum = -1;
        pair<int,int> maxNumPos;

        for(int iD = 0 ; iD < 8 ; ++iD)
        {
            int ny = curPos.first + dy[iD];
            int nx = curPos.second + dx[iD];

            if(ny < 0 || nx < 0 || ny > n-1 || nx > n-1 || maxNum > matrix[ny][nx]) continue;

            maxNum = matrix[ny][nx];
            maxNumPos = {ny, nx};
        }

        int tmp = matrix[maxNumPos.first][maxNumPos.second];
        matrix[maxNumPos.first][maxNumPos.second] = matrix[curPos.first][curPos.second];
        matrix[curPos.first][curPos.second] = tmp;
        ++curNum;
    }



}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    
    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    while(m--) Solve();

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';        
        }
        cout << '\n';
    }

    return 0;
}

/*

정사각형 격자가 주어진다.
m번의 걸쳐서 숫자들을 이동한다.
한 번의 턴에는 숫자 1이 적힌 위치에서 숫자 n*n이 적힌 위치까지 순서대로 하나씩 보면ㅅ ㅓ특정 조건에 맞춰 다들 이동한다.

8방향으로 인접한 칸들 중 가장 큰 숫자와 가운데 칸의 숫자를 교환한다.
*/