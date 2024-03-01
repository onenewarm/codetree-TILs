#include <iostream>
#include <cstring>

using namespace std;

struct Marble
{
    int maxWeight;
    int sumWeight;
    int num;
    int dir;
};

int n,m,t;

Marble matrix[51][51];
Marble nextMatrix[51][51];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1};

void Solve()
{
    memset(nextMatrix, 0, sizeof(Marble) * 51 * 51);
    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            if(matrix[iRow][iCol].num == 0) continue;
            
            int dir = matrix[iRow][iCol].dir;

            int ny = iRow + dy[dir];
            int nx = iCol + dx[dir];

            if(ny < 1 || nx < 1 || ny > n || nx > n)
            {
                matrix[iRow][iCol].dir = (dir + 2) % 4;
                ny = iRow;
                nx = iCol;
            }

            if(nextMatrix[ny][nx].maxWeight < matrix[iRow][iCol].maxWeight)
            {
                nextMatrix[ny][nx].maxWeight = matrix[iRow][iCol].maxWeight;
                nextMatrix[ny][nx].dir = matrix[iRow][iCol].dir;
            }
            else if(nextMatrix[ny][nx].maxWeight == matrix[iRow][iCol].maxWeight)
            {
                if(nextMatrix[ny][nx].num < matrix[iRow][iCol].num)
                {
                    nextMatrix[ny][nx].maxWeight = matrix[iRow][iCol].maxWeight;
                    nextMatrix[ny][nx].dir = matrix[iRow][iCol].dir;
                }
            }

            nextMatrix[ny][nx].num = max(matrix[ny][nx].num, matrix[iRow][iCol].num);
            nextMatrix[ny][nx].sumWeight += matrix[iRow][iCol].sumWeight;
        }
    }

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            nextMatrix[iRow][iCol].maxWeight = nextMatrix[iRow][iCol].sumWeight;
        }
    }

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            matrix[iRow][iCol] = nextMatrix[iRow][iCol];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;

    int num = 1;

    while(m--)
    {
        int r,c,w;
        char d;

        cin >> r >> c >> d >> w;

        int dir;

        if(d == 'U') dir = 0;
        else if(d == 'R') dir = 1;
        else if(d == 'D') dir = 2;
        else dir = 3;

        matrix[r][c] = {w, w, num++, dir};
    }

    while(t--)
    {
        Solve();
    }

    int cnt = 0;
    int maxWeight = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            if(matrix[iRow][iCol].num > 0)
            {
                ++cnt;
                maxWeight = max(maxWeight, matrix[iRow][iCol].sumWeight);
            }
        }
    }

    cout << cnt << ' ' << maxWeight;

    return 0;
}

/*

정사각형 격자판에 m개의 구슬이 있습니다.
격자는 벽으로 둘러싸 있습니다.
상하좌우로 이동이 가능합니다.
구슬마다 무게가 있습니다.
벽 부딪히면 반대로 방향전환에는 1초에 시간

충돌 발생 시, 구슬들은 전부 합쳐진다.
합쳐지면 하나의 구슬이 만들어지고, 이 구슬의 무게는 해당위치에 모인 모든 구슬의 합이 된다.
합쳐진 구슬들 중 가장 큰 번호가 매겨져 있는 놈이 방향을 결정한다. 번호도 가장 큰 것으로

t초가 지난 이후 여전히 격자 안에 남아있는 구슬의 개수와 가장 무거운 구슬의 무게를 출력해라.



*/