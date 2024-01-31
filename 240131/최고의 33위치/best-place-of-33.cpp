#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int matrix[21][21];

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0 ; iCol < N ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = 0;

    //탐색이 되는 기준인 왼쪽 모서리를 for문으로 표현한다.
    for(int iStdRow = 0 ; iStdRow < N-2 ; ++iStdRow)
    {
        for(int iStdCol = 0 ; iStdCol < N-2 ; ++iStdCol)
        {
            int coinCnt = 0;
            for(int iRow = iStdRow ; iRow < iStdRow + 3 ; ++iRow)
            {
                for(int iCol = iStdCol ; iCol < iStdCol + 3 ; ++iCol)
                {
                    if(matrix[iRow][iCol] != 0) ++coinCnt;
                }
            }
            ans = max(ans, coinCnt);
        }
    }

    cout << ans;

    return 0;
}


/*
고급 요구사항 :
N*N 크기의 격자 정보가 주어진다. 해당 위치에 동전이 있다면 1, 없다면 0이다.
N*N 격자를 벗어나지 않도록 3*3 크기의 격자를 적절하게 잡아서 해당 범위 안에 있는
동전의 개수가 최대가 되로록 만들어라.

입력 :
N : 격자의 크기(3~20)

N*N번 격자의 정보 : 0은 동전x 1은 동전o

출력 :
최대 동전의 수

아이디어 :
3x3 격자의 왼쪽 상단 모서리가 기준이 된다. 3개의 단위로 경계가 나뉘게 된다.
그 위치에서 x + 0~2 , y + 0~2를 순회 하면서 1의 개수를 샌다.
max로 ans를 갱신한다.

*/