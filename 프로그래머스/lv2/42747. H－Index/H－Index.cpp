#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    int cnt = 0;
    vector<int> v;
    sort(arr.begin(), arr.end());
    int tmp = arr.back();
    int s = 0;

    for (int i = 0; i <= tmp; i++)
    {
        cnt = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] >= i)
            {
                cnt++;
                s = i;
            }
        }
        if (cnt >= s)
        {
            v.push_back(s);
        }
    }

    sort(v.begin(), v.end(), greater<>());

    if (!v.empty())
    {
        answer = v.front();
    }
    
    return answer;
}