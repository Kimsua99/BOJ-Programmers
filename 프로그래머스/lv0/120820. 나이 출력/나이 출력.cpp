#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

using namespace std;

int solution(int age) 
{
    int answer = 0;
    
    answer = 2022 + 1 - age;
    return answer;
}

int main() 
{    
    cout << solution(40);
}