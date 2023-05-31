#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    vector<int> arr(elements);
    set<int> s;//중복 방지를 위해

    for (int i = 0; i < elements.size() - 1; i++)//가장 마지막 원소 제외하고 기존 배열에 붙여서 원형으로 만듦
    {
        arr.push_back(elements[i]);
    }
    for (int i = 0; i < elements.size(); i++)
    {
        vector<int> v;

        for (int j = 0; j < elements.size(); j++)
        {
            int num = 0;

            for (int k = j; k < i + j + 1; k++)//부분 수열 합 벡터에 넣어줌.
            {
                num += arr[k];
            }

            v.push_back(num);
        }

        for (int j = 0; j < v.size(); j++)//중복 제거를 위해 set에 v 벡터 값들을 넣어줌.
            s.insert(v[j]);
    }
    answer = s.size();//중복 제거된 값 개수 리턴
    return answer;
}