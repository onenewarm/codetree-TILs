#include <iostream>

using namespace std;

int n;
pair<int,int> lines[15];
int visit[1001];
int res = 0;

bool CheckVisit(int x1, int x2)
{
    for(int dx = x1 ; dx <= x2 ; ++dx)
    {
        if(visit[dx] == 1) return false;
    }

    return true;
}

void DFS(int iLines, int curRes)
{
    int x1,x2;
    x1 = lines[iLines].first;
    x2 = lines[iLines].second;

    if(CheckVisit(x1,x2))
    {
        for(int dx = x1 ; dx <= x2 ; ++dx)
        {
            visit[dx] = 1;
        }
        ++curRes;
    }

    if(iLines == n - 1) res = max(res, curRes);

    for(int iNextLines = iLines + 1 ; iNextLines < n ; ++iNextLines)
    {
        DFS(iNextLines, curRes);
        int nextX1 = lines[iNextLines].first;
        int nextX2 = lines[iNextLines].second;

        for(int dx = nextX1 ; dx <= nextX2 ; ++dx)
        {
            visit[dx] = 0;
        }
    }
}

void Solve()
{
    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        DFS(iCnt, 0);
        int x1,x2;

        x1 = lines[iCnt].first;
        x2 = lines[iCnt].second;

        for(int dx = x1 ; dx <= x2 ; ++dx)
        {
            visit[dx] = 0;
        }
    }

    cout << res;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        int x1,x2;
        cin >> x1 >> x2;
        lines[iCnt] = {x1, x2};
    }

    Solve();

    return 0;
}

/*

수직선 상에 선분이 주어진다.

겹치지 않게 가장 많은 수의 선분을 고르는 프로그램

*/