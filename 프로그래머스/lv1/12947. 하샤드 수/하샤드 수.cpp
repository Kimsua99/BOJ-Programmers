#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) 
{
    int xx = x;
    bool answer = true;
    int sum = 0;
    while(x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    if(xx % sum == 0)
        answer = true;
    else
        answer = false;
    
    return answer;
}
int main()
{
    int x;
    cin >> x;
    cout << solution(x);
}