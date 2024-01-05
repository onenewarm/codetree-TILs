#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    char str[101];

    cin >> str;

    int ans = 0;

    for(int iC = 0 ; iC < n-2; ++iC)
    {
        if(str[iC] == 'C')
        {
            for(int iO = iC + 1; iO < n - 1; ++iO)
            {
                if(str[iO] == 'O')
                {
                    for(int iW = iO + 1;iW < n ; ++iW)
                    {
                        if(str[iW] == 'W') ++ans;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}