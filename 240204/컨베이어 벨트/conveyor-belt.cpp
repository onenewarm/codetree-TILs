#include <iostream>

using namespace std;

int n,t;
int matrix[2][200];
int iFirstRow = 0;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> t;

    for(int iRow = 0 ; iRow < 2 ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    //(iFirstRow - 1 + n) % n;
    //(iSecondRow + 1) % n;

    while(t--)
    {
        int tmp = matrix[0][(iFirstRow + (n-1)) % n];
        matrix[0][(iFirstRow + (n-1)) % n] = matrix[1][(iFirstRow + (n-1)) % n];
        matrix[1][(iFirstRow + (n-1)) % n] = tmp;

        iFirstRow = (iFirstRow - 1 + n) % n;
    }

    for(int iRow = 0 ; iRow < 2 ; ++iRow)
    {
        for(int iCol = iFirstRow ; iCol < iFirstRow + n ; ++iCol)
        {
            cout << matrix[iRow][iCol % n] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
고급 요구사항 :
시계 방향으로 한 칸 씩 회전하는 컨베이어 벨트가 있다.
컨베이어 벨트 위아래로 n개씩 총 2*n 개의 숫자가 두 줄로 적혀 있다.
1초에 한 칸씩 움직인다.
t초 시간 후 상태를 출력하여라.

입력 :
n (1 ~ 200)
t (1 ~ 1000)

아이디어 :
시간복잡도를 줄이기 위해서 전체를 움직이는 것이 아니라, 첫번째 시작점만을 이동한다.
첫번째 Col, 마지막 Col에 대해서만 후 처리가 필요하다.
Row의 변경이 생기기 때문이다. 

*/