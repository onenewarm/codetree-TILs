#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char matrix[21][21];
int N;
int totalCoin;

pair<int,int> positions[10];
pair<int,int> endPos;

int res = 2147483647;

void MinPath(int coinCount, int curPos, int curMoveCnt)
{
    if(coinCount == 3)
    {
        curMoveCnt += abs(positions[curPos].first - endPos.first) + 
                        abs(positions[curPos].second - endPos.second);
        res = min(res, curMoveCnt);
        return;
    }

    for(int nextPos = curPos + 1 ; nextPos <= totalCoin ; ++nextPos)
    {
        if(coinCount + 1 + (totalCoin - nextPos) < 3) return; 

        int moveCnt = abs(positions[curPos].first - positions[nextPos].first) + 
                        abs(positions[curPos].second - positions[nextPos].second);
        MinPath(coinCount + 1, nextPos, curMoveCnt + moveCnt);
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        cin >> matrix[iRow];
    }

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0 ; iCol < N ; ++iCol)
        {
            if(matrix[iRow][iCol] != '.')
            {
                if(matrix[iRow][iCol] == 'S') positions[0] = {iRow, iCol};
                else if(matrix[iRow][iCol] == 'E') endPos = {iRow, iCol};
                else
                {
                    positions[matrix[iRow][iCol] - '0'] = {iRow, iCol};
                    totalCoin = max(totalCoin, matrix[iRow][iCol] - '0');
                }
            }
        }
    }

    MinPath(0, 0, 0);

    cout << res;

    return 0;
}

/*

1번은 무조건 s에서 1로 가야함.
그렇다면~
2차원 배열로 테이블을 만들 수 있을 것 같다.
s에서 1 -> 2,3 -> (3 / 4)
s에서 2, 1에서 2 이런식으로

테이블을 만들 필요가 있는가?

백트래킹으로 볼 것이다.
사실상 1은 한 번 계산이 되고 재활용 되지 않는다.
재활용 되지 않는 부분이 있다.

각각의 위치는 맨하탄 방식으로 이동하는 횟수를 알 수 있다.

*/