#include <iostream>

using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m;

    int matrix[101][101];

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = 0;

    for(int iStd = 0 ; iStd < n ; ++iStd)
    {
        int cnt = 0;
        int prevNum = 0;
        for(int iRow = 0 ; iRow < n ; ++iRow)
        {
            if(prevNum != matrix[iRow][iStd])
            {
                prevNum = matrix[iRow][iStd];
                cnt = 1;
            }
            else
            {
                ++cnt;
            }

            if(cnt == m)
            {
                ++ans;
                cnt = 0;
                prevNum = 0;
                break;
            }
        }
        
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(prevNum != matrix[iStd][iCol])
            {
                prevNum = matrix[iStd][iCol];
                cnt = 1;
            }
            else
            {
                ++cnt;
            }

            if(cnt == m)
            {
                ++ans;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}

/*

고급 요구사항 :
1 ~ 100 숫자로만 이루어진 n*n 격자가 주어진다.
연속하여 m개 이상의 동일한 원소가 나오는 순간이 존재하는 수열
행과 열을 쭉 봤을 때 거기서 위에 만족하는 것이 몇개인지 카운팅 해라

입력 :
n, m이 입력된다. ( 1 ~ 100) n은 격자의 크기 m은 연속하는 원소의 개수의 기준
그리고 n*n의 격자의 입력

출력 :
2n개의 수열 중에서 요구사항을 만족하는 카운트

아이디어 :
Row 기준의 for문
Col 기준의 for문

두개를 만들어서 연속된 수의 개수를 cnt로 저장하고, prevNum으로 현재 값을 갱신한다.

*/