#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    char a[11];

    cin >> a;

    char* pA = a;

    int ans = 0;
    bool flag = true;

    while(*pA != '\0')
    {
        if(*pA == '0')
        {
            *pA = '1';
            flag = false;
            break;
        }
        ++pA;
    }

    if(flag == true) *(pA -1) = '0';

    char* pAns = a;
    while(*pAns != '\0')
    {
        if(*pAns == '1') ans = ans * 2 + 1;
        else ans = ans*2;

        ++pAns;
    }

    cout << ans;

    return 0;
}