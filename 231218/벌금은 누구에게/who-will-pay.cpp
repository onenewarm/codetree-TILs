#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, k, m;

    cin >> n >> m >> k;

    vector<int> students(n+1 , 0);

    for(int iCnt = 0; iCnt < m;++iCnt)
    {
        int num;
        cin >> num;
        students[num]++;
        if(students[num] == k)
        {
            cout << num;
            return 0;
        }
    }
    cout << -1;
    return 0;
}