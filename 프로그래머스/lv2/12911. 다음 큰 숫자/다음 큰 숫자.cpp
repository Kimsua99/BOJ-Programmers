#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int nOne = 0;
    int iOne = 0;
    int tmp = n;
    vector <int> v;

    while (tmp > 0)
    {
        if(tmp % 2 == 1)
            nOne++;
        tmp /= 2;
    }
    for (int i = n + 1; i < 1000000; i++)
    {
        iOne = 0;
        int num = i;
        while (num > 0)
        {
            if (num % 2 == 1)
                iOne++;
            num /= 2;
        }
        if (iOne == nOne)
        {
            answer = i;
            break;
        }
    }

    return answer;
}