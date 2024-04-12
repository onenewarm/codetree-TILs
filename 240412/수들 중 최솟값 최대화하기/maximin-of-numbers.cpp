#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> matrix;
vector<int> visitCol;

int res = 0;

vector<int> curNums;

void ChooseRow(int curRow)
{
    if(curRow == n)
    {
        int minNum = 214783647;
        for(int iCnt = 0 ; iCnt < curNums.size() ; ++iCnt)
        {
            minNum = min(minNum, curNums[iCnt]);
        }
        res = max(res, minNum);

        return ;
    }

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        if(visitCol[iCol] == 1) continue;

        visitCol[iCol] = 1;
        curNums.push_back(matrix[curRow][iCol]);
        ChooseRow(curRow + 1);
        curNums.pop_back();
        visitCol[iCol] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    matrix.resize(n, vector<int>(n));
    visitCol.resize(n,0);

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    ChooseRow(0);

    cout << res;

    return 0;
}