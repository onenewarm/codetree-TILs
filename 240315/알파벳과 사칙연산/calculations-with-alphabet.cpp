#include <iostream>
#include <cstring>
#include <vector>

#define INVALID_CHAR 'N'

using namespace std;

int maxRes = -21000000;
char equation[201];

int Calculate(int* vars)
{
    char* pCurPoint = equation;

    int res = 0;
    char oper = INVALID_CHAR;

    while(*pCurPoint != '\0')
    {
        if(*pCurPoint >= 'a' && *pCurPoint <= 'f')
        {
            int idx = *pCurPoint - 'a';
            if(oper != INVALID_CHAR)
            {
                if(oper == '+') res += vars[idx];
                else if(oper == '-') res -= vars[idx];
                else res *= vars[idx];
                oper = INVALID_CHAR;
            }
            else res = vars[idx];
        }
        else oper = *pCurPoint;

        ++pCurPoint;
    }

    return res;
}

void Dfs(vector<char>& alphabets, int cnt, int* nums, int selNum)
{
    if(cnt == alphabets.size() - 1)
    {
        int idx = alphabets[cnt];
        nums[idx - 'a'] = selNum;
        int calcRes = Calculate(nums);
        maxRes = max(maxRes, calcRes);
        return;
    }

    char alphabet = alphabets[cnt++];
    nums[alphabet - 'a'] = selNum;

    for(int iCnt = cnt ; iCnt < alphabets.size() ; ++iCnt)
    {
        for(int nextSelNum = 1 ; nextSelNum <= 4 ; ++nextSelNum)
        {
            Dfs(alphabets, cnt, nums, nextSelNum);
        }
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> equation;

    vector<char> alphabets;
    int vars[6] = {};

    char* tmp = equation;

    while(*tmp != '\0')
    {
        if(*tmp >= 'a' && *tmp <= 'f') vars[*tmp - 'a'] = 1;
        ++tmp;
    }

    for(int iCnt = 0 ; iCnt < 6 ; ++iCnt)
    {
        if(vars[iCnt] == 1) alphabets.push_back('a' + iCnt);
    }

    for(int Num = 1 ; Num <= 4 ; ++Num)
    {
        Dfs(alphabets, 0, vars, Num);
    }

    cout << maxRes;

    return 0;
}