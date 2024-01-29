#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    const int MAX_SIZE = 2147483647;
    const int MIN_SIZE = -2147483647;

    int minX = MAX_SIZE, maxX = MIN_SIZE, minY = MAX_SIZE, maxY = MIN_SIZE;

    int N;
    cin >> N;

    int Candidates[4];

    int x[101];
    int y[101];

    for(int iCnt = 0; iCnt < N ; ++iCnt)
    {
        cin >> x[iCnt] >> y[iCnt];
    }

    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        if(minX > x[iCnt])
        {
            Candidates[0] = iCnt;
            minX = x[iCnt];
        }

        if(maxX < x[iCnt])
        {
            Candidates[1] = iCnt;
            maxX = x[iCnt];
        }

        if(minY > y[iCnt])
        {
            Candidates[2] = iCnt;
            minY = y[iCnt];
        }

        if(maxY < y[iCnt])
        {
            Candidates[3] = iCnt;
            maxY = y[iCnt];
        }
    }

    int ans = MAX_SIZE;

    for(int iCandidate = 0 ; iCandidate < 4 ; ++iCandidate)
    {
        minX = MAX_SIZE, maxX = MIN_SIZE, minY = MAX_SIZE, maxY = MIN_SIZE;
        for(int iCnt = 0 ; iCnt < N ; ++iCnt)
        {
            if(Candidates[iCandidate] == iCnt) continue;

            if(minX > x[iCnt])
            {
                minX = x[iCnt];
            }

            if(maxX < x[iCnt])
            {
                maxX = x[iCnt];
            }

            if(minY > y[iCnt])
            {
                minY = y[iCnt];
            }

            if(maxY < y[iCnt])
            {
                maxY = y[iCnt];
            }
        }

        int rectSize = (maxX - minX) * (maxY - minY);
        ans = min(ans, rectSize);
    }

    cout << ans;

    return 0;
}

/*

고급 요구 사항 :
점 N개가 있다. 2차원 좌표 평면에
N개의 점 중에서 하나를 제외시킨다.
이 경우 모든 점들을 포함하는 직사각형의 넓이를 최소로 하는 프로그램을 만들어라

입력 : 
점 개수 N이 주어진다. (3 ~ 100)
N개의 줄에 거쳐서 (x,y)가 주어진다. ( 1 ~ 40000 )

출력 : 
첫 번째 줄에 모든 점들을 포함하는 직사각형의 최소 넓이를 출력한다.
남은 점들이 모두 x값이 같거나 y값이 같은 경우에는 필요한 직사각형의 넓이가 0이 될 수도 있다.

*/