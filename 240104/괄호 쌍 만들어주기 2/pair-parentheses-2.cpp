#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int ans = 0;

    char str[101];

    scanf("%s",str);

    int size = 0;

    char* pStr = str;
    while(*pStr != '\0')
    {
        ++size;
        ++pStr;
    }

    for(int iCnt = 0 ; iCnt < size ; ++iCnt)
    {
        if(str[iCnt] == '(')
        {
            if(iCnt + 1 < size && str[iCnt + 1] == '(')
            {
                for(int iComp = iCnt + 2; iComp < size ; ++iComp)
                {
                    if(str[iComp] == ')')
                    {
                        if(iComp + 1 < size && str[iComp + 1] == ')') ++ans;
                    }
                }

            }    
        }

    }

    cout << ans;

    return 0;
}