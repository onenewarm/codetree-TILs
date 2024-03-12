#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 11

using namespace std;

int n,m;

vector<pair<int,int>> lines;
vector<pair<int,int>> selectedLines;

int res = 2100000;

bool Possible()
{
    int num1[MAX_N], num2[MAX_N];

    for(int iX = 0 ; iX < n ; ++iX)
    {
        num1[iX] = num2[iX] = iX;
    }

    for(int iCnt = 0 ; iCnt < (int)lines.size() ; ++iCnt)
    {
        int idx = lines[iCnt].second;
        swap(num1[idx], num1[idx + 1]);
    }

    for(int iCnt = 0 ; iCnt < (int)selectedLines.size() ; ++iCnt)
    {
        int idx = selectedLines[iCnt].second;
        swap(num2[idx], num2[idx + 1]);
    }

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        if(num1[iCnt] != num2[iCnt]) return false;
    }

    return true;
}

void Dfs(int cnt)
{
    if(cnt == m)
    {
        if(Possible())
        {
            res = min(res, (int)selectedLines.size());
        }
        return;
    }

    selectedLines.push_back(lines[cnt]);
    Dfs(cnt + 1);
    selectedLines.pop_back();

    Dfs(cnt + 1); 
}  


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int iCnt = 0 ; iCnt < m ; ++iCnt)
    {
        int a,b;
        cin >> a >> b;
        lines.push_back({b, a - 1});
    }

    sort(lines.begin(), lines.end());

    Dfs(0);

    cout << res;

    return 0;
}