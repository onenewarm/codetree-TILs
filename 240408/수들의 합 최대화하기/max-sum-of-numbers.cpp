#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> matrix;
int colVisit[10];

int res = 0;
int curSum = 0;

void Choose(int iCurPos)
{
    if(iCurPos == n)
    {
        res = max(res, curSum);
        return;
    }

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        if(colVisit[iCol] != 0) continue;
        
        curSum += matrix[iCurPos][iCol];
        colVisit[iCol] = 1;

        Choose(iCurPos + 1);
        
        curSum -= matrix[iCurPos][iCol];
        colVisit[iCol] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    matrix.resize(n, vector<int>(n));

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Choose(0);

    cout << res;

    return 0;
}

/*

visit의 조건만 바뀐 문제이다.
선택을 행을 기준으로 하고, 선택된 행이 속하는 열을
visit으로 관리를 하면 된다.


*/