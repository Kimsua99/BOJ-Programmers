#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    for(long long i = 1; i < 50000000; i++)
    {
        if(i * i == n)
        {
            answer = (i + 1) * (i + 1);
            break;   
        }
        else
            answer = -1;
    }
    return answer;
}

int main()
{
    long long n;
    cin >> n;
    cout << solution(n);
}