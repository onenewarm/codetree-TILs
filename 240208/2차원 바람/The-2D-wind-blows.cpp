#include <iostream>

using namespace std;

int N,M,Q;
int matrix[101][101];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void Shift(int r1, int c1, int r2, int c2)
{
    int tmp = matrix[r1][c2];
    for(int iCol = c2 ; iCol > c1 ; --iCol)
    {
        matrix[r1][iCol] = matrix[r1][iCol - 1];
    }

    for(int iRow = r1 ; iRow < r2 ; ++iRow)
    {
        matrix[iRow][c1] = matrix[iRow+1][c1];
    }

    for(int iCol = c1 ; iCol < c2 ; ++iCol)
    {
        matrix[r2][iCol] = matrix[r2][iCol + 1];
    }

    for(int iRow = r2 ; iRow > r1 + 1 ; --iRow)
    {
        matrix[iRow][c2] = matrix[iRow-1][c2];
    }

    matrix[r1 + 1][c2] = tmp;
}

void Update(int r1, int c1, int r2, int c2)
{
    int tmpMatrix[101][101];

    for(int iRow = r1 ; iRow <= r2 ; ++iRow)
    {
        for(int iCol = c1 ; iCol <= c2 ; ++iCol)
        {
            int sum = matrix[iRow][iCol];
            int sumCnt = 1;

            for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
            {
                int nextY = iRow + dy[iCnt];
                int nextX = iCol + dx[iCnt];

                if(nextY < 0 || nextX < 0 || nextY > N -1 || nextX > M -1) continue;

                ++sumCnt;
                sum += matrix[nextY][nextX];
            }

            tmpMatrix[iRow][iCol] = sum / sumCnt;
        }
    }

    for(int iRow = r1 ; iRow <= r2 ; ++iRow)
    {
        for(int iCol = c1 ; iCol <= c2 ; ++iCol)
        {
            matrix[iRow][iCol] = tmpMatrix[iRow][iCol];
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M >> Q;

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0 ; iCol < M ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    while(Q--)
    {
        int r1, c1, r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        --r1; --c1; --r2; --c2;

        Shift(r1,c1,r2,c2);

        Update(r1,c1,r2,c2);
    }

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0 ; iCol < M ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
고급 요구사항 :
N * M 행렬이 있다. 요소는 0 ~ 9
Q번의 바람이 분다.

바람 : 특정 직사각형 영역의 경계에 있는 숫자들을 시계 방향으로 한 칸씩 shift하고,
직사각형 내 영역에 있는 값들을 각각 자신의 위치를 기준으로 자신과 인접한 원소들의 평균 값으로 바꾼다.

*/