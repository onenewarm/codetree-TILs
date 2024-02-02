#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n,m;
    cin >> n >> m;

    int matrix[5][5];

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }  

    int ans = -2147483647;

    //왼쪽 위 모서리
    for(int y1 = 0 ; y1 < n ; ++y1)
    {
        for(int x1 = 0 ; x1 < m ; ++x1)
        {
            //오른쪽 아래 모서리
            for(int y2 = y1 ; y2 < n ; ++y2)
            {
                for(int x2 = x1 ; x2 < m ; ++x2)
                {
                    int visit[5][5] = {};

                    int firstRectSum = 0;

                    for(int iRow = y1 ; iRow <= y2 ; ++iRow)
                    {
                        for(int iCol = x1 ; iCol <= x2 ; ++iCol)
                        {
                            visit[iRow][iCol] = 1;
                            firstRectSum += matrix[iRow][iCol];
                        }
                    }
                    
                    //두번째 사각형 왼쪽 위 모서리
                    for(int _y1 = 0 ; _y1 < n ; ++_y1)
                    {
                        for(int _x1 = 0 ; _x1 < m ; ++_x1)
                        {
                            //두번째 사각형 오른쪽 아래 모서리
                            for(int _y2 = _y1 ; _y2 < n ; ++_y2)
                            {
                                for(int _x2 = _x1 ; _x2 < m ; ++_x2)
                                {
                                    bool flag = true;
                                    int secondRectSum = 0;

                                    for(int iRow = _y1 ; iRow <= _y2 ; ++iRow)
                                    {
                                        for(int iCol = _x1 ; iCol <= _x2 ; ++iCol)
                                        {
                                            secondRectSum += matrix[iRow][iCol];
                                            if(visit[iRow][iCol] != 0)
                                            {
                                                flag = false;
                                                break;
                                            }
                                        }
                                    }

                                    if(flag)
                                    {
                                        ans = max(ans, firstRectSum + secondRectSum);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}

/*
고급 요구사항 :
n * m 크기의 이차원 영역이 있다. 각 위치에 정수 값이 하나씩 적혀있다.
서로 겹치지 않게 두 직사각형을 잡아서 적힌 숫자들의 총 합이 최대가 되도록 하는 프로그램을 만들어라

두 직사각형의 경계는 서로 닿아야 한다.
대각선을 이용한 직사각형은 만들지 못한다.

입력 :
n, m (2 ~ 5)
정수 값 ( -1000 ~ 1000 )

*/