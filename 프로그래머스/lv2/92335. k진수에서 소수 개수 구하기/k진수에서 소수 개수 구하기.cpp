#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long num) //소수 판별하는 함수
{
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); ++i) 
    {
        if (num % i == 0) return false;
    }
    return true;

}
int solution(int n, int k) 
{
    int answer = 0;
    vector<pair<string, int>> v;

    //진수 구하기
    string s = "";
    while (n > 0) 
    {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    string tmp = "";

    for (char c : s) 
    {
        if (c == '0') //한 글자씩 확인하면서 0이 나올 경우
        {
            if (!tmp.empty() && isPrime(stoll(tmp))) //해당 스트링이 비어있지 않으면서 소수일 경우
            {
                answer++;
            }
            tmp = "";//비워줌
        }
        else tmp += c;//소수 판별을 위해 해당 숫자를 스트링에 추가함.
    }

    if (!tmp.empty() && isPrime(stoll(tmp))) //진수 변환하였을 때 0이 아닌 숫자들만 있는 경우 소수 판별
    {  //마지막꺼 
        answer++;
    }
    return answer;
}