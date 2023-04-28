#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> v) 
{
    vector<int> answer;

    if(v.size() <= 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int x = min_element(v.begin(), v.end()) - v.begin();
    v.erase(v.begin() + x);
    return v;
    
}