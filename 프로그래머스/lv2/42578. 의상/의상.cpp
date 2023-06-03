#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;//결과 값에 곱하기를 해야 하므로 0이 아닌 1로 변경

    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) 
    {
        m[clothes[i][1]]++;//여기서 1은 뒤의 요소 즉 headgear, face와 같은 종류를 뜻함
    }//옷이 담긴 벡터를 전체적으로 돌면서 각 종류 별로 개수를 카운트해준다.

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) //반복자 사용해서 맵의 전체를 돌면서 요소를 하나하나 따짐.
    {
        answer *= it->second + 1;//second는 두번째 인자로 개수를 뜻함. 개수에 + 1을 해서 곱해줌. 
    }


    return answer - 1;//적어도 하나는 입어야 하므로 모두 안 입었을 경우를 제외함.
}