#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> points;

int res = 1 << 30;

vector<int> selected;

void FindMaxDistance()
{
    int maxDistance = 0;

    for(int iItemA = 0 ; iItemA < selected.size() ; ++iItemA)
    {
        for(int iItemB = iItemA + 1 ; iItemB < selected.size() ; ++iItemB)
        {
            int xDistance = (points[selected[iItemA]].first - points[selected[iItemB]].first);
            int yDistance = (points[selected[iItemA]].second - points[selected[iItemB]].second);
            int distance = (xDistance * xDistance) + (yDistance * yDistance);
            
            if(distance >= res) return;

            maxDistance = max(maxDistance, distance);
        }
    }

    res = min(res, maxDistance);
}



void Dfs(int curIdx)
{
    if(selected.size() == m)
    {
        FindMaxDistance();
        return;
    }

    if(curIdx == n) return;

    selected.push_back(curIdx);
    Dfs(curIdx + 1);
    selected.pop_back();
    Dfs(curIdx + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        int x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    Dfs(0);

    cout << res;

    return 0;
}