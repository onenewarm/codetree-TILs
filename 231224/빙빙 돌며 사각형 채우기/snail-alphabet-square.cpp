#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n,m;
    cin >> n >> m;

    int loopCnt = n*m;
    
    char matrixVal = 0;

    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};

    int curX = -1;
    int curY = 0;

    int iDir = 1;

    char matrix[101][101] = {0,};

    while(loopCnt--)
    {
        int nextY = curY + dy[iDir];
        int nextX = curX + dx[iDir];

        if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > m-1 || matrix[nextY][nextX] != 0) iDir = (iDir + 1) % 4;

        curY = curY + dy[iDir];
        curX = curX + dx[iDir];

        matrix[curY][curX] = (matrixVal % 26) + 'A';
        ++matrixVal;
    }

    for(int iRow = 0; iRow < n ;++iRow)
    {
        for(int iCol = 0; iCol < m ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }

    return 0;
}