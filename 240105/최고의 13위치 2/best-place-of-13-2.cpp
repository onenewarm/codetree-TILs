#include <iostream>
#include <vector>

using namespace std;


struct Item
{
    int y;
    int x;
    int cnt;
};

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    int matrix[20][20];

    for(int iCnt = 0; iCnt <n;++iCnt)
    {
        for(int jCnt = 0; jCnt <n;++jCnt)
        {
            cin >> matrix[iCnt][jCnt];
        }
    }

    vector<Item> items;

    for(int iRow = 0; iRow < n ;++iRow)
    {
        for(int iCol = 0; iCol < n - 2 ; iCol++)
        {
            int cnt = matrix[iRow][iCol] + matrix[iRow][iCol+1] + matrix[iRow][iCol+2];
            items.push_back({iRow, iCol, cnt});
        }
    }

    
    int ans = 0;


    for(int iCmpA = 0; iCmpA < items.size(); ++iCmpA)
    {
        for(int iCmpB = iCmpA + 1;iCmpB < items.size();++iCmpB)
        {
            Item A = items[iCmpA];
            Item B = items[iCmpB];

            bool calcFlag = false;

            if(A.y != B.y) calcFlag = true;
            else
            {
                if(B.x - A.x > 2) calcFlag =true;
            } 

            if(calcFlag) ans = max(ans, A.cnt + B.cnt);
        }
    }

    
    cout << ans;

    return 0;
}