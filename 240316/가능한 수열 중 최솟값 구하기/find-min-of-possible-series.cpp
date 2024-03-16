#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> curNums;

bool PartPossible(int slideSize)
{
    int s = 0;
    int e = s + (slideSize - 1);
    while(e < n)
    {
        int left = s;
        int right = (s + e) / 2 + 1;

        int range = slideSize / 2;

        int chkFlag = true;

        for(int chkCnt = 0 ; chkCnt < range ; ++chkCnt)
        {
            if(curNums[left++] != curNums[right++])
            {
                chkFlag = false;
                break;
            }
        }

        if(chkFlag == true) return false;

        ++s;
        ++e;
    }
    return true;
}

bool Possible(int size)
{
    int slideSize = 2;

    while(slideSize <= size)
    {
        if(!PartPossible(slideSize)) return false;
        slideSize += 2;
    }

    return true;
}

bool exitFlag = false;

void ChooseNum(int chooseCnt)
{
    if(exitFlag) return;

    if(chooseCnt > 1 && Possible(chooseCnt))
    {
        if(chooseCnt == n)
        {
            for(int iCnt = 0 ; iCnt < curNums.size() ; ++iCnt)
            {
                cout << curNums[iCnt];
            }
            exitFlag = true;
            return;
        }
    }
    else if(chooseCnt > 1) return;

    for(int Num = 4 ; Num <= 6 ; ++Num)
    {
        curNums.push_back(Num);
        ChooseNum(chooseCnt + 1);
        curNums.pop_back();
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    ChooseNum(0);

    return 0;
}