#include <iostream>

using namespace std;

int n,t;

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n >> t;

    int matrix[3][201];

    for(int iRow = 0 ; iRow < 3 ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int iFirstCol = 0;

    while(t--)
    {
        int iChange = (iFirstCol + (n - 1)) % n;
        int tmp1 = matrix[1][iChange];
        int tmp2 = matrix[2][iChange];
        
        matrix[1][iChange] = matrix[0][iChange];
        matrix[2][iChange] = tmp1;
        matrix[0][iChange] = tmp2;

        iFirstCol = (iFirstCol + n - 1) % n;
    }

    for(int iRow = 0 ; iRow < 3 ; ++iRow)
    {
        for(int iCol = iFirstCol ; iCol < iFirstCol + n ; ++iCol)
        {
            cout << matrix[iRow][iCol % n] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}