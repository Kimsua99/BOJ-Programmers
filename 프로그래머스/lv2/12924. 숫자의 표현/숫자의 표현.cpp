#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int sum = 0;
    bool isStart = false;
    int first = 0;
    for (int i = 1; i < n; i++)
    {
        if(isStart = false)
        {
            first = i;
            isStart = true;
        }
        sum += i;
        if(sum >= n)
        {
            if (sum == n)
            {
                answer++;
                sum = 0;
                isStart = false;
                first++;
                i = first;
            }
            else
            {
                sum = 0;
                isStart = false;
                first++;
                i = first;
            }  
        }
    }
    return answer + 1;
}