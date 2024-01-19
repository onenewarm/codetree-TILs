#include <iostream>

using namespace std;

struct Input
{
    int num;
    int cnt1;
    int cnt2;
};

int main() {

    Input inputs[10];
    int n;

    cin >> n;

    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        int num, cnt1, cnt2;

        cin >> num >> cnt1 >> cnt2;

        inputs[iCnt] = {num, cnt1, cnt2};
    }

    int ans = 0;

    for(int iFirst = 1 ; iFirst < 10 ; ++iFirst)
    {
        for(int iSecond = 1 ; iSecond < 10 ; ++iSecond)
        {
            for(int iThird = 1 ; iThird < 10 ; ++iThird)
            {
                bool flag = true;
                for(int iInputs = 0 ; iInputs < n ; ++iInputs)
                {
                    int curCnt1 = 0;
                    int curCnt2 = 0;

                    int InputsFirst = inputs[iInputs].num / 100;
                    int InputsSecond = (inputs[iInputs].num / 10) % 10;
                    int InputsThird = inputs[iInputs].num % 10;

                    if(iFirst == InputsFirst) ++curCnt1;
                    if(iSecond == InputsSecond) ++curCnt1;
                    if(iThird == InputsThird) ++curCnt1;

                    if(iFirst == InputsSecond) ++curCnt2;
                    if(iFirst == InputsThird) ++curCnt2;

                    if(iSecond == InputsFirst) ++curCnt2;
                    if(iSecond == InputsThird) ++curCnt2;

                    if(iThird == InputsFirst) ++curCnt2;
                    if(iThird == InputsSecond) ++curCnt2;

                    if(curCnt1 != inputs[iInputs].cnt1 || curCnt2 != inputs[iInputs].cnt2)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag == true) ++ans;
            }
        }
    }

    cout << ans;

    return 0;
}
/*
111 ~ 999 까지를 비교

1. 3중 for문으로 111 ~ 999 를 모두 살펴본다.
2. 입력으로 주어진 입력들을 struct에 담고, 이를 배열에 담는다.
3. 이 배열을 순회 하면서 현재의 값들과 비교를 한다.

*/