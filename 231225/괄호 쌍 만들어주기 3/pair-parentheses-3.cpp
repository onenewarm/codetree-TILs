#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    char str[101];

    cin >> str;

    char* pStr = str;

    int ans = 0;

    while(*pStr != '\0')
    {
        if(*pStr == ')')
        {
            ++pStr;
            continue;
        }

        char* pRear = pStr + 1;

        while(*pRear != '\0')
        {
            if(*pRear == ')') ++ans;
            ++pRear;
        }

        ++pStr;
    }

    cout << ans;

    return 0;
}