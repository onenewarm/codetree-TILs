#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<vector<int>> adj;

int res = 0;

vector<int> visit;

void DFS(int curVertex)
{
    bool endFlag = true;

    for(int iEdge = 0 ; iEdge < adj[curVertex].size() ; ++iEdge)
    {
        int adjNodeNum = adj[curVertex][iEdge];
        if(visit[adjNodeNum]) continue;

        endFlag = false;
        visit[adjNodeNum] = 1;
        DFS(adjNodeNum);
        visit[adjNodeNum] = 0;
    }

    if(endFlag == true) ++res;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    adj.resize(n+1);
    visit.resize(n+1, 0);

    for(int EdgeCnt = 0 ; EdgeCnt < m ; ++EdgeCnt)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visit[1] = 1;
    DFS(1);

    cout << res;

    return 0;
}