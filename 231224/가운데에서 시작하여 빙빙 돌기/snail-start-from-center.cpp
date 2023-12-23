#include <iostream>

using namespace std;

int matrix[101][101];

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    int curX = n;
    int curY = n-1;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0 , -1};

    int loopCnt = n*n;
    int iDir = 3;

    int matrixVal = n*n;

    while(loopCnt--)
    {
        int nextY = curY + dy[iDir];
        int nextX = curX + dx[iDir];

        if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > n-1 || matrix[nextY][nextX] != 0) iDir = (iDir + 1) % 4;

        curY += dy[iDir];
        curX += dx[iDir];

        matrix[curY][curX] = matrixVal--;
    }

    for(int iRow = 0; iRow < n;++iRow)
    {
        for(int iCol = 0; iCol < n;++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }

    return 0;
}