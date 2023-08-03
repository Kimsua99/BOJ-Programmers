#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(int num) //에라토스테네스의 체 -> 2부터 n까지의 수 중에 소수를 판별하기 위한 알고리즘. 소수를 찾으면 해당 수의 배수를 모두 지워나가는 방식이다. n까지 확인할 필요 없이 루트 n까지만 나누어서 떨어지면 소수가 아니다.
{
    if (num < 2) //1은 소수가 아님
        return false;

    for (int i = 2; i <= sqrt(num); i++)//2부터 num의 루트값까지 반복
        if (num % i == 0)//나누어 떨어지면 소수가 아님. 
            return false;
    return true;//나누어떨어지는 수가 없으면 소수임.
}

int solution(string numbers) 
{
    int answer = 0;

    vector<char> v;
    vector<int> toNum;

    for (int i = 0; i < numbers.size(); i++)//숫자 개별로 문자열에 넣기
    {
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());

    do
    {
        string str = " ";
        for (int i = 0; i < v.size(); i++)
        {
            str.push_back(v[i]);//char을 string으로 변환
            toNum.push_back(stoi(str));//string을 int로 변환
        }
    } while (next_permutation(v.begin(), v.end()));//next_permutation -> 모든 경우의 수를 저장함

    sort(toNum.begin(), toNum.end());
    toNum.erase(unique(toNum.begin(), toNum.end()), toNum.end());//중복 판별 및 제거

    for (int i = 0; i < toNum.size(); i++)
        if (isPrime(toNum[i])) 
            answer++;

    return answer;
}
