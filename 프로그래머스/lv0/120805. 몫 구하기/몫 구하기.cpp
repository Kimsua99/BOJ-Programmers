#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) 
{
    int answer = 0;
    answer = num1 / num2;
    return answer;
}

int main()
{
    int num1, num2 = 0;
    cin >> num1 >> num2;
    cout << solution(num1, num2);
}