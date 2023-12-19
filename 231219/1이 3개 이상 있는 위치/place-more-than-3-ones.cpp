#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1 ,1, 0 ,0};

int main() {
    // 여기에 코드를 작성해주세요.

    vector<vector<int>> matrix;

    int n ;
    cin >> n;
    matrix.resize(n, vector<int>(n));

    for(int iRow = 0 ;iRow < n;++iRow)
    {
        for(int iCol = 0; iCol < n ;++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = 0;

    for(int iRow = 0 ;iRow < n;++iRow)
    {
        for(int iCol = 0; iCol < n ;++iCol)
        {
            int cnt = 0;
            for(int iCnt = 0; iCnt < 4;++iCnt)
            {
                int checkY = iRow + dy[iCnt];
                int checkX = iCol + dx[iCnt];

                if(checkY < 0 || checkX < 0 || checkY > n-1 || checkX > n-1) continue;

                if(matrix[checkY][checkX]) ++cnt;
            }
            if(cnt >= 3) ++ans;
        }   
    }

    cout << ans;

    return 0;
}