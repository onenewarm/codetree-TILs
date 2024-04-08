#include <iostream>
#include <vector>

using namespace std;

int n;
int visit[9];

vector<int> nums;

void Choose(int iCurPos)
{
    if(iCurPos == n)
    {
        for(int iCnt = 0 ; iCnt < nums.size() ; ++iCnt)
        {
            cout << nums[iCnt] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int num = n ; num > 0 ; --num)
    {
        if(visit[num] != 0) continue;
        nums.push_back(num);
        visit[num] = 1;
        Choose(iCurPos + 1);
        nums.pop_back();
        visit[num] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    Choose(0);

    return 0;
}