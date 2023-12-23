#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n,m;
    cin >> n >> m;

    int matrix[100][100] = {0, };
    
    int cnt = n*m;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = { 0, 1, 0, -1};

    int curX = 0;
    int curY = -1;

    int iDir = 2;

    int matrixVal = 1;

    while(cnt--)
    {
        int nextY = curY + dy[iDir];
        int nextX = curX + dx[iDir];

        if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > m-1 || matrix[nextY][nextX] != 0) iDir = (iDir+3) % 4;

        curX += dx[iDir];
        curY += dy[iDir];

        matrix[curY][curX] = matrixVal++;
    }

    for(int iRow = 0; iRow< n;++iRow)
    {
        for(int iCol = 0; iCol <m ;++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

/*
달팽이 모양으로 matrix를 채우기
현재 시작 방향은 '하'

시계 반대 방향으로 dx가 움직인다.
그렇다면 그냥 시계방향으로 dy, dx를 만들고 +3 % 4 방식이 좋아보인다



*/