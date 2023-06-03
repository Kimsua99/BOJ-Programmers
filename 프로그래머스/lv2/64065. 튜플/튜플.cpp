#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    // 맨앞 맨뒤 중괄호 제거
    s.erase(s.begin()+1);
    s.erase(s.end()-1);

    string temp = "";

    map<int, int> m;
    // 숫자인 경우 문자열에 추가해주고 숫자가 아닌 특수문자들이 나온다면 문자열에 내용물이 있는지 확인하고 있을 경우 문자열을 정수로 형변환 한 다음 맵에 추가해준다.
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if(temp != "") 
            {
                m[stoi(temp)] += 1;//숫자를 넣을 뿐만 아니라 카운트 값까지 같이 넣음.
                temp = "";
            }
            continue;
        }
        else {
            temp += s[i];
        }
    }

    answer.resize(m.size());//맵의 사이즈로 변경해준다
    // 맵에서 카운팅 된 횟수는 맵의 사이즈와 같다. 따라서 아래와 같이 작성해주면
    // 원하는 답과 거꾸로 된 결론이 나오게 되는데, 이 때 reverse 메소드를 활용해서
    // 원하는 결과값이 나오게 answer 벡터를 역순으로 바꿔준다.
    for(auto it = m.begin(); it != m.end(); it++) //맵을 모두 돌면서 
    {
        answer[it->second-1] = it->first;//answer의 인덱스와 맞춰주기 위해 카운트 값에서 1을 뺀 숫자의 인덱스에 해당 카운트에 맞는 숫자를 넣어준다. 카운트 값이 작은 순서대로 숫자가 정렬됨
    }
    
    reverse(answer.begin(), answer.end());//리버스하여 카운트가 아닌 숫자값을 취한다.
    
    return answer;
}