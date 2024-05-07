#include <iostream>

using namespace std;

int table[1001];

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    table[0] = 1;
    table[1] = 1;

    for(int rectWidth = 2 ; rectWidth <= n ; ++rectWidth)
    {
        table[rectWidth] = table[rectWidth - 1] + 2*table[rectWidth - 2]; 
    }

    cout << table[n];

    return 0;
}