#include <iostream>
#include <vector>

using namespace std;

int K,N;
vector<int> nums;

void Print()
{
    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        cout << nums[iCnt] << ' ';
    }
    cout << '\n';
}

void Choose(int curCnt)
{
    if(curCnt == N)
    {
        Print();
        return;
    }

    for(int addNum = 1 ; addNum <= K ; ++addNum)
    {
        if(curCnt >= 2 && nums[curCnt - 1] == addNum && nums[curCnt] == addNum) continue;
        nums.push_back(addNum);
        Choose(curCnt + 1);
        nums.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> K >> N;

    Choose(0);

    return 0;
}