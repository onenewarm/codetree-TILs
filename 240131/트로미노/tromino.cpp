#include <iostream>

using namespace std;

int matrix[201][201];

int n,m;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = 0;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            int OOBRow = iRow + 1;
            int OOBCol = iCol + 1;

            if(OOBRow < n && OOBCol < m)
            {
                //ㄴ자 확인
                int curSum = 0;
                curSum = matrix[iRow][iCol] + matrix[iRow+1][iCol] + matrix[iRow+1][iCol+1];
                ans = max(ans, curSum);

                //역ㄴ
                curSum = matrix[iRow][iCol+1] + matrix[iRow+1][iCol] + matrix[iRow+1][iCol+1];
                ans = max(ans, curSum);

                //ㄱ
                curSum = matrix[iRow][iCol] + matrix[iRow][iCol+1] + matrix[iRow+1][iCol+1];
                ans = max(ans, curSum);

                //역ㄱ
                curSum = matrix[iRow][iCol] + matrix[iRow][iCol+1] + matrix[iRow+1][iCol];
                ans = max(ans, curSum);
            } 

            OOBRow = iRow + 2;
            
            if(OOBRow < n)
            {
                int curSum = 0;
                curSum = matrix[iRow][iCol] + matrix[iRow+1][iCol] + matrix[iRow+2][iCol];

                ans = max(ans, curSum);
            }

            OOBCol = iCol + 2;

            if(OOBCol < m)
            {
                int curSum = 0;
                curSum = matrix[iRow][iCol] + matrix[iRow][iCol+1] + matrix[iRow][iCol+2];

                ans = max(ans, curSum);
            }
        }
    }

    cout << ans;

    return 0;
}

/*

고급 요구사항 :
n,m 크기의 블록이 있고 그 블록 각각에는 숫자가 적혀있다.
두 개의 블록이 주어지는데, 이 블록들은 회전이 가능하고 이 블록을 격자안에 넣었을 때
적힌 숫자의 합이 최대가 되도록 해라.

입력 : 
n, m (3 ~ 200) 격자 크기

아이디어 :
블록을 회전하고 뒤집었을 때에 대한 모양의 모든 조합을 기준으로 잡는다.

ㄴ자 블록은

ㄴ, 역ㄴ, ㄱ, 역ㄱ

ㅡ자 블록은
ㅣ,ㅡ

4개, 2개

총 6개의 경우의 수가 나온다.

ㄴ자 블록의 경우 2*2 사각형으로 보고 왼쪽 상단 모서리를 기준으로 잡는다.
ㅡ자 블록의 경우 1*3 , 3*1 직사각형으로 보고 왼쪽 상단 모서리를 기준으로 잡는다.

*/