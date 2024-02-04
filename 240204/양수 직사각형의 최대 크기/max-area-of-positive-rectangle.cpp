#include <iostream>

using namespace std;

int matrix[20][20];

int CheckRange(int y1, int x1, int y2, int x2)
{
    int cnt = 0;
    for(int iRow = y1 ; iRow <= y2 ; ++iRow)
    {
        for(int iCol = x1 ; iCol <= x2 ; ++iCol)
        {
            ++cnt;
            if(matrix[iRow][iCol] < 0) return -1;
        }
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n , m;
    cin >> n >> m;



    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = -1;

    for(int y1 = 0 ; y1 < n ; ++y1)
    {
        for(int x1 = 0 ; x1 < m ; ++x1)
        {
            for(int y2 = y1 ; y2 < n ; ++y2)
            {
                for(int x2 = x1 ; x2 < m ; ++x2)
                {
                    ans = max(ans,CheckRange(y1, x1, y2, x2));      
                }
            }
        }
    }

    cout << ans;

    return 0;
}

/*

고급 요구사항 :
n * m 크기의 이차원 영역이 주어진다.
각 위치에는 정수 값이 적혀져 있다.
가능한 양수 직사각형 중 최대 크기를 구하려고 한다.

양수 직사각형 : 직사각형 내에 있는 숫자들이 전부 양수이다. 대각선을 이용한 직사각형은 만들지 않는다.

입력 :
n , m (1 ~ 20)
정수값 ( -1000 ~ 1000 )

출력 :
직사각형 중 최대 크기를 출력하라 만약에 없다면 -1을 출력하라.

아이디어 :
모든 직사각형을 그려서 그 안에 있는 모든 값들이 양수 인지를 확인한다.
x1, y1, x2, y2가 기준이 된다. [x1, x2] && [y1, y2] 이 범위를 확인한다.



*/