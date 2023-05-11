#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) 
{
    string answer = "";
    
    vector<int> v;
    string tmp;
    
    for(int i=0;i<s.length();i++)//주어진 문자열 반복
    {
        if(s[i]!= ' ')//만약 공백이 아닐 경우 -> 숫자거나 부호일 경우
        {
            tmp += s[i];//해당 값을 tmp 문자열에 추가해줌.
        }
        else//공백을 만났을 경우
        {
            v.push_back(stoi(tmp));//부호 + 숫자 또는 숫자 있는 문자열을 정수로 형변환하고 벡터에 넣음
            tmp.clear();//해당 문자열은 초기화
        }
    }
    
    v.push_back(stoi(tmp));//마지막 원소의 경우 공백이 없이 단순 숫자이기 때문에 형변환해서 더해줌
    
    sort(v.begin(),v.end());//오름차순 정렬
    
    answer += to_string(v.front())+" "+ to_string(v.back());//가장 앞(= 최솟값), 가장 뒤(최댓값) 출력
    return answer;
}