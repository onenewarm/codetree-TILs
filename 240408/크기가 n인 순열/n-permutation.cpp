#include <iostream>
#include <list>

using namespace std;

int n;
int visit[9];

list<int> nums;

void Choose(int iCurPos)
{
    if(iCurPos == n)
    {
        for(auto iter = nums.begin() ; iter != nums.end() ; ++iter)
        {
            cout << (*iter) << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int num = 1 ; num <= n ; ++num)
    {
        if(visit[num] == 1) continue;
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