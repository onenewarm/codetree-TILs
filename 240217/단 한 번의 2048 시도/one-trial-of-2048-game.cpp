#include <iostream>

using namespace std;

int matrix[4][4];
char ch;

void Solve()
{
    bool dirFlag;

    if(ch == 'R' || ch == 'L') dirFlag = true;
    else dirFlag = false;

    int InitCurPos, InitAddPos;
    int nextAdd;

    if(dirFlag)
    {
        if(ch == 'R')
        {
            InitCurPos = 3;
            InitAddPos = 3;
            nextAdd = -1;
        }
        else
        {
            InitCurPos = 0;
            InitAddPos = 0;
            nextAdd = 1;
        }
        
        int curPos, addPos;

        for(int iRow = 0; iRow < 4 ;++iRow)
        {
            curPos = InitCurPos;
            addPos = InitAddPos;
            while(curPos >= 0 && curPos < 4)
            {
                if(matrix[iRow][curPos] != 0)
                {
                    matrix[iRow][addPos] = matrix[iRow][curPos];
                    if(addPos != curPos) matrix[iRow][curPos] = 0;
                    addPos += nextAdd;
                }
                curPos += nextAdd;
            }

            curPos = InitCurPos;
            addPos = InitAddPos;

            while(curPos >= 0 && curPos < 4)
            {
                if(matrix[iRow][curPos] != 0)
                {
                    if(curPos - nextAdd >= 0 && curPos - nextAdd <= 3 &&
                    matrix[iRow][curPos - nextAdd] == matrix[iRow][curPos])
                    {
                        matrix[iRow][curPos - nextAdd] *= 2;
                        matrix[iRow][curPos] = 0;
                    } 
                    else
                    {
                        matrix[iRow][addPos] = matrix[iRow][curPos];
                        if(addPos != curPos) matrix[iRow][curPos] = 0;
                        addPos += nextAdd;
                    }
                }
                curPos += nextAdd;
            }
        }
    
    }
    else
    {
        if(ch == 'D')
        {
            InitCurPos = 3;
            InitAddPos = 3;
            nextAdd = -1;
        }
        else
        {
            InitCurPos = 0;
            InitAddPos = 0;
            nextAdd = 1;
        }

        int curPos, addPos;

        for(int iCol = 0; iCol < 4 ;++iCol)
        {
            curPos = InitCurPos;
            addPos = InitAddPos;
            while(curPos >= 0 || curPos < 4)
            {
                if(matrix[curPos][iCol] != 0)
                {
                    matrix[addPos][iCol] = matrix[curPos][iCol];
                    if(addPos != curPos ) matrix[curPos][iCol] = 0;
                    addPos += nextAdd;
                }
                curPos += nextAdd;
            }

            curPos = InitCurPos;
            addPos = InitAddPos;

            while(curPos >= 0 && curPos < 4)
            {
                if(matrix[curPos][iCol] != 0)
                {
                    if(curPos - nextAdd >= 0 && curPos - nextAdd <= 3 &&
                    matrix[curPos - nextAdd][iCol] == matrix[curPos][iCol])
                    {
                        matrix[curPos - nextAdd][iCol] *= 2;
                        matrix[curPos][iCol] = 0;
                    } 
                    else
                    {
                        matrix[addPos][iCol] = matrix[curPos][iCol];
                        if(addPos != curPos) matrix[curPos][iCol] = 0;
                        addPos += nextAdd;
                    }
                }
                curPos += nextAdd;
            }
        }

        
    }


    for(int iRow = 0 ; iRow < 4 ; ++iRow)
    {
        for(int iCol = 0 ; iCol < 4 ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    for(int iRow = 0 ; iRow < 4 ; ++iRow)
    {
        for(int iCol = 0 ; iCol < 4 ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    cin >> ch;

    Solve();

    return 0;
}