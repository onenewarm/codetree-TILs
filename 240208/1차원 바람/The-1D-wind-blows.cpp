#include <iostream>

using namespace std;

int N,M,Q;
int matrix[101][101];
int iFirstCols[101];

void Shift(int targetRow, char dir)
{
    if(dir == 'L') iFirstCols[targetRow] = (iFirstCols[targetRow] + M - 1 ) % M;
    else iFirstCols[targetRow] = (iFirstCols[targetRow] + 1) % M; 
}

bool Check(int curRow, int targetRow)
{
    if(targetRow < 0 || targetRow > N-1) return false;

    for(int iCnt = 0 ; iCnt < M ; ++iCnt)
    {
        int iCur = (iFirstCols[curRow] + iCnt) % M;
        int iTarget = (iFirstCols[targetRow] + iCnt) % M;

        if(matrix[curRow][iCur] == matrix[targetRow][iTarget]) return true;
    }
    return false;
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
        int targetRow;
        char dir;

        cin >> targetRow >> dir;

        --targetRow;

        Shift(targetRow, dir);

        int curRow = targetRow;
        char curDir = dir;

        while(Check(curRow, curRow - 1))
        {
            if(curDir == 'L') curDir = 'R';
            else curDir = 'L';

            --curRow;

            Shift(curRow, curDir);
        }

        curRow = targetRow;
        curDir = dir;

        while(Check(curRow, curRow + 1))
        {
            if(curDir == 'L') curDir = 'R';
            else curDir = 'L';

            ++curRow;

            Shift(curRow, curDir);
        }

    }

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = iFirstCols[iRow] ; iCol < M + iFirstCols[iRow] ; ++iCol)
        {
            cout << matrix[iRow][iCol % M] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

/*
고급 요구사항 :
NxM 행렬이 있다. 요소는 0 ~ 9이다.

Q번의 연산이 발생한다.
연산 : 행의 원소들을 왼쪽 혹은 오른쪽으로 한 칸 씩 밀어서 shift 한다. -> 1 2 3 / 3 1 2
위 아래로도 영향이 발생한다.
연산이 수행되는 행에서 순차적으로 위 아래 방향으로 전파가 되며 전파 방향이 바뀌는 경우는 없다.
전파가 이어질 조건 : 현재 행과 나아가는 행에서 단 하나라도 같은 열에 같은 숫자가 적혀있는 경우
현재 행의 연산방향 반대로 전파된 행의 연산이 발생한다.


*/